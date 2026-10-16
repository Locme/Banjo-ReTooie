// Night sounds for the day and night cycle (src/gameplay/day_night.cpp): crickets and the odd owl at
// night, birdsong in the morning, played quietly under the game's own sound.
//
// Banjo-Tooie has no sounds like these, so they are made here rather than taken from the game: each
// cricket is a train of short high pulses, an owl is a few soft low hoots, a bird is a phrase of quick
// sweeping notes. day_night::tick says how much of each to play (from the time of day and the level);
// main.cpp's queue_samples mixes them into the game's sound on the audio thread, where the gains ease
// so nothing clicks.

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdint>

#include "tooie_day_night.h"

namespace {
    constexpr float pi = 3.14159265f;

    // Set by the game thread, read by the audio thread.
    std::atomic<float> want_crickets{0.0f};
    std::atomic<float> want_owls{0.0f};
    std::atomic<float> want_birds{0.0f};
    std::atomic<float> want_rain{0.0f};
    // A thunderclap: a new number in thunder_count asks for one, after thunder_delay seconds.
    std::atomic<uint32_t> thunder_count{0};
    std::atomic<float> thunder_delay{0.0f};
    std::atomic<float> thunder_loudness{0.0f};

    // A small random number source, only used on the audio thread.
    uint32_t seed = 0x9E3779B9u;
    float random01() {
        seed ^= seed << 13;
        seed ^= seed >> 17;
        seed ^= seed << 5;
        return (seed >> 8) * (1.0f / 16777216.0f);
    }
    float random_range(float a, float b) {
        return a + (b - a) * random01();
    }

    // A cricket: chirps of a few pulses of one high note, sung for a while, then a rest.
    struct Cricket {
        float pitch = 0.0f;      // Hz
        float period = 0.0f;     // seconds from one chirp to the next
        int pulses = 3;
        float pan = 0.5f;        // 0 left, 1 right
        float loudness = 0.0f;
        double phase = 0.0;      // carrier, in cycles
        float chirp_time = 0.0f; // seconds into this chirp
        bool singing = true;
        float song_left = 0.0f;  // seconds left of singing or resting
    };

    // An owl: now and then a "hoo ... hu-hoooo".
    struct Owl {
        float wait = 12.0f;     // seconds until the next call
        float time = -1.0f;     // seconds into the call; negative when quiet
        float pitch = 400.0f;
        float pan = 0.5f;
        double phase = 0.0;
    };

    // A bird: a phrase of a few quick notes, then a pause.
    struct Bird {
        float wait = 1.0f;      // seconds until the next phrase
        int notes_left = 0;
        float note_time = 0.0f; // seconds into the note (negative: the gap before it)
        float note_length = 0.0f;
        float from = 0.0f;      // Hz at the start of the note
        float to = 0.0f;        // Hz at its end
        float trill = 0.0f;     // Hz of warble, 0 for a plain sweep
        float pan = 0.5f;
        float base = 3000.0f;   // this bird's voice
        double phase = 0.0;
    };

    // Rain: noise shaped to a hiss, with the odd nearer drop pattering in it, a little different in each ear.
    struct Rain {
        float low[2] = {};   // the lowpass of each ear
        float high[2] = {};  // the lowpass that is taken off for a highpass
        float patter = 0.0f; // the envelope of a nearer drop
        float patter_pan = 0.5f;
    };

    // A thunderclap: a crack, then a long low rumble.
    struct Thunder {
        uint32_t seen = 0;
        float wait = -1.0f;  // seconds until it starts (negative: none coming)
        float time = -1.0f;  // seconds into it (negative: silent)
        float loudness = 0.0f;
        float brown = 0.0f;
        float low = 0.0f;
        float lower = 0.0f;
        float wobble = 0.0f;
    };

    Rain rain;
    Thunder thunder_state;
    float gain_rain = 0.0f;

    float noise() {
        return random01() * 2.0f - 1.0f;
    }

