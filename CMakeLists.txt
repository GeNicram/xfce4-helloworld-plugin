cmake_minimum_required(VERSION 2.8)

project(hello-plugin)

# version number
set(hello-plugin_version_major "1")
set(hello-plugin_version_minor "0")
set(hello-plugin_version_micro "0")
set(hello-plugin_version "${hello-plugin_version_major}.${hello-plugin_version_minor}.${hello-plugin_version_micro}")

include(GNUInstallDirs)

add_subdirectory(icons)
add_subdirectory(src)
add_subdirectory(po)
