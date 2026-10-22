// Ray Tracing Material Pick Mode's picks and their file (see include/tooie_material_pick.h).
#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <map>
#include <mutex>
#include <sstream>
#include <unordered_map>

#include "tooie_dev_files.h"
#include "tooie_material_pick.h"

namespace {
    using tooie::material_pick::Material;

    std::mutex materials_mutex;
    std::map<uint64_t, Material> materials;
    // As rt_material_tags.txt has them.
    std::map<uint64_t, Material> saved_materials;
    std::atomic<uint32_t> materials_version{ 1 };

    std::filesystem::path file_path() {
        return tooie::dev_files::path("rt_material_tags.txt");
    }

    // The line of a material: "albedo=RRGGBB roughness=N metalness=N emissive=N".
    std::string material_text(const Material& m) {
        if (m.none) {
            return "none";
        }
        char text[96];
        snprintf(text, sizeof(text), "albedo=%02X%02X%02X roughness=%d metalness=%d emissive=%d subsurface=%d", m.red, m.green, m.blue, int(m.roughness), int(m.metalness), int(m.emissive), int(m.subsurface));
        return text;
    }

    // Writes the file from saved_materials (materials_mutex held).
    void write_locked() {
        std::error_code ec;
        std::filesystem::create_directories(file_path().parent_path(), ec);
        std::ofstream out(file_path());
        out << "# Ray tracing materials (Ray Tracing Material Pick Mode key): texture, albedo (hex colour), roughness (0 to 100), metalness (0 to 100), emissive (percent), subsurface (0 to 100), or none (switches a built-in material off). Send this file in for the port's list.\n";
        for (const auto& [hash, material] : saved_materials) {
            char text[32];
            snprintf(text, sizeof(text), "%016llx", (unsigned long long)hash);
            out << text << " " << material_text(material) << "\n";
        }
    }

    const char* note_locked(uint64_t hash) {
        const auto live = materials.find(hash);
        const auto saved = saved_materials.find(hash);
        const bool has_live = live != materials.end();
        const bool has_saved = saved != saved_materials.end();
        if (has_live != has_saved) {
            return has_live ? ", not saved" : ", saved one removed";
        }
        return (has_live && (live->second != saved->second)) ? ", not saved" : "";
    }

