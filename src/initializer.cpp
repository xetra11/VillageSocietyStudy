/**
 * Initializes VilSoc assets
 *
 * @file initializer.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef INITIALIZER_CPP
#define INITIALIZER_CPP

#include <iostream>

#include "initializer.hpp"

namespace X11 {

  void Initializer::init_zones(TileType type, Grid& grid, int size, int amount) {
    sf::Vector2i random_pos;
    for (int count = 1; count <= amount; count++) {
      bool is_occupied;
      int tries = 0;
      do {
        tries++;
        random_pos = Initializer::get_random_position(grid);
        is_occupied = Initializer::is_rect_area_occupied(grid, random_pos, size);
      } while (is_occupied && tries < MAX_RANDOM_TRIES);
      affect_rectangle(grid, random_pos, size, type);
    }
  }

  void Initializer::init_assets(Layer& assets) {
  }

  std::vector<Tile*> Initializer::get_zones_by_type(TileType type, Layer& layer) {
    std::vector<Tile*> zones;
    Grid& grid = layer.get_grid();
    for (Tile& tile : grid) {
      if (tile.get_type() == type) {
        zones.push_back(&tile);
      }
    }
    return zones;
  }

  void Initializer::affect_rectangle(Grid& grid, sf::Vector2i& topleft, int size, TileType type) {
    std::vector<Tile*> zone_tiles;
    for (int width = 0; width < size; width++) {
      for (int height = 0; height < size; height++) {
        int index = (topleft.x * topleft.y) + width + (height * GRID_WIDTH);
        Tile& tile = grid[index];
        tile.set_type(type);
        tile.set_grid_position(index);
        zone_tiles.push_back(&tile);
      }
    }
    //each zone tile stores the array of zone tiles
    for (auto zoneTile : zone_tiles) {
      zoneTile->set_zone_tiles(zone_tiles);
    }
  }

  bool Initializer::is_rect_area_occupied(Grid& grid, sf::Vector2i& topleft, int size) {
    for (int width = 0; width < size; width++) {
      for (int height = 0; height < size; height++) {
        int index = (topleft.x * topleft.y) + width + (height * GRID_WIDTH);
        Tile& tile = grid[index];
        bool is_occupied = tile.get_type() != TileType::Empty;
        if (is_occupied) { return true; }
      }
    }
    return false;
  }

  void Initializer::init_layer(Layer& layer) {
    spdlog::info("grid width: {}", GRID_WIDTH);
    spdlog::info("grid height: {}", GRID_HEIGHT);

   Grid& grid = layer.get_grid();

    for (int height = 0; height < GRID_HEIGHT; height++) {
      for (int width = 0; width < GRID_WIDTH; width++) {
        sf::Vector2f coord_position(width * TILE_SIZE, height * TILE_SIZE);
        Tile new_tile(coord_position);
        int index = width + (height * GRID_WIDTH);
        new_tile.set_grid_position(index);
        grid[index] = new_tile;
      }
    }
  }

  void Initializer::init_background_layer(Layer& layer) {
    spdlog::info("init background layer");
    Initializer::init_layer(layer);
    Grid& grid = layer.get_grid();
    // setup initial zone
    spdlog::info("setup initial village zones");
//    Initializer::init_zones(TileType::Estate, grid, 4, ESTATE_COUNT);
    Initializer::init_zones(TileType::House, grid, 1, VILLAGER_COUNT);
    Initializer::init_zones(TileType::Community, grid, 2, COMMUNITY_COUNT);
    Initializer::init_zones(TileType::Workshop, grid, 1, VILLAGER_COUNT);
    spdlog::info("zones initialized");
  }

  void Initializer::init_foreground_layer(Layer& layer) {
    Initializer::init_layer(layer);
    Grid& grid = layer.get_grid();
    spdlog::info("setup foreground layer");
    spdlog::info("foreground initialized");
  }

  void Initializer::init_menu_layer(Layer& layer) {
    spdlog::info("setup menu layer");
    Initializer::init_notification_bar(layer);
    spdlog::info("menu initialized");
  }

  void Initializer::init_scene_layer(Layer& layer) {
    spdlog::info("init scene layer");
    Initializer::init_layer(layer);
    Grid& grid = layer.get_grid();
    // setup initial zones
  }

  sf::Vector2i Initializer::get_random_position(Grid& grid) {
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> distX(0, GRID_WIDTH);
    std::uniform_int_distribution<int> distY(0, GRID_HEIGHT);
    int randX = distX(engine);
    int randY = distY(engine);
    sf::Vector2i random_pos(randX, randY);
    return random_pos;
  }

  sf::Vector2i Initializer::getRandomPosition(sf::IntRect boundaries) {
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> distX(boundaries.left, boundaries.left + boundaries.width);
    std::uniform_int_distribution<int> distY(boundaries.top, boundaries.top + boundaries.height);
    int randX = distX(engine);
    int randY = distY(engine);
    sf::Vector2i random_pos(randX, randY);
    return random_pos;
  }

  void Initializer::init_game(Game& game, Layer& layer) {
    spdlog::info("init game");
    std::vector<Tile*> house_zones = Initializer::get_zones_by_type(TileType::House, layer);
    std::vector<Tile*> workplaces = Initializer::get_zones_by_type(TileType::Workshop, layer);
    std::vector<Tile*> community_areas = Initializer::get_zones_by_type(TileType::Community, layer);
    game.homes = house_zones;
    game.workplaces = workplaces;
    game.community_areas = community_areas;
    Initializer::init_villagers(game);
  }

  void Initializer::init_villagers(Game& game) {
    for (int index = 0; index < VILLAGER_COUNT; index++) {
      Tile* home = game.homes[index];
      Tile* workplace = game.workplaces[index];
      Tile* community = game.community_areas[0];
      Villager villager = Villager(home);
      villager.daily_destinations.insert(std::pair<TaskState, Tile*>(TaskState::Home, home));
      villager.daily_destinations.insert(std::pair<TaskState, Tile*>(TaskState::Work, workplace));
      villager.daily_destinations.insert(std::pair<TaskState, Tile*>(TaskState::Community, community));
      villager.set_speed(1.f);
      game.add_villager(villager);
    }
  }

  void Initializer::init_notification_bar(Layer& layer) {
    sf::Shape* notification_bar = new sf::RectangleShape(sf::Vector2f(100.f, 100.f));
    layer.assets.push_back(notification_bar);
  }

}

#endif
