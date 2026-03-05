cmake_minimum_required(VERSION 3.10)

project(VulkanC VERSION 1.0 LANGUAGES C)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(vulkan_app
    src/main.c
)

target_link_libraries(vulkan_app
    Vulkan::Vulkan
    glfw
)