    const Material presets[tooie::material_pick::preset_count] = {
        // Default: a plain dielectric, half rough.
        { 255, 255, 255, 50, 0, 0, 0 },
        // Mirror: fully metallic, no roughness.
        { 255, 255, 255, 0, 100, 0, 0 },
        // Brushed metal: a wide lobe.
        { 255, 255, 255, 40, 100, 0, 0 },
        // Gold.
        { 255, 200, 90, 20, 100, 0, 0 },
        // Plastic: a smooth dielectric, a faint reflection.
        { 255, 255, 255, 15, 0, 0, 0 },
        // Rubber: rough, almost no reflection.
        { 255, 255, 255, 95, 0, 0, 0 },
        // Glowing: a lamp of its own colour.
        { 255, 255, 255, 60, 0, 250, 0 },
        // Wax: soft, light carries through it.
        { 255, 235, 200, 35, 0, 0, 80 },
        // Leaf: sun behind it shows green through it.
        { 120, 220, 70, 70, 0, 0, 90 },
    };
    // The classes the sweep of the texture dump sorted textures into (see ray_material_defaults.inc), and the material each gets.
    enum MaterialClass : uint8_t { c_chrome, c_gold, c_copper, c_steel, c_rust, c_glass, c_gem, c_glaze, c_plastic, c_leaf, c_petal, c_wax, c_glow, c_plain };
    const Material class_materials[] = {
        // chrome: polished metal, a sharp reflection.
        { 255, 255, 255, 12, 100, 0, 0, false },
        // gold.
        { 255, 205, 100, 22, 100, 0, 0, false },
        // copper and bronze.
        { 235, 150, 105, 30, 100, 0, 0, false },
        // steel: satin grey metal, a soft reflection.
        { 255, 255, 255, 45, 85, 0, 0, false },
        // rust: worn, dull metal, a wide faint one.
        { 255, 255, 255, 78, 45, 0, 0, false },
        // glass.
        { 255, 255, 255, 4, 0, 0, 0, false },
        // gem: glossy, light through it, a faint glow.
        { 255, 255, 255, 8, 0, 15, 50, false },
        // glaze: ceramic, polished stone, glossy paint.
        { 255, 255, 255, 18, 0, 0, 0, false },
        // plastic.
        { 255, 255, 255, 30, 0, 0, 0, false },
        // leaf: rough, light through it.
        { 255, 255, 255, 75, 0, 0, 70, false },
        // petal and soft fruit.
        { 255, 255, 255, 60, 0, 0, 85, false },
        // wax, jelly and slime.
        { 255, 255, 255, 35, 0, 0, 80, false },
        // glow: lit lamps, glowing crystals and magic (no light source of its own: the Lamp and Light Source picks do that).
        { 255, 255, 255, 50, 0, 150, 0, false },
        // plain: the Default preset (a plain dielectric, half rough), as L picked it on 2026-10-22.
        { 255, 255, 255, 50, 0, 0, 0, false },
    };
    struct BuiltIn {
        uint64_t hash;
        MaterialClass material;
    };
    const BuiltIn built_ins[] = {
#include "ray_material_defaults.inc"
    };
    // L's rt_material_tags.txt of 2026-10-22, round two: each overwrites the built-in material of its texture (or adds
    // one); "none" (the material's none flag) switches it off.
    struct ShippedMaterial {
        uint64_t hash;
        Material material;
    };
    const ShippedMaterial shipped_materials[] = {
        { 0x3141c709d926acd4ull, { 255, 255, 255, 50, 0, 0, 0, false } },
        { 0x34edb75eecfadfe4ull, { 255, 255, 255, 50, 0, 0, 0, true } },
        { 0x45b2b9c646280f84ull, { 255, 255, 255, 40, 10, 0, 0, false } },
        { 0x63436e936af9acc0ull, { 255, 255, 255, 45, 0, 125, 0, false } },
        { 0xad0d1fa2daebc8fcull, { 255, 255, 255, 50, 0, 0, 0, false } },
    };
    const std::unordered_map<uint64_t, Material>& built_in_map() {
        static const std::unordered_map<uint64_t, Material> map = [] {
            std::unordered_map<uint64_t, Material> built;
            for (const BuiltIn& entry : built_ins) {
                built[entry.hash] = class_materials[entry.material];
            }
            for (const ShippedMaterial& shipped : shipped_materials) {
                built[shipped.hash] = shipped.material;
            }
            return built;
        }();
        return map;
    }
    const char* preset_names[tooie::material_pick::preset_count] = { "Default", "Mirror", "Brushed metal", "Gold", "Plastic", "Rubber", "Glowing", "Wax", "Leaf" };
}

const char* const tooie::material_pick::property_labels[tooie::material_pick::property_count] = { "Albedo red", "Albedo green", "Albedo blue", "Roughness", "Metalness", "Emissive", "Subsurface" };

const char* tooie::material_pick::preset_name(int preset) {
    return preset_names[std::clamp(preset, 0, preset_count - 1)];
}

tooie::material_pick::Material tooie::material_pick::preset_material(int preset, const Material& current) {
    (void)current;
    return presets[std::clamp(preset, 0, preset_count - 1)];
}

void tooie::material_pick::load() {
    static std::once_flag once;
    std::call_once(once, [] {
        std::ifstream in(tooie::dev_files::read_path("rt_material_tags.txt"));
        std::string line;
        std::lock_guard lock{ materials_mutex };
        while (std::getline(in, line)) {
            std::istringstream words(line);
            std::string hash_text, word;
            if (!(words >> hash_text) || (hash_text[0] == '#')) {
                continue;
            }
            Material material;
            while (words >> word) {
                const size_t equals = word.find('=');
                if (equals == std::string::npos) {
                    material.none = material.none || (word == "none");
                    continue;
                }
                const std::string name = word.substr(0, equals);
                const std::string value = word.substr(equals + 1);
                if (name == "albedo") {
                    const unsigned long rgb = std::strtoul(value.c_str(), nullptr, 16);
                    material.red = uint8_t((rgb >> 16) & 0xFF);
                    material.green = uint8_t((rgb >> 8) & 0xFF);
                    material.blue = uint8_t(rgb & 0xFF);
                } else if (name == "roughness") {
                    material.roughness = uint8_t(std::clamp(std::atoi(value.c_str()), 0, 100));
                } else if (name == "metalness") {
                    material.metalness = uint8_t(std::clamp(std::atoi(value.c_str()), 0, 100));
                } else if (name == "emissive") {
                    material.emissive = uint16_t(std::clamp(std::atoi(value.c_str()), 0, 1000));
                } else if (name == "subsurface") {
                    material.subsurface = uint8_t(std::clamp(std::atoi(value.c_str()), 0, 100));
                }
            }
            materials[std::strtoull(hash_text.c_str(), nullptr, 16)] = material;
        }
        if (!materials.empty()) {
            fprintf(stderr, "[material-pick] %zu materials from %s\n", materials.size(), file_path().string().c_str());
        }
        saved_materials = materials;
        materials_version.fetch_add(1);
    });
}

