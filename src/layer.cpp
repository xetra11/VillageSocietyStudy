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
  Layer::Layer() : tileGrid{Grid(GRID_WIDTH * GRID_HEIGHT)} {}

  Layer::~Layer() = default;

  void Layer::draw_layer(sf::RenderWindow& window) {
    for (auto& tile : this->tileGrid) {
      sf::RectangleShape& shape = tile.get_tile_shape();
      window.draw(shape);
    }
  }

  Tile* Layer::getTileAtPosition(sf::Vector2i position) {
    sf::Vector2i gridVector((position.x / TILE_SIZE), (position.y / TILE_SIZE - 1));
    spdlog::info("gridvector x {0} y {1}", gridVector.x, gridVector.y);
    Tile& tile = this->tileGrid[gridVector.x + (gridVector.y * GRID_WIDTH)];
    return &tile;
  }

  Grid& Layer::get_grid() { return this->tileGrid; }

  void Layer::setGrid(Grid grid) { this->tileGrid = std::move(grid); }

  AssetList& Layer::get_assets() { return this->assets; }


}

#endif
