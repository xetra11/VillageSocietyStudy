/**
 * The layer interface that renders different tilegrid layer
 *
 * @file layer.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef LAYER_CPP
#define LAYER_CPP

#include "layer.hpp"

namespace X11 {
  Layer::Layer(std::vector<Tile> grid){this->tileGrid = grid;}
  virtual Layer::~Layer();
  void Layer::drawLayer(sf::RenderWindow& window){
    for (auto& tile : this->tileGrid) {
      sf::RectangleShape& shape = tile.getTileShape();
      window.draw(shape);
    }
  }
  Tile* Layer::getTileAtPosition(sf::Vector2i position){
    sf::Vector2i gridVector((position.x/TILE_SIZE), (position.y/TILE_SIZE-1));
    spdlog::info("gridvector x {0} y {1}", gridVector.x, gridVector.y);
    Tile& tile = this->grid[gridVector.x + (gridVector.y * GRID_WIDTH)];
    return &tile;
  }
}


#endif
