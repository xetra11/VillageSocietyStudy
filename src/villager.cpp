/**
 * The class for the villager agent
 *
 * @file villager.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef VILLAGER_CPP
#define VILLAGER_CPP

#include "villager.hpp"

#define HEAD 0
#define BODY 1

namespace X11 {
  Villager::Villager() : characterShapes{std::vector<sf::Shape*>(2,0)} {
    sf::Shape* headShape = new sf::RectangleShape(sf::Vector2f(5.f, 5.f));
    sf::Shape* bodyShape = new sf::RectangleShape(sf::Vector2f(5.f, 10.f));

    headShape->setPosition(0, 0);
    headShape->setFillColor(sf::Color::Magenta);
    bodyShape->setPosition(0, 5);
    bodyShape->setFillColor(sf::Color::Cyan);

    this->characterShapes[HEAD] = headShape;
    this->characterShapes[BODY] = bodyShape;

    sf::IntRect rect(0, 0, 5, 10);
    this->rect = rect;
  }
  Villager::~Villager() {}

  sf::IntRect Villager::getRect() {return this->rect;}
  sf::Shape* Villager::getHeadShape() {return this->characterShapes[HEAD];}
  sf::Shape* Villager::getBodyShape() {return this->characterShapes[BODY];}
  std::vector<sf::Shape*> Villager::getCharacterShape() {return this->characterShapes;}
};

#endif
