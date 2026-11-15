//
// RT64
//

#pragma once
// Include guard as well as #pragma once (see rt64_grass_blades.h: DXC reaches this file by two spellings of its path).
#ifndef RT64_EXT_SHARED_RT64_CRITTERS_H
#define RT64_EXT_SHARED_RT64_CRITTERS_H

#include "shared/rt64_hlsl.h"

// Banjo-Tooie: small creatures in the 3D grass (rt64_critters.cpp): insects, birds, frogs and crabs over the levels'
// ground, and fish, sea turtles, rays and bubbles under the sea. The CPU moves them and sends one Critter each a frame;
// CritterVS.hlsl builds each one's chunky low-poly shape from SV_VertexID alone (no vertex buffers), and the whole lot
// is one instanced draw of CRITTER_VERTICES vertices,
// coloured by the uber pixel shader's 3D grass path (RASTER_GRASS_BLADES: the colour comes from the vertices).
//
// The shape: a body of nine rings of CRITTER_SIDES corners between two tips (the four rings a kind gives, one between
// each two of them and one rounding off each end: 18 triangles a side), and three pairs of wings, fins, legs or
// flippers of two quads each, bent at the middle (24 triangles), drawn as a plain list of triangles.
#define CRITTER_SIDES 12
#define CRITTER_BODY_TRIANGLES (18 * CRITTER_SIDES)
#define CRITTER_WING_TRIANGLES 24
#define CRITTER_VERTICES ((CRITTER_BODY_TRIANGLES + CRITTER_WING_TRIANGLES) * 3)
#define CRITTER_MAX 256

// The kinds (Critter.look.x), each with colour variants (look.y; CritterVS.hlsl's CritterColours).
#define CRITTER_BEE 0
#define CRITTER_BUTTERFLY 1
#define CRITTER_DRAGONFLY 2
#define CRITTER_MOTH 3
#define CRITTER_FIREFLY 4
#define CRITTER_BEETLE 5
#define CRITTER_FLY 6
#define CRITTER_FISH 7
// Birds (in the sky and on the ground), frogs and crabs on the ground, and a sea turtle, a ray and bubbles under the sea.
#define CRITTER_BIRD 8
#define CRITTER_FROG 9
#define CRITTER_CRAB 10
#define CRITTER_TURTLE 11
#define CRITTER_RAY 12
#define CRITTER_BUBBLE 13
// A round eye, white with a black pupil at its front: a frog's, a turtle's and a fish's are each one of these, set on
// the head by the CPU (rt64_critters.cpp's AddEyes).
#define CRITTER_EYE 14
#define CRITTER_KINDS 15

#ifdef HLSL_CPU
namespace interop {
#endif
    // One creature this frame, in 48 bytes: where it is (xyz) and its size in world units (w, 0: not drawn); which way
    // it faces (x: yaw, a turn round the world's up from +x towards +z, in radians), its nose up or down (y, radians),
    // how its wings or fins stand (z: the wings' angle up from flat in radians, or a fish's tail swish), and its bank
    // (w, radians); its kind, colour variant, brightness (0 to 255, 255 full) and a glow (0 to 255, a firefly's tail).
    struct Critter {
        float4 position;
        float4 pose;
        uint4 look;
    };
#ifdef HLSL_CPU
};
#endif

#endif // RT64_EXT_SHARED_RT64_CRITTERS_H
