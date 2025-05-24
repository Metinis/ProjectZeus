cmake_minimum_required(VERSION 3.28)
project(ZeusEditor)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(${CMAKE_SOURCE_DIR}/include/glfw/include)

include_directories(${CMAKE_SOURCE_DIR}/include/glad/include)

add_library(glad STATIC include/glad/src/glad.c)

add_subdirectory(${CMAKE_SOURCE_DIR}/include/glfw)
add_subdirectory(../ZeusEngineCore ZeusEngineCoreBuild)


set(IMGUI_SRC
        include/imgui/imgui.cpp
        include/imgui/imgui_draw.cpp
        include/imgui/imgui_tables.cpp
        include/imgui/imgui_widgets.cpp
        include/imgui/imgui_demo.cpp  # Optional
)

add_library(imgui STATIC ${IMGUI_SRC})
target_include_directories(imgui PUBLIC include/imgui)


set(SOURCES
        src/main.cpp
        src/core/Application.cpp
        src/core/Application.h
        src/core/Window.cpp
        src/core/Window.h
        src/imgui/ImGUILayer.cpp
        src/imgui/ImGUILayer.h
        src/imgui/ImGUILayerOpenGL.cpp
        src/imgui/ImGUILayerOpenGL.h
        src/imgui/ImGUILayerVulkan.cpp
        src/imgui/ImGUILayerVulkan.h
        src/imgui/ImGUILayer.cpp
        src/imgui/ImGUILayerOpenGL.cpp
)

add_executable(ZeusEditor ${SOURCES})

if (APPLE)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(COREVIDEO_LIBRARY CoreVideo REQUIRED)

    target_link_libraries(ZeusEditor PRIVATE
            ${COCOA_LIBRARY}
            ${IOKIT_LIBRARY}
            ${COREVIDEO_LIBRARY}
    )

    find_package(Vulkan REQUIRED)
    target_link_libraries(ZeusEditor PRIVATE Vulkan::Vulkan)

elseif(WIN32)
    find_package(Vulkan REQUIRED)
    target_link_libraries(ZeusEditor PRIVATE Vulkan::Vulkan)
endif()

target_link_libraries(ZeusEditor PRIVATE glfw glad imgui)
set(IMGUI_BACKEND_SRC
        include/imgui/backends/imgui_impl_glfw.cpp
        include/imgui/backends/imgui_impl_opengl3.cpp
        #include/imgui/backends/imgui_impl_vulkan.cpp
)

target_sources(imgui PRIVATE ${IMGUI_BACKEND_SRC})
target_include_directories(imgui PUBLIC include/imgui/backends)
target_link_libraries(ZeusEditor PRIVATE ZeusEngineCore)


