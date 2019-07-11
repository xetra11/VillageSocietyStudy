#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#define ESTATE_COUNT 8
#define COMMUNITY_COUNT 3

#define ESTATE_SHAPE_SIZE 30.f
#define COMMUNITY_SHAPE_SIZE 15.f
#define WORKSPACE_SHAPE_SIZE 20.f
#define HOUSE_SHAPE_SIZE 10.f
#define TILE_SIZE 10.f

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define GRID_WIDTH WINDOW_WIDTH/TILE_SIZE
#define GRID_HEIGHT WINDOW_HEIGHT/TILE_SIZE

#define MAX_GRID_INDEX GRID_WIDTH*GRID_HEIGHT

#endif
