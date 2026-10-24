#include <thread>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <unordered_map>
#include <vector>
#include <array>
#include <filesystem>
#include <numeric>
#include <stdexcept>
#include <cinttypes>

#include "nfd.h"

#include "ultramodern/ultra64.h"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/config.hpp"
// Android starts the game through SDLActivity, which calls SDL_main: SDL.h renames main() there.
#ifndef __ANDROID__
#define SDL_MAIN_HANDLED
#endif
#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#include "SDL2/SDL_syswm.h"
// Undefine x11 macros that get included by SDL_syswm.h.
#undef None
#undef Status
#undef LockMask
#undef ControlMask
#undef Success
#undef Always
#endif

#include "recompui/recompui.h"
#include "recompui/program_config.h"
#include "recompui/renderer.h"
#include "recompui/config.h"
#include "util/file.h"
#include "recompinput/input_events.h"
#include "recompinput/recompinput.h"
#include "recompinput/profiles.h"
#include "tooie_hand_cursor.h"
#include "tooie_asset_mods.h"
#include "tooie_boot_screen.h"
#include "tooie_frame_overlay.h"
#include "tooie_game.h"
#include "tooie_menu_pause.h"
#include "tooie_photo_mode.h"
#include "tooie_picture_filters.h"
#include "tooie_save_state.h"
#include "tooie_shader_progress.h"
#include "tooie_session_log.h"
#include "tooie_watchdog.h"
#include "tooie_api_restart.h"
#include "tooie_debug.h"
#include "tooie_day_night.h"
#ifdef __ANDROID__
#include "tooie_android.h"
#endif
#include "librecomp/game.hpp"
#include "librecomp/mods.hpp"
#include "librecomp/helpers.hpp"


#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <timeapi.h>
#include "SDL_syswm.h"
#define APP_ICON 1
#endif

#include "../../lib/rt64/src/contrib/stb/stb_image.h"

#ifdef TOOIE_VERSION
const std::string version_string = TOOIE_VERSION;
#else
const std::string version_string = "0.1.0";
#endif

template<typename... Ts>
void exit_error(const char* str, Ts ...args) {
    // TODO pop up an error
    ((void)fprintf(stderr, str, args), ...);
    assert(false);
        
    ultramodern::error_handling::quick_exit(__FILE__, __LINE__, __FUNCTION__);
}

ultramodern::gfx_callbacks_t::gfx_data_t create_gfx() {
    SDL_SetHint(SDL_HINT_WINDOWS_DPI_AWARENESS, "permonitorv2");
    SDL_SetHint(SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE, "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS5_RUMBLE, "1");
    SDL_SetHint(SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH, "1");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC) > 0) {
        exit_error("Failed to initialize SDL2: %s\n", SDL_GetError());
    }

    fprintf(stdout, "SDL Video Driver: %s\n", SDL_GetCurrentVideoDriver());

    return {};
}

ultramodern::input::connected_device_info_t get_connected_device_info(int controller_num) {
    if (recompinput::players::is_single_player_mode() || recompinput::players::get_player_is_assigned(controller_num)) {
        return ultramodern::input::connected_device_info_t{
            .connected_device = ultramodern::input::Device::Controller,
            .connected_pak = ultramodern::input::Pak::RumblePak,
        };
    }

    return ultramodern::input::connected_device_info_t{
        .connected_device = ultramodern::input::Device::None,
        .connected_pak = ultramodern::input::Pak::None,
    };
}

#include "icon_bytes.h"

namespace RT64 {
    // rt64-ext/src/render/rt64_raster_shader_cache_ext.h.
    void SetShippedShaderListPath(const std::filesystem::path &path);
}

namespace plume {
    // lib/rt64/src/contrib/plume/plume_vulkan.h (from lib-patches/plume.patch).
    void SetPipelineCachePath(const std::filesystem::path &path);
}

namespace RT64 {
    // lib/rt64/src/render/rt64_raster_shader_cache.h (from lib-patches/rt64.patch).
    void SetShaderListPath(const std::filesystem::path &path);
    // lib/rt64/src/hle/rt64_present_queue.cpp (from lib-patches/rt64.patch).
    void SetIdleRepaint(bool enabled);
}

