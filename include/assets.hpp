/**
 * Asset classes
 *
 * @file assets.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ASSETS_HPP
#define ASSETS_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"

namespace X11 {

  class Villager {
  private:
    std::array<sf::Shape*, 2> shapes;
  public:
    Villager();
    explicit Villager(sf::Vector2f position);
    virtual ~Villager();
    void setPosition(sf::Vector2f position);
    std::array<sf::Shape*, 2>& get_shapes();
  };

}

#endif
