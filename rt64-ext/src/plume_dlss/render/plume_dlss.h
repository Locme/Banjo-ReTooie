//
// RT64
//

#pragma once

#include <string>
#include <unordered_set>

// Banjo-Tooie: plume_vulkan.cpp (built with DLSS_ENABLED) asks for the Vulkan extensions NGX needs for DLSS when it makes the
// instance and the device. They are looked up in rt64-ext/src/render/rt64_dlss.cpp.
namespace plume {
    struct VulkanDevice;

    struct DLSS {
        static std::unordered_set<std::string> getRequiredInstanceExtensionsVulkan();
        static std::unordered_set<std::string> getRequiredDeviceExtensionsVulkan(VulkanDevice *device);
    };
}