#if defined(__gnu_linux__)
bool SetImageAsIcon(const char* filename, SDL_Window* window)
{
    // Read data
    int width, height, bytesPerPixel;
    void* data = stbi_load_from_memory(reinterpret_cast<const uint8_t*>(icon_bytes), sizeof(icon_bytes), &width, &height, &bytesPerPixel, 4);

    // Calculate pitch
    int pitch;
    pitch = width * 4;
    pitch = (pitch + 3) & ~3;

    // Setup relevance bitmask
    int Rmask, Gmask, Bmask, Amask;

#if SDL_BYTEORDER == SDL_LIL_ENDIAN
    Rmask = 0x000000FF;
    Gmask = 0x0000FF00;
    Bmask = 0x00FF0000;
    Amask = 0xFF000000;
#else
    Rmask = 0xFF000000;
    Gmask = 0x00FF0000;
    Bmask = 0x0000FF00;
    Amask = 0x000000FF;
#endif

    SDL_Surface* surface = nullptr;
    if (data != nullptr) {
        surface = SDL_CreateRGBSurfaceFrom(data, width, height, 32, pitch, Rmask, Gmask,
                            Bmask, Amask);
    }

    if (surface == nullptr) {   
        if (data != nullptr) {
            stbi_image_free(data);
        }
        return false;
	} else {
        SDL_SetWindowIcon(window,surface);
        SDL_FreeSurface(surface);
        stbi_image_free(data);
        return true;
    }
}
#endif

SDL_Window* window;

ultramodern::renderer::WindowHandle create_window(ultramodern::gfx_callbacks_t::gfx_data_t) {
    uint32_t flags = SDL_WINDOW_RESIZABLE;

#if defined(__APPLE__)
    flags |= SDL_WINDOW_METAL;
#elif defined(RT64_SDL_WINDOW_VULKAN)
    flags |= SDL_WINDOW_VULKAN;
#endif

    // TOOIE_WINDOW=<w>x<h>: start at another size (headless tests use a small one, as software rendering is slow).
    int window_w = 1600;
    int window_h = 900;
    if (const char* size = std::getenv("TOOIE_WINDOW")) {
        std::sscanf(size, "%dx%d", &window_w, &window_h);
    }
    window = SDL_CreateWindow(tooie::program_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_w, window_h, flags);

    if (window == nullptr) {
        exit_error("Failed to create window: %s\n", SDL_GetError());
    }

    tooie::boot_screen::set_window(window);

    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    SDL_GetWindowWMInfo(window, &wmInfo);

#if defined(_WIN32)
    // Load each icon at the size Windows draws it, so the title bar picks the small frame from app.ico.
    HICON small_icon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(APP_ICON), IMAGE_ICON,
        GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
    HICON big_icon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(APP_ICON), IMAGE_ICON,
        GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON), LR_DEFAULTCOLOR);
    if (small_icon != nullptr) {
        SendMessage(wmInfo.info.win.window, WM_SETICON, ICON_SMALL, (LPARAM)(small_icon));
    }
    if (big_icon != nullptr) {
        SendMessage(wmInfo.info.win.window, WM_SETICON, ICON_BIG, (LPARAM)(big_icon));
    }
#elif defined(__gnu_linux__)
    SetImageAsIcon("icons/app.png", window);
#endif

#if defined(_WIN32)
    return ultramodern::renderer::WindowHandle{ wmInfo.info.win.window, GetCurrentThreadId() };
#elif defined(__linux__) || defined(__ANDROID__)
    return ultramodern::renderer::WindowHandle{ window };
#elif defined(__APPLE__)
    SDL_MetalView view = SDL_Metal_CreateView(window);
    return ultramodern::renderer::WindowHandle{ wmInfo.info.cocoa.window,  SDL_Metal_GetLayer(view) };
#else
    static_assert(false && "Unimplemented");
#endif
}

void update_gfx(void*) {
    tooie::watchdog::note_window_update();
    recompinput::handle_events();
    // The cursor's picture (the hand, src/input/hand_cursor.cpp); the 3D hand steps through its frames here.
    tooie::hand_cursor::update();
    // The menus are drawn, and read their input, only when a frame is shown. While one is open, RT64 shows
    // the last frame again when the game sends none (a map change or a load), so the menu keeps responding.
    // Checked every 50 ms: it takes the UI's lock, which the UI holds while it draws.
    static auto next_menu_check = std::chrono::steady_clock::time_point{};
    const auto now = std::chrono::steady_clock::now();
    if (now >= next_menu_check) {
        next_menu_check = now + std::chrono::milliseconds(50);
        const bool menu_open = recompui::is_context_capturing_input();
        RT64::SetIdleRepaint(ultramodern::is_game_started() && menu_open);
        tooie::menu_pause::set_menu_open(menu_open);
    }
#ifdef __ANDROID__
    tooie::android::update_touch();
#endif
}

static SDL_AudioCVT audio_convert;
static SDL_AudioDeviceID audio_device = 0;

// Samples per channel per second.
static uint32_t sample_rate = 48000;
static uint32_t output_sample_rate = 48000;
// Channel count.
constexpr uint32_t input_channels = 2;
static uint32_t output_channels = 2;

// Terminology: a frame is a collection of samples for each channel. e.g. 2 input samples is one input frame. This is unrelated to graphical frames.

// Number of frames to duplicate for fixing interpolation at the start and end of a chunk.
constexpr uint32_t duplicated_input_frames = 4;
// The number of output frames to skip for playback (to avoid playing duplicate inputs twice).
static uint32_t discarded_output_frames;

constexpr uint32_t bytes_per_frame = input_channels * sizeof(float);

// Debug aid: TOOIE_AUDIO_LOG=1 prints, every 2 s, how much audio was queued when the game handed over
// each chunk, how many chunks were sped up to cut latency, and how often the queue had run dry.
static void audio_stats_note(uint64_t queued_us, uint32_t skip_factor) {
    tooie::frame_overlay::note_audio_chunk(queued_us, skip_factor != 0);
    static const bool enabled = std::getenv("TOOIE_AUDIO_LOG") != nullptr;
    if (!enabled) {
        return;
    }
    static uint64_t chunks = 0, skipped = 0, dry = 0, min_us = UINT64_MAX, max_us = 0;
    static auto last = std::chrono::steady_clock::now();
    static bool started = false;
    chunks++;
    if (skip_factor != 0) {
        skipped++;
    }
    if (started && queued_us == 0) {
        dry++;
    }
    started = true;
    min_us = std::min(min_us, queued_us);
    max_us = std::max(max_us, queued_us);
    auto now = std::chrono::steady_clock::now();
    if (now - last >= std::chrono::seconds(2)) {
        printf("[audio] %llu chunks, queued %.1f-%.1f ms, %llu sped up, %llu ran dry\n", (unsigned long long)chunks,
            min_us / 1000.0, max_us / 1000.0, (unsigned long long)skipped, (unsigned long long)dry);
        fflush(stdout);
        chunks = skipped = dry = max_us = 0;
        min_us = UINT64_MAX;
        last = now;
    }
}

void queue_samples(int16_t* audio_data, size_t sample_count) {
    // Buffer for holding the output of swapping the audio channels. This is reused across
    // calls to reduce runtime allocations.
    static std::vector<float> swap_buffer;
    static std::array<float, duplicated_input_frames * input_channels> duplicated_sample_buffer;

    // Make sure the swap buffer is large enough to hold the audio data, including any extra space needed for resampling.
    size_t resampled_sample_count = sample_count + duplicated_input_frames * input_channels;
    size_t max_sample_count = std::max(resampled_sample_count, resampled_sample_count * audio_convert.len_mult);
    if (max_sample_count > swap_buffer.size()) {
        swap_buffer.resize(max_sample_count);
    }
    
    // Copy the duplicated frames from last chunk into this chunk
    for (size_t i = 0; i < duplicated_input_frames * input_channels; i++) {
        swap_buffer[i] = duplicated_sample_buffer[i];
    }

    // Convert the audio from 16-bit values to floats and swap the audio channels into the
    // swap buffer to correct for the address xor caused by endianness handling.
    float cur_main_volume = static_cast<float>(recompui::config::sound::get_main_volume()) / 100.0f; // Get the current main volume, normalized to 0.0-1.0.
    // Muted while a cutscene skip fast-forwards, so it is not heard sped up (L).
    if (tooie::cutscene_skip_active()) {
        cur_main_volume = 0.0f;
    }
    // Muted while Freeze replays the same two frames (it would buzz).
    if (tooie::save_state::frozen()) {
        cur_main_volume = 0.0f;
    }
    for (size_t i = 0; i < sample_count; i += input_channels) {
        swap_buffer[i + 0 + duplicated_input_frames * input_channels] = audio_data[i + 1] * (0.5f / 32768.0f) * cur_main_volume;
        swap_buffer[i + 1 + duplicated_input_frames * input_channels] = audio_data[i + 0] * (0.5f / 32768.0f) * cur_main_volume;
    }
    
    // Crickets, owls and birds with the day and night cycle.
    tooie::night_sounds::mix(swap_buffer.data() + duplicated_input_frames * input_channels, sample_count / input_channels,
        sample_rate, cur_main_volume);
    // Photo mode's shutter click.
    tooie::photo_mode::mix_shutter(swap_buffer.data() + duplicated_input_frames * input_channels, sample_count / input_channels,
        sample_rate, cur_main_volume);

    // TODO handle cases where a chunk is smaller than the duplicated frame count.
    assert(sample_count > duplicated_input_frames * input_channels);

    // Copy the last converted samples into the duplicated sample buffer to reuse in resampling the next queued chunk.
    for (size_t i = 0; i < duplicated_input_frames * input_channels; i++) {
        duplicated_sample_buffer[i] = swap_buffer[i + sample_count];
    }
    
    audio_convert.buf = reinterpret_cast<Uint8*>(swap_buffer.data());
    audio_convert.len = (sample_count + duplicated_input_frames * input_channels) * sizeof(swap_buffer[0]);

    int ret = SDL_ConvertAudio(&audio_convert);

    if (ret < 0) {
        printf("Error using SDL audio converter: %s\n", SDL_GetError());
        throw std::runtime_error("Error using SDL audio converter");
    }

    // The SDL queue holds output frames (float, output_channels each) at the output rate, so time it with
    // those. It used to be divided by the game's rate (22050 Hz) and the input frame size, which counted
    // the queue about 2.2x too long: normal play then crossed the 100 ms limit below now and then and a
    // chunk was played at double speed, which was the short glitchy sound in some scenes.
    uint64_t queued_output_frames = uint64_t(SDL_GetQueuedAudioSize(audio_device)) / (output_channels * sizeof(float));
    uint64_t cur_queued_microseconds = queued_output_frames * 1000000 / output_sample_rate;
    uint32_t num_bytes_to_queue = audio_convert.len_cvt - output_channels * discarded_output_frames * sizeof(swap_buffer[0]);
    float* samples_to_queue = swap_buffer.data() + output_channels * discarded_output_frames / 2;

    // Prevent audio latency from building up by skipping samples in incoming audio when too many samples are already queued.
    // Skip samples based on how many microseconds of samples are queued already.
    uint32_t skip_factor = cur_queued_microseconds / 100000;
    if (skip_factor != 0) {
        uint32_t skip_ratio = 1 << skip_factor;
        num_bytes_to_queue /= skip_ratio;
        for (size_t i = 0; i < num_bytes_to_queue / (output_channels * sizeof(swap_buffer[0])); i++) {
            samples_to_queue[2 * i + 0] = samples_to_queue[2 * skip_ratio * i + 0];
            samples_to_queue[2 * i + 1] = samples_to_queue[2 * skip_ratio * i + 1];
        }
    }

    audio_stats_note(cur_queued_microseconds, skip_factor);

    // Debug aid: TOOIE_AUDIO_DUMP=<file> appends what is queued (float stereo at the output rate) to a raw
    // file, for comparing runs (pitch, tempo) headless.
    static FILE* audio_dump = [] {
        const char* path = std::getenv("TOOIE_AUDIO_DUMP");
        return path != nullptr ? std::fopen(path, "wb") : nullptr;
    }();
    if (audio_dump != nullptr) {
        std::fwrite(samples_to_queue, 1, num_bytes_to_queue, audio_dump);
    }

    // Queue the swapped audio data.
    // Offset the data start by only half the discarded frame count as the other half of the discarded frames are at the end of the buffer.
    SDL_QueueAudio(audio_device, samples_to_queue, num_bytes_to_queue);
}

