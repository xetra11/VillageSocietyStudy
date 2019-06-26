/**
 * Entry of game engine for the village society AI study
 *
 * @file vilsoc.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef VILSOC_CPP
#define VILSOC_CPP

#include "vilsoc.hpp"

using namespace std;

namespace X11 {
  VillageSociety::VillageSociety() {}
  VillageSociety::~VillageSociety() {}

  int VillageSociety::run(float delta) {
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "VilSoc");
    spdlog::info("start rendering");
    Engine engine;
    engine.initialize();
    while (window->isOpen()){

      sf::Event event;
      while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window->close();
      }

      window->clear();
      engine.draw(window);
      window->display();
    }
    return 0;
  }
}

#endif
