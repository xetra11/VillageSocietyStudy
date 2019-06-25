/**
 * Entry of game engine for the village society AI study
 *
 * @file vilsoc.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef VILSOC_HPP
#define VILSOC_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "initializer.hpp"

namespace X11 {
  class VillageSociety {
  private:
    sf::RenderWindow* window;
    Initializer* initializer;

  public:
    VillageSociety();
    virtual ~VillageSociety();
    int run();
  };
}

#endif