    // One frame of rain, both ears.
    void rain_sample(float dt, float& left, float& right) {
        // Roughly 400 Hz to 5 kHz.
        const float a_low = 1.0f - std::exp(-2.0f * pi * 5000.0f * dt);
        const float a_high = 1.0f - std::exp(-2.0f * pi * 400.0f * dt);
        float out[2];
        for (int c = 0; c < 2; c++) {
            rain.low[c] += (noise() - rain.low[c]) * a_low;
            rain.high[c] += (rain.low[c] - rain.high[c]) * a_high;
            out[c] = rain.low[c] - rain.high[c];
        }
        // Now and then a drop close by: a short tick.
        rain.patter *= std::exp(-dt / 0.006f);
        if (random01() < dt * 25.0f) {
            rain.patter = random_range(0.3f, 1.0f);
            rain.patter_pan = random01();
        }
        const float tick = noise() * rain.patter * 0.6f;
        left = out[0] + tick * (1.0f - rain.patter_pan);
        right = out[1] + tick * rain.patter_pan;
    }

    float thunder_sample(float dt) {
        Thunder& t = thunder_state;
        if (t.wait >= 0.0f) {
            t.wait -= dt;
            if (t.wait < 0.0f) {
                t.time = 0.0f;
            }
        }
        if (t.time < 0.0f) {
            return 0.0f;
        }
        t.time += dt;
        if (t.time > 7.0f) {
            t.time = -1.0f;
            return 0.0f;
        }
        // Brown noise, through two lowpasses for the rumble; the crack keeps more of the top.
        t.brown = t.brown * 0.998f + noise() * 0.04f;
        const float a = 1.0f - std::exp(-2.0f * pi * 180.0f * dt);
        const float b = 1.0f - std::exp(-2.0f * pi * 70.0f * dt);
        t.low += (t.brown - t.low) * a;
        t.lower += (t.low - t.lower) * b;
        // The rumble rolls: its loudness wanders.
        t.wobble += (random01() - t.wobble) * (dt * 3.0f);
        const float crack = (t.time < 0.25f) ? (1.0f - t.time / 0.25f) * t.low * 2.5f : 0.0f;
        const float swell = std::min(1.0f, t.time / 0.35f) * std::exp(-t.time / 1.8f);
        return (t.lower * 6.0f * swell * (0.5f + t.wobble) + crack) * t.loudness;
    }

    Cricket crickets[4];
    Owl owl;
    Bird birds[3];
    bool started = false;

    // Gains as heard, easing towards the wanted ones.
    float gain_crickets = 0.0f;
    float gain_owls = 0.0f;
    float gain_birds = 0.0f;

    void start() {
        started = true;
        for (Cricket& c : crickets) {
            c.pitch = random_range(3900.0f, 4700.0f);
            c.period = random_range(0.38f, 0.75f);
            c.pulses = 3 + (int)(random01() * 2.0f);
            c.pan = random_range(0.15f, 0.85f);
            c.loudness = random_range(0.6f, 1.0f);
            c.chirp_time = random_range(0.0f, c.period);
            c.singing = random01() < 0.7f;
            c.song_left = random_range(0.5f, 8.0f);
        }
        for (Bird& b : birds) {
            b.base = random_range(2600.0f, 4200.0f);
            b.pan = random_range(0.1f, 0.9f);
            b.wait = random_range(0.5f, 4.0f);
        }
    }

    // How loud the pulses of a cricket's chirp are at this moment, 0 to 1.
    float cricket_envelope(const Cricket& c) {
        constexpr float pulse = 0.018f;
        constexpr float step = 0.032f;
        const int index = (int)(c.chirp_time / step);
        if (index >= c.pulses) {
            return 0.0f;
        }
        const float x = (c.chirp_time - index * step) / pulse;
        if (x >= 1.0f) {
            return 0.0f;
        }
        const float s = std::sin(pi * x);
        return s * s;
    }

    float cricket_sample(Cricket& c, float dt) {
        c.song_left -= dt;
        if (c.song_left <= 0.0f) {
            // Sings for a while, then rests for a while.
            c.singing = !c.singing;
            c.song_left = c.singing ? random_range(4.0f, 16.0f) : random_range(1.0f, 6.0f);
        }
        c.chirp_time += dt;
        if (c.chirp_time >= c.period) {
            c.chirp_time -= c.period * random_range(0.97f, 1.03f);
        }
        c.phase += c.pitch * dt;
        c.phase -= std::floor(c.phase);
        if (!c.singing) {
            return 0.0f;
        }
        return std::sin(2.0f * pi * (float)c.phase) * cricket_envelope(c) * c.loudness;
    }

