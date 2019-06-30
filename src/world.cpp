/**
 * The world container
 *
 * @file world.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef WORLD_CPP
#define WORLD_CPP

#include "world.hpp"

namespace X11 {
  World::World() {
    spdlog::info("create world");
  }
  World::~World(){}

  void World::drawAssets(sf::RenderWindow& window) {
    this->drawGrid(window);
  }

  void World::drawGrid(sf::RenderWindow& window) {
    for (auto tile : this->grid) {
      sf::RectangleShape& shape = tile.getTileShape();
      window.draw(shape);
    }
  }

  void World::setWorldGrid(std::vector<Tile> grid) {this->grid = grid;}
  std::vector<Tile>& World::getWorldGrid() {return this->grid;}

  Tile* World::getTileAtPosition(sf::Vector2i position){
    sf::Vector2i gridVector((position.x/TILE_SIZE), (position.y/TILE_SIZE-1));
    spdlog::info("gridvector x {0} y {1}", gridVector.x, gridVector.y);
    Tile& tile = this->grid[gridVector.x + (gridVector.y * GRID_WIDTH)];
    return &tile;
  }
};

#endif
