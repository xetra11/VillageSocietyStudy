/**
 * wrapper class for sf::Text
 *
 * @file text.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef TEXT_CPP
#define TEXT_CPP

#include <text.hpp>

namespace X11 {

  Text::Text() {
    ResourceManager* resources = ResourceManager::instance();
    if (!resources->fonts.empty()) {
      this->setFont(resources->fonts.at(Font::DejaVuSans));
    }
    this->setFillColor(sf::Color::Black);
    this->setStyle(sf::Text::Bold);
    this->setCharacterSize(15);
  }
}

#endif
