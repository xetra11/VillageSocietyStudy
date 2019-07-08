/**
 * The grid tile class
 *
 * @file tile.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef TILE_HPP
#define TILE_HPP

#include "config.hpp"
#include "assets.hpp"
#include <SFML/Graphics.hpp>

namespace X11 {

  enum class TileType : char {
    Empty = 'n', Estate = 'e', Workshop = 'w', House = 'h', Community = 'c', Villager = 'v'
  };

  class Tile {
  private:
    sf::RectangleShape tile_shape;
    sf::IntRect boundaries;
    TileType type;
    std::vector<Tile*> zone_tiles;
    int grid_position;
  public:
    Tile();
    explicit Tile(sf::Vector2f position);
    bool is_selected;
    virtual ~Tile();
    sf::RectangleShape& get_tile_shape();
    sf::IntRect get_boundaries();
    void set_type(TileType type);
    TileType get_type();
    std::vector<Tile*>& get_zone_tiles();
    void set_zone_tiles(std::vector<Tile*> zone_tiles);
    static void set_color_by_type(TileType type, sf::Shape& shape);
    void set_grid_position(int grid_index);
    int get_grid_position();
    void place_onto(sf::Shape* shape);
    void place_onto(Villager& villager);
  };

}

#endif
