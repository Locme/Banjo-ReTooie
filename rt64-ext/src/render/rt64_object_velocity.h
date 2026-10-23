//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_OBJECT_VELOCITY_H
#define RT64_EXT_RENDER_RT64_OBJECT_VELOCITY_H

#include "rt64_descriptor_sets.h"

namespace RT64 {
    // Banjo-Tooie: the objects' velocity pass (ObjectVelocityVS.hlsl): the world positions and the world velocities
    // RT64 worked out for the frame.
    struct ObjectVelocityDescriptorSet : RenderDescriptorSetBase {
        uint32_t worldPos;
        uint32_t worldVel;

        ObjectVelocityDescriptorSet(RenderDevice *device = nullptr) {
            builder.begin();
            worldPos = builder.addStructuredBuffer(1);
            worldVel = builder.addStructuredBuffer(2);
            builder.end();

            if (device != nullptr) {
                create(device);
            }
        }
    };
};

#endif // RT64_EXT_RENDER_RT64_OBJECT_VELOCITY_H
