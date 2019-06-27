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
#include "engine.hpp"
#include "world.hpp"

namespace X11 {
  class VillageSociety {
  public:
    VillageSociety();
    virtual ~VillageSociety();
    int run(float delta);
  };
}

#endif
