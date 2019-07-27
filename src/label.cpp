#ifndef LABEL_CPP
#define LABEL_CPP

#include <string>
#include "menu/label.hpp"

namespace X11 {

  Label::Label(std::string label_text, sf::Vector2f position, bool is_debug) {
    this->is_debug = is_debug;
    Text label;
    Text value;
    label.setString(label_text);
    label.setPosition(position);
    value.setPosition(sf::Vector2f(label.getPosition().x + 70.f, label.getPosition().y));
    this->label = label;
    this->value = value;
  }

  void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->label);
    target.draw(this->value);
  }
}

#endif
