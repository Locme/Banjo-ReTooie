# NVIDIA DLSS runtime

`nvngx_dlss.dll` is NVIDIA's DLSS runtime. It is not part of this project and is **not covered by the GPL**: it is
NVIDIA's software under the NVIDIA RTX SDKs licence in `LICENSE.txt`, loaded at run time as a separate file.
The build downloads it from https://github.com/NVIDIA/DLSS (commit pinned in `CMakeLists.txt`, SHA-256 checked)
and puts it beside the executable on Windows. This product contains DLSS technology from NVIDIA.
