//
// RT64
//

// Banjo-Tooie: 3D grass blades (rt64_grass_blades.h). A ground draw's blades are drawn straight after it as one
// instanced draw with its own material, so the pixel shader (RasterPS.hlsl, RASTER_GRASS_BLADES) colours each blade
// with the ground's own texture, vertex colours and fog at its root. No vertex buffers: SV_InstanceID is the blade
// among the slot's tiles drawn this frame, SV_VertexID the corner of the blade.
//
// RasterParams.grassShell is the ground draw's slot plus one; with RASTER_GRASS_MID the slot's mid-distance tiles are
// drawn, one triangle a blade, instead of its near tiles.

#include "shared/rt64_blender.h"
#include "shared/rt64_color_combiner.h"
#include "shared/rt64_raster_params.h"
#include "shared/rt64_grass_blades.h"

#include "FbRendererCommon.hlsli"
#include "TextureSampler.hlsli"

[[vk::push_constant]] ConstantBuffer<RasterParams> gConstants : register(b0, space0);

StructuredBuffer<GrassBlade> grassBlades : register(t72, space0);
StructuredBuffer<GrassSlot> grassSlots : register(t73, space0);
StructuredBuffer<GrassTileDraw> grassTiles : register(t74, space0);
// The frame's index buffer and its vertices' texture coordinates and colours, as the ground's own draw reads them
// (after the RSP's work: tile scale, lighting and fog are in them).
StructuredBuffer<uint> grassIndices : register(t75, space0);
StructuredBuffer<float2> grassTexcoords : register(t76, space0);
StructuredBuffer<float4> grassColors : register(t77, space0);
// The trodden ground's map (rt64_grass_blades.h's GRASS_PRESS_*), two words a cell.
StructuredBuffer<uint> grassPress : register(t78, space0);

// The widest blade in world units (GrassBlade's width is a share of it).
static const float GrassMaxWidth = 13.0f;
// A blade grows in over the last part of its share: those ranked from 1 to 1 + GrassGrow times the share kept.
static const float GrassGrow = 0.8f;
// How far the wind and Banjo push a blade's tip over, as a share of its height.
static const float GrassMaxBend = 0.55f;

// A direction (no translation) to clip space: GrassToClip(p + v) is GrassToClip(p) + GrassDirToClip(v).
float4 GrassDirToClip(float3 v) {
    const float4 w = float4(v, 0.0f);
    return float4(dot(FrParams.grassWorldToClip[0], w), dot(FrParams.grassWorldToClip[1], w), dot(FrParams.grassWorldToClip[2], w), dot(FrParams.grassWorldToClip[3], w));
}

float4 GrassToClip(float3 world) {
    const float4 w = float4(world, 1.0f);
    return float4(dot(FrParams.grassWorldToClip[0], w), dot(FrParams.grassWorldToClip[1], w), dot(FrParams.grassWorldToClip[2], w), dot(FrParams.grassWorldToClip[3], w));
}

// The wind: two slow waves rolling across the world at different angles, as the game's own plants sway.
// Grass Patches: a smooth noise over the ground (two sizes of blotch, about 420 and 160 units across), 0 to 1.
float GrassPatchHash(float2 p) {
    return frac(sin(dot(p, float2(127.1f, 311.7f))) * 43758.5453f);
}

float GrassPatchNoise(float2 p) {
    const float2 i = floor(p);
    float2 f = frac(p);
    f = f * f * (3.0f - 2.0f * f);
    const float a = GrassPatchHash(i), b = GrassPatchHash(i + float2(1.0f, 0.0f));
    const float c = GrassPatchHash(i + float2(0.0f, 1.0f)), d = GrassPatchHash(i + float2(1.0f, 1.0f));
    return lerp(lerp(a, b, f.x), lerp(c, d, f.x), f.y);
}

// sway scales the moving part (1 full, 0 the wind's steady lean only).
float2 GrassWind(float2 xz, float sway) {
    const float time = FrParams.grassParams.y;
    const float a = sin(dot(xz, float2(0.0061f, 0.0023f)) - time * 1.1f);
    const float b = sin(dot(xz, float2(-0.0019f, 0.0047f)) - time * 0.7f + 1.7f);
    return float2(0.8f, 0.45f) * ((a * 0.6f + b * 0.4f) * sway + 0.35f) * FrParams.grassParams.x;
}

// The ground's colour at a blade's root as its own draw would show it there: its texture (the finest level), colour
// combiner and blender (its fog), with the root-to-tip shading (shade) on the combined colour before the fog.
// The flowers' colours, the game's bright ones (Rare's yellow, white, pink, red, blue and violet flowers): a flower's
// head is this colour lit by the ground's shading under it.
static const float3 GrassFlowerColors[6] = {
    float3(1.0f, 0.86f, 0.18f), float3(0.97f, 0.96f, 0.88f), float3(1.0f, 0.52f, 0.72f),
    float3(0.92f, 0.22f, 0.18f), float3(0.45f, 0.62f, 1.0f), float3(0.68f, 0.42f, 0.95f)
};

// A clover's kind (after the six flower colours; rt64_grass.cpp's CloverKind).
static const uint GrassCloverKind = 7;

// The kinds of blade the levels' plants are made of (GrassFormOf).
static const uint GrassLeafGrass = 0;
static const uint GrassLeafKelp = 1;
static const uint GrassLeafEel = 2;
static const uint GrassLeafFern = 3;
static const uint GrassLeafBroad = 4;
static const uint GrassLeafStraw = 5;
static const uint GrassLeafLawn = 6;
static const uint GrassLeafFrost = 7;
static const uint GrassLeafDune = 8;
static const uint GrassLeafLettuce = 9;
static const uint GrassLeafWrack = 10;
// Each level's two grasses of its own (GrassFormOf): the meadows' timothy and sedge, Terrydactyland's horsetails and
// tussocks, Mayahem Temple's palm fronds and cattail reeds, Glitter Gulch Mine's yucca spikes and tumbleweed tufts,
// Witchyworld's pennant grass and topiary tufts, Hailfire Peaks' ice shards and frozen tufts, its charred stalks and
// ash grass, Grunty Industries' dock leaves and wire grass, Jolly Roger's sea oats and succulents, and Cloud
// Cuckooland's candy grass and cloud tufts.
static const uint GrassLeafSeed = 11;
static const uint GrassLeafSedge = 12;
static const uint GrassLeafHorsetail = 13;
static const uint GrassLeafTussock = 14;
static const uint GrassLeafPalm = 15;
static const uint GrassLeafReed = 16;
static const uint GrassLeafYucca = 17;
static const uint GrassLeafTumble = 18;
static const uint GrassLeafPennant = 19;
static const uint GrassLeafTopiary = 20;
static const uint GrassLeafIce = 21;
static const uint GrassLeafFrozen = 22;
static const uint GrassLeafCharred = 23;
static const uint GrassLeafAsh = 24;
static const uint GrassLeafDock = 25;
static const uint GrassLeafWire = 26;
static const uint GrassLeafOats = 27;
static const uint GrassLeafSucculent = 28;
static const uint GrassLeafCandy = 29;
static const uint GrassLeafCloud = 30;
// Each level's third grass: the meadows' blue fescue, Terrydactyland's club moss, Mayahem Temple's bamboo, Glitter Gulch
// Mine's sagebrush, Witchyworld's neon grass, the icy side's cotton grass, the lava side's obsidian spikes, Grunty
// Industries' toxic weeds, Jolly Roger's sea rushes, Cloud Cuckooland's rainbow grass, and the seabed's red weed.
static const uint GrassLeafFescue = 31;
static const uint GrassLeafClubMoss = 32;
static const uint GrassLeafBamboo = 33;
static const uint GrassLeafSage = 34;
static const uint GrassLeafNeon = 35;
static const uint GrassLeafCotton = 36;
static const uint GrassLeafObsidian = 37;
static const uint GrassLeafToxic = 38;
static const uint GrassLeafRush = 39;
static const uint GrassLeafRainbow = 40;
static const uint GrassLeafRedWeed = 41;

// A blade's form, by the level's plants: its kind, and times its width and height, how pointed it is (its width half
// way up as a share of its root's), times its own lean and the wind's push, the most its tip bends over, how far its
// tip hangs down again (arching fronds and leaves), times the ridge down its middle, how straight it is (0 a curve as
// grass bends, 1 straight), how much of the level's tint it takes and its own colour on top.
struct GrassForm {
    uint leaf;
    float width;
    float height;
    float mid;
    float lean;
    float stiff;
    float maxBend;
    float droop;
    float ridge;
    float straight;
    float tint;
    float3 color;
    // (A piecewise form (piece): root wide at the root, mid wide midAt of the way up (where the simple blade's middle
    // corners go), then narrowing to the tip as 1 - s^tipPow.)
    bool piece;
    float root;
    float midAt;
    float tipPow;
    // How much of its own colour it keeps (0: grey), dark bands every other row of the finer shape (horsetails), and a
    // colour over its upper part (seed heads, embers, ice): tipColor.a its strength, from tipFrom of the way up, lit by
    // the ground's shading or by itself (tipGlow).
    float sat;
    float bands;
    float4 tipColor;
    float tipFrom;
    float tipGlow;
};

// A kind's Amount in Graphics > 3D Grass (include/tooie_picture_filters.h's grass_kind_options): 0 none, 1 its usual share,
// up to 3. FrameParams.grassKindAmounts keeps them a byte each, the grasses from 0 (GrassLeafBit), the flowers from 48
// (FlowerFormOf).
float GrassKindAmount(uint index) {
    const uint word = FrParams.grassKindAmounts[index >> 4u][(index >> 2u) & 3u];
    return float((word >> ((index & 3u) * 8u)) & 0xFFu) * (3.0f / 255.0f);
}

// A kind's place in that table, 48 for the levels' usual blades, which have no Amount of their own.
uint GrassLeafBit(uint leaf) {
    if ((leaf >= GrassLeafSeed) && (leaf <= GrassLeafCloud)) {
        return leaf - 8u;
    }
    if ((leaf >= GrassLeafFescue) && (leaf <= GrassLeafRedWeed)) {
        return leaf - 2u;
    }
    return (leaf == GrassLeafFern) ? 23u : ((leaf == GrassLeafBroad) ? 24u : ((leaf == GrassLeafKelp) ? 25u : ((leaf == GrassLeafEel) ? 26u
        : ((leaf == GrassLeafLettuce) ? 27u : ((leaf == GrassLeafWrack) ? 28u : 48u)))));
}

// The level's usual blade, which a kind switched off is drawn as.
uint GrassUsualLeaf(uint plant) {
    if ((plant == GRASS_PLANT_FERN) || (plant == GRASS_PLANT_STRAW) || (plant == GRASS_PLANT_DESERT) || (plant == GRASS_PLANT_INDUSTRY) || (plant == GRASS_PLANT_LAVA)) {
        return GrassLeafStraw;
    }
    return (plant == GRASS_PLANT_LAWN) ? GrassLeafLawn : ((plant == GRASS_PLANT_FROST) ? GrassLeafFrost : ((plant == GRASS_PLANT_DUNE) ? GrassLeafDune : GrassLeafGrass));
}

// The Amount of a level's own kind (GrassKindAmount), 0 for its usual blade.
float GrassLeafAmount(uint leaf) {
    const uint index = GrassLeafBit(leaf);
    return (index < 48u) ? GrassKindAmount(index) : 0.0f;
}

