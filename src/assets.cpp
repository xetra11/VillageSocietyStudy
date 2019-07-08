/**
 * Asset classes
 *
 * @file assets.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ASSETS_CPP
#define ASSETS_CPP

#include "assets.hpp"

#define HEAD 0
#define HEAD_SIZE_X 5.f
#define HEAD_SIZE_Y 5.f
#define BODY 1
#define BODY_SIZE_X 5.f
#define BODY_SIZE_Y 10.f
#define HEAD_BODY_DELTA 5

namespace X11 {

  Villager::Villager() : shapes{std::array<sf::Shape*,2>()}{
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

  Villager::Villager(sf::Vector2f position) : Villager() {
    this->setPosition(position);
  }

  Villager::~Villager() = default;

  std::array<sf::Shape*, 2>& Villager::get_shapes() { return this->shapes; }

  void Villager::setPosition(sf::Vector2f position) {
    this->shapes[HEAD]->setPosition(position);
    this->shapes[BODY]->setPosition(position.x, position.y + HEAD_BODY_DELTA);

  }

}

#endif
