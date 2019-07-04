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
  void GridRenderer::empty_tiles(Grid& tile_grid) {
    for (Tile& tile : tile_grid) {
      Tile::set_color_by_type(tile.get_type(), tile.get_tile_shape());
      tile.get_tile_shape().setOutlineColor(sf::Color::Transparent);
    }
  }
  void GridRenderer::outline_tile(Tile& tile) {
    tile.get_tile_shape().setOutlineColor(sf::Color::White);
    tile.get_tile_shape().setOutlineThickness(-0.8f);
  }
  void GridRenderer::highlight_tile(Tile& tile) {
    sf::RectangleShape& tile_shape = tile.get_tile_shape();
    sf::Color color = tile_shape.getFillColor();
    color.a = 255;
    tile_shape.setFillColor(color);
  }
  int GridRenderer::map_coords_to_grid_pos(sf::Vector2f coord_pos) {
    sf::Vector2i grid_vector((coord_pos.x / TILE_SIZE), (coord_pos.y / TILE_SIZE));
    int grid_index = grid_vector.x + (grid_vector.y * GRID_WIDTH);
    return grid_index;
  }
}

#endif