uint32_t tooie::material_pick::version() {
    return materials_version.load();
}

void tooie::material_pick::for_each(const std::function<void(uint64_t hash, const Material& material)>& visit) {
    std::lock_guard lock{ materials_mutex };
    for (const auto& [hash, material] : materials) {
        visit(hash, material);
    }
}

bool tooie::material_pick::builtin(uint64_t hash, Material& material) {
    const auto& map = built_in_map();
    const auto it = map.find(hash);
    if (it == map.end()) {
        return false;
    }
    material = it->second;
    return true;
}

bool tooie::material_pick::effective(uint64_t hash, Material& material, bool& own) {
    own = false;
    {
        std::lock_guard lock{ materials_mutex };
        const auto it = materials.find(hash);
        if (it != materials.end()) {
            own = true;
            material = it->second;
            return !material.none;
        }
    }
    return builtin(hash, material) && !material.none;
}

void tooie::material_pick::for_each_effective(const std::function<void(uint64_t hash, const Material& material, bool own)>& visit) {
    {
        std::lock_guard lock{ materials_mutex };
        for (const auto& [hash, material] : materials) {
            if (!material.none) {
                visit(hash, material, true);
            }
        }
        for (const auto& [hash, material] : built_in_map()) {
            if ((materials.find(hash) == materials.end()) && !material.none) {
                visit(hash, material, false);
            }
        }
    }
}

bool tooie::material_pick::get(uint64_t hash, Material& material) {
    std::lock_guard lock{ materials_mutex };
    const auto it = materials.find(hash);
    if (it == materials.end()) {
        return false;
    }
    material = it->second;
    return true;
}

void tooie::material_pick::set(uint64_t hash, const Material* material) {
    {
        std::lock_guard lock{ materials_mutex };
        if (material != nullptr) {
            materials[hash] = *material;
        } else {
            materials.erase(hash);
        }
    }
    materials_version.fetch_add(1);
}

std::string tooie::material_pick::step_property(uint64_t hash, Property property, int notches, bool fine) {
    Material material;
    bool own = false;
    if (!effective(hash, material, own)) {
        material = Material{};
    }
    const int step = (property <= property_blue) ? (fine ? 1 : 16) : ((property == property_emissive) ? (fine ? 5 : 25) : (fine ? 1 : 5));
    auto stepped = [&](int value, int low, int high) { return std::clamp(value + notches * step, low, high); };
    switch (property) {
    case property_red: material.red = uint8_t(stepped(material.red, 0, 255)); break;
    case property_green: material.green = uint8_t(stepped(material.green, 0, 255)); break;
    case property_blue: material.blue = uint8_t(stepped(material.blue, 0, 255)); break;
    case property_roughness: material.roughness = uint8_t(stepped(material.roughness, 0, 100)); break;
    case property_metalness: material.metalness = uint8_t(stepped(material.metalness, 0, 100)); break;
    case property_emissive: material.emissive = uint16_t(stepped(material.emissive, 0, 1000)); break;
    default: material.subsurface = uint8_t(stepped(material.subsurface, 0, 100)); break;
    }
    set(hash, &material);
    char text[96];
    switch (property) {
    case property_red: snprintf(text, sizeof(text), "Albedo red %d", int(material.red)); break;
    case property_green: snprintf(text, sizeof(text), "Albedo green %d", int(material.green)); break;
    case property_blue: snprintf(text, sizeof(text), "Albedo blue %d", int(material.blue)); break;
    case property_roughness: snprintf(text, sizeof(text), "Roughness %d%%", int(material.roughness)); break;
    case property_metalness: snprintf(text, sizeof(text), "Metalness %d%%", int(material.metalness)); break;
    case property_emissive: snprintf(text, sizeof(text), "Emissive %d%%", int(material.emissive)); break;
    default: snprintf(text, sizeof(text), "Subsurface %d%%", int(material.subsurface)); break;
    }
    return text;
}