// (variant: the blade's own hash, 0 to 1, choosing among a level's kinds.)
// (A form of height 0 is not drawn: a seaweed past what its Amounts keep.)
GrassForm GrassFormOf(uint plant, float variant) {
    GrassForm f;
    f.leaf = GrassLeafGrass;
    f.width = 1.0f;
    f.height = 1.0f;
    f.mid = 0.75f;
    f.lean = 1.0f;
    f.stiff = 1.0f;
    f.maxBend = GrassMaxBend;
    f.droop = 0.0f;
    f.ridge = 1.0f;
    f.straight = 0.0f;
    f.tint = 1.0f;
    f.color = float3(1.0f, 1.0f, 1.0f);
    f.piece = false;
    f.root = 1.0f;
    f.midAt = 0.5f;
    f.tipPow = 1.0f;
    f.sat = 1.0f;
    f.bands = 0.0f;
    f.tipColor = float4(0.0f, 0.0f, 0.0f, 0.0f);
    f.tipFrom = 0.5f;
    f.tipGlow = 0.0f;
    uint leaf = GrassUsualLeaf(plant);
    // (A second hash, for a kind's own colours.)
    const float pick = frac(variant * 7.13f);
    if (plant == GRASS_PLANT_KELP) {
        // Five seaweeds share the seabed (red weed, eelgrass, sea lettuce, bladder wrack and kelp), each its usual share
        // times its Amount; with less than all of it taken, fewer plants grow, and with more, they share it out.
        float red = 0.15f * GrassLeafAmount(GrassLeafRedWeed);
        float4 share = float4(0.22f, 0.18f, 0.17f, 0.28f) * float4(GrassLeafAmount(GrassLeafEel), GrassLeafAmount(GrassLeafLettuce),
            GrassLeafAmount(GrassLeafWrack), GrassLeafAmount(GrassLeafKelp));
        const float total = red + share.x + share.y + share.z + share.w;
        if (total > 1.0f) {
            share /= total;
            red /= total;
        }
        if (variant >= red + share.x + share.y + share.z + share.w) {
            f.height = 0.0f;
            return f;
        }
        const float u = variant - red;
        leaf = (variant < red) ? GrassLeafRedWeed : ((u < share.x) ? GrassLeafEel : ((u < share.x + share.y) ? GrassLeafLettuce
            : ((u < share.x + share.y + share.z) ? GrassLeafWrack : GrassLeafKelp)));
    }
    else {
        // Each level's own grasses, up to four, each its usual share times its Amount, the level's usual blade the rest
        // (at least a twentieth of it). The shares are tuned so they go together: the quiet kinds (sedge, tussocks,
        // frozen tufts, ash grass, wire grass, rushes) about one blade in ten, the bold, tall or glowing ones (cattails,
        // bamboo, palm fronds, neon, obsidian, rainbow) a few in a hundred, as accents (L 2026-11-14).
        uint4 own = uint4(GrassLeafGrass, GrassLeafGrass, GrassLeafGrass, GrassLeafGrass);
        float4 share = float4(0.0f, 0.0f, 0.0f, 0.0f);
        if (plant == GRASS_PLANT_FERN) {
            own = uint4(GrassLeafFern, GrassLeafHorsetail, GrassLeafTussock, GrassLeafClubMoss);
            share = float4(0.04f, 0.05f, 0.12f, 0.08f);
        }
        else if (plant == GRASS_PLANT_DESERT) {
            own = uint4(GrassLeafYucca, GrassLeafTumble, GrassLeafSage, GrassLeafGrass);
            share = float4(0.04f, 0.1f, 0.1f, 0.0f);
        }
        else if (plant == GRASS_PLANT_INDUSTRY) {
            own = uint4(GrassLeafDock, GrassLeafWire, GrassLeafToxic, GrassLeafGrass);
            share = float4(0.04f, 0.1f, 0.04f, 0.0f);
        }
        else if (plant == GRASS_PLANT_LAVA) {
            own = uint4(GrassLeafCharred, GrassLeafAsh, GrassLeafObsidian, GrassLeafGrass);
            share = float4(0.05f, 0.12f, 0.03f, 0.0f);
        }
        else if (plant == GRASS_PLANT_LAWN) {
            own = uint4(GrassLeafPennant, GrassLeafTopiary, GrassLeafNeon, GrassLeafGrass);
            share = float4(0.04f, 0.08f, 0.03f, 0.0f);
        }
        else if (plant == GRASS_PLANT_FROST) {
            own = uint4(GrassLeafIce, GrassLeafFrozen, GrassLeafCotton, GrassLeafGrass);
            share = float4(0.04f, 0.12f, 0.05f, 0.0f);
        }
        else if (plant == GRASS_PLANT_JUNGLE) {
            own = uint4(GrassLeafBroad, GrassLeafPalm, GrassLeafReed, GrassLeafBamboo);
            share = float4(0.015f, 0.015f, 0.006f, 0.01f);
            f.height = 1.05f;
        }
        else if (plant == GRASS_PLANT_DUNE) {
            own = uint4(GrassLeafOats, GrassLeafSucculent, GrassLeafRush, GrassLeafGrass);
            share = float4(0.05f, 0.06f, 0.1f, 0.0f);
        }
        else if (plant == GRASS_PLANT_CANDY) {
            own = uint4(GrassLeafCandy, GrassLeafCloud, GrassLeafRainbow, GrassLeafGrass);
            share = float4(0.05f, 0.06f, 0.03f, 0.0f);
        }
        else if (plant == GRASS_PLANT_MEADOW) {
            own = uint4(GrassLeafSeed, GrassLeafSedge, GrassLeafFescue, GrassLeafGrass);
            share = float4(0.04f, 0.08f, 0.08f, 0.0f);
        }
        share *= float4(GrassLeafAmount(own.x), GrassLeafAmount(own.y), GrassLeafAmount(own.z), GrassLeafAmount(own.w));
        const float total = share.x + share.y + share.z + share.w;
        if (total > 0.95f) {
            share *= 0.95f / total;
        }
        if (variant < share.x) {
            leaf = own.x;
        }
        else if (variant < share.x + share.y) {
            leaf = own.y;
        }
        else if (variant < share.x + share.y + share.z) {
            leaf = own.z;
        }
        else if (variant < share.x + share.y + share.z + share.w) {
            leaf = own.w;
        }
    }
    f.leaf = leaf;
    if (leaf == GrassLeafKelp) {
        // A kelp ribbon: wide and flat, its edges ruffled, swaying from its holdfast as the water moves it.
        f.width = 4.5f;
        f.lean = 0.5f;
        f.maxBend = 0.6f;
        f.ridge = 0.0f;
    }
    else if (leaf == GrassLeafEel) {
        // Eelgrass: long, narrow and soft, its tip round.
        f.width = 1.0f;
        f.height = 1.3f;
        f.mid = 0.9f;
        f.lean = 0.6f;
        f.stiff = 1.2f;
        f.ridge = 0.3f;
    }
    else if (leaf == GrassLeafLettuce) {
        // Sea lettuce: short, very wide, round and crinkled sheets spreading out low, a bright yellow-green.
        f.width = 7.0f;
        f.height = 0.35f;
        f.lean = 1.0f;
        f.stiff = 0.8f;
        f.maxBend = 0.75f;
        f.droop = 0.25f;
        f.ridge = 0.0f;
        f.tint = 0.6f;
        f.color = float3(1.1f, 1.2f, 0.75f);
    }
    else if (leaf == GrassLeafWrack) {
        // Bladder wrack: a brown-olive stem of round lobes, its midrib raised.
        f.width = 3.5f;
        f.height = 0.9f;
        f.lean = 0.7f;
        f.stiff = 0.8f;
        f.ridge = 0.4f;
        f.tint = 0.7f;
        f.color = float3(0.95f, 0.8f, 0.55f);
    }
    else if (leaf == GrassLeafFern) {
        // A fern frond: wide, its leaflets in pairs up a stem, arching out and down, greener than the dry grass round it.
        f.width = 6.0f;
        f.ridge = 0.4f;
        f.height = 1.2f;
        f.stiff = 0.6f;
        f.maxBend = 0.85f;
        f.droop = 0.3f;
        f.tint = 0.3f;
        f.color = float3(0.9f, 1.06f, 0.92f);
    }
    else if (leaf == GrassLeafBroad) {
        // A broad jungle leaf: narrow at its stalk, widest in the middle, pointed, arching out and down, a deep green.
        f.width = 6.5f;
        f.height = 0.95f;
        f.stiff = 0.6f;
        f.maxBend = 0.8f;
        f.droop = 0.25f;
        f.ridge = 0.5f;
        f.color = float3(0.86f, 1.0f, 0.84f);
    }
    else if (leaf == GrassLeafStraw) {
        // Dry straw: thin, stiff and needle-pointed, standing nearly straight.
        f.width = 0.6f;
        f.height = 1.1f;
        f.mid = 0.45f;
        f.lean = 0.6f;
        f.stiff = 0.7f;
        f.straight = 0.5f;
    }
    else if (leaf == GrassLeafLawn) {
        // A mown lawn: short, upright and blunt, barely swaying.
        f.height = 0.85f;
        f.mid = 0.9f;
        f.lean = 0.3f;
        f.stiff = 0.45f;
        f.ridge = 0.6f;
        f.straight = 0.6f;
    }
    else if (leaf == GrassLeafFrost) {
        // Frosted spikes: narrow, stiff and straight, their tips iced white.
        f.width = 0.7f;
        f.height = 0.9f;
        f.mid = 0.5f;
        f.lean = 0.4f;
        f.stiff = 0.3f;
        f.ridge = 1.3f;
        f.straight = 0.75f;
    }
    else if (leaf == GrassLeafDune) {
        // Dune grass: long, thin and curling over, all leaning with the sea wind.
        f.width = 0.55f;
        f.height = 1.2f;
        f.mid = 0.6f;
        f.lean = 1.7f;
        f.stiff = 1.3f;
        f.maxBend = 0.7f;
        f.droop = 0.1f;
    }
    else if (leaf == GrassLeafSeed) {
        // Timothy: a tall, thin, straight stalk ending in a pale seed spike.
        f.width = 0.45f;
        f.height = 1.45f;
        f.mid = 0.85f;
        f.lean = 0.6f;
        f.straight = 0.7f;
        f.tipColor = float4(0.86f, 0.8f, 0.55f, 0.85f);
        f.tipFrom = 0.45f;
    }
    else if (leaf == GrassLeafSedge) {
        // Sedge: broad, blunt and darker, low.
        f.width = 1.8f;
        f.height = 0.8f;
        f.mid = 0.95f;
        f.lean = 0.7f;
        f.ridge = 1.3f;
        f.color = float3(0.82f, 0.95f, 0.78f);
    }
    else if (leaf == GrassLeafHorsetail) {
        // A horsetail: an upright jointed stem, dark bands at its joints, a brown cone at its top, fresher green.
        f.piece = true;
        f.width = 1.1f;
        f.root = 0.8f;
        f.mid = 0.8f;
        f.tipPow = 3.0f;
        f.height = 1.5f;
        f.lean = 0.25f;
        f.stiff = 0.4f;
        f.straight = 1.0f;
        f.bands = 0.35f;
        f.tint = 0.25f;
        f.color = float3(0.78f, 1.08f, 0.72f);
        f.tipColor = float4(0.55f, 0.42f, 0.28f, 0.7f);
        f.tipFrom = 0.82f;
    }
    else if (leaf == GrassLeafTussock) {
        // A dry tussock: short, fine, blond and flopping over.
        f.width = 0.7f;
        f.height = 0.6f;
        f.lean = 1.8f;
        f.maxBend = 0.8f;
        f.droop = 0.15f;
        f.color = float3(1.1f, 1.02f, 0.82f);
    }
    else if (leaf == GrassLeafPalm) {
        // A palm frond: long and arching, cut into narrow leaflets.
        f.width = 6.0f;
        f.height = 1.4f;
        f.stiff = 0.6f;
        f.maxBend = 0.85f;
        f.droop = 0.35f;
        f.ridge = 0.4f;
        f.color = float3(0.84f, 1.05f, 0.8f);
    }
    else if (leaf == GrassLeafReed) {
        // A cattail reed: a tall straight stem with a fat brown seed head near its top.
        f.width = 0.7f;
        f.height = 1.8f;
        f.lean = 0.4f;
        f.stiff = 0.8f;
        f.straight = 0.9f;
        f.tipColor = float4(0.42f, 0.27f, 0.15f, 1.0f);
        f.tipFrom = 0.66f;
    }
    else if (leaf == GrassLeafYucca) {
        // A yucca spike: a stiff blue-grey sword, widest low down.
        f.piece = true;
        f.width = 2.6f;
        f.root = 0.5f;
        f.midAt = 0.3f;
        f.mid = 1.0f;
        f.height = 1.1f;
        f.lean = 0.4f;
        f.stiff = 0.2f;
        f.straight = 0.9f;
        f.ridge = 1.2f;
        f.tint = 0.3f;
        f.sat = 0.6f;
        f.color = float3(0.78f, 0.95f, 1.0f);
    }
    else if (leaf == GrassLeafTumble) {
        // A tumbleweed tuft: short, dry, brown and curled over.
        f.width = 0.6f;
        f.height = 0.45f;
        f.lean = 2.0f;
        f.maxBend = 0.85f;
        f.droop = 0.2f;
        f.sat = 0.7f;
        f.color = float3(1.18f, 0.95f, 0.68f);
    }
    else if (leaf == GrassLeafPennant) {
        // Pennant grass: tall and thin, its tip a carnival red, yellow or blue.
        f.width = 0.6f;
        f.height = 1.4f;
        f.lean = 0.5f;
        f.straight = 0.6f;
        f.tipColor = float4((pick < 0.33f) ? float3(1.0f, 0.2f, 0.22f) : ((pick < 0.66f) ? float3(1.0f, 0.85f, 0.12f) : float3(0.25f, 0.45f, 1.0f)), 1.0f);
        f.tipFrom = 0.55f;
    }
    else if (leaf == GrassLeafTopiary) {
        // A topiary tuft: short, clipped square and bright.
        f.piece = true;
        f.width = 2.2f;
        f.midAt = 0.7f;
        f.mid = 1.05f;
        f.tipPow = 0.6f;
        f.height = 0.55f;
        f.lean = 0.1f;
        f.stiff = 0.2f;
        f.straight = 1.0f;
        f.ridge = 0.5f;
        f.color = float3(0.9f, 1.15f, 0.85f);
    }
    else if (leaf == GrassLeafIce) {
        // An ice shard: a stiff, straight, faceted crystal, pale blue and lit from within.
        f.piece = true;
        f.width = 2.0f;
        f.root = 0.4f;
        f.midAt = 0.4f;
        f.mid = 1.0f;
        f.height = 1.0f;
        f.lean = 0.3f;
        f.stiff = 0.05f;
        f.straight = 1.0f;
        f.ridge = 1.4f;
        f.tint = 0.0f;
        f.tipColor = float4(0.78f, 0.9f, 1.0f, 0.9f);
        f.tipFrom = -0.3f;
        f.tipGlow = 0.35f;
    }
    else if (leaf == GrassLeafFrozen) {
        // A frozen tuft: short and curled, white with frost towards its tips.
        f.width = 0.8f;
        f.height = 0.5f;
        f.lean = 1.5f;
        f.maxBend = 0.8f;
        f.droop = 0.2f;
        f.tipColor = float4(0.95f, 0.97f, 1.0f, 0.8f);
        f.tipFrom = 0.35f;
    }
    else if (leaf == GrassLeafCharred) {
        // A charred stalk: black and straight, its tip still glowing like an ember.
        f.width = 0.6f;
        f.height = 1.3f;
        f.lean = 0.4f;
        f.stiff = 0.3f;
        f.straight = 1.0f;
        f.tint = 0.0f;
        f.sat = 0.15f;
        f.color = float3(0.4f, 0.36f, 0.34f);
        f.tipColor = float4(1.0f, 0.42f, 0.08f, 1.0f);
        f.tipFrom = 0.72f;
        f.tipGlow = 1.0f;
    }
    else if (leaf == GrassLeafAsh) {
        // Ash grass: short, grey and curled.
        f.width = 0.7f;
        f.height = 0.5f;
        f.lean = 1.6f;
        f.maxBend = 0.8f;
        f.droop = 0.15f;
        f.tint = 0.2f;
        f.sat = 0.1f;
        f.color = float3(0.85f, 0.82f, 0.8f);
    }
    else if (leaf == GrassLeafDock) {
        // A dock leaf: broad, rust-brown at its edges and tip, flopping out.
        f.piece = true;
        f.width = 4.0f;
        f.root = 0.25f;
        f.midAt = 0.45f;
        f.mid = 1.0f;
        f.tipPow = 1.3f;
        f.height = 0.8f;
        f.lean = 1.2f;
        f.maxBend = 0.7f;
        f.droop = 0.15f;
        f.ridge = 0.6f;
        f.tint = 0.5f;
        f.color = float3(1.12f, 0.88f, 0.62f);
        f.tipColor = float4(0.62f, 0.32f, 0.14f, 0.55f);
        f.tipFrom = 0.35f;
    }
    else if (leaf == GrassLeafWire) {
        // Wire grass: thin, grey and kinked over.
        f.width = 0.35f;
        f.height = 1.2f;
        f.lean = 1.4f;
        f.stiff = 0.3f;
        f.straight = 0.8f;
        f.tint = 0.6f;
        f.sat = 0.3f;
        f.color = float3(0.9f, 0.92f, 0.9f);
    }
    else if (leaf == GrassLeafOats) {
        // Sea oats: a tall stalk nodding over with a golden seed head.
        f.width = 0.5f;
        f.height = 1.6f;
        f.lean = 1.2f;
        f.maxBend = 0.7f;
        f.droop = 0.25f;
        f.tipColor = float4(0.95f, 0.82f, 0.5f, 0.9f);
        f.tipFrom = 0.55f;
    }
    else if (leaf == GrassLeafSucculent) {
        // A beach succulent: short, fat, fleshy leaves, reddening at their tips.
        f.piece = true;
        f.width = 1.6f;
        f.root = 0.6f;
        f.midAt = 0.55f;
        f.mid = 1.0f;
        f.tipPow = 0.7f;
        f.height = 0.4f;
        f.lean = 1.6f;
        f.maxBend = 0.85f;
        f.droop = 0.2f;
        f.color = float3(0.85f, 1.1f, 0.82f);
        f.tipColor = float4(0.92f, 0.42f, 0.4f, 0.6f);
        f.tipFrom = 0.6f;
    }
    else if (leaf == GrassLeafCandy) {
        // Candy grass: its upper half a pastel pink, lilac or mint.
        f.width = 0.6f;
        f.height = 1.2f;
        f.tipColor = float4((pick < 0.33f) ? float3(1.0f, 0.65f, 0.85f) : ((pick < 0.66f) ? float3(0.8f, 0.7f, 1.0f) : float3(0.65f, 1.0f, 0.85f)), 0.9f);
        f.tipFrom = 0.35f;
    }
    else if (leaf == GrassLeafCloud) {
        // A cloud tuft: short, round-topped and white.
        f.piece = true;
        f.width = 2.4f;
        f.midAt = 0.6f;
        f.mid = 1.0f;
        f.tipPow = 0.5f;
        f.height = 0.45f;
        f.lean = 0.2f;
        f.stiff = 0.5f;
        f.straight = 1.0f;
        f.tipColor = float4(1.0f, 1.0f, 1.0f, 0.85f);
        f.tipFrom = -0.2f;
        f.tipGlow = 0.3f;
    }
    else if (leaf == GrassLeafFescue) {
        // Blue fescue: short, fine, blue-grey tufts splaying out.
        f.width = 0.5f;
        f.height = 0.65f;
        f.lean = 1.6f;
        f.maxBend = 0.75f;
        f.tint = 0.6f;
        f.sat = 0.6f;
        f.color = float3(0.85f, 0.98f, 1.12f);
    }
    else if (leaf == GrassLeafClubMoss) {
        // Club moss: short, upright, fuzzy dark-green spikes.
        f.piece = true;
        f.width = 1.5f;
        f.midAt = 0.6f;
        f.mid = 0.95f;
        f.tipPow = 0.8f;
        f.height = 0.55f;
        f.lean = 0.2f;
        f.stiff = 0.4f;
        f.straight = 1.0f;
        f.ridge = 1.3f;
        f.tint = 0.2f;
        f.color = float3(0.7f, 1.0f, 0.65f);
    }
    else if (leaf == GrassLeafBamboo) {
        // A bamboo shoot: tall, straight and pale, dark rings at its joints.
        f.piece = true;
        f.width = 1.0f;
        f.root = 0.9f;
        f.mid = 0.9f;
        f.tipPow = 3.0f;
        f.height = 1.9f;
        f.lean = 0.2f;
        f.stiff = 0.3f;
        f.straight = 1.0f;
        f.bands = 0.3f;
        f.tint = 0.4f;
        f.color = float3(1.05f, 1.12f, 0.78f);
    }
    else if (leaf == GrassLeafSage) {
        // Sagebrush: short, bushy, silver-grey and curled.
        f.width = 0.9f;
        f.height = 0.6f;
        f.lean = 1.8f;
        f.maxBend = 0.8f;
        f.droop = 0.15f;
        f.tint = 0.3f;
        f.sat = 0.35f;
        f.color = float3(0.95f, 1.0f, 0.95f);
        f.tipColor = float4(0.85f, 0.88f, 0.82f, 0.6f);
        f.tipFrom = 0.3f;
    }
    else if (leaf == GrassLeafNeon) {
        // Neon grass: tall blades whose tips glow purple, lime or orange like the fair's lights.
        f.width = 0.55f;
        f.height = 1.2f;
        f.straight = 0.6f;
        f.tipColor = float4((pick < 0.33f) ? float3(0.75f, 0.3f, 1.0f) : ((pick < 0.66f) ? float3(0.5f, 1.0f, 0.3f) : float3(1.0f, 0.55f, 0.15f)), 1.0f);
        f.tipFrom = 0.6f;
        f.tipGlow = 1.0f;
    }
    else if (leaf == GrassLeafCotton) {
        // Arctic cotton grass: thin stalks with a white tuft of cotton at the top.
        f.width = 0.45f;
        f.height = 1.4f;
        f.lean = 0.5f;
        f.straight = 0.8f;
        f.tipColor = float4(1.0f, 1.0f, 1.0f, 1.0f);
        f.tipFrom = 0.78f;
        f.tipGlow = 0.2f;
    }
    else if (leaf == GrassLeafObsidian) {
        // An obsidian spike: a glassy black-purple blade, its point glowing red.
        f.piece = true;
        f.width = 2.4f;
        f.root = 0.5f;
        f.midAt = 0.35f;
        f.mid = 1.0f;
        f.height = 0.9f;
        f.lean = 0.3f;
        f.stiff = 0.05f;
        f.straight = 1.0f;
        f.ridge = 1.5f;
        f.tint = 0.0f;
        f.sat = 0.2f;
        f.color = float3(0.35f, 0.3f, 0.4f);
        f.tipColor = float4(0.9f, 0.15f, 0.05f, 0.7f);
        f.tipFrom = 0.75f;
        f.tipGlow = 1.0f;
    }
    else if (leaf == GrassLeafToxic) {
        // A toxic weed: sickly yellow-green and floppy, its tips glowing green.
        f.width = 0.9f;
        f.height = 1.0f;
        f.lean = 1.3f;
        f.maxBend = 0.7f;
        f.droop = 0.15f;
        f.tint = 0.4f;
        f.color = float3(1.2f, 1.15f, 0.45f);
        f.tipColor = float4(0.6f, 1.0f, 0.2f, 0.8f);
        f.tipFrom = 0.6f;
        f.tipGlow = 0.6f;
    }
    else if (leaf == GrassLeafRush) {
        // A sea rush: stiff, straight, dark green and pointed.
        f.width = 0.5f;
        f.height = 1.3f;
        f.lean = 0.3f;
        f.stiff = 0.5f;
        f.straight = 1.0f;
        f.ridge = 1.3f;
        f.color = float3(0.8f, 0.95f, 0.75f);
    }
    else if (leaf == GrassLeafRainbow) {
        // Rainbow grass: each blade's tip one colour of the rainbow.
        f.width = 0.7f;
        f.height = 1.15f;
        const uint hue = min(uint(pick * 6.0f), 5u);
        const float3 rainbow = (hue == 0u) ? float3(1.0f, 0.3f, 0.3f) : ((hue == 1u) ? float3(1.0f, 0.62f, 0.2f) : ((hue == 2u) ? float3(1.0f, 0.95f, 0.3f)
            : ((hue == 3u) ? float3(0.4f, 1.0f, 0.4f) : ((hue == 4u) ? float3(0.4f, 0.6f, 1.0f) : float3(0.75f, 0.45f, 1.0f)))));
        f.tipColor = float4(rainbow, 0.9f);
        f.tipFrom = 0.4f;
    }
    else if (leaf == GrassLeafRedWeed) {
        // Red weed: a feathery red-pink seaweed of narrow leaflets.
        f.width = 4.0f;
        f.height = 0.7f;
        f.maxBend = 0.6f;
        f.droop = 0.2f;
        f.ridge = 0.3f;
        f.tint = 0.2f;
        f.color = float3(1.4f, 0.6f, 0.6f);
        f.tipColor = float4(0.9f, 0.3f, 0.35f, 0.7f);
        f.tipFrom = 0.0f;
    }
    // The usual grass of each level is itself a mix of four (by a second hash): fine, tall, narrow-pointed blades; broad,
    // short, blunt ones; long ones curling over; and plain ones a little shorter and greener, each a shade apart, so a
    // field never looks like one blade copied (L 2026-11-14).
    const bool usual = (leaf == GrassLeafGrass) || (leaf == GrassLeafStraw) || (leaf == GrassLeafLawn) || (leaf == GrassLeafFrost) || (leaf == GrassLeafDune);
    if (usual) {
        const float mix = frac(variant * 3.71f + 0.13f);
        // (Fine, broad and curling blades each a quarter times its Amount (GrassKindAmount 0 to 2), plain ones the rest.)
        float3 mixShare = float3(0.3f, 0.2f, 0.2f) * float3(GrassKindAmount(0u), GrassKindAmount(1u), GrassKindAmount(2u));
        const float mixTotal = mixShare.x + mixShare.y + mixShare.z;
        if (mixTotal > 1.0f) {
            mixShare /= mixTotal;
        }
        const uint mixKind = (mix < mixShare.x) ? 0u : ((mix < mixShare.x + mixShare.y) ? 1u : ((mix < mixShare.x + mixShare.y + mixShare.z) ? 2u : 3u));
        if (mixKind == 0u) {
            f.width *= 0.65f;
            f.height *= 1.25f;
            f.mid = min(f.mid, 0.6f);
            f.lean *= 0.8f;
            f.color *= float3(1.04f, 1.03f, 0.9f);
        }
        else if (mixKind == 1u) {
            f.width *= 1.7f;
            f.height *= 0.75f;
            f.mid = max(f.mid, 0.85f);
            f.ridge *= 1.2f;
            f.color *= float3(0.9f, 0.97f, 0.88f);
        }
        else if (mixKind == 2u) {
            f.lean *= 1.9f;
            f.maxBend = max(f.maxBend, 0.75f);
            f.droop = max(f.droop, 0.12f);
            f.straight *= 0.5f;
            f.height *= 1.05f;
            f.color *= float3(1.07f, 1.05f, 0.86f);
        }
        else {
            f.height *= 0.92f;
            f.color *= float3(0.96f, 1.02f, 0.95f);
        }
    }
    return f;
}

