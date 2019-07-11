/**
 * Asset classes
 *
 * @file assets.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ASSETS_CPP
#define ASSETS_CPP

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

  sf::Vector2f Villager::get_destination() {
    return this->destination_tile.get_tile_shape().getPosition();
  }

}

#endif
