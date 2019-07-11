/**
 * Asset classes
 *
 * @file assets.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ASSETS_HPP
#define ASSETS_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "tile.hpp"

#define HEAD 0
#define HEAD_SIZE_X 5.f
#define HEAD_SIZE_Y 5.f
#define BODY 1
#define BODY_SIZE_X 5.f
#define BODY_SIZE_Y 10.f
#define HEAD_BODY_DELTA 5

namespace X11 {
  class Tile;
  class Villager {
  private:
    std::array<sf::Shape*, 2> shapes;
    Tile& destination_tile;
  public:
    Villager();
    explicit Villager(Tile& starting_tile);
    ~Villager() = default;
    void set_destination(Tile& tile_to_move);
    Tile& get_destination();

    std::array<sf::Shape*, 2>& get_shapes() { return this->shapes; }
  };

}

#endif
