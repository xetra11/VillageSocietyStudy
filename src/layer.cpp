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
  Layer::Layer() : tileGrid{std::vector<Tile>(GRID_WIDTH * GRID_HEIGHT)}{}
  Layer::~Layer() {}
  void Layer::drawLayer(sf::RenderWindow& window){
    for (auto& tile : this->tileGrid) {
      sf::RectangleShape& shape = tile.getTileShape();
      window.draw(shape);
    }

    if (this->assets.size() > 0) {
      for(auto& asset : assets) {
        for(auto& shape : asset.getShapes()) {
          window.draw(*shape);
        }
      }
    } else {
      spdlog::info("no assets to draw");
    }

  }

  Tile* Layer::getTileAtPosition(sf::Vector2i position){
    sf::Vector2i gridVector((position.x/TILE_SIZE), (position.y/TILE_SIZE-1));
    spdlog::info("gridvector x {0} y {1}", gridVector.x, gridVector.y);
    Tile& tile = this->tileGrid[gridVector.x + (gridVector.y * GRID_WIDTH)];
    return &tile;
  }

  std::vector<Tile>& Layer::getGrid() { return this->tileGrid;}
  void Layer::setGrid(std::vector<Tile> grid) { this->tileGrid = grid; }

  std::vector<Asset>& Layer::getAssets() { return this->assets; }
}

#endif