// Whether a blade of this kind needs the finer shape (rows of corners up its length: ribbons, leaflets, lobes, a seed
// head part way up, joints); the others are drawn with the simple one even where the level has the finer.
bool GrassLeafNeedsRibbon(uint leaf) {
    return (leaf == GrassLeafKelp) || (leaf == GrassLeafLettuce) || (leaf == GrassLeafWrack) || (leaf == GrassLeafFern) || (leaf == GrassLeafBroad)
        || (leaf == GrassLeafPalm) || (leaf == GrassLeafReed) || (leaf == GrassLeafHorsetail) || (leaf == GrassLeafBamboo) || (leaf == GrassLeafRedWeed);
}

// A blade's width up its length (t, 0 at the root to 1 at the tip; row: the finer shape's row there), as a share of
// its width at the root.
float GrassFormWidth(GrassForm f, float t, uint row) {
    if (f.leaf == GrassLeafPalm) {
        // (A bare stalk, then narrow leaflets: every other row nearly closed.)
        if (row == 0) {
            return 0.08f;
        }
        return pow(sin(3.1415927f * min(t * 1.05f, 1.0f)), 0.5f) * (((row & 1u) != 0) ? 0.2f : 1.0f);
    }
    if (f.leaf == GrassLeafReed) {
        // (A thin stem with the fat seed head round 0.7 to 0.9 of the way up.)
        return ((t > 0.65f) && (t < 0.95f)) ? 2.6f : 0.55f;
    }
    if (f.piece) {
        if (t <= f.midAt) {
            return lerp(f.root, f.mid, t / max(f.midAt, 1e-3f));
        }
        return f.mid * (1.0f - pow(saturate((t - f.midAt) / max(1.0f - f.midAt, 1e-3f)), f.tipPow));
    }
    if (f.leaf == GrassLeafKelp) {
        // (Narrow at the holdfast, then a ribbon to a round tip.)
        return lerp(0.3f, 1.0f, smoothstep(0.0f, 0.3f, t)) * (1.0f - pow(t, 6.0f));
    }
    if (f.leaf == GrassLeafLettuce) {
        // (A short stalk, then a round sheet.)
        return max(pow(sin(3.1415927f * t), 0.5f), (row == 0) ? 0.2f : 0.0f);
    }
    if (f.leaf == GrassLeafWrack) {
        // (A stem, then round lobes up it, every other row pinched in.)
        if (row == 0) {
            return 0.15f;
        }
        return (0.55f + 0.45f * sin(3.1415927f * t)) * (((row & 1u) != 0) ? 1.0f : 0.4f);
    }
    if ((f.leaf == GrassLeafFern) || (f.leaf == GrassLeafRedWeed)) {
        // (A bare stem at the root, then leaflets: every other row wide, so the edges zigzag.)
        if (row == 0) {
            return 0.1f;
        }
        return pow(sin(3.1415927f * min(t * 1.05f, 1.0f)), 0.6f) * (((row & 1u) != 0) ? 0.35f : 1.0f);
    }
    if (f.leaf == GrassLeafBroad) {
        return max(pow(sin(3.1415927f * t), 0.7f), (row == 0) ? 0.12f : 0.0f);
    }
    // (Grass narrows to its point, mid wide half way up.)
    return 1.0f - pow(t, log2(1.0f / max(1.0f - f.mid, 0.01f)));
}

