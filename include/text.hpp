/**
 * specialization for sf::Text
 *
 * @file text.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef TEXT_HPP
#define TEXT_HPP

#include <SFML/Graphics.hpp>
#include <resources.hpp>

namespace X11 {
class Text : public sf::Text {
  private:
  public:
    Text();
    ~Text() override = default;
  };
}

#endif
