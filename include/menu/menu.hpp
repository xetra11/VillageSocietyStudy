/**
 * The user interface
 *
 * @file menu.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef MENU_HPP
#define MENU_HPP

#include "config.hpp"
#include "text.hpp"
#include "menu/label.hpp"
#include <SFML/Graphics.hpp>

namespace X11 {
  class Menu : public sf::Drawable {
  private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  public:
    Menu(sf::Vector2f position, sf::Vector2f size);
    ~Menu() = default;
    sf::RectangleShape shape;
    std::vector<Text> texts;
    std::vector<Label> labels;
  };
}
#endif
