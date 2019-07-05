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
#define BODY 1

namespace X11 {

  Villager::Villager() {
    sf::RectangleShape head_shape(sf::Vector2f(5.f, 5.f));
    sf::RectangleShape body_shape(sf::Vector2f(5.f, 10.f));

    head_shape.setPosition(0, 0);
    head_shape.setFillColor(sf::Color::Magenta);
    body_shape.setPosition(0, 5);
    body_shape.setFillColor(sf::Color::Cyan);

    this->shapes[HEAD] = &head_shape;
    this->shapes[BODY] = &body_shape;
  }

  Villager::~Villager() = default;

  std::array<sf::Shape*, 2>& Villager::get_shapes() { return this->shapes; }

  void Villager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*(shapes[HEAD]), states);
    target.draw(*(shapes[BODY]), states);
  }
}

#endif
