cmake_minimum_required(VERSION 2.8.9)
project(vilsoc)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

set (LIBS sfml-graphics sfml-window sfml-system)

add_executable(vilsoc main.cpp ${SOURCES})
target_link_libraries(vilsoc ${LIBS})