size_t get_frames_remaining() {
    constexpr float buffer_offset_frames = 1.0f;
    // Get the number of remaining buffered audio bytes.
    uint64_t buffered_byte_count = SDL_GetQueuedAudioSize(audio_device);

    // Scale the byte count based on the ratio of sample rates and channel counts.
    buffered_byte_count = buffered_byte_count * 2 * sample_rate / output_sample_rate / output_channels;

    // Adjust the reported count to be some number of refreshes in the future, which helps ensure that
    // there are enough samples even if the audio thread experiences a small amount of lag. This prevents
    // audio popping on games that use the buffered audio byte count to determine how many samples
    // to generate.
    uint32_t frames_per_vi = (sample_rate / 60);
    if (buffered_byte_count > (buffer_offset_frames * bytes_per_frame * frames_per_vi)) {
        buffered_byte_count -= (buffer_offset_frames * bytes_per_frame * frames_per_vi);
    }
    else {
        buffered_byte_count = 0;
    }
    // Convert from byte count to sample count.
    return static_cast<uint32_t>(buffered_byte_count / bytes_per_frame);
}

void update_audio_converter() {
    int ret = SDL_BuildAudioCVT(&audio_convert, AUDIO_F32, input_channels, sample_rate, AUDIO_F32, output_channels, output_sample_rate);

    if (ret < 0) {
        printf("Error creating SDL audio converter: %s\n", SDL_GetError());
        throw std::runtime_error("Error creating SDL audio converter");
    }

    // Calculate the number of samples to discard based on the sample rate ratio and the duplicate frame count.
    discarded_output_frames = duplicated_input_frames * output_sample_rate / sample_rate;
}

void set_frequency(uint32_t freq) {
    sample_rate = freq;
    
    update_audio_converter();
}

