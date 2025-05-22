cmake_minimum_required(VERSION 3.28)
project(ZeusEngine)

set(CMAKE_CXX_STANDARD 26)

add_executable(ZeusEngine src/main.cpp
        src/core/Application.cpp
        src/core/Application.h
        src/core/Window.cpp
        src/core/Window.h
        src/core/Window.cpp
        src/core/Window.h
        src/renderer/IRenderer.cpp
        src/renderer/IRenderer.h
        src/renderer/OpenGLRenderer.cpp
        src/renderer/OpenGLRenderer.h
        src/renderer/VulkanRenderer.cpp
        src/renderer/VulkanRenderer.h)
