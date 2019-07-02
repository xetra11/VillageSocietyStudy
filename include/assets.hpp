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
  class Asset {
  protected:
    std::vector<sf::Shape*> shapes;
  public:
    Asset();
    ~Asset();
    std::vector<sf::Shape*>& getShapes();
  };

  class Villager : public Asset {
  private:
  public:
    Villager();
    virtual ~Villager();
    sf::Shape& getHeadShape();
    sf::Shape& getBodyShape();
  };

};

#endif
