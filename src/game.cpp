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

  void Game::move_villagers(int speed) {
    for (Villager& villager : this->villager_list) {
      sf::Vector2f head_pos = villager.get_shapes()[HEAD]->getPosition();
      sf::Vector2f body_pos = villager.get_shapes()[BODY]->getPosition();
      Tile& destination_tile = villager.get_destination();
      sf::Vector2f destination_pos = destination_tile.get_tile_shape().getPosition();

      sf::Vector2f delta_vector_head = destination_pos - head_pos;
      sf::Vector2f delta_vector_body = destination_pos - body_pos;
      float distance_head = sqrt(pow(delta_vector_head.x, 2) + pow(delta_vector_head.y, 2));
      float distance_body = sqrt(pow(delta_vector_body.x, 2) + pow(delta_vector_body.y, 2));

      // only move/calculate if distance is great enough
      if (distance_body > 0.5 && distance_head > 0.5) {
        sf::Vector2f normalized_head = sf::Vector2f(0, 0);
        if (distance_head != 0) {
          normalized_head = sf::Vector2f(delta_vector_head.x / distance_head,
                                         delta_vector_head.y / distance_head);
        }
        sf::Vector2f normalized_body = sf::Vector2f(0, 0);
        if (distance_body != 0) {
          normalized_body = sf::Vector2f(delta_vector_body.x / distance_body,
                                         delta_vector_body.y / distance_body);
        }

        villager.get_shapes()[HEAD]->setPosition(head_pos + normalized_head);
        villager.get_shapes()[BODY]->setPosition(body_pos + normalized_body);
      }
    }
  }

}

#endif
