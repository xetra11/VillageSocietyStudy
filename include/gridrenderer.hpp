/**
 * helper class for rendering functions for the tile grid
 *
 * @file gridrenderer.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef GRIDRENDERER_HPP
#define GRIDRENDERER_HPP

#include "tile.hpp"

namespace X11 {
  class GridRenderer{
  public:
    static void emptyTiles(std::vector<Tile>& tileGrid);
  };
}

#endif