// How a flower's six diamonds (four corners each: its base, one side, its far point, the other side) make its head
// (FlowerForm.layout): petals round a centre, facing up and towards the camera; ribs round a ball on the stem
// (pompoms, puffs, a barrel cactus); leaves or shards rising out from the root (bromeliads, cycads, crystals); bells
// hanging from the stem (bluebells, snowdrops); a balloon facing the camera (Witchyworld's balloon flowers).
static const uint FlowerLayoutRadial = 0;
static const uint FlowerLayoutBall = 1;
static const uint FlowerLayoutRosette = 2;
static const uint FlowerLayoutBells = 3;
static const uint FlowerLayoutBalloon = 4;

// A flower's form (FlowerFormOf): the usual one (generic, coloured by its kind from GrassFlowerColors) or the level's
// own: its layout, how many diamonds are petals (the sixth is the centre when centre is set), a petal's length (times
// the head's size), half the angle it spans, where its sides are (a share of its length), its tip raised out of the
// head's plane (negative: down; a rosette's: how steeply its leaves rise, in radians), the middle raised (a
// toadstool's cap), the first petal longer (an orchid's lip), the sides turned (a pinwheel), how far the head turns
// to the camera, the stem's height (times the grass's) and width, the stem's own colour (a = 1), its size, lean and
// glow (tips lit by themselves), and its colours: petals colorA at their base and colorB at their tip, or alternating
// petal by petal (alternate), and the centre's.
struct FlowerForm {
    bool generic;
    // (Past what the level's flowers' Amounts keep, in a level with no usual flowers: not drawn.)
    bool hidden;
    uint layout;
    uint petals;
    bool centre;
    float reach;
    float spread;
    float waist;
    float cup;
    float dome;
    float lip;
    float twist;
    float face;
    float stem;
    float stemWidth;
    float4 stemColor;
    float size;
    float lean;
    float glow;
    bool alternate;
    float3 colorA;
    float3 colorB;
    float3 centreColor;
};

// (pick: the flower's own hash, choosing among the level's flowers; kind: its colour, 1 to 6.)
FlowerForm FlowerFormOf(uint plant, float pick, uint kind) {
    FlowerForm f;
    f.generic = true;
    f.hidden = false;
    f.layout = FlowerLayoutRadial;
    f.petals = 5;
    f.centre = true;
    f.reach = 1.0f;
    f.spread = 0.5f;
    f.waist = 0.55f;
    f.cup = 0.0f;
    f.dome = 0.0f;
    f.lip = 0.0f;
    f.twist = 0.0f;
    f.face = 0.45f;
    f.stem = 1.25f;
    f.stemWidth = 1.0f;
    f.stemColor = float4(0.0f, 0.0f, 0.0f, 0.0f);
    f.size = 1.0f;
    f.lean = 0.0f;
    f.glow = 0.0f;
    f.alternate = false;
    f.colorA = float3(1.0f, 1.0f, 1.0f);
    f.colorB = float3(1.0f, 1.0f, 1.0f);
    f.centreColor = float3(1.0f, 0.8f, 0.15f);
    // Each level's three flowers, each its usual share times its Amount (GrassKindAmount from 48, three a level in the
    // order below: include/tooie_picture_filters.h's grass_kind_options). The meadows and Cloud Cuckooland grow the
    // usual flowers in the rest; the other levels only their own, fewer when their Amounts are under 100.
    const bool keepsUsual = (plant == GRASS_PLANT_MEADOW) || (plant == GRASS_PLANT_CANDY);
    const uint speciesBase = (plant == GRASS_PLANT_MEADOW) ? 0u : ((plant == GRASS_PLANT_JUNGLE) ? 3u : ((plant == GRASS_PLANT_FERN) ? 6u
        : ((plant == GRASS_PLANT_DESERT) ? 9u : ((plant == GRASS_PLANT_LAWN) ? 12u : ((plant == GRASS_PLANT_FROST) ? 15u
        : ((plant == GRASS_PLANT_LAVA) ? 18u : ((plant == GRASS_PLANT_INDUSTRY) ? 21u : ((plant == GRASS_PLANT_DUNE) ? 24u
        : ((plant == GRASS_PLANT_CANDY) ? 27u : 48u)))))))));
    if (speciesBase >= 48u) {
        return f;
    }
    // (Each flower's usual share, tuned so they go together: the delicate ones most of the level's flowers, the showy
    // ones (birds of paradise, cycads, crystal sprouts, ice crystals, ember puffs, lollipops) now and then.)
    static const float usualShare[30] = {
        0.25f, 0.15f, 0.25f,   // daisies, bluebells, buttercups (the usual flowers the rest)
        0.45f, 0.25f, 0.3f,    // orchids, bromeliads, birds of paradise
        0.2f, 0.45f, 0.35f,    // cycads, magnolias, giant puffballs
        0.3f, 0.2f, 0.5f,      // barrel cacti, crystal sprouts, desert marigolds
        0.3f, 0.45f, 0.25f,    // carnival pinwheels, toadstools, balloon flowers
        0.45f, 0.2f, 0.35f,    // snowdrops, ice crystal clusters, edelweiss
        0.4f, 0.4f, 0.2f,      // fire lilies, flame poppies, ember puffs
        0.5f, 0.3f, 0.2f,      // dandelions, dandelion clocks, thistles
        0.5f, 0.25f, 0.25f,    // sea pinks, sea holly, sea lavender
        0.25f, 0.15f, 0.25f    // candy puffs, lollipop swirls, sugar stars (the usual flowers the rest)
    };
    float3 share = float3(GrassKindAmount(48u + speciesBase), GrassKindAmount(49u + speciesBase), GrassKindAmount(50u + speciesBase))
        * float3(usualShare[speciesBase], usualShare[speciesBase + 1u], usualShare[speciesBase + 2u]);
    const float total = share.x + share.y + share.z;
    if (total > 1.0f) {
        share /= total;
    }
    if (pick >= share.x + share.y + share.z) {
        f.hidden = !keepsUsual;
        return f;
    }
    // (Which of the level's three: 0, 1 or 2.)
    const uint which = (pick < share.x) ? 0u : ((pick < share.x + share.y) ? 1u : 2u);
    f.generic = false;
    if (plant == GRASS_PLANT_MEADOW) {
        if (which == 0u) {
            // A daisy: thin white petals, pink at their tips, round a big yellow centre.
            f.spread = 0.3f;
            f.reach = 1.15f;
            f.colorA = float3(0.98f, 0.98f, 0.95f);
            f.colorB = float3(1.0f, 0.8f, 0.88f);
        }
        else if (which == 1u) {
            // Bluebells: a nodding stem hung with blue bells.
            f.layout = FlowerLayoutBells;
            f.petals = 4;
            f.centre = false;
            f.reach = 1.2f;
            f.stem = 1.35f;
            f.lean = 0.45f;
            f.colorA = float3(0.4f, 0.45f, 0.95f);
            f.colorB = float3(0.55f, 0.6f, 1.0f);
        }
        else {
            // Buttercups: five glossy yellow cupped petals.
            f.cup = 0.5f;
            f.spread = 0.55f;
            f.waist = 0.65f;
            f.reach = 0.9f;
            f.glow = 0.15f;
            f.colorA = float3(1.0f, 0.88f, 0.1f);
            f.colorB = float3(1.0f, 0.95f, 0.4f);
            f.centreColor = float3(0.9f, 0.75f, 0.1f);
        }
    }
    else if (plant == GRASS_PLANT_JUNGLE) {
        if (which == 0u) {
            // An orchid: purple petals and a big white-pink lip, a small yellow centre, turned to the camera.
            f.lip = 0.7f;
            f.spread = 0.42f;
            f.reach = 1.2f;
            f.face = 0.9f;
            f.size = 1.2f;
            f.colorA = float3(0.75f, 0.35f, 0.9f);
            f.colorB = float3(1.0f, 0.85f, 0.95f);
        }
        else if (which == 1u) {
            // A bromeliad: a rosette of spiky red leaves rising out of the ground round a yellow heart.
            f.layout = FlowerLayoutRosette;
            f.cup = 0.9f;
            f.spread = 0.18f;
            f.reach = 2.4f;
            f.waist = 0.4f;
            f.stem = 0.05f;
            f.stemWidth = 0.0f;
            f.size = 1.3f;
            f.colorA = float3(0.3f, 0.55f, 0.22f);
            f.colorB = float3(0.92f, 0.15f, 0.2f);
            f.centreColor = float3(1.0f, 0.85f, 0.2f);
        }
        else {
            // A bird of paradise: narrow orange petals rising like a crest, with a long blue tongue.
            f.lip = 0.8f;
            f.spread = 0.22f;
            f.cup = 0.6f;
            f.face = 0.7f;
            f.size = 1.3f;
            f.stem = 1.4f;
            f.centre = false;
            f.colorA = float3(1.0f, 0.55f, 0.1f);
            f.colorB = float3(0.25f, 0.35f, 0.95f);
        }
    }
    else if (plant == GRASS_PLANT_FERN) {
        if (which == 0u) {
            // A cycad: stiff dark fronds rising from the ground round an orange cone.
            f.layout = FlowerLayoutRosette;
            f.cup = 0.55f;
            f.spread = 0.22f;
            f.reach = 3.0f;
            f.waist = 0.5f;
            f.stem = 0.05f;
            f.stemWidth = 0.0f;
            f.size = 1.4f;
            f.colorA = float3(0.25f, 0.45f, 0.18f);
            f.colorB = float3(0.42f, 0.62f, 0.25f);
            f.centreColor = float3(0.9f, 0.5f, 0.15f);
        }
        else if (which == 1u) {
            // A magnolia: big cream cupped petals blushing pink at their tips.
            f.petals = 6;
            f.centre = false;
            f.cup = 0.9f;
            f.spread = 0.45f;
            f.reach = 1.1f;
            f.size = 1.4f;
            f.colorA = float3(1.0f, 0.95f, 0.85f);
            f.colorB = float3(0.95f, 0.65f, 0.78f);
        }
        else {
            // A giant puffball: a big pale fungus ball on the ground.
            f.layout = FlowerLayoutBall;
            f.petals = 6;
            f.centre = false;
            f.waist = 1.0f;
            f.reach = 1.4f;
            f.stem = 0.05f;
            f.stemWidth = 0.0f;
            f.size = 1.3f;
            f.colorA = float3(0.95f, 0.92f, 0.85f);
            f.colorB = float3(1.0f, 1.0f, 0.95f);
        }
    }
    else if (plant == GRASS_PLANT_DESERT) {
        if (which == 0u) {
            // A barrel cactus: a ribbed green ball on the ground with a pink flower on top.
            f.layout = FlowerLayoutBall;
            f.waist = 1.0f;
            f.reach = 1.3f;
            f.stem = 0.05f;
            f.stemWidth = 0.0f;
            f.size = 1.5f;
            f.colorA = float3(0.3f, 0.6f, 0.32f);
            f.colorB = float3(0.42f, 0.72f, 0.4f);
            f.centreColor = float3(1.0f, 0.4f, 0.62f);
        }
        else if (which == 1u) {
            // Crystal sprouts: glittering cyan and violet shards out of the ground.
            f.layout = FlowerLayoutRosette;
            f.petals = 6;
            f.centre = false;
            f.cup = 1.25f;
            f.spread = 0.12f;
            f.reach = 2.2f;
            f.waist = 0.35f;
            f.stem = 0.05f;
            f.stemWidth = 0.0f;
            f.glow = 0.6f;
            f.alternate = true;
            f.colorA = float3(0.5f, 0.95f, 1.0f);
            f.colorB = float3(0.8f, 0.6f, 1.0f);
        }
        else {
            // A desert marigold: yellow petals round an orange heart.
            f.spread = 0.45f;
            f.colorA = float3(1.0f, 0.82f, 0.1f);
            f.colorB = float3(1.0f, 0.92f, 0.35f);
            f.centreColor = float3(0.85f, 0.45f, 0.05f);
        }
    }
    else if (plant == GRASS_PLANT_LAWN) {
        if (which == 0u) {
            // A carnival pinwheel: six broad petals, red and yellow by turns, swirled.
            f.petals = 6;
            f.centre = false;
            f.spread = 0.5f;
            f.twist = 0.35f;
            f.reach = 1.1f;
            f.face = 0.8f;
            f.size = 1.3f;
            f.alternate = true;
            f.colorA = float3(1.0f, 0.25f, 0.3f);
            f.colorB = float3(1.0f, 0.85f, 0.2f);
        }
        else if (which == 1u) {
            // A toadstool: a red domed cap with a white spot on top, on a thick white stalk.
            f.dome = 0.55f;
            f.spread = 0.65f;
            f.waist = 0.75f;
            f.face = 0.0f;
            f.stem = 0.4f;
            f.stemWidth = 4.0f;
            f.stemColor = float4(0.95f, 0.92f, 0.85f, 1.0f);
            f.size = 1.4f;
            f.colorA = float3(0.9f, 0.15f, 0.12f);
            f.colorB = float3(0.85f, 0.12f, 0.1f);
            f.centreColor = float3(1.0f, 1.0f, 0.95f);
        }
        else {
            // A balloon flower: a round balloon on a tall thin stalk, red, blue, yellow or green by the flower's colour,
            // with a pale shine up and to the left and a knot at the bottom.
            f.layout = FlowerLayoutBalloon;
            f.petals = 5;
            f.centre = false;
            f.reach = 1.0f;
            f.stem = 1.8f;
            f.stemWidth = 0.5f;
            f.size = 1.0f;
            const float3 balloon = ((kind % 4u) == 0u) ? float3(1.0f, 0.2f, 0.2f) : (((kind % 4u) == 1u) ? float3(0.25f, 0.45f, 1.0f)
                : (((kind % 4u) == 2u) ? float3(1.0f, 0.9f, 0.2f) : float3(0.3f, 0.9f, 0.35f)));
            f.colorA = balloon;
            f.colorB = balloon;
            f.centreColor = lerp(balloon, float3(1.0f, 1.0f, 1.0f), 0.55f);
        }
    }
    else if (plant == GRASS_PLANT_FROST) {
        if (which == 0u) {
            // Snowdrops: white bells, green-tipped, hanging from a bowed stem.
            f.layout = FlowerLayoutBells;
            f.petals = 2;
            f.centre = false;
            f.reach = 1.3f;
            f.stem = 1.0f;
            f.lean = 0.5f;
            f.colorA = float3(0.97f, 0.98f, 1.0f);
            f.colorB = float3(0.75f, 0.95f, 0.7f);
        }
        else if (which == 1u) {
            // An ice crystal cluster: tall pale shards out of the snow, lit from within.
            f.layout = FlowerLayoutRosette;
            f.petals = 6;
            f.centre = false;
            f.cup = 1.2f;
            f.spread = 0.12f;
            f.reach = 2.6f;
            f.waist = 0.35f;
            f.stem = 0.05f;
            f.stemWidth = 0.0f;
            f.glow = 0.5f;
            f.colorA = float3(0.8f, 0.92f, 1.0f);
            f.colorB = float3(0.95f, 0.98f, 1.0f);
        }
        else {
            // Edelweiss: woolly white star petals round a yellow heart.
            f.spread = 0.3f;
            f.waist = 0.5f;
            f.reach = 1.2f;
            f.face = 0.6f;
            f.colorA = float3(0.92f, 0.93f, 0.9f);
            f.colorB = float3(1.0f, 1.0f, 1.0f);
            f.centreColor = float3(0.95f, 0.85f, 0.35f);
        }
    }
    else if (plant == GRASS_PLANT_LAVA) {
        if (which == 0u) {
            // A fire lily: narrow red petals curling up like a flame, yellow at their tips.
            f.petals = 6;
            f.centre = false;
            f.cup = 1.1f;
            f.spread = 0.25f;
            f.reach = 1.2f;
            f.size = 1.2f;
            f.glow = 0.3f;
            f.colorA = float3(1.0f, 0.3f, 0.08f);
            f.colorB = float3(1.0f, 0.78f, 0.15f);
        }
        else if (which == 1u) {
            // A flame poppy: four broad cupped orange-red petals round a black heart.
            f.petals = 4;
            f.spread = 0.7f;
            f.waist = 0.7f;
            f.cup = 0.35f;
            f.size = 1.3f;
            f.colorA = float3(1.0f, 0.38f, 0.1f);
            f.colorB = float3(1.0f, 0.5f, 0.15f);
            f.centreColor = float3(0.1f, 0.08f, 0.08f);
        }
        else {
            // An ember puff: a glowing orange ball like a floating ember.
            f.layout = FlowerLayoutBall;
            f.petals = 6;
            f.centre = false;
            f.waist = 1.0f;
            f.reach = 0.8f;
            f.glow = 0.8f;
            f.colorA = float3(1.0f, 0.35f, 0.05f);
            f.colorB = float3(1.0f, 0.75f, 0.2f);
        }
    }
    else if (plant == GRASS_PLANT_INDUSTRY) {
        if (which == 0u) {
            // A dandelion: a yellow pompom.
            f.layout = FlowerLayoutBall;
            f.petals = 6;
            f.centre = false;
            f.waist = 1.0f;
            f.reach = 0.7f;
            f.colorA = float3(1.0f, 0.8f, 0.1f);
            f.colorB = float3(1.0f, 0.9f, 0.3f);
        }
        else if (which == 1u) {
            // A dandelion clock: a bigger white seed puff on a taller stem.
            f.layout = FlowerLayoutBall;
            f.petals = 6;
            f.centre = false;
            f.waist = 1.0f;
            f.reach = 1.0f;
            f.stem = 1.5f;
            f.colorA = float3(0.92f, 0.92f, 0.9f);
            f.colorB = float3(1.0f, 1.0f, 1.0f);
        }
        else {
            // A thistle: a purple spiky ball on a tall stem.
            f.layout = FlowerLayoutBall;
            f.petals = 6;
            f.centre = false;
            f.waist = 0.8f;
            f.reach = 0.75f;
            f.stem = 1.3f;
            f.colorA = float3(0.65f, 0.3f, 0.75f);
            f.colorB = float3(0.8f, 0.45f, 0.9f);
        }
    }
    else if (plant == GRASS_PLANT_DUNE) {
        if (which == 0u) {
            // A sea pink: a round pink pompom on a thin stem.
            f.layout = FlowerLayoutBall;
            f.petals = 6;
            f.centre = false;
            f.waist = 1.0f;
            f.reach = 0.8f;
            f.colorA = float3(1.0f, 0.5f, 0.72f);
            f.colorB = float3(1.0f, 0.68f, 0.85f);
        }
        else if (which == 1u) {
            // Sea holly: a spiky silver-blue ruff round a blue thistle head.
            f.spread = 0.15f;
            f.waist = 0.3f;
            f.reach = 1.35f;
            f.cup = 0.25f;
            f.colorA = float3(0.6f, 0.68f, 0.85f);
            f.colorB = float3(0.78f, 0.85f, 0.95f);
            f.centreColor = float3(0.35f, 0.45f, 0.85f);
        }
        else {
            // Sea lavender: little purple bells along a stem.
            f.layout = FlowerLayoutBells;
            f.petals = 4;
            f.centre = false;
            f.reach = 0.6f;
            f.stem = 1.2f;
            f.lean = 0.2f;
            f.colorA = float3(0.65f, 0.5f, 0.9f);
            f.colorB = float3(0.75f, 0.6f, 1.0f);
        }
    }
    else if (plant == GRASS_PLANT_CANDY) {
        if (which == 0u) {
            // A candy puff: a pastel ball, pink, mint, lilac or lemon by the flower's colour.
            f.layout = FlowerLayoutBall;
            f.petals = 6;
            f.centre = false;
            f.waist = 1.0f;
            f.reach = 1.1f;
            f.size = 1.2f;
            const float3 pastel = ((kind % 4u) == 0u) ? float3(1.0f, 0.72f, 0.86f) : (((kind % 4u) == 1u) ? float3(0.72f, 1.0f, 0.86f)
                : (((kind % 4u) == 2u) ? float3(0.86f, 0.76f, 1.0f) : float3(1.0f, 0.97f, 0.7f)));
            f.colorA = pastel;
            f.colorB = saturate(pastel * 1.1f);
        }
        else if (which == 1u) {
            // A lollipop swirl: a flat round disc of pink and white petals by turns, swirled, on a tall stalk.
            f.petals = 6;
            f.spread = 0.55f;
            f.waist = 0.8f;
            f.twist = 0.4f;
            f.face = 1.6f;
            f.stem = 1.5f;
            f.alternate = true;
            f.colorA = float3(1.0f, 0.45f, 0.7f);
            f.colorB = float3(1.0f, 0.97f, 0.97f);
            f.centreColor = float3(1.0f, 0.97f, 0.97f);
        }
        else {
            // A sugar star: five narrow, glowing pastel-yellow points round a pink heart.
            f.spread = 0.2f;
            f.waist = 0.35f;
            f.reach = 1.3f;
            f.glow = 0.4f;
            f.face = 0.9f;
            f.colorA = float3(1.0f, 0.95f, 0.6f);
            f.colorB = float3(1.0f, 1.0f, 0.85f);
            f.centreColor = float3(1.0f, 0.8f, 0.9f);
        }
    }
    else {
        f.generic = true;
    }
    if (f.petals > 5u) {
        f.centre = false;
    }
    return f;
}