bool reset_audio(uint32_t output_freq) {
    SDL_AudioSpec spec_desired{
        .freq = (int)output_freq,
        .format = AUDIO_F32,
        .channels = (Uint8)output_channels,
        .silence = 0, // calculated
        .samples = 0x100, // Fairly small sample count to reduce the latency of internal buffering
        .padding = 0, // unused
        .size = 0, // calculated
        .callback = nullptr,
        .userdata = nullptr
    };

    audio_device = SDL_OpenAudioDevice(nullptr, false, &spec_desired, nullptr, 0);
    if (audio_device == 0) {
        std::string audio_error = std::string("No audio device could be found. Please make sure an audio device is available.\nError opening audio device: ") + std::string(SDL_GetError());
        recompui::message_box(audio_error.c_str());
        return false;
    }

    SDL_PauseAudioDevice(audio_device, 0);

    output_sample_rate = output_freq;
    update_audio_converter();

    return true;
}

extern RspUcodeFunc n_aspMain;

RspUcodeFunc* get_rsp_microcode(const OSTask* task) {
    switch (task->t.type) {
    case M_AUDTASK:
        return n_aspMain;

    default:
        fprintf(stderr, "Unknown task: %" PRIu32 "\n", task->t.type);
        return nullptr;
    }
}

extern "C" void recomp_entrypoint(uint8_t * rdram, recomp_context * ctx);
gpr get_entrypoint_address();

// array of supported GameEntry objects
std::vector<recomp::GameEntry> supported_games = {
    {
        .rom_hash = 0x00F70DE5F2D70EA2ULL,
        .internal_name = "BANJO TOOIE",
        .display_name = "Banjo-Tooie",
        .game_id = u8"bt.n64.us.1.0",
        .mod_game_id = "bt",
        .save_type = recomp::SaveType::Eep16k,
        .thumbnail_bytes = std::span<const char>(icon_bytes),
        .is_enabled = true,
        .entrypoint_address = get_entrypoint_address(),
        .entrypoint = recomp_entrypoint,
        .on_init_callback = tooie::on_game_init,
    },
};

#ifdef _WIN32

struct PreloadContext {
    HANDLE handle;
    HANDLE mapping_handle;
    SIZE_T size;
    PVOID view;
};

