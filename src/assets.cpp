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

  Asset::Asset() {}
  Asset::~Asset() {}

  std::vector<sf::Shape*>& Asset::getShapes() { return this->shapes;}

  Villager::Villager() {
    sf::RectangleShape* headShape = new sf::RectangleShape(sf::Vector2f(5.f, 5.f));
    sf::RectangleShape* bodyShape = new sf::RectangleShape(sf::Vector2f(5.f, 10.f));

    headShape->setPosition(0, 0);
    headShape->setFillColor(sf::Color::Magenta);
    bodyShape->setPosition(0, 5);
    bodyShape->setFillColor(sf::Color::Cyan);

    this->shapes.push_back(headShape);
    this->shapes.push_back(bodyShape);
  }
  Villager::~Villager() {}

  sf::Shape& Villager::getHeadShape() {return *(this->shapes[HEAD]);}
  sf::Shape& Villager::getBodyShape() {return *(this->shapes[BODY]);}
};

#endif
