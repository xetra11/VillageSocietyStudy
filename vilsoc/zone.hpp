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
  template <typename T>
  class Zone {
  private:
    T shape;
  public:
    Zone(int size) {
      this->shape = new T(size);
    }
    virtual ~Zone() {};

    sf::FloatRect getRect();
    bool intersects(Zone& with);
    T getShape();
  };

}


#endif
