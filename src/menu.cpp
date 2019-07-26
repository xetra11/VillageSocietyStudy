/**
 * The user interface
 *
 * @file menu.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef MENU_CPP
#define MENU_CPP

#define DEV_MODE true

#include "menu.hpp"

namespace X11 {

  Menu::Menu(sf::Vector2f position, sf::Vector2f size) : shape { sf::RectangleShape(size) }   {
    this->shape.setPosition(position);
    this->shape.setFillColor(sf::Color(205,133,63, 255));
  }

  void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->shape, states);
    for (Text text : this->texts) {
      if (text.is_debug && DEV_MODE) {
        target.draw(text);
      } else if (!text.is_debug) {
        target.draw(text);
      }
    }
  }

}

#endif