    // The call's notes: start, length (seconds) and how far the pitch falls by its end.
    struct Hoot {
        float start;
        float length;
        float fall;
    };
    constexpr Hoot hoots[] = {
        { 0.00f, 0.42f, 0.04f },
        { 1.30f, 0.16f, 0.02f },
        { 1.62f, 0.95f, 0.07f },
    };
    constexpr float owl_call_length = 2.6f;

    float owl_sample(float dt, float wanted) {
        if (owl.time < 0.0f) {
            owl.wait -= dt;
            if (owl.wait > 0.0f) {
                return 0.0f;
            }
            if (wanted <= 0.0f) {
                owl.wait = random_range(4.0f, 10.0f);
                return 0.0f;
            }
            owl.time = 0.0f;
            owl.pitch = random_range(360.0f, 440.0f);
            owl.pan = random_range(0.1f, 0.9f);
        }
        owl.time += dt;
        if (owl.time >= owl_call_length) {
            owl.time = -1.0f;
            owl.wait = random_range(18.0f, 45.0f);
            return 0.0f;
        }
        for (const Hoot& h : hoots) {
            const float x = (owl.time - h.start) / h.length;
            if (x < 0.0f || x >= 1.0f) {
                continue;
            }
            // Soft in, softer out, a slow wobble on the long note.
            const float envelope = std::min(1.0f, x / 0.12f) * std::pow(1.0f - x, 0.7f);
            const float wobble = 1.0f + 0.012f * std::sin(2.0f * pi * 5.5f * (owl.time - h.start));
            const float pitch = owl.pitch * (1.0f - h.fall * x) * wobble;
            owl.phase += pitch * dt;
            owl.phase -= std::floor(owl.phase);
            const float p = 2.0f * pi * (float)owl.phase;
            // A little breath in the tone: the second and third harmonics, quietly.
            return (std::sin(p) + 0.18f * std::sin(2.0f * p) + 0.06f * std::sin(3.0f * p)) * envelope;
        }
        return 0.0f;
    }

    void next_note(Bird& b) {
        b.note_length = random_range(0.04f, 0.14f);
        b.note_time = -random_range(0.03f, 0.09f);
        const float start = b.base * random_range(0.8f, 1.35f);
        const float shape = random01();
        if (shape < 0.4f) {
            // A sweep down.
            b.from = start * 1.25f;
            b.to = start * 0.75f;
            b.trill = 0.0f;
        }
        else if (shape < 0.75f) {
            // A sweep up.
            b.from = start * 0.8f;
            b.to = start * 1.3f;
            b.trill = 0.0f;
        }
        else {
            // A warble.
            b.from = start;
            b.to = start;
            b.trill = random_range(25.0f, 40.0f);
            b.note_length *= 1.6f;
        }
    }

    float bird_sample(Bird& b, float dt, float wanted) {
        if (b.notes_left == 0) {
            b.wait -= dt;
            if (b.wait > 0.0f) {
                return 0.0f;
            }
            if (wanted <= 0.0f) {
                b.wait = random_range(1.0f, 3.0f);
                return 0.0f;
            }
            b.notes_left = 3 + (int)(random01() * 6.0f);
            next_note(b);
        }
        b.note_time += dt;
        if (b.note_time < 0.0f) {
            return 0.0f;
        }
        const float x = b.note_time / b.note_length;
        if (x >= 1.0f) {
            b.notes_left--;
            if (b.notes_left == 0) {
                // Fewer, further apart, when only a few birds are about.
                b.wait = random_range(2.0f, 7.0f) / std::max(wanted, 0.3f);
            }
            else {
                next_note(b);
            }
            return 0.0f;
        }
        const float envelope = std::sin(pi * x);
        float pitch = b.from + (b.to - b.from) * x;
        if (b.trill > 0.0f) {
            pitch *= 1.0f + 0.12f * std::sin(2.0f * pi * b.trill * b.note_time);
        }
        b.phase += pitch * dt;
        b.phase -= std::floor(b.phase);
        return std::sin(2.0f * pi * (float)b.phase) * envelope * envelope;
    }
}