// (flower: a flower head's colour, used in place of the ground's texture under the ground's shading, when its a is 1.)
float4 GrassGroundColor(float2 uv, float4 smoothColor, float4 flatColor, float shade, float4 flower) {
    const uint instanceIndex = instanceRenderIndices[gConstants.renderIndex].instanceIndex;
    const RenderParams rp = DynamicRenderParams[instanceIndex];
    const OtherMode otherMode = { rp.omL, rp.omH };
    const uint firstTile = instanceRenderIndices[gConstants.renderIndex].rdpTileIndex;
    float4 texVal0 = float4(0.0f, 0.0f, 0.0f, 1.0f);
    float4 texVal1 = float4(0.0f, 0.0f, 0.0f, 1.0f);
    if (renderFlagUsesTexture0(rp.flags)) {
        RDPTile rdpTile = RDPTiles[firstTile];
        if (!renderFlagDynamicTiles(rp.flags)) {
            rdpTile.cms = renderCMS0(rp.flags);
            rdpTile.cmt = renderCMT0(rp.flags);
            rdpTile.nativeSampler = renderFlagNativeSampler0(rp.flags);
        }
        texVal0 = sampleTexture(otherMode, rp.flags, uv, float2(0.0f, 0.0f), float2(0.0f, 0.0f), rdpTile, GPUTiles[firstTile], false);
    }
    if (renderFlagUsesTexture1(rp.flags)) {
        const bool oneCycleHardwareBug = (otherMode.cycleType() == G_CYC_1CYCLE);
        const uint tileIndex = firstTile + (oneCycleHardwareBug ? 0 : 1);
        RDPTile rdpTile = RDPTiles[tileIndex];
        if (!renderFlagDynamicTiles(rp.flags)) {
            rdpTile.cms = oneCycleHardwareBug ? renderCMS0(rp.flags) : renderCMS1(rp.flags);
            rdpTile.cmt = oneCycleHardwareBug ? renderCMT0(rp.flags) : renderCMT1(rp.flags);
            rdpTile.nativeSampler = oneCycleHardwareBug ? renderFlagNativeSampler0(rp.flags) : renderFlagNativeSampler1(rp.flags);
        }
        texVal1 = sampleTexture(otherMode, rp.flags, uv, float2(0.0f, 0.0f), float2(0.0f, 0.0f), rdpTile, GPUTiles[tileIndex], oneCycleHardwareBug);
    }

    const float4 shadeColor = renderFlagSmoothShade(rp.flags) ? smoothColor : float4(flatColor.rgb, smoothColor.a);
    const ColorCombiner colorCombiner = { rp.ccL, rp.ccH };
    ColorCombiner::Inputs ccInputs;
    ccInputs.otherMode = otherMode;
    ccInputs.alphaOnly = false;
    ccInputs.texVal0 = texVal0;
    ccInputs.texVal1 = texVal1;
    ccInputs.primColor = instanceRDPParams[instanceIndex].primColor;
    ccInputs.shadeColor = shadeColor;
    ccInputs.envColor = instanceRDPParams[instanceIndex].envColor;
    ccInputs.keyCenter = instanceRDPParams[instanceIndex].keyCenter;
    ccInputs.keyScale = instanceRDPParams[instanceIndex].keyScale;
    ccInputs.lodFraction = 0.0f;
    ccInputs.primLodFrac = instanceRDPParams[instanceIndex].primLOD.x;
    ccInputs.noise = 0.5f;
    ccInputs.K4 = (instanceRDPParams[instanceIndex].convertK[4] / 255.0f);
    ccInputs.K5 = (instanceRDPParams[instanceIndex].convertK[5] / 255.0f);
    float4 combinerColor;
    float alphaCompareValue;
    colorCombiner.run(ccInputs, combinerColor, alphaCompareValue);
    combinerColor.rgb = saturate(combinerColor.rgb * shade);
    if (flower.a > 0.5f) {
        combinerColor.rgb = saturate(flower.rgb * saturate(shadeColor.rgb * 1.15f) * shade);
    }

    // A grass layer the game blends over the ground: its own colour, solid (the bake left out where it fades).
    if ((otherMode.cycleType() != G_CYC_COPY) && Blender::usesAlphaBlend(otherMode)) {
        return float4(combinerColor.rgb, 1.0f);
    }

    Blender::Inputs blInputs;
    blInputs.blendColor = instanceRDPParams[instanceIndex].blendColor;
    blInputs.fogColor = instanceRDPParams[instanceIndex].fogColor;
    blInputs.shadeAlpha = shadeColor.a;
    return float4(Blender::run(otherMode, rp.flags, blInputs, combinerColor, false).rgb, 1.0f);
}

