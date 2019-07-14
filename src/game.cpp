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
#include "initializer.hpp"

namespace X11 {
  Game::Game() : daily_state {TaskState::Home} { }

  void Game::set_selected_tile_position(int grid_index) { this->selected_tile_position = grid_index; }

  int Game::get_selected_tile_position() { return this->selected_tile_position; }

  void Game::move_villagers() {
    for (Villager& villager : this->villager_list) {
      villager.move_to_destination(villager.get_speed());
    }
  }

  void Game::update_destination() {
    for (Villager& villager: this->villager_list) {
      if (this->daily_state == TaskState::Home) {
        villager.set_destination(villager.daily_destinations.at(TaskState::Home));
      } else if (this->daily_state == TaskState::Work) {
        villager.set_destination(villager.daily_destinations.at(TaskState::Work));
      } else if (this->daily_state == TaskState::Community) {
        villager.set_destination(villager.daily_destinations.at(TaskState::Community));
      }
    }
  }

  void Game::change_daily_state() {
    if (this->tick % 10 == 0) {
      this->tick = 1;
      if (this->daily_state == TaskState::Home) {
        this->daily_state = TaskState::Work;
        spdlog::info("statechange to work");
      } else if (this->daily_state == TaskState::Work) {
        this->daily_state = TaskState::Community;
        spdlog::info("statechange  to community");
      } else if (this->daily_state == TaskState::Community) {
        this->daily_state = TaskState::Home;
        spdlog::info("statechange to home");
      }
    }

  }

}

#endif