bool preload_executable(PreloadContext& context) {
    wchar_t module_name[MAX_PATH];
    GetModuleFileNameW(NULL, module_name, MAX_PATH);

    context.handle = CreateFileW(module_name, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (context.handle == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Failed to load executable into memory!");
        context = {};
        return false;
    }

    LARGE_INTEGER module_size;
    if (!GetFileSizeEx(context.handle, &module_size)) {
        fprintf(stderr, "Failed to get size of executable!");
        CloseHandle(context.handle);
        context = {};
        return false;
    }

    context.size = module_size.QuadPart;

    context.mapping_handle = CreateFileMappingW(context.handle, nullptr, PAGE_READONLY, 0, 0, nullptr);
    if (context.mapping_handle == nullptr) {
        fprintf(stderr, "Failed to create file mapping of executable!");
        CloseHandle(context.handle);
        context = {};
        return EXIT_FAILURE;
    }

    context.view = MapViewOfFile(context.mapping_handle, FILE_MAP_READ, 0, 0, 0);
    if (context.view == nullptr) {
        fprintf(stderr, "Failed to map view of of executable!");
        CloseHandle(context.mapping_handle);
        CloseHandle(context.handle);
        context = {};
        return false;
    }

    DWORD pid = GetCurrentProcessId();
    HANDLE process_handle = OpenProcess(PROCESS_SET_QUOTA | PROCESS_QUERY_INFORMATION, FALSE, pid);
    if (process_handle == nullptr) {
        fprintf(stderr, "Failed to open own process!");
        CloseHandle(context.mapping_handle);
        CloseHandle(context.handle);
        context = {};
        return false;
    }

    SIZE_T minimum_set_size, maximum_set_size;
    if (!GetProcessWorkingSetSize(process_handle, &minimum_set_size, &maximum_set_size)) {
        fprintf(stderr, "Failed to get working set size!");
        CloseHandle(context.mapping_handle);
        CloseHandle(context.handle);
        context = {};
        return false;
    }

    if (!SetProcessWorkingSetSize(process_handle, minimum_set_size + context.size, maximum_set_size + context.size)) {
        fprintf(stderr, "Failed to set working set size!");
        CloseHandle(context.mapping_handle);
        CloseHandle(context.handle);
        context = {};
        return false;
    }

    if (VirtualLock(context.view, context.size) == 0) {
        fprintf(stderr, "Failed to lock view of executable! (Error: %08lx)\n", GetLastError());
        CloseHandle(context.mapping_handle);
        CloseHandle(context.handle);
        context = {};
        return false;
    }
    
    return true;
}

void release_preload(PreloadContext& context) {
    VirtualUnlock(context.view, context.size);
    CloseHandle(context.mapping_handle);
    CloseHandle(context.handle);
    context = {};
}

#elif defined(__linux__) || defined(APPLE)

struct PreloadContext {

};

bool preload_executable(PreloadContext& context) {
    // Preloading isn't implemented on Linux and MacOS, but it's also unnecessary there, as the OS already preloads the executable.
    // Therefore, we can just consider the executable to be preloaded.
    return true;
}

void release_preload(PreloadContext& context) {
}

#else

struct PreloadContext {};

bool preload_executable(PreloadContext& context) {
    return false;
}

void release_preload(PreloadContext& context) {
}

#endif

void enable_texture_pack(recomp::mods::ModContext& context, const recomp::mods::ModHandle& mod) {
    recompui::renderer::enable_texture_pack(context, mod);
}

void disable_texture_pack(recomp::mods::ModContext&, const recomp::mods::ModHandle& mod) {
    recompui::renderer::disable_texture_pack(mod);
}

void reorder_texture_pack(recomp::mods::ModContext&) {
    recompui::renderer::trigger_texture_pack_update();
}

void enable_asset_mod(recomp::mods::ModContext& context, const recomp::mods::ModHandle& mod) {
    tooie::asset_mods::enable_mod(mod.manifest.mod_id, mod.manifest.mod_root_path, context.get_mod_order_index(mod.manifest.mod_id));
}

void disable_asset_mod(recomp::mods::ModContext&, const recomp::mods::ModHandle& mod) {
    tooie::asset_mods::disable_mod(mod.manifest.mod_id);
}

void reorder_asset_mods(recomp::mods::ModContext& context) {
    tooie::asset_mods::reorder([&](const std::string& mod_id) { return context.get_mod_order_index(mod_id); });
}

// Set by `--game bt`: start the game straight away when the ROM is installed,
// skipping the launcher.
bool autostart_game = false;

void on_launcher_init(recompui::LauncherMenu *menu) {
    auto game_options_menu = menu->init_game_options_menu(
        supported_games[0].game_id,
        supported_games[0].mod_game_id,
        supported_games[0].display_name,
        supported_games[0].thumbnail_bytes,
        recompui::GameOptionsMenuLayout::Center
    );

    // The launcher's options, with the start option named Play. Left and right on it pick the effects
    // preset (Graphics > Effects preset), applied when Play is pressed (L, 2026-10-16).
    recompui::GameOption* play = game_options_menu->add_start_game_or_load_rom_option("Load ROM", "Play");
    game_options_menu->add_setup_controls_option();
    game_options_menu->add_settings_option();
    game_options_menu->add_mods_option();
    game_options_menu->add_exit_option();

    using tooie::picture_filters::Preset;
    static const Preset presets[] = { Preset::Original, Preset::Enhanced, Preset::Retro, Preset::Custom };
    static const std::vector<std::string> preset_names = { "Vanilla", "Enhanced", "Retro", "Custom" };
    size_t current = 3;
    for (size_t i = 0; i < std::size(presets); i++) {
        if (presets[i] == tooie::picture_filters::preset()) {
            current = i;
        }
    }
    play->set_choices(preset_names, current, nullptr);
    game_options_menu->set_before_start_callback([play]() {
        // Custom keeps the effects as they are set.
        tooie::picture_filters::set_preset(presets[play->get_choice()]);
    });

    if (autostart_game && recomp::is_rom_valid(supported_games[0].game_id)) {
        // Start a moment later, as the launcher's own option does: the VI
        // thread only sets up a video mode while no game is running, and it
        // has not run yet when the launcher is first built.
        std::thread([]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            recompui::update_game_mod_id(supported_games[0].mod_game_id);
            recomp::start_game(supported_games[0].game_id, {});
            recompui::hide_all_contexts();
        }).detach();
    }
}

