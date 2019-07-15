#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#define ESTATE_COUNT 8
#define VILLAGER_COUNT 10
#define COMMUNITY_COUNT 3

#define TILE_SIZE 20.f
#define WINDOW_WIDTH 860
#define WINDOW_HEIGHT 720

#define GRID_WIDTH WINDOW_WIDTH/TILE_SIZE*2
#define GRID_HEIGHT WINDOW_HEIGHT/TILE_SIZE*2

#define MAX_GRID_INDEX GRID_WIDTH*GRID_HEIGHT

#endif
