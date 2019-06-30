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
}

#endif
