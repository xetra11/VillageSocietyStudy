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
  typedef std::vector<Tile> Grid;
  typedef std::vector<Asset> AssetList;

  class Layer {
  private:
    Grid tileGrid;
    AssetList assets;
  public:
    Layer();
    virtual ~Layer();
    void draw_layer(sf::RenderWindow& window);
    Tile* getTileAtPosition(sf::Vector2i position);
    Grid& get_grid();
    void setGrid(Grid grid);
    AssetList& get_assets();
  };
}


#endif
