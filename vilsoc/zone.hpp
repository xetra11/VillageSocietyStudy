/**
 * Wrapper for SFML Shapes
 *
 * @file vsentity.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ZONE_HPP
#define ZONE_HPP

#include <SFML/Graphics.hpp>

namespace X11 {

  class Zone {
  protected:
    sf::Shape* shape;
    sf::IntRect rect;
  public:
    Zone();
    virtual ~Zone();

    sf::Shape* getShape();
    sf::IntRect getRect();

    bool intersects(Zone* with);
  };

  class ZoneCircle : public Zone {
  public:
    ZoneCircle(int size, sf::Vector2i position, sf::Color color);
    virtual ~ZoneCircle();
  };

  class ZoneRectangle : public Zone {
  public:
    ZoneRectangle(int size, sf::Vector2i position, sf::Color color);
    virtual ~ZoneRectangle();
  };
};




#endif
