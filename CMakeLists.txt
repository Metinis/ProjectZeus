cmake_minimum_required(VERSION 3.21)

project(ZeusWorkspace)

if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY
        "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
        CACHE STRING "" FORCE
    )
endif()


add_subdirectory(ZeusEngineCore)
add_subdirectory(ZeusEditor)
add_subdirectory(ZeusBox)
 