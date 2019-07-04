/**
 * The layer interface that renders different tilegrid layer
 *
 * @file layer.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef LAYER_HPP
#define LAYER_HPP

#include "tile.hpp"
#include "assets.hpp"

namespace X11 {

  class Layer {
  private:
    std::vector<Tile> tileGrid;
    std::vector<Asset> assets;
  public:
    Layer();
    virtual ~Layer();
    void draw_layer(sf::RenderWindow& window);
    Tile* getTileAtPosition(sf::Vector2i position);
    std::vector<Tile>& get_grid();
    void setGrid(std::vector<Tile> grid);
    std::vector<Asset>& get_assets();
  };
}


#endif
