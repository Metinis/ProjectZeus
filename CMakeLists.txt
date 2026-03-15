cmake_minimum_required(VERSION 3.21)

project(ZeusWorkspace)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(ZeusEngineCore)
add_subdirectory(ZeusEditor)
add_subdirectory(ZeusBox)

add_custom_target(run
  COMMAND $<TARGET_FILE:ZeusEditor>
  DEPENDS ZeusEditor
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
 
