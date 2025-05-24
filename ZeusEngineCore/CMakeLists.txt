cmake_minimum_required(VERSION 3.28)
project(ZeusEngineCore)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Engine source files
set(SOURCES
        src/renderer/IRenderer.cpp
        src/renderer/OpenGLRenderer.cpp
        src/renderer/VulkanRenderer.cpp
)

# Engine public headers
set(HEADERS
        include/ZeusEngineCore/IRenderer.h
        include/ZeusEngineCore/OpenGLRenderer.h
        include/ZeusEngineCore/VulkanRenderer.h
        include/ZeusEngineCore/RendererAPI.h
)

# Create static library
add_library(ZeusEngineCore STATIC ${SOURCES} ${HEADERS})

target_include_directories(ZeusEngineCore PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Platform-specific dependencies
if (APPLE)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(COREVIDEO_LIBRARY CoreVideo REQUIRED)

    target_link_libraries(ZeusEngineCore PRIVATE
            ${COCOA_LIBRARY}
            ${IOKIT_LIBRARY}
            ${COREVIDEO_LIBRARY}
    )

    find_package(Vulkan REQUIRED)
    target_link_libraries(ZeusEngineCore PRIVATE Vulkan::Vulkan)

elseif(WIN32)
    find_package(Vulkan REQUIRED)
    target_link_libraries(ZeusEngineCore PRIVATE Vulkan::Vulkan)
endif()
