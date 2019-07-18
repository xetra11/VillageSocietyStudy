/**
 * The user interface
 *
 * @file menu.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef MENU_CPP
#define MENU_CPP

#include "menu.hpp"

namespace X11 {
  Menu::Menu(sf::Vector2f position, sf::Vector2f size) : sf::RectangleShape(size)  {
    this->setPosition(position);
    this->setFillColor(sf::Color(205,133,63, 255));
  }

}

#endif
