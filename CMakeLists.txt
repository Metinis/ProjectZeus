cmake_minimum_required(VERSION 3.28)
project(ZeusEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR}/include/glfw/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/include/glfw)

set(SOURCES
        src/main.cpp
        src/core/Application.cpp
        src/core/Application.h
        src/core/Window.cpp
        src/core/Window.h
        src/renderer/IRenderer.cpp
        src/renderer/IRenderer.h
        src/renderer/OpenGLRenderer.cpp
        src/renderer/OpenGLRenderer.h
        src/renderer/VulkanRenderer.cpp
        src/renderer/VulkanRenderer.h
        src/renderer/RendererAPI.h
)

add_executable(ZeusEngine ${SOURCES})

if (APPLE)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(COREVIDEO_LIBRARY CoreVideo REQUIRED)

    target_link_libraries(ZeusEngine PRIVATE
            ${COCOA_LIBRARY}
            ${IOKIT_LIBRARY}
            ${COREVIDEO_LIBRARY}
    )

    find_package(Vulkan REQUIRED)
    target_link_libraries(ZeusEngine PRIVATE Vulkan::Vulkan)

elseif(WIN32)
    find_package(Vulkan REQUIRED)
    target_link_libraries(ZeusEngine PRIVATE Vulkan::Vulkan)
endif()

target_link_libraries(ZeusEngine PRIVATE glfw)
