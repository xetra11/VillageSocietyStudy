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

#define ESTATE_COUNT 5
#define COMMUNITY_COUNT 5

using namespace std;

namespace X11 {

  Initializer::Initializer() {}
  Initializer::~Initializer() {}

  bool Initializer::isOccupied(sf::IntRect rect) {
    for (auto occupied : this->occupiedAreas) {
      if (occupied.intersects(rect)) {
        return true;
      }
    }
    return false;
  }

  void Initializer::initEstates(std::vector<Tile*>& grid) {
    sf::Vector2i randomPos = this->getRandomPosition();
    affectFillColorRadius(grid, randomPos, 1, sf::Color(103, 128, 159, 100));
  }

  void Initializer::affectFillColorRadius(std::vector<Tile*>& grid, sf::Vector2i& center, int radius, sf::Color color) {
    grid[center.x * center.y]->getTileShape().setFillColor(color); // center
    grid[(center.x * center.y) - 1]->getTileShape().setFillColor(color); // left
    grid[(center.x * center.y) + 1]->getTileShape().setFillColor(color); // right
    grid[(center.x * center.y) - GRID_WIDTH]->getTileShape().setFillColor(color); // top
    grid[(center.x * center.y) + GRID_WIDTH]->getTileShape().setFillColor(color); // bottom
    grid[(center.x * center.y) - GRID_WIDTH-1]->getTileShape().setFillColor(color); // top-left
    grid[(center.x * center.y) - GRID_WIDTH+1]->getTileShape().setFillColor(color); // top-right
    grid[(center.x * center.y) + GRID_WIDTH-1]->getTileShape().setFillColor(color); // bottom-left
    grid[(center.x * center.y) + GRID_WIDTH+1]->getTileShape().setFillColor(color); // bottom-right
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

  sf::Vector2i Initializer::getRandomPosition() {
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
