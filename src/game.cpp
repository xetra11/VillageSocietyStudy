/**
 * the game system
 *
 * @file game.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef GAME_CPP
#define GAME_CPP

#include <iostream>
#include "game.hpp"
namespace X11 {

  void Game::set_selected_tile_position(int grid_index) { this->selected_tile_position = grid_index; }

  int Game::get_selected_tile_position() { return this->selected_tile_position; }

  void Game::move_villagers() {
    for (Villager& villager : this->villager_list) {
      villager.move_to_destination(villager.get_speed());
    }
  }

  void Game::update_daily_tasks(Grid& background_grid) {
  }

}

#endif
