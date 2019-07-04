/**
 * Entry of game engine for the village society AI study
 *
 * @file vilsoc.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef VILSOC_CPP
#define VILSOC_CPP

#include "vilsoc.hpp"

namespace X11 {
  VillageSociety::VillageSociety() {}
  VillageSociety::~VillageSociety() {}

  int VillageSociety::start() {
    spdlog::info("start vilsoc");
    Engine engine;
    engine.run();
    return 0;
  }
}

#endif