void tooie::material_pick::save_one(uint64_t hash) {
    std::lock_guard lock{ materials_mutex };
    const auto live = materials.find(hash);
    if (live == materials.end()) {
        saved_materials.erase(hash);
    } else {
        saved_materials[hash] = live->second;
    }
    write_locked();
}

void tooie::material_pick::delete_saved(uint64_t hash) {
    {
        std::lock_guard lock{ materials_mutex };
        materials.erase(hash);
        saved_materials.erase(hash);
        write_locked();
    }
    materials_version.fetch_add(1);
}

size_t tooie::material_pick::unsaved_count() {
    std::lock_guard lock{ materials_mutex };
    size_t count = 0;
    for (const auto& [hash, material] : materials) {
        const auto saved = saved_materials.find(hash);
        count += ((saved == saved_materials.end()) || (saved->second != material)) ? 1 : 0;
    }
    for (const auto& [hash, material] : saved_materials) {
        count += (materials.find(hash) == materials.end()) ? 1 : 0;
    }
    return count;
}

size_t tooie::material_pick::discard_changes() {
    const size_t count = unsaved_count();
    {
        std::lock_guard lock{ materials_mutex };
        materials = saved_materials;
    }
    materials_version.fetch_add(1);
    return count;
}

size_t tooie::material_pick::save_all() {
    std::lock_guard lock{ materials_mutex };
    saved_materials = materials;
    write_locked();
    return saved_materials.size();
}

namespace {
    std::vector<uint64_t> effect_owned;
    std::vector<uint64_t> parallax_owned;
}

void tooie::material_pick::set_owners(std::vector<uint64_t> effect, std::vector<uint64_t> parallax) {
    std::sort(effect.begin(), effect.end());
    std::sort(parallax.begin(), parallax.end());
    std::lock_guard lock{ materials_mutex };
    effect_owned = std::move(effect);
    parallax_owned = std::move(parallax);
}

std::string tooie::material_pick::describe(uint64_t hash, uint32_t layer, uint32_t layers, Property chosen, bool show_all) {
    if (hash == 0) {
        return "No textured surface here";
    }
    Material material;
    bool own = false;
    const bool has = effective(hash, material, own);
    const char* note = "";
    bool switched_off = false;
    {
        std::lock_guard lock{ materials_mutex };
        note = note_locked(hash);
        const auto it = materials.find(hash);
        switched_off = (it != materials.end()) && it->second.none;
    }
    char text[700];
    if (has) {
        snprintf(text, sizeof(text), "%016llx\nRay tracing material (%s%s)\nAlbedo %02X%02X%02X, Roughness %d%%, Metalness %d%%, Emissive %d%%, Subsurface %d%%\n"
            "Shift + wheel: %s (Ctrl: fine). Right click or keys 1-7: change what the wheel does\nLeft click: switch it off, middle click or key 8: next preset, key 9: Show All %s",
            (unsigned long long)hash, own ? "yours" : "built-in", note, material.red, material.green, material.blue, int(material.roughness), int(material.metalness), int(material.emissive), int(material.subsurface),
            property_labels[chosen], show_all ? "on" : "off");
    } else {
        snprintf(text, sizeof(text), "%016llx\nNo ray tracing material%s%s\nLeft click: give it one, middle click: a preset, Shift + wheel: %s\nKeys 1-7 choose what the wheel does, key 9: Show All %s",
            (unsigned long long)hash, switched_off ? " (its built-in one is switched off)" : "", note, property_labels[chosen], show_all ? "on" : "off");
    }
    std::string result = text;
    {
        std::lock_guard lock{ materials_mutex };
        if (std::binary_search(effect_owned.begin(), effect_owned.end(), hash)) {
            result += "\nA shader effect owns this texture (ice, lamp, grass or glow): it gets no built-in material";
        }
        if (std::binary_search(parallax_owned.begin(), parallax_owned.end(), hash)) {
            result += "\nParallax is on this texture too: it stacks with the material";
        }
    }
    if (layers > 1) {
        result += "\nLayer " + std::to_string((layer % layers) + 1) + " of " + std::to_string(layers);
    }
    return result;
}