int main(int argc, char** argv) {
#ifdef __ANDROID__
    tooie::android::setup_paths();
#endif
    tooie::api_restart::remember_launch_dir();
    for (int i = 1; i + 1 < argc; i++) {
        if (strcmp(argv[i], "--game") == 0 && strcmp(argv[i + 1], "bt") == 0) {
            autostart_game = true;
        }
        else if (strcmp(argv[i], "--pad-script") == 0) {
            if (!tooie::debug::parse_pad_script(argv[i + 1])) {
                return EXIT_FAILURE;
            }
        }
        else if (strcmp(argv[i], "--dialogue_text_speed") == 0) {
            if (!tooie::parse_text_speed_arg(argv[i + 1])) {
                fprintf(stderr, "--dialogue_text_speed takes 1, 2, 4 or instant\n");
                return EXIT_FAILURE;
            }
        }
    }
    recomp::Version project_version{};
    if (!recomp::Version::from_string(version_string, project_version)) {
        ultramodern::error_handling::message_box(("Invalid version string: " + version_string).c_str());
        return EXIT_FAILURE;
    }

    // Map this executable into memory and lock it, which should keep it in physical memory. This ensures
    // that there are no stutters from the OS having to load new pages of the executable whenever a new code page is run.
    PreloadContext preload_context;
    bool preloaded = preload_executable(preload_context);

    if (!preloaded) {
        fprintf(stderr, "Failed to preload executable!\n");
    }

#ifdef _WIN32
    // Set up high resolution timing period.
    timeBeginPeriod(1);

    // Process arguments.
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--show-console") == 0)
        {
            if (GetConsoleWindow() == nullptr)
            {
                AllocConsole();
                freopen("CONIN$", "r", stdin);
                freopen("CONOUT$", "w", stderr);
                freopen("CONOUT$", "w", stdout);
            }

            break;
        }
    }

    // Set up console output to accept UTF-8 on windows
    SetConsoleOutputCP(CP_UTF8);

    // Change to a font that supports Japanese characters
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 16;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"NSimSun");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
#endif

#ifdef _WIN32
    // Force wasapi on Windows, as there seems to be some issue with sample queueing with directsound currently.
    SDL_setenv("SDL_AUDIODRIVER", "wasapi", true);
#endif

#if defined(__linux__) && defined(RECOMP_FLATPAK)
    // When using Flatpak, applications tend to launch from the home directory by default.
    // Mods might use the current working directory to store the data, so we switch it to a directory
    // with persistent data storage and write permissions under Flatpak to ensure it works.
    std::error_code ec;
    std::filesystem::current_path("/var/data", ec);
#endif

    // Initialize native file dialogs.
    NFD_Init();

    // Initialize program settings.
    recompui::programconfig::set_program_name(tooie::program_name);
    recompui::programconfig::set_program_id(tooie::program_id);
    
    // Initialize SDL audio and set the output frequency.
    SDL_InitSubSystem(SDL_INIT_AUDIO);
    if (!reset_audio(48000)) {
        // It is not possible to initialize without an audio device.
        return EXIT_FAILURE;
    }

    // Source controller mappings file
    std::u8string controller_db_path = (recompui::file::get_program_path() / "recompcontrollerdb.txt").u8string();
    if (SDL_GameControllerAddMappingsFromFile(reinterpret_cast<const char *>(controller_db_path.c_str())) < 0) {
        fprintf(stderr, "Failed to load controller mappings: %s\n", SDL_GetError());
    }

    // Register fonts.
    recompui::register_primary_font("InterVariable.ttf", "Inter Variable");
    // Lettering of the settings sidebar layout (Apache 2.0, assets/LuckiestGuy-LICENSE.txt).
    recompui::register_extra_font("LuckiestGuy-Regular.ttf");

    // Register configuration path.
    const std::filesystem::path app_folder = tooie::resolve_app_folder();
    recomp::register_config_path(app_folder);
    tooie::install_crash_handler(app_folder);
    // RT64 keeps the shaders met in earlier sessions here and compiles them again in the
    // background at start (roadmap 4.32), so a first visit to an area stutters less. On Windows the
    // compiled shaders are also kept, in cache/shaders, so that compile is quick after the first time.
    RT64::SetShaderListPath(app_folder / "cache" / "shader_list.bin");
    // Vulkan also keeps the driver's compiled pipelines here (plume.patch), so the list is quick after the first start.
    plume::SetPipelineCachePath(app_folder / "cache" / "vulkan_pipelines.bin");
    tooie::shader_progress::start();
#ifdef _WIN32
    // The Windows build has no console, so keep what the game and the runtime
    // print (errors before an abort, among others) in logs/console.log.
    if (GetConsoleWindow() == nullptr) {
        std::filesystem::path console_log = app_folder / "logs" / "console.log";
        std::error_code ec;
        std::filesystem::resize_file(console_log, 0, ec); // start empty; both streams append
        if (_wfreopen(console_log.c_str(), L"a", stderr) != nullptr) {
            setvbuf(stderr, nullptr, _IONBF, 0);
        }
        _wfreopen(console_log.c_str(), L"a", stdout);
        setvbuf(stdout, nullptr, _IONBF, 0);
    }
#endif

    // Register supported games and patches
    for (const auto& game : supported_games) {
        recomp::register_game(game);
    }
#ifdef __ANDROID__
    if (!tooie::android::install_picked_rom(supported_games[0].game_id)) {
        return EXIT_FAILURE;
    }
    // There is no launcher choice to make on a phone: go straight into the game once the ROM is in.
    autostart_game = true;
