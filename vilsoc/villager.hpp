
/**
 * The class for the villager agent
 *
 * @file villager.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef VILLAGER_HPP
#define VILLAGER_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"

namespace X11 {
  class Villager {
  private:
    sf::IntRect rect;
    std::vector<sf::Shape*> characterShapes;
  public:
    Villager();
    virtual ~Villager();
    sf::IntRect getRect();
    sf::Shape* getHeadShape();
    sf::Shape* getBodyShape();
    std::vector<sf::Shape*> getCharacterShape();
  };

};

#endif
