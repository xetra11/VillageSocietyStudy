/**
 * The grid tile class
 *
 * @file tile.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef TILE_HPP
#define TILE_HPP

#include "config.hpp"
#include <SFML/Graphics.hpp>

namespace X11 {

  enum class TileType : char { Empty='n', Estate='e', Workshop='w', House='h', Community='c', Villager='v'};

  class Tile {
  private:
    sf::RectangleShape tileShape;
    sf::IntRect boundaries;
    TileType type;
    std::vector<Tile*> zoneTiles;
    int gridPosition;
  public:
    Tile();
    Tile(sf::Vector2f position);
    bool isSelected;
    virtual ~Tile();
    sf::RectangleShape& getTileShape();
    sf::IntRect getBoundaries();
    void setType(TileType type);
    TileType getType();
    std::vector<Tile*>& getZoneTiles();
    void setZoneTiles(std::vector<Tile*> zoneTiles);
    static void setColorByType(TileType type, sf::Shape& shape);
    void setGridPosition(int gridIndex);
    int getGridPosition();
  };

}

#endif
