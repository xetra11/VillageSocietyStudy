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
    static void empty_tiles(std::vector<Tile>& tile_grid);
    static void outline_tile(Tile& tile);
    static void highlight_tile(Tile& tile);
    static int map_coords_to_grid_pos(sf::Vector2f coord_pos);
  };
}

#endif
