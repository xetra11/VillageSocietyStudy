#ifndef LABEL_HPP
#define LABEL_HPP

#include <SFML/Graphics.hpp>
#include "text.hpp"

namespace X11 {
  class Label : public sf::Drawable {
  private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    std::vector<Text> texts;
  public:
    Label(std::string label, sf::Vector2f position, bool is_debug);
    ~Label() = default;
    bool is_debug = false;
  };
}

#endif
