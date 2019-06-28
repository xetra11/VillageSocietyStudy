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
#include <random>
#include "initializer.hpp"

using namespace std;

namespace X11 {

  Initializer::Initializer() {}
  Initializer::~Initializer() {}

  void Initializer::initObjects(TileType type, std::vector<Tile*>& grid, int size, int amount) {
    sf::Vector2i randomPos;
    for (int count = 1; count <= amount; count++) {
      bool isOccupied;
      do {
        randomPos = this->getRandomPosition(grid);
        isOccupied = this->isRectAreaOccupied(grid, randomPos, size);
      } while (isOccupied);
      affectRectangle(grid, randomPos, size, type);
    }
  }

  void Initializer::affectRectangle(std::vector<Tile*>& grid, sf::Vector2i& topleft, int size, TileType type) {
    for (int width = 0; width < size; width++) {
      for (int height = 0; height < size; height++) {
        int index = (topleft.x * topleft.y) + width + (height * GRID_WIDTH);
        Tile* tile = grid[index];
        tile->setType(type);
        tile->setId(index);
      }
    }
  }

  bool Initializer::isRectAreaOccupied(std::vector<Tile*>& grid, sf::Vector2i& topleft, int size) {
    bool isOccupied = false;
    for (int width = 0; width < size; width++) {
      for (int height = 0; height < size; height++) {
        isOccupied = grid[(topleft.x * topleft.y) + width + (height * GRID_WIDTH)]->getType() != TileType::Empty;
        if (isOccupied) { return true; }
      }
    }
    return false;
  }

  std::vector<Tile*> Initializer::initWorldGrid() {
    spdlog::info("build grid");
    spdlog::info("grid width: {}", GRID_WIDTH);
    spdlog::info("grid height: {}", GRID_HEIGHT);

    std::vector<Tile*> worldGrid(GRID_WIDTH * GRID_HEIGHT);
    for (int height = 0; height < GRID_HEIGHT; height++) {
      for (int width = 0; width < GRID_WIDTH; width++) {
        sf::Vector2f position(width * TILE_SIZE, height * TILE_SIZE);
        Tile* newTile = new Tile(position);
        int index = width + (height * GRID_WIDTH);
        worldGrid[index] = newTile;
        newTile->setId(index);
      }
    }
    return worldGrid;
  }

  sf::Vector2i Initializer::getRandomPosition(std::vector<Tile*>& grid) {
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
