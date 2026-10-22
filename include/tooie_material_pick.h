#ifndef __TOOIE_MATERIAL_PICK_H__
#define __TOOIE_MATERIAL_PICK_H__

// Ray Tracing Material Pick Mode (src/debug/material_pick.cpp, driven by the pick worker in src/debug/parallax_pick.cpp): the
// Ray Tracing Material Pick Mode key frees the mouse as a crosshair and the texture under it is highlighted. A picked texture
// gets a production PBR material for Graphics > Ray tracing: an albedo (base colour tint), roughness (how wide the lobe its
// reflection rays are scattered over is: 0 a mirror, 100 brushed), metalness (0 a dielectric, 100 a metal that reflects in its
// albedo's colour with no diffuse of its own), emissive (light it gives off into the traced scene, in percent of its own
// colour) and subsurface (how much light a lamp or the sun behind it carries through, tinted by the albedo). The picks are kept in rt_material_tags.txt in the Dev Files folder and sent to RT64 (SetSceneRayMaterials).
#include <cstdint>
#include <functional>
#include <string>

namespace tooie::material_pick {
    struct Material {
        uint8_t red = 255, green = 255, blue = 255;
        // 0 to 100.
        uint8_t roughness = 50;
        uint8_t metalness = 0;
        // Percent of the surface's own colour added as light, 0 to 1000.
        uint16_t emissive = 0;
        // 0 to 100.
        uint8_t subsurface = 0;
        // A pick that switches the built-in material of a texture off (file word "none").
        bool none = false;
        bool operator==(const Material& o) const {
            return (red == o.red) && (green == o.green) && (blue == o.blue) && (roughness == o.roughness) && (metalness == o.metalness) && (emissive == o.emissive) && (subsurface == o.subsurface) && (none == o.none);
        }
        bool operator!=(const Material& o) const { return !(*this == o); }
    };

    // What the wheel changes (Shift + wheel, Ctrl for fine steps), chosen with right click or the number keys.
    enum Property : int {
        property_red = 0,
        property_green = 1,
        property_blue = 2,
        property_roughness = 3,
        property_metalness = 4,
        property_emissive = 5,
        property_subsurface = 6,
        property_count = 7
    };
    extern const char* const property_labels[property_count];

    // Presets for middle click to step through: Default, Mirror, Brushed metal, Gold, Plastic, Rubber, Glowing, Wax, Leaf.
    constexpr int preset_count = 9;
    const char* preset_name(int preset);
    Material preset_material(int preset, const Material& current);

    // Loads rt_material_tags.txt (once).
    void load();
    // Bumped each time a pick changes, so the list sent to RT64 is rebuilt.
    uint32_t version();
    // Each texture picked, with its material.
    void for_each(const std::function<void(uint64_t hash, const Material& material)>& visit);
    // The materials that ship with the port (sweeps of the 7,259-texture dump, src/debug/ray_material_defaults.inc). A pick
    // of the same texture replaces its built-in one; a "none" pick switches it off.
    bool builtin(uint64_t hash, Material& material);
    // A texture's material as the traced pass gets it: its pick, else its built-in one; false for none. own: it is a pick.
    bool effective(uint64_t hash, Material& material, bool& own);
    // Every texture with a material as the traced pass gets it (picks over the built-in ones, "none" picks left out).
    void for_each_effective(const std::function<void(uint64_t hash, const Material& material, bool own)>& visit);

    // A texture's material as it stands (false: none).
    bool get(uint64_t hash, Material& material);
    // Gives a texture a material, or takes it away (null).
    void set(uint64_t hash, const Material* material);
    // Steps a property up or down by notches (steps of 16 for a colour channel, 5% for roughness and metalness and 25% for
    // emissive, a fifth of that with fine; 5% for subsurface); starts from the default material on a texture with none. Returns the new text.
    std::string step_property(uint64_t hash, Property property, int notches, bool fine);

    // Writes the one texture (as it stands, or its removal) to the file; the Delete Saved Pick key's removal.
    void save_one(uint64_t hash);
    void delete_saved(uint64_t hash);
    size_t unsaved_count();
    size_t discard_changes();
    size_t save_all();

    // The label beside the cursor for a texture.
    std::string describe(uint64_t hash, uint32_t layer, uint32_t layers, Property chosen, bool show_all);
}

#endif