#endif

    recompui::register_ui_exports();

    tooie::register_overlays();

    recompinput::players::set_single_player_mode(true);

    tooie::init_config();
    // Compile all shaders at start (General tab, on by default): the shipped list of every shader the game asks
    // for is queued beside the player's own list. Read here because the renderer reads the lists when it starts.
    try {
        if (std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::precompile_shaders_option))) {
            RT64::SetShippedShaderListPath(recompui::file::get_asset_path("shader_list_full.bin"));
        }
    } catch (...) {
        RT64::SetShippedShaderListPath(recompui::file::get_asset_path("shader_list_full.bin"));
    }
    tooie::session_log::start(version_string);
    // Zips dropped into the mods folder are unpacked before every mod scan (startup and Refresh Mods).
    // The first scan is the one at startup, before the renderer takes the window. The renderer starts right
    // after it and builds its shader pipelines before it shows anything, which can take a while, so the window
    // says so instead of staying black. The text stays on the window until the renderer's first frame replaces it.
    recomp::mods::set_before_scan_callback([](bool game_started) {
        static bool at_boot = true;
        tooie::unpack_mod_zips(game_started, at_boot);
        if (at_boot) {
            tooie::boot_screen::show("Compiling Shaders", "");
            tooie::boot_screen::close();
        }
        at_boot = false;
    });

    tooie::start_save_backups();

    recompui::register_launcher_init_callback(on_launcher_init);

    recomp::rsp::callbacks_t rsp_callbacks{
        .get_rsp_microcode = get_rsp_microcode,
    };

    ultramodern::renderer::callbacks_t renderer_callbacks{
        .create_render_context = [](uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
            auto presentation_mode = ultramodern::renderer::PresentationMode::PresentEarly;
            return tooie::watchdog::wrap(recompui::renderer::create_render_context(rdram, window_handle, presentation_mode, developer_mode));
        },
    };

    ultramodern::gfx_callbacks_t gfx_callbacks{
        .create_gfx = create_gfx,
        .create_window = create_window,
        .update_gfx = update_gfx,
    };

    ultramodern::audio_callbacks_t audio_callbacks{
        .queue_samples = queue_samples,
        .get_frames_remaining = get_frames_remaining,
        .set_frequency = set_frequency,
    };

    ultramodern::input::callbacks_t input_callbacks{
        .poll_input = [] {
            tooie::watchdog::note_game_input();
            recompinput::poll_inputs();
        },
        .get_input = tooie::debug::get_n64_input,
        .set_rumble = recompinput::set_rumble,
        .get_connected_device_info = get_connected_device_info,
    };

    ultramodern::events::callbacks_t thread_callbacks{
        .vi_callback = recompinput::update_rumble,
        .gfx_init_callback = nullptr,
    };

    ultramodern::error_handling::callbacks_t error_handling_callbacks{
        .message_box = recompui::message_box,
    };

    ultramodern::threads::callbacks_t threads_callbacks{
        .get_game_thread_name = nullptr,
    };

    // Register the texture pack content type with rt64.json as its content file.
    recomp::mods::ModContentType texture_pack_content_type{
        .content_filename = "rt64.json",
        .allow_runtime_toggle = true,
        .on_enabled = enable_texture_pack,
        .on_disabled = disable_texture_pack,
        .on_reordered = reorder_texture_pack,
    };
    auto texture_pack_content_type_id = recomp::mods::register_mod_content_type(texture_pack_content_type);

    // Register the .rtz texture pack file format with the previous content type as its only allowed content type.
    recomp::mods::register_mod_container_type("rtz", std::vector{ texture_pack_content_type_id }, false);

    // Asset mods (models and other assets by id, src/game/asset_mods.cpp): a mod folder with an
    // assets.json and an assets/ folder. One mod can be both this and a texture pack.
    recomp::mods::ModContentType asset_mod_content_type{
        .content_filename = "assets.json",
        .allow_runtime_toggle = true,
        .on_enabled = enable_asset_mod,
        .on_disabled = disable_asset_mod,
        .on_reordered = reorder_asset_mods,
    };
    recomp::mods::register_mod_content_type(asset_mod_content_type);

    recomp::start(
        project_version,
        {},
        rsp_callbacks,
        renderer_callbacks,
        audio_callbacks,
        input_callbacks,
        gfx_callbacks,
        thread_callbacks,
        error_handling_callbacks,
        threads_callbacks
    );

    NFD_Quit();

    if (preloaded) {
        release_preload(preload_context);
    }

#ifdef _WIN32
    // End high resolution timing period.
    timeEndPeriod(1);
#endif

    tooie::api_restart::relaunch_if_requested(argc, argv);

    return EXIT_SUCCESS;
}
