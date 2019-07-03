cmake_minimum_required(VERSION 3.1)
project(vilsoc)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

set(LIBS sfml-graphics sfml-window sfml-system)

if (WIN32)
    set(SFML_DIR "C:\\Program Files (x86)\\SFML-2.5.1")
    find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
endif (WIN32)

add_executable(vilsoc main.cpp ${SOURCES})
target_link_libraries(vilsoc ${LIBS})
