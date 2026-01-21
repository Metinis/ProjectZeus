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

add_custom_target(ZeusScripts ALL)

foreach(src ${SCRIPT_SOURCES})
    get_filename_component(script_name ${src} NAME_WE)

    add_library(${script_name} SHARED ${src})

    target_compile_definitions(${script_name}
    PRIVATE PLUGIN_EXPORTS)

    target_link_libraries(${script_name} PRIVATE ZeusEngineCore)

    set_target_properties(${script_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${SCRIPT_OUTPUT_DIR}
        LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_OUTPUT_DIR} 
        ARCHIVE_OUTPUT_DIRECTORY ${SCRIPT_OUTPUT_DIR}
    )

    if(WIN32)
        set_target_properties(${script_name} PROPERTIES
            PREFIX ""             
            SUFFIX ".dll"
        )
    elseif(APPLE)
        set_target_properties(${script_name} PROPERTIES
            PREFIX "lib"
            SUFFIX ".dylib"
        )
    else()
        set_target_properties(${script_name} PROPERTIES
            PREFIX "lib"
            SUFFIX ".so"
        )
    endif()

    add_dependencies(ZeusScripts ${script_name})
    if(TARGET ZeusEditor)
        add_dependencies(ZeusEditor ${script_name})
    endif()
endforeach()
