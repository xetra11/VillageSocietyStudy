/**
 * Wrapper for SFML Shapes
 *
 * @file zone.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ZONE_CPP
#define ZONE_CPP

#include "zone.hpp"

namespace X11 {
  Zone::Zone() {}
  Zone::~Zone() {}

  sf::Shape* Zone::getShape() {
    return this->shape;
  }
  sf::IntRect Zone::getRect() {
    return this->rect;
  }

  bool Zone::intersects(Zone* with) {
    return this->rect.intersects(with->getRect());
  }

  ZoneCircle::ZoneCircle(int size, sf::Vector2i position, sf::Color color) {
    sf::Shape* shape = new sf::CircleShape(size) ;
    shape->setPosition(sf::Vector2f(position.x, position.y));
    shape->setFillColor(color);
    sf::Vector2i rectSize(size*2, size*2);
    sf::IntRect rect = sf::IntRect(position, rectSize);

    this->shape = shape;
    this->rect = rect;
  }
  ZoneCircle::~ZoneCircle() {};

  ZoneRectangle::ZoneRectangle(int size, sf::Vector2i position, sf::Color color) {
    sf::Shape* shape = new sf::RectangleShape(sf::Vector2f(size, size)) ;
    shape->setPosition(sf::Vector2f(position.x, position.y));
    shape->setFillColor(color);
    sf::Vector2i rectSize(size, size);
    sf::IntRect rect = sf::IntRect(position, rectSize);

    this->shape = shape;
    this->rect = rect;
  }
  ZoneRectangle::~ZoneRectangle() {};

}

#endif
