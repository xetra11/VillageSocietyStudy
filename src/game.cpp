/**
 * the game system
 *
 * @file game.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef GAME_CPP
#define GAME_CPP

#include "game.hpp"

namespace X11 {

  void Game::set_selected_tile_position(int grid_index){ this->selected_tile_position = grid_index;}
  int Game::get_selected_tile_position() { return this->selected_tile_position;}

}
#endif
