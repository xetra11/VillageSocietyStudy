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
    T* shape;
    sf::IntRect rect;
  public:
    Zone(int size, sf::Vector2i position) {
      this->shape = new T(size);
      sf::Vector2i shapeSize(size, size);
      this->rect = sf::IntRect(position, shapeSize);
    }
    virtual ~Zone() {};

    sf::IntRect getRect();
    T* getShape(){
      return this->shape;
    }

    bool intersects(Zone<T>& with) {
      return this->getRect()->intersects(with);
    }
  };


}


#endif
