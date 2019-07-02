/**
 * Initializes VilSoc assets
 *
 * @file initializer.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef INITIALIZER_CPP
#define INITIALIZER_CPP

#include "initializer.hpp"

namespace X11 {

  void Initializer::initZones(TileType type, std::vector<Tile>& grid, int size, int amount) {
    sf::Vector2i randomPos;
    for (int count = 1; count <= amount; count++) {
      bool isOccupied;
      do {
        randomPos = Initializer::getRandomPosition(grid);
        isOccupied = Initializer::isRectAreaOccupied(grid, randomPos, size);
      } while (isOccupied);
      affectRectangle(grid, randomPos, size, type);
    }
  }

  void Initializer::initAssets(std::vector<Asset>& assets) {
    Villager* villager = new Villager();
    assets.push_back(*villager);
  }

  void Initializer::affectRectangle(std::vector<Tile>& grid, sf::Vector2i& topleft, int size, TileType type) {
    std::vector<Tile*> zoneTiles;
    for (int width = 0; width < size; width++) {
      for (int height = 0; height < size; height++) {
        int index = (topleft.x * topleft.y) + width + (height * GRID_WIDTH);
        Tile& tile = grid[index];
        tile.setType(type);
        tile.setGridPosition(index);
        zoneTiles.push_back(&tile);
      }
    }
    //each zone tile stores the array of zone tiles
    for (auto zoneTile : zoneTiles) {
      zoneTile->setZoneTiles(zoneTiles);
    }
  }

    bool Initializer::isRectAreaOccupied(std::vector<Tile>& grid, sf::Vector2i& topleft, int size) {
      bool isOccupied = false;
      for (int width = 0; width < size; width++) {
        for (int height = 0; height < size; height++) {
          int index = (topleft.x * topleft.y) + width + (height * GRID_WIDTH);
          Tile& tile = grid[index];
          isOccupied = tile.getType() != TileType::Empty;
          if (isOccupied) { return true; }
        }
      }
      return false;
    }

    void Initializer::initLayer(Layer& layer) {
      spdlog::info("grid width: {}", GRID_WIDTH);
      spdlog::info("grid height: {}", GRID_HEIGHT);

      std::vector<Tile>& grid = layer.getGrid();

      for (int height = 0; height < GRID_HEIGHT; height++) {
        for (int width = 0; width < GRID_WIDTH; width++) {
          sf::Vector2f coordPosition(width * TILE_SIZE, height * TILE_SIZE);
          Tile newTile(coordPosition);
          int index = width + (height * GRID_WIDTH);
          newTile.setGridPosition(index);
          grid[index] = newTile;
        }
      }
    }

    void Initializer::initBackgroundLayer(Layer& layer) {
      Initializer::initLayer(layer);
      std::vector<Tile>& grid = layer.getGrid();
      // setup initial zones
      spdlog::info("setup initial village zones");
      Initializer::initZones(TileType::Estate, grid, 4, ESTATE_COUNT);
      Initializer::initZones(TileType::Community, grid, 2, COMMUNITY_COUNT);
      Initializer::initZones(TileType::Workshop, grid, 1, ESTATE_COUNT);
      Initializer::initZones(TileType::House, grid, 1, ESTATE_COUNT);
      spdlog::info("zones initialized");
    }

    void Initializer::initSceneLayer(Layer& layer) {
      Initializer::initLayer(layer);
      std::vector<Tile>& grid = layer.getGrid();
      // setup initial zones
      spdlog::info("setup initial scene assets");
      Initializer::initAssets(layer.getAssets());
      spdlog::info("assets initialized");
    }

    sf::Vector2i Initializer::getRandomPosition(std::vector<Tile>& grid) {
      std::random_device seeder;
      std::mt19937 engine(seeder());
      std::uniform_int_distribution<int> distX(0, GRID_WIDTH);
      std::uniform_int_distribution<int> distY(0, GRID_HEIGHT);
      int randX = distX(engine);
      int randY = distY(engine);
      sf::Vector2i randomPos(randX, randY);
      return randomPos;
    }

    sf::Vector2i Initializer::getRandomPosition(sf::IntRect boundaries) {
      std::random_device seeder;
      std::mt19937 engine(seeder());
      std::uniform_int_distribution<int> distX(boundaries.left, boundaries.left + boundaries.width);
      std::uniform_int_distribution<int> distY(boundaries.top, boundaries.top + boundaries.height);
      int randX = distX(engine);
      int randY = distY(engine);
      sf::Vector2i randomPos(randX, randY);
      return randomPos;
    }

  }

#endif
