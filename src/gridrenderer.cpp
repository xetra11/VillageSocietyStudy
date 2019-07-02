/**
 * helper class for rendering functions for the tile grid
 *
 * @file gridrenderer.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef GRIDRENDERER_CPP
#define GRIDRENDERER_CPP

#include "gridrenderer.hpp"

namespace X11 {
  void GridRenderer::emptyTiles(std::vector<Tile>& tileGrid) {
    for (Tile& tile : tileGrid) {
      Tile::setColorByType(tile.getType(), tile.getTileShape());
      tile.getTileShape().setOutlineColor(sf::Color::Transparent);
    }
  }
  void GridRenderer::outlineTile(Tile& tile) {
    tile.getTileShape().setOutlineColor(sf::Color::White);
    tile.getTileShape().setOutlineThickness(0.8f);
  }
  void GridRenderer::highlightTile(Tile& tile) {
    sf::RectangleShape& tileShape = tile.getTileShape();
    sf::Color color = tileShape.getFillColor();
    color.a = 255;
    tileShape.setFillColor(color);
  }
  int GridRenderer::mapCoordsToGridPos(sf::Vector2f coordPos) {
    sf::Vector2i gridVector((coordPos.x/TILE_SIZE), (coordPos.y/TILE_SIZE-1));
    int gridIndex = gridVector.x + (gridVector.y * GRID_WIDTH);
    return gridIndex;
  }
}

#endif
