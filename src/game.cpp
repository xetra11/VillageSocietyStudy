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

  void Game::set_selected_tile_position(int grid_index) { this->selected_tile_position = grid_index; }

  int Game::get_selected_tile_position() { return this->selected_tile_position; }

  void Game::move_villagers(int speed) {
    // for (Villager& villager : this->villager_list) {
    Villager& villager = this->villager_list[0];
      sf::Vector2f head_pos = villager.get_shapes()[HEAD]->getPosition();
      sf::Vector2f body_pos = villager.get_shapes()[BODY]->getPosition();
      sf::Vector2f destination = villager.get_destination();
      spdlog::info("body {0} {1}", body_pos.x, body_pos.y);
      spdlog::info("head {0} {1}", head_pos.x, head_pos.y);
      spdlog::info("destination {0} {1}", destination.x, destination.y);

      sf::Vector2f delta_vector_head = head_pos - destination;
      sf::Vector2f delta_vector_body = body_pos - destination;
      float distance_head = sqrt(pow(delta_vector_head.x, 2) + pow(delta_vector_head.y, 2));
      float distance_body = sqrt(pow(delta_vector_body.x, 2) + pow(delta_vector_body.y, 2));
      spdlog::info("distance_head {}", distance_head);
      spdlog::info("distance_body {}", distance_body);
      sf::Vector2f normalized_head = sf::Vector2f(delta_vector_head/distance_head, delta_vector_head/distance_head);
      sf::Vector2f normalized_body = sf::Vector2f(delta_vector_body/distance_body, delta_vector_body/distance_body);
      spdlog::info("normalized_head {}", normalized_head);
      spdlog::info("normalized_body {}", normalized_body);
    // }
  }

}

#endif
