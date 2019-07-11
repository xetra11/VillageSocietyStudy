/**
 * Asset classes
 *
 * @file assets.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ASSETS_CPP
#define ASSETS_CPP

#include <iostream>
#include "assets.hpp"


namespace X11 {

  Villager::Villager(Tile& starting_tile) : shapes{std::array<sf::Shape*,2>()}, destination_tile(starting_tile) {
    auto head_shape = new sf::RectangleShape(sf::Vector2f(HEAD_SIZE_X, HEAD_SIZE_Y));
    auto body_shape = new sf::RectangleShape(sf::Vector2f(BODY_SIZE_X, BODY_SIZE_Y));

    head_shape->setPosition(0, 0);
    head_shape->setFillColor(sf::Color::Magenta);
    head_shape->setOrigin(HEAD_SIZE_X/2, HEAD_SIZE_Y/2);
    body_shape->setPosition(0, HEAD_BODY_DELTA);
    body_shape->setOrigin(BODY_SIZE_X/2, (BODY_SIZE_Y - HEAD_BODY_DELTA) /2);
    body_shape->setFillColor(sf::Color::Cyan);

    this->shapes[HEAD] = head_shape;
    this->shapes[BODY] = body_shape;
  }


  void Villager::set_destination(Tile& tile_to_move) {this->destination_tile = tile_to_move;
  }

  Tile& Villager::get_destination() {
    return this->destination_tile;
  }

  void Villager::set_position(sf::Vector2f new_position) {
    this->shapes[HEAD]->setPosition(new_position);
    this->shapes[BODY]->setPosition(new_position + sf::Vector2f(0, HEAD_BODY_DELTA));
  }

  void Villager::move_to_destination(float speed) {
    sf::Vector2f head_pos = this->get_shapes()[HEAD]->getPosition();
    Tile& destination_tile = this->get_destination();
    sf::Vector2f destination_pos = destination_tile.get_tile_center() + sf::Vector2f (0, PERSPECTIVE_DELTA_VILLAGER);

    sf::Vector2f delta_vector_head = destination_pos - head_pos;
    float distance_head = sqrt(pow(delta_vector_head.x, 2) + pow(delta_vector_head.y, 2));

    // only move/calculate if distance is great enough
    if (distance_head > 0.5) {
      sf::Vector2f normalized_vector = sf::Vector2f(0, 0);
      if (distance_head != 0) {
        normalized_vector = sf::Vector2f(delta_vector_head.x / distance_head,
                                       delta_vector_head.y / distance_head);
      }
      this->set_position(head_pos + (normalized_vector * speed));
    }
  }

}

#endif
