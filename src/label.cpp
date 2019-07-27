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
    value.setString("<none>");
    value.setPosition(sf::Vector2f(label.getPosition().x + 70.f, label.getPosition().y));
  }

  void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (Text text : this->texts) {
      target.draw(text);
    }
  }
}

#endif
