/**
 * Initializes VilSoc assets
 *
 * @file initializer.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef INITIALIZER_CPP
#define INITIALIZER_CPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "initializer.hpp"
#include <random>

using namespace std;

namespace X11 {

  Initializer::Initializer() {}
  Initializer::~Initializer() {}

  void Initializer::initEstates(std::vector<Tile*>& grid) {
    for (int count = 1; count <= ESTATE_COUNT; count++) {
      sf::Vector2i randomPos = this->getRandomPosition(grid, true);
      affectRectangle(grid, randomPos, 4, TileType::Estate);
    }
  }

  void Initializer::initCommunityAreas(std::vector<Tile*>& grid) {
    for (int count = 1; count <= COMMUNITY_COUNT; count++) {
      sf::Vector2i randomPos = this->getRandomPosition(grid, true);
      affectRectangle(grid, randomPos, 1, TileType::Community);
    }
  }

  void Initializer::affectRectangle(std::vector<Tile*>& grid, sf::Vector2i& topleft, int size, TileType type) {
    for (int width = 0; width < size; width++) {
      for (int height = 0; height < size; height++) {
        grid[(topleft.x * topleft.y) + width + (height * GRID_WIDTH)]->setType(type);
      }
    }
  }

  std::vector<Tile*> Initializer::initWorldGrid() {
    spdlog::info("build grid");
    spdlog::info("grid width: {}", GRID_WIDTH);
    spdlog::info("grid height: {}", GRID_HEIGHT);

    std::vector<Tile*> worldGrid(GRID_WIDTH * GRID_HEIGHT);
    for (int height = 0; height < GRID_HEIGHT; height++) {
      for (int width = 0; width < GRID_WIDTH; width++) {
        sf::Vector2f position(width * TILE_SIZE, height * TILE_SIZE);
        auto newTile = new Tile(position);
        worldGrid[width + (height * GRID_WIDTH)] = newTile;
      }
    }
    return worldGrid;
  }

  sf::Vector2i Initializer::getRandomPosition(std::vector<Tile*>& grid, bool allowOccupied) {
    sf::Vector2i randomPos;
    bool isOccupied;
    do {
      std::random_device seeder;
      std::mt19937 engine(seeder());
      std::uniform_int_distribution<int> distX(0, GRID_WIDTH);
      std::uniform_int_distribution<int> distY(0, GRID_HEIGHT);
      int randX = distX(engine);
      int randY = distY(engine);
      randomPos = sf::Vector2i(randX, randY);
      isOccupied = (grid[randX * randY]->getType() != TileType::Empty);
    } while(isOccupied && !allowOccupied);
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
