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
  Menu::Menu(sf::Vector2f position, sf::Vector2f size) : shape { sf::RectangleShape(size) }   {
    this->shape.setPosition(position);
    this->shape.setFillColor(sf::Color(205,133,63, 255));
  }

  void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->shape, states);
    for (Text text : this->texts) {
      target.draw(text);
    }
  }

}

#endif
