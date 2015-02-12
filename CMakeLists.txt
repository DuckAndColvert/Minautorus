project(minautorus)
set(EXECUTABLE_OUTPUT_PATH bin/)
cmake_minimum_required(VERSION 2.8)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML2 REQUIRED sfml-graphics>=2.1 sfml-audio>=2.1)

file(
GLOB_RECURSE

src_path

src/*.cpp
include/*.hpp

)

add_definitions( -std=c++11 )

include_directories(
include/
)

add_executable(
minautorus

${src_path}

)

target_link_libraries(
minautorus
sfml-audio
sfml-graphics
sfml-window
sfml-system
)