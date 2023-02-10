cmake_minimum_required(VERSION 3.25)

project("Glai")

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Glai)
add_subdirectory(Game)
add_subdirectory(sandbox)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT sandbox )
