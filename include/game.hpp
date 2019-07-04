/**
 * the game system
 *
 * @file game.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

namespace X11 {
  class Game {
  private:
    int selected_tile_position;
  public:
    int get_selected_tile_position();
    void set_selected_tile_position(int grid_index);
  };
}

#endif
