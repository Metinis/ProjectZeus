cmake_minimum_required(VERSION 3.16)
project(ZeusBox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SCRIPT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets/scripts)

set(SCRIPT_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets/scripts/bin)

file(GLOB SCRIPT_SOURCES
        ${SCRIPT_DIR}/*.cpp
)
message(STATUS "Script sources: ${SCRIPT_SOURCES}")

set(COMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets/components)

set(COMP_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets/components/bin)

file(GLOB COMP_SOURCES
        ${COMP_DIR}/*.cpp
)

message(STATUS "Comp sources: ${COMP_SOURCES}")

add_custom_target(ZeusScripts ALL)

foreach(src ${COMP_SOURCES})
    get_filename_component(comp_name ${src} NAME_WE)

    add_library(${comp_name} SHARED ${src})

    target_link_libraries(${comp_name} PRIVATE ZeusEngineCore)

    set_target_properties(${comp_name} PROPERTIES
            PREFIX "lib"
            SUFFIX ".dylib"
            LIBRARY_OUTPUT_DIRECTORY ${COMP_OUTPUT_DIR}
    )

    add_dependencies(ZeusScripts ${comp_name})
    add_dependencies(ZeusEditor ${comp_name})
endforeach()

foreach(src ${SCRIPT_SOURCES})
    get_filename_component(script_name ${src} NAME_WE)

    add_library(${script_name} SHARED ${src})

    target_link_libraries(${script_name} PRIVATE ZeusEngineCore)

    set_target_properties(${script_name} PROPERTIES
            PREFIX "lib"
            SUFFIX ".dylib"
            LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_OUTPUT_DIR}
    )

    add_dependencies(ZeusScripts ${script_name})
    add_dependencies(ZeusEditor ${script_name})
endforeach()