void tooie::night_sounds::thunder(float delay, float loudness) {
    thunder_delay.store(delay, std::memory_order_relaxed);
    thunder_loudness.store(loudness, std::memory_order_relaxed);
    thunder_count.fetch_add(1, std::memory_order_release);
}

void tooie::night_sounds::set(float crickets_amount, float owls_amount, float birds_amount, float rain_amount) {
    want_rain.store(rain_amount, std::memory_order_relaxed);
    want_crickets.store(crickets_amount, std::memory_order_relaxed);
    want_owls.store(owls_amount, std::memory_order_relaxed);
    want_birds.store(birds_amount, std::memory_order_relaxed);
}

void tooie::night_sounds::mix(float* stereo, size_t frames, uint32_t rate, float volume) {
    const float target_crickets = want_crickets.load(std::memory_order_relaxed);
    const float target_owls = want_owls.load(std::memory_order_relaxed);
    const float target_birds = want_birds.load(std::memory_order_relaxed);
    const float target_rain = want_rain.load(std::memory_order_relaxed);
    const uint32_t thunders = thunder_count.load(std::memory_order_acquire);
    if (thunders != thunder_state.seen) {
        thunder_state.seen = thunders;
        thunder_state.wait = thunder_delay.load(std::memory_order_relaxed);
        thunder_state.loudness = std::clamp(thunder_loudness.load(std::memory_order_relaxed), 0.2f, 1.0f);
    }
    if (gain_crickets <= 0.0f && gain_owls <= 0.0f && gain_birds <= 0.0f && gain_rain <= 0.0f && owl.time < 0.0f &&
        thunder_state.wait < 0.0f && thunder_state.time < 0.0f &&
        target_crickets <= 0.0f && target_owls <= 0.0f && target_birds <= 0.0f && target_rain <= 0.0f) {
        return;
    }
    if (!started) {
        start();
    }
    if (rate == 0 || volume <= 0.0f) {
        return;
    }

    const float dt = 1.0f / (float)rate;
    // About a second and a half to ease in or out.
    const float ease = std::min(1.0f, dt / 1.5f);
    // Loudness under the game's sound (which peaks at 0.5 here): quiet, so it stays in the background.
    constexpr float cricket_level = 0.010f;
    constexpr float owl_level = 0.030f;
    constexpr float bird_level = 0.014f;
    constexpr float rain_level = 0.045f;
    constexpr float thunder_level = 0.032f;

    for (size_t i = 0; i < frames; i++) {
        gain_crickets += (target_crickets - gain_crickets) * ease;
        gain_owls += (target_owls - gain_owls) * ease;
        gain_birds += (target_birds - gain_birds) * ease;
        gain_rain += (target_rain - gain_rain) * ease;

        float left = 0.0f;
        float right = 0.0f;
        for (Cricket& c : crickets) {
            const float s = cricket_sample(c, dt) * cricket_level * gain_crickets;
            left += s * (1.0f - c.pan);
            right += s * c.pan;
        }
        {
            const float s = owl_sample(dt, target_owls) * owl_level * gain_owls;
            left += s * (1.0f - owl.pan);
            right += s * owl.pan;
        }
        for (Bird& b : birds) {
            const float s = bird_sample(b, dt, target_birds) * bird_level * gain_birds;
            left += s * (1.0f - b.pan);
            right += s * b.pan;
        }
        if (gain_rain > 0.0001f) {
            float rl, rr;
            rain_sample(dt, rl, rr);
            left += rl * rain_level * gain_rain;
            right += rr * rain_level * gain_rain;
        }
        {
            const float s = thunder_sample(dt) * thunder_level;
            left += s;
            right += s;
        }
        stereo[2 * i + 0] += left * volume;
        stereo[2 * i + 1] += right * volume;
    }
}
