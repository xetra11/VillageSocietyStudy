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
  typedef std::vector<sf::Shape*> AssetList;

  class Layer {
  private:
    Grid tileGrid;
  public:
    Layer();
    virtual ~Layer();
    AssetList assets;
    void draw_layer(sf::RenderWindow& window);
    Tile* getTileAtPosition(sf::Vector2i position);
    Grid& get_grid();
    void setGrid(Grid grid);
  };
}


#endif