void VSMain(
    in uint iVertexId : SV_VertexID
    , in uint iInstanceId : SV_InstanceID
    , out float4 oPosition : SV_POSITION
    , out float2 oUV : TEXCOORD
    , out float4 oSmoothColor : COLOR0
    , out nointerpolation float4 oFlatColor : COLOR1
    , out float4 oFurAnchor : TEXCOORD1
)
{
    // (Anything not drawn is left outside the screen.)
    oPosition = float4(2.0f, 2.0f, 2.0f, 1.0f);
    oUV = 0.0f;
    oSmoothColor = 0.0f;
    oFlatColor = 0.0f;
    oFurAnchor = 0.0f;

    // The tile this blade is in: the slot's tiles for this pass, each with where its blades start among the instances.
    const bool mid = (gConstants.grassShells & RASTER_GRASS_MID) != 0;
    const bool flower = (gConstants.grassShells & RASTER_GRASS_FLOWERS) != 0;
    const GrassSlot slot = grassSlots[gConstants.grassShell - 1];
    const uint first = slot.info.x + (flower ? (slot.info.y + slot.info.z) : (mid ? slot.info.y : 0u));
    const uint count = flower ? slot.flowers.x : (mid ? slot.info.z : slot.info.y);
    if (count == 0) {
        return;
    }

    uint low = 0;
    uint high = count - 1;
    while (low < high) {
        const uint middle = (low + high + 1) / 2;
        if (grassTiles[first + middle].info.z <= iInstanceId) {
            low = middle;
        }
        else {
            high = middle - 1;
        }
    }

    const GrassTileDraw tile = grassTiles[first + low];
    const uint inTile = iInstanceId - tile.info.z;
    if (inTile >= tile.info.y) {
        return;
    }

    // The blade (rt64_grass_blades.h): its place in its tile, its turn and lean, rank, width and height.
    const GrassBlade blade = grassBlades[tile.info.x + inTile];
    const uint place = blade.info.y;
    const float3 root = tile.origin.xyz + float3(float(place & 0x3FFu) * (GRASS_TILE_SIZE / 1023.0f), float(place >> 20) * (tile.origin.w / 4095.0f),
        float((place >> 10) & 0x3FFu) * (GRASS_TILE_SIZE / 1023.0f));
    const float2 turnLean = float2(float((blade.info.z >> 16) & 0xFFu), float(blade.info.z >> 24)) / 255.0f;
    const float2 rankWidth = float2(float(blade.info.w & 0xFFFu) / 4095.0f, float((blade.info.w >> 12) & 0xFFu) / 255.0f);
    const float bladeLength = float(blade.info.w >> 20) * (GRASS_HEIGHT_MAX / 4095.0f);

    // Each blade thins by its own distance from the camera, so blades come and go one at a time and slowly as the
    // camera moves, never a tile at once: the share kept there (FrameParams.grassLod) times its tile's share
    // (asfloat(tile.info.w): the Density's share, eased by the frame budget; over 1.5 for tall grass, kept whole), and
    // a blade whose rank comes near that share grows in or shrinks away over a stretch of distance. The blades kept are
    // drawn wider (Cook et al. 2007, capped at four times), so the field keeps its cover far off.
    const float3 camera = float3(FrParams.grassWorldX.w, FrParams.grassWorldY.w, FrParams.grassWorldZ.w);
    const float bladeDistance = distance(root, camera);
    const float4 lod = FrParams.grassLod;
    const float tileShare = asfloat(tile.info.w);
    // (Past the full reach the share falls with the distance's square. Never nearer.)
    const float farShare = (bladeDistance <= lod.x) ? 1.0f : pow(lod.x / bladeDistance, 2.0f);
    const float fadeShare = saturate((lod.y - bladeDistance) / max(lod.y - lod.z, 1.0f));
    const float keep = max(((tileShare > 1.5f) ? 1.0f : (tileShare * farShare)) * fadeShare, 1e-4f);
    const float shrink = saturate((keep * (1.0f + GrassGrow) - rankWidth.x) / (GrassGrow * keep));
    // (Long grass, in tall tiles, by Long Grass Height: FrameParams.grassStyle.y.)
    // (And by the level's own look: FrameParams.grassLevel.w.)
    float height = bladeLength * FrParams.grassParams.w * shrink * ((tileShare > 1.5f) ? FrParams.grassStyle.y : 1.0f) * FrParams.grassLevel.w;
    // (Seabed weed grows no flowers or clover.)
    if (flower && (FrParams.grassWater.x > 0.0f)) {
        return;
    }
    // A flower is drawn while its own amount rank (its width share) is under Flower Amount (grassStyle.x, a share of the
    // most baked); clovers always are.
    const uint kind = (blade.info.x >> 24) & 0xFu;
    if (flower && (kind != GrassCloverKind) && (rankWidth.y >= FrParams.grassStyle.x)) {
        return;
    }
    // Grass Patches (FrameParams.grassStyle.w, 0 to 1): the grass grows in patches with bare ground between, the
    // stronger the setting the smaller and further apart, shortening towards a patch's edge. The long grass on the
    // lawns' sides stays whole, and a flower or clover outside a patch is left out.
    const float patches = FrParams.grassStyle.w;
    if ((patches > 0.0f) && (tileShare <= 1.5f)) {
        // The two noises summed bunch up round 0.5, so they are spread out again to cover 0 to 1 about evenly, and the
        // setting moves the patch edge across that whole range: at 5% only a few bare spots, at 100% only the highest
        // points of the noise keep grass.
        const float raw = 0.65f * GrassPatchNoise(root.xz / 420.0f) + 0.35f * GrassPatchNoise(root.xz / 160.0f + 17.3f);
        const float n = saturate((raw - 0.5f) * 2.4f + 0.5f);
        const float edge = lerp(0.12f, 0.9f, patches);
        const float patch = smoothstep(edge - 0.06f, edge + 0.06f, n);
        if (flower && (patch < 0.5f)) {
            return;
        }
        height *= patch;
    }
    // Seaweed grows far sparser than grass: a few plants here and there in its clumps, not a lawn of them (by the
    // blade's own hash, not its rank, so it thins evenly at every distance).
    if ((FrParams.grassWater.x > 0.0f) && (frac(turnLean.x * 97.13f + rankWidth.y * 41.7f + root.x * 0.0123f) > 0.1f)) {
        return;
    }
    if (height <= 0.01f) {
        return;
    }
    const float widen = clamp(1.0f / min(keep, 1.0f), 1.0f, 4.0f);
    // Near blades take the far blades' shape (one triangle, broader) over the last part of the near reach, so the hand
    // from one draw to the other doesn't show.
    const float farShape = mid ? 1.0f : saturate((bladeDistance - 0.7f * lod.w) / (0.3f * lod.w));
    // The level's plants (FrameParams.grassWater.y, rt64_grass_blades.h's GRASS_PLANT_*): this blade's form, by its own
    // hash among the level's kinds. Near blades of kelp, ferns and broad leaves are drawn with the finer shape.
    const uint levelPlant = uint(FrParams.grassWater.y + 0.5f);
    const uint plant = flower ? GRASS_PLANT_MEADOW : levelPlant;
    // (The finer shape's own pass: RASTER_GRASS_RIBBON.)
    const bool ribbonMesh = !mid && !flower && ((gConstants.grassShells & RASTER_GRASS_RIBBON) != 0);
    // (Each kind's share by its Amount in Graphics > 3D Grass: GrassKindAmount.)
    const GrassForm form = GrassFormOf(plant, frac(rankWidth.x * 53.7f + turnLean.x * 11.3f));
    // (A flower's own form, by the level's plants and its own hash: FlowerFormOf; worked out in the flower pass only, a
    // blade's being the usual one.)
    const FlowerForm bloom = FlowerFormOf(flower ? levelPlant : GRASS_PLANT_STRAW, frac(turnLean.x * 13.7f + rankWidth.x * 71.3f), kind);
    if ((!flower && (form.height <= 0.0f)) || (flower && (kind != GrassCloverKind) && bloom.hidden)) {
        return;
    }
    // In a level whose plants need the finer shape, its near blades are drawn in two passes: the few that need it with
    // it (RASTER_GRASS_RIBBON), the rest with the simple shape, which is far cheaper (seven corners, not nineteen).
    if (!mid && !flower && GRASS_PLANT_RIBBON(plant) && (ribbonMesh != GrassLeafNeedsRibbon(form.leaf))) {
        return;
    }

    // The blade's corners (SV_VertexID, rt64_grass_blades.h): the root's edges and middle, the bend's edges and middle
    // half way up, and the tip (a far blade uses the root's edges and the tip). Each corner is (across: -1 to 1, along:
    // 0 to 1); the middle ones are the blade's ridge.
    static const float2 bladeCorners[7] = {
        float2(-1.0f, 0.0f), float2(0.0f, 0.0f), float2(1.0f, 0.0f), float2(-0.75f, 0.5f), float2(0.0f, 0.5f), float2(0.75f, 0.5f), float2(0.0f, 1.0f)
    };
    // A flower (its own pass; its colour in the triangle's top bits): a thin stem a little taller than the grass (its
    // first triangle, root to tip), then its head at the tip (FlowerHead below).
    const uint flowerKind = (blade.info.x >> 24) & 0xFu;
    float2 corner = bladeCorners[min(iVertexId, 6u)];
    uint row = 0;
    if (ribbonMesh) {
        // (Six rows of three corners, then the tip.)
        row = min(iVertexId / 3u, 6u);
        corner = (iVertexId >= 18u) ? float2(0.0f, 1.0f) : float2(float(iVertexId % 3u) - 1.0f, float(row) * 0.18f);
    }
    // (The simple blade's middle corners where its form is widest: GrassForm.midAt.)
    if (!flower && !ribbonMesh && (corner.y > 0.0f) && (corner.y < 1.0f)) {
        corner.y = form.midAt;
    }
    // The ridge down the blade's middle (not the tip, not a flower's stem).
    const bool ridge = !flower && (corner.x == 0.0f) && (corner.y < 1.0f);
    if (flower) {
        corner = float2((iVertexId == 0) ? -1.0f : ((iVertexId == 1) ? 1.0f : 0.0f), (iVertexId >= 2) ? 1.0f : 0.0f);
    }
    // (Its edges as wide as its form is there: GrassFormWidth.)
    if (!flower && (corner.x != 0.0f) && (corner.y < 1.0f)) {
        corner.x = sign(corner.x) * GrassFormWidth(form, corner.y, row);
    }
    // (The bend's middle corners move onto the straight sides of the one-triangle blade.)
    if (corner.y < 1.0f) {
        corner.x = lerp(corner.x, sign(corner.x) * (1.0f - corner.y), farShape);
    }

    // Its turn, lean (towards the way it faces), the wind, and Banjo pushing it aside, all as the tip's sideways bend.
    const float turn = turnLean.x * 6.2831853f;
    const float2 facing = float2(cos(turn), sin(turn));
    // Blades small on screen barely sway: with no anti-aliasing a thin blade moving less than a pixel makes its edge
    // pixels blink on and off, and a field of them shimmers. So the wind's movement fades from full on blades over 3.5%
    // of the screen's height to a tenth on ones under 0.5% (the steady lean stays), and far grass holds still.
    const float4 swayRootClip = GrassToClip(root);
    // (Straight up from the root: the matrix's up column times the height, not a whole transform.)
    const float4 swayTipClip = swayRootClip + height * float4(FrParams.grassWorldToClip[0].y, FrParams.grassWorldToClip[1].y, FrParams.grassWorldToClip[2].y, FrParams.grassWorldToClip[3].y);
    const float swayHeight = abs(swayTipClip.y / max(swayTipClip.w, 1e-3f) - swayRootClip.y / max(swayRootClip.w, 1e-3f)) * 0.5f;
    const float sway = lerp(0.1f, 1.0f, saturate((swayHeight - 0.005f) / 0.03f));
    // (Fronds and leaves that hang down again always arch out some way.)
    const float leanAmount = flower ? bloom.lean : ((form.droop > 0.2f) ? (0.45f + 0.35f * turnLean.y) : (turnLean.y * 0.5f * form.lean));
    float2 bend = facing * leanAmount + GrassWind(root.xz, sway) * form.stiff;
    if (FrParams.grassWater.x > 0.0f) {
        // Seabed weed sways slowly back and forth with the water instead of in the wind, each frond a little out of step.
        const float phase = dot(root.xz, float2(0.011f, 0.017f)) + turnLean.x * 6.2831853f;
        const float water = FrParams.grassParams.y;
        bend = facing * (turnLean.y * 0.3f * form.lean) + float2(sin(water * 0.8f + phase), cos(water * 0.6f + phase * 1.3f)) * (0.4f * sway * form.stiff);
    }
    // Banjo treads the grass down: the cell of the trodden ground's map under the blade (FrameParams.grassPress,
    // rt64_grass_blades.h's GRASS_PRESS_*) says when his feet last went over it, which way they pushed it and how near
    // the middle of his path it is. A trodden blade lies down that way, darkened a little, stays down for a while and
    // then rises again slowly, each at its own pace, quickly at first and then ever more slowly, so his path stays
    // trodden long after he has gone. On ground rising the way it was pushed it is kept above the slope (lift).
    // Grass round his body leans out of his way as he goes through it, and grass he runs past ripples
    // (grassTrailBounds.w, his speed). Only blades within the map's circle round him (grassTrailBounds) look at it.
    const float4 player = FrParams.grassPlayer;
    const float4 trailBounds = FrParams.grassTrailBounds;
    float press = 0.0f;
    float lift = 0.0f;
    if ((player.w > 0.0f) && (length(root.xz - trailBounds.xy) < trailBounds.z)) {
        const float4 pressMap = FrParams.grassPress;
        const int2 cell = int2(floor(root.xz / pressMap.x));
        const uint slot = (uint(cell.y & (GRASS_PRESS_SIZE - 1)) * GRASS_PRESS_SIZE + uint(cell.x & (GRASS_PRESS_SIZE - 1))) * 2u;
        const uint word0 = grassPress[slot];
        const uint word1 = grassPress[slot + 1u];
        const uint tag = uint((cell.x >> 8) & 15) | (uint((cell.y >> 8) & 15) << 4);
        const float depth = float(word0 >> 24) / 255.0f;
        const float groundY = float(int(word1 << 16) >> 16);
        // (What trod it was this far above the blade's root: feet on the ground press fully, something up off the ground
        // less, and something in the air, over 32 units up, not at all.)
        const float above = groundY - root.y;
        if ((depth > 0.0f) && (((word1 >> 16) & 0xFFu) == tag) && (above > -40.0f) && (above < 32.0f)) {
            const float age = float((uint(pressMap.y) - (word0 & 0xFFFFu)) & 0xFFFFu);
            const float pace = frac(rankWidth.x * 37.0f + turnLean.x * 3.0f);
            const float back = saturate((age - pressMap.z * (0.7f + 0.6f * pace)) / (pressMap.w * (0.6f + 0.8f * pace)));
            // (Flattest only along the middle of his path, the rest bent over less: a trodden path, not a mown lane.)
            press = smoothstep(0.15f, 0.85f, depth) * (1.0f - back) * (1.0f - back) * saturate(1.0f - max(above - 8.0f, 0.0f) / 24.0f);
            const float angle = float((word0 >> 16) & 0xFFu) * (6.2831853f / 256.0f);
            bend += float2(cos(angle), sin(angle)) * press * 1.3f;
            lift = float(word1 >> 24) / 64.0f;
        }
        const float2 nearAway = root.xz - player.xz;
        const float nearReach = length(nearAway);
        const float brush = smoothstep(0.0f, 1.0f, saturate(1.0f - nearReach / 70.0f)) * saturate(1.0f - abs(root.y - player.y) / 80.0f);
        bend += (nearAway / max(nearReach, 1e-3f)) * brush * 0.6f;
        const float ripple = trailBounds.w * saturate(1.0f - nearReach / 90.0f) * sin(FrParams.grassParams.y * 14.0f - nearReach * 0.15f);
        bend += (nearAway / max(nearReach, 1e-3f)) * ripple * 0.12f;
    }

    // (A blade stepped on may lie flatter than the wind ever bends one. Bent towards ground rising beside it, its tip
    // stays a little above the ground, the slope it stands on being baked with it (blade.info.x), so it never dips into
    // a hillside and comes up out of it again as the wind or Banjo moves it: grass seemed to grow in on slopes.)
    const float bendLength = length(bend);
    const float slopeAngle = float((blade.info.x >> 20) & 0xFu) * (6.2831853f / 16.0f);
    const float slopeSteep = float(blade.info.x >> 28) * 0.25f;
    const float uphill = max(dot(bend, float2(cos(slopeAngle), sin(slopeAngle))), 0.0f) / max(bendLength, 1e-4f);
    const float aboveGround = cos(atan(max(lift, slopeSteep * uphill)) + 0.15f);
    bend *= min(min(bendLength, max(form.maxBend, 0.8f * press)), aboveGround) / max(bendLength, 1e-4f);
    const float t = corner.y;
    const float bladeHeight = flower ? (height * ((kind == GrassCloverKind) ? 0.45f : bloom.stem)) : (height * form.height);
    const float rise = bladeHeight * sqrt(saturate(1.0f - dot(bend, bend)));
    const float curve = lerp(lerp(t * t, t, form.straight), t, farShape);
    // (An arching frond or leaf comes down again towards its tip, never below its root; trodden down, less.)
    float3 along = float3(bend.x * bladeHeight * curve, rise * t - min(form.droop * bladeHeight * (1.0f - press), rise * 0.8f) * t * t * t, bend.y * bladeHeight * curve);
    // Kelp and eelgrass wave: a slow wave runs up each from its root to its tip, each a little out of step.
    const float wavePhase = turnLean.x * 6.2831853f + dot(root.xz, float2(0.013f, 0.007f));
    if ((form.leaf == GrassLeafKelp) || (form.leaf == GrassLeafEel) || (form.leaf == GrassLeafWrack) || (form.leaf == GrassLeafRedWeed)) {
        along += float3(facing.x, 0.0f, facing.y) * (sin(FrParams.grassParams.y * 1.7f - t * 5.0f + wavePhase) * t * bladeHeight * 0.16f * sway);
    }

    // Across the blade, kept at least about a pixel wide on screen so far and edge-on blades don't break up into
    // flickering lines (Persson's phone-wire trick, without its fade, which would need blending).
    // A blade seen edge-on is turned part of the way to face the camera (Ghost of Tsushima's grass), so it never thins
    // to a line. Only from 300 units out, fully from 800: a near blade turning as the camera goes past it swings round
    // and broadens, which reads as grass growing in front of Banjo (L 2026-11-12), and near blades are folded on their
    // ridge, so they never thin to a line anyway.
    float2 side = float2(-facing.y, facing.x);
    const float2 toCamera = camera.xz - root.xz;
    const float cameraDistance = length(toCamera);
    if (cameraDistance > 1e-3f) {
        const float2 cameraSide = float2(-toCamera.y, toCamera.x) / cameraDistance;
        const float edgeOn = 1.0f - abs(dot(side, cameraSide));
        const float turnFar = saturate((cameraDistance - 300.0f) / 500.0f);
        side = normalize(lerp(side, cameraSide * ((dot(side, cameraSide) < 0.0f) ? -1.0f : 1.0f), 0.6f * edgeOn * turnFar) + 1e-5f);
    }
    // (A wide form is drawn a little less wide far off, where it is one triangle.)
    const float formWidth = lerp(form.width, 1.0f + 0.5f * (form.width - 1.0f), farShape);
    float3 across = float3(side.x, 0.0f, side.y) * (GrassMaxWidth * 0.5f * (0.6f + 0.4f * rankWidth.y) * FrParams.grassStyle.z * widen * lerp(1.0f, 1.6f, farShape) * formWidth);
    const float4 rootClip = swayRootClip;
    const float4 sideClip = rootClip + GrassDirToClip(across);
    const float2 pixels = (sideClip.xy / max(sideClip.w, 1e-3f) - rootClip.xy / max(rootClip.w, 1e-3f)) * FbParams.resolution * 0.5f;
    const float pixelWidth = length(pixels);
    // How tall the blade is on screen, as a share of the screen's height: small blades lose their light and dark
    // (GrassDetail below), so their edges can't sparkle and flicker as the wind moves them.
    const float4 tipClip = swayTipClip;
    const float screenHeight = abs(tipClip.y / max(tipClip.w, 1e-3f) - rootClip.y / max(rootClip.w, 1e-3f)) * 0.5f;
    // (Also gone over the last part of the Distance setting, where the blades thin out to none (fadeShare), so the far
    // edge of the grass melts into the ground's own colour instead of ending in a line.)
    const float detail = saturate((screenHeight - 0.004f) / 0.016f) * fadeShare;
    if (rootClip.w > 1e-3f) {
        across *= clamp(FrParams.grassParams.z / max(pixelWidth, 1e-3f), 1.0f, 3.0f);
    }

    float3 world = root + along + across * corner.x;
    // The ridge stands out of the blade's face, a quarter of its width, so the blade is a shallow fold (fading to flat
    // as near blades take the far shape).
    if (ridge) {
        world += float3(facing.x, 0.0f, facing.y) * (length(across) * 0.5f * (1.0f - farShape) * form.ridge);
    }
    // A kelp ribbon's and sea lettuce's edges ruffle, rippling in and out of their face along their length.
    if (((form.leaf == GrassLeafKelp) || (form.leaf == GrassLeafLettuce)) && (corner.x != 0.0f) && (t > 0.0f)) {
        world += float3(facing.x, 0.0f, facing.y) * (length(across) * ((form.leaf == GrassLeafLettuce) ? 0.45f : 0.3f) * abs(corner.x) * sin(t * 17.0f + FrParams.grassParams.y * 2.3f + wavePhase) * (1.0f - farShape));
    }
    // A flower's head: five petals round a centre, in a plane facing up and tilted towards the camera, so it reads
    // as a flower from above and from the side. A petal is a diamond (its base at the centre, its two sides, its tip),
    // lighter at its tip; the centre is a small square raised a little over the petals.
    const bool head = flower && (iVertexId >= 3);
    bool flowerCentre = false;
    float headShade = 1.0f;
    uint headDiamond = 0;
    uint headPoint = 0;
    if (flower) {
        if (head) {
            // (Six diamonds of four corners: its middle, one side, its far point, the other side.)
            const uint hv = iVertexId - 3;
            const uint diamond = hv / 4;
            const uint petalPoint = hv % 4;
            headDiamond = diamond;
            headPoint = petalPoint;
            const float3 tip = root + float3(bend.x * bladeHeight, rise, bend.y * bladeHeight);
            const float3 toCamera = normalize(camera - tip + float3(0.0f, 1e-3f, 0.0f));
            const bool cloverHead = (kind == GrassCloverKind);
            // (A clover's leaves lie flatter than a flower's head.)
            // (Each clover tilted its own way, a little.)
            const float2 cloverTilt = (float2(frac(turnLean.x * 7.31f), frac(turnLean.x * 3.17f)) - 0.5f) * 0.5f;
            const float3 facingUp = cloverHead ? normalize(float3(cloverTilt.x, 0.9f, cloverTilt.y) + toCamera * 0.2f)
                : normalize(float3(0.0f, 0.65f, 0.0f) + toCamera * bloom.face);
            const float3 a = normalize(cross(facingUp, (abs(facingUp.y) < 0.99f) ? float3(0.0f, 1.0f, 0.0f) : float3(1.0f, 0.0f, 0.0f)));
            const float3 b = cross(facingUp, a);
            // (The head shrinks away over the last stretch of the flowers' reach, so they fade out instead of popping.)
            // (A third of flowers are big ones: their lean is 1; a clover's size varies with it.)
            const float size = cloverHead ? lerp(0.75f, 1.15f, turnLean.y) : (((turnLean.y > 0.5f) ? 1.6f : 1.0f) * bloom.size);
            // (Flowers reach as far as the grass, thinning as the blades do; far off they are drawn bigger, up to two and a
            // half times, so they still read as flowers and not specks. Clovers keep their size.)
            const float far = cloverHead ? 1.0f : lerp(1.0f, 2.5f, saturate((bladeDistance - 900.0f) / 4000.0f));
            const float radius = (cloverHead ? 6.5f : (4.0f + 0.07f * bladeHeight)) * size * far;
            float3 offset = 0.0f;
            // (Where the head's diamonds are placed from: the stem's tip, the ball's middle, the rosette's base.)
            float3 anchor = tip;
            const float3 up = float3(0.0f, 1.0f, 0.0f);
            if (cloverHead) {
                // Three leaves, each two round lobes side by side (a heart): each lobe a diamond from the centre out.
                const uint leaf = diamond / 2;
                const uint lobe = diamond % 2;
                const float base = turnLean.x * 6.2831853f + float(leaf) * 2.0943951f + ((lobe == 0) ? -0.33f : 0.33f);
                const float angle = base + ((petalPoint == 1) ? -0.55f : ((petalPoint == 3) ? 0.55f : 0.0f));
                const float reach = (petalPoint == 0) ? 0.0f : ((petalPoint == 2) ? 1.0f : 0.7f);
                // (Cupped: the lobe's edge and tip curl up a little out of the leaf's plane.)
                offset = (a * cos(angle) + b * sin(angle)) * radius * reach + facingUp * (radius * ((petalPoint == 2) ? 0.18f : ((petalPoint == 0) ? 0.0f : 0.1f)));
                headShade = (petalPoint == 2) ? 1.12f : ((petalPoint == 0) ? 0.82f : 1.0f);
            }
            else {
                const float2 square = (petalPoint == 0) ? float2(-1.0f, 0.0f) : ((petalPoint == 1) ? float2(0.0f, -1.0f) : ((petalPoint == 2) ? float2(1.0f, 0.0f) : float2(0.0f, 1.0f)));
                const float side = (petalPoint == 1) ? -1.0f : ((petalPoint == 3) ? 1.0f : 0.0f);
                const float n = float(max(bloom.petals, 1u));
                const bool isCentre = bloom.centre && (diamond == 5);
                const bool unused = !isCentre && (diamond >= bloom.petals);
                headShade = (petalPoint == 2) ? (1.15f + bloom.glow) : ((petalPoint == 0) ? 0.8f : 1.0f);
                if (bloom.layout == FlowerLayoutBall) {
                    // Ribs from the ball's bottom to its top, each spanning its share of the way round, so together
                    // they close into a ribbed ball; the centre a small square on top.
                    anchor = tip + up * (radius * bloom.reach);
                    const float ballRadius = radius * bloom.reach;
                    if (isCentre) {
                        offset = (float3(1.0f, 0.0f, 0.0f) * square.x + float3(0.0f, 0.0f, 1.0f) * square.y) * (ballRadius * 0.3f) + up * (ballRadius * 1.02f);
                        flowerCentre = true;
                    }
                    else if (!unused) {
                        const float slice = 3.1415927f / n;
                        const float angle = turnLean.x * 6.2831853f + float(diamond) * 2.0f * slice + side * slice;
                        offset = (petalPoint == 0) ? -up * ballRadius : ((petalPoint == 2) ? up * ballRadius
                            : float3(cos(angle), 0.0f, sin(angle)) * (ballRadius * bloom.waist));
                        headShade = (petalPoint == 2) ? 1.15f : ((petalPoint == 0) ? 0.75f : 1.0f);
                    }
                }
                else if (bloom.layout == FlowerLayoutRosette) {
                    // Leaves or shards rising out from the root, each steeper or longer a little by its own hash; the
                    // centre a small raised square (a cone).
                    if (isCentre) {
                        offset = (float3(1.0f, 0.0f, 0.0f) * square.x + float3(0.0f, 0.0f, 1.0f) * square.y) * (radius * 0.35f) + up * (radius * 0.6f);
                        flowerCentre = true;
                    }
                    else if (!unused) {
                        const float own = frac(float(diamond) * 0.618f + turnLean.x * 3.0f);
                        const float angle = turnLean.x * 6.2831853f + float(diamond) * (6.2831853f / n) + own * 0.4f;
                        const float rising = bloom.cup + (own - 0.5f) * 0.3f;
                        const float3 outward = float3(cos(angle), 0.0f, sin(angle));
                        const float3 dir = outward * cos(rising) + up * sin(rising);
                        const float3 sideways = float3(-outward.z, 0.0f, outward.x);
                        const float leafLength = radius * bloom.reach * (0.75f + 0.5f * own);
                        offset = (petalPoint == 0) ? float3(0.0f, 0.0f, 0.0f) : ((petalPoint == 2) ? dir * leafLength
                            : (dir * (leafLength * bloom.waist) + sideways * (leafLength * bloom.spread * side)));
                    }
                }
                else if (bloom.layout == FlowerLayoutBalloon) {
                    // A disc facing the camera, a little taller than wide: five diamonds from its middle out, each
                    // reaching its far point and both sides to the rim, so together they close into a round ten-sided
                    // outline instead of the pointed ball the ribs made. Their shared middle is pulled up and to the
                    // left and drawn pale, a shine, and the rim is lit from that side and darker on the other, so it
                    // reads as round. The sixth diamond is the knot under it, where the stalk meets it.
                    const float3 view = normalize(float3(toCamera.x, 0.0f, toCamera.z) + float3(1e-4f, 0.0f, 0.0f));
                    const float3 right = normalize(cross(up, view));
                    const float ballRadius = radius * bloom.reach;
                    anchor = tip + up * (ballRadius * 1.25f);
                    const float2 light = float2(-0.6f, 0.8f);
                    if (diamond < 5u) {
                        const float slice = 6.2831853f / 10.0f;
                        const float angle = 1.5707963f + float(diamond) * 2.0f * slice + side * slice;
                        const float2 rim = float2(cos(angle), sin(angle));
                        if (petalPoint == 0) {
                            offset = (right * light.x + up * light.y) * (ballRadius * 0.35f);
                            flowerCentre = true;
                            headShade = 1.1f;
                        }
                        else {
                            offset = right * (rim.x * ballRadius) + up * (rim.y * ballRadius * 1.15f);
                            headShade = 0.8f + 0.25f * dot(rim, light);
                        }
                    }
                    else {
                        // (The knot: a small point under the balloon, its two sides tucked into its bottom.)
                        const float knot = ballRadius * 0.22f;
                        offset = (petalPoint == 0) ? (-up * (ballRadius * 1.05f)) : ((petalPoint == 2) ? (-up * (ballRadius * 1.15f + knot))
                            : (-up * (ballRadius * 1.1f + knot) + right * (knot * side)));
                        headShade = 0.7f;
                    }
                }
                else if (bloom.layout == FlowerLayoutBells) {
                    // Bells hung along the stem's top, alternately either side of it, facing the camera: a point where
                    // it hangs, flared corners and a scalloped rim.
                    if (!unused) {
                        const float alongStem = 1.0f - float(diamond) * 0.17f;
                        const float3 cameraSide = normalize(cross(up, toCamera) + float3(1e-4f, 0.0f, 0.0f));
                        const float3 hang = lerp(root, tip, alongStem) + float3(facing.x, 0.0f, facing.y) * (radius * 0.35f * (((diamond & 1u) != 0) ? -1.0f : 1.0f));
                        const float bell = radius * bloom.reach;
                        anchor = hang;
                        offset = (petalPoint == 0) ? float3(0.0f, 0.0f, 0.0f) : ((petalPoint == 2) ? -up * (bell * 0.8f)
                            : (-up * (bell * 0.95f) + cameraSide * (bell * 0.5f * side)));
                        headShade = (petalPoint == 0) ? 1.1f : 0.95f;
                    }
                }
                else {
                    // Petals round a centre (the first one longer by lip, the sides turned by twist, the tips raised by
                    // cup and the middle by dome); the centre a small square raised over them.
                    if (isCentre) {
                        offset = (a * square.x + b * square.y) * (radius * 0.32f) + facingUp * (0.4f + radius * bloom.dome * 1.05f);
                        flowerCentre = true;
                    }
                    else if (!unused) {
                        const float base = turnLean.x * 6.2831853f + float(diamond) * (6.2831853f / n);
                        const float angle = base + side * bloom.spread + ((side != 0.0f) ? bloom.twist : 0.0f);
                        const float reach = ((petalPoint == 0) ? 0.0f : ((petalPoint == 2) ? 1.0f : bloom.waist)) * bloom.reach * ((diamond == 0) ? (1.0f + bloom.lip) : 1.0f);
                        const float lift = (petalPoint == 0) ? bloom.dome : (bloom.cup * ((petalPoint == 2) ? 1.0f : 0.45f));
                        offset = (a * cos(angle) + b * sin(angle)) * (radius * reach) + facingUp * (radius * lift);
                    }
                }
            }
            world = anchor + offset;
        }
        else {
            world = root + along + across * corner.x * (0.12f * bloom.stemWidth);
        }
    }
    float4 position = GrassToClip(world);
    position.xy = position.xy * gConstants.screenScale + gConstants.screenOffset * position.w;
    oPosition = position;

    // The ground under the root: its texture coordinates and colours, from where the blade stands on its triangle.
    const uint triangleStart = slot.info.w + (blade.info.x & 0xFFFFFu) * 3;
    const uint3 v = uint3(grassIndices[triangleStart], grassIndices[triangleStart + 1], grassIndices[triangleStart + 2]);
    const float2 weights = float2(float(blade.info.z & 0xFFu), float((blade.info.z >> 8) & 0xFFu)) / 255.0f;
    const float3 w = float3(weights.x, weights.y, 1.0f - weights.x - weights.y);
    oUV = grassTexcoords[v.x] * w.x + grassTexcoords[v.y] * w.y + grassTexcoords[v.z] * w.z;
    const float4 smoothColor = grassColors[v.x] * w.x + grassColors[v.y] * w.y + grassColors[v.z] * w.z;
    // Darker at the root and a little lighter at the tip, each blade a shade apart; the pixel shader draws this colour
    // as it is (RasterPS.hlsl, RASTER_GRASS_BLADES).
    // A gust bending the blade over catches the light: the tips brighten as the wind's waves roll across the field.
    const float gust = saturate(length(GrassWind(root.xz, 1.0f)) / max(FrParams.grassParams.x, 0.05f) - 0.6f) * sway;
    // (The ridge lighter, the edges darker, so a blade looks rounded; a far blade's tip stands in for its ridge.)
    const float roundShade = flower ? 1.0f : lerp(1.12f, 0.88f, abs(corner.x));
    // (Faded towards the ground's own flat colour as the blade gets small on screen, Jahrmann & Wimmer's trick against
    // far grass shimmering: a small blade's edges then can't flicker, there being no light and dark to catch.)
    const float shade = lerp(0.97f, lerp(0.78f, 1.15f + 0.1f * gust, t) * (0.94f + 0.12f * rankWidth.x) * roundShade, detail);
    // (A yellow flower has an orange centre, the others a yellow one.)
    const float3 centreColor = (flowerKind == 1) ? float3(0.85f, 0.42f, 0.1f) : float3(1.0f, 0.8f, 0.15f);
    const bool flowerHead = head && (kind != GrassCloverKind);
    float3 bloomColor = flowerCentre ? centreColor : GrassFlowerColors[min(max(flowerKind, 1u) - 1, 5u)];
    // (A level's own flower: its petals colorA at their base and colorB at their tip, or by turns, an orchid's lip
    // colorB, its centre its own.)
    if (flowerHead && !bloom.generic) {
        bloomColor = flowerCentre ? bloom.centreColor : ((bloom.alternate ? ((headDiamond & 1u) != 0u) : (headPoint == 2u)) ? bloom.colorB : bloom.colorA);
        if ((bloom.lip > 0.0f) && (headDiamond == 0u) && !flowerCentre) {
            bloomColor = bloom.colorB;
        }
    }
    // (A toadstool's stalk is its own colour.)
    const bool stemPainted = flower && !head && (kind != GrassCloverKind) && (bloom.stemColor.a > 0.5f);
    const float4 flowerColor = flowerHead ? float4(bloomColor, 1.0f) : (stemPainted ? float4(bloom.stemColor.rgb, 1.0f) : float4(0.0f, 0.0f, 0.0f, 0.0f));
    oSmoothColor = GrassGroundColor(oUV, smoothColor, grassColors[v.x], head ? headShade : shade, flowerColor);
    // The level's tint (FrameParams.grassLevel), more towards the tips: dry grass in Terrydactyland, frosty on the icy
    // side of Hailfire Peaks, kelp green on the seabed. Not on flower heads.
    // (A blade's form may take less of it and has its own colour on top: ferns and jungle leaves greener.)
    if (!head) {
        oSmoothColor.rgb = saturate(oSmoothColor.rgb * lerp(float3(1.0f, 1.0f, 1.0f), FrParams.grassLevel.rgb, (0.4f + 0.6f * t) * form.tint) * form.color);
        // Frosted spikes: iced white towards their tips.
        if (form.leaf == GrassLeafFrost) {
            const float light = dot(oSmoothColor.rgb, float3(0.3f, 0.59f, 0.11f));
            oSmoothColor.rgb = lerp(oSmoothColor.rgb, float3(0.88f, 0.94f, 1.0f) * saturate(0.55f + light), 0.55f * t * t * t);
        }
    }
    // Clumps of grass a shade apart, some lighter and a little yellower, as a meadow is (not the flowers' heads).
    if (!flowerHead) {
        const float2 clumpCell = floor(root.xz / 70.0f);
        const float clumpTint = frac(sin(dot(clumpCell, float2(12.9898f, 78.233f))) * 43758.5453f);
        oSmoothColor.rgb = saturate(oSmoothColor.rgb * lerp(float3(0.93f, 0.95f, 0.95f), float3(1.1f, 1.08f, 0.88f), clumpTint));
    }
    // A blade's tip a little warmer and sunnier than its root (Banjo-Tooie's painted grass is lighter at the top), and
    // trodden blades a little darker. Near blades only: far ones keep the ground's own colour (detail).
    if (!flower) {
        oSmoothColor.rgb = saturate(oSmoothColor.rgb * lerp(float3(1.0f, 1.0f, 1.0f), float3(1.06f, 1.05f, 0.88f), t * t * detail) * (1.0f - 0.07f * press));
        // Light through the blades: seen towards the sun, a blade's upper part glows a warm yellow-green, as sunlit
        // grass does against the light. Judged by the way the camera faces across the ground, not up or down: the
        // game's camera looks down at Banjo and the sun is low, so in three dimensions the two would hardly ever line
        // up. Only as much as the ground there is lit by the game's own shading (its vertex colour), so grass in shade
        // and in caves stays as it is; near blades only (detail), so far grass holds still.
        const float3 sun = FrParams.grassSun.xyz;
        const float2 lookAcross = (root.xz - camera.xz) / max(length(root.xz - camera.xz), 1e-3f);
        const float2 sunAcross = sun.xz / max(length(sun.xz), 1e-3f);
        const float against = smoothstep(0.45f, 0.95f, dot(lookAcross, sunAcross)) * saturate(sun.y * 4.0f);
        const float lit = saturate((dot(smoothColor.rgb, float3(0.3f, 0.59f, 0.11f)) - 0.35f) / 0.4f);
        const float glow = against * lit * t * detail * FrParams.grassSun.w;
        oSmoothColor.rgb = saturate(oSmoothColor.rgb * lerp(float3(1.0f, 1.0f, 1.0f), float3(1.28f, 1.32f, 0.82f), glow));
    }
    // A clover's leaves: the ground's colour made lighter and fresher, towards a clover green, so they stand out from it.
    if (head && (kind == GrassCloverKind)) {
        const float light = dot(oSmoothColor.rgb, float3(0.3f, 0.59f, 0.11f));
        oSmoothColor.rgb = saturate(lerp(oSmoothColor.rgb * 1.12f, float3(0.42f, 0.78f, 0.3f) * (0.6f + light), 0.2f));
    }
    // A blade's own colouring: greyed (GrassForm.sat), banded every other row (horsetails), and its upper part a colour of
    // its own (seed heads, embers, ice, pennant tips), lit by the ground's shading or, glowing, by itself; far blades
    // less of it (detail), so it melts into the ground's colour with them.
    if (!flower) {
        const float grey = dot(oSmoothColor.rgb, float3(0.3f, 0.59f, 0.11f));
        oSmoothColor.rgb = lerp(float3(grey, grey, grey), oSmoothColor.rgb, form.sat);
        if ((form.bands > 0.0f) && ribbonMesh && ((row & 1u) != 0u)) {
            oSmoothColor.rgb *= 1.0f - form.bands;
        }
        const float tipShare = form.tipColor.a * saturate((t - form.tipFrom) / max(1.0f - form.tipFrom, 1e-3f)) * lerp(0.5f, 1.0f, detail);
        if (tipShare > 0.0f) {
            const float3 lit = form.tipColor.rgb * saturate(smoothColor.rgb * 1.15f) * shade;
            oSmoothColor.rgb = lerp(oSmoothColor.rgb, saturate(lerp(lit, form.tipColor.rgb, form.tipGlow)), tipShare);
        }
    }
    oFlatColor = oSmoothColor;
    oFurAnchor = float4(corner.x, t, rankWidth.x, 0.0f);
}
