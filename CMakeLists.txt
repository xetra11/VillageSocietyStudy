cmake_minimum_required(VERSION 3.1)
project(vilsoc)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

set(LIBS sfml-graphics sfml-window sfml-system)

if (WIN32)
    set(SFML_DIR "C:\\Program Files (x86)\\SFML-2.5.1")
    find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

    if(NOT TARGET spdlog)
        # Stand-alone build
        set(SPDLOG_DIR "C:\\Program Files (x86)\\spdlog-1.3.1")
        find_package(SPDLOG REQUIRED)
    endif()

endif (WIN32)

add_executable(vilsoc main.cpp ${SOURCES})
if (WIN32)
  target_link_libraries(vilsoc ${LIBS} spdlog::spdlog)
endif (WIN32)
if (UNIX)
  target_link_libraries(vilsoc ${LIBS})
endif (UNIX)
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/logs")
