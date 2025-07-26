cmake_minimum_required(VERSION 3.28)
project(ZeusWorkspace)

if(MINGW)
    # Apply these flags *globally* to all targets
    add_compile_options(-static-libgcc)
    # Let stdc++ be linked dynamically to avoid multiple definitions
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -Wl,-Bdynamic")
endif()

add_subdirectory(ZeusEngineCore)
add_subdirectory(ZeusEditor)
