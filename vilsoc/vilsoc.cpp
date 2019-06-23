/**
 * Entry of game engine for the village society AI study
 *
 * @file vilsoc.cpp
 * @author Patrick Charles H. | xetra11
 */

#include "vilsoc.hpp"

namespace X11 {
  VillageSociety::VillageSociety() {
    window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML Works");
    shape = new sf::CircleShape(100.f);
    shape->setFillColor(sf::Color::Green);
  }

  VillageSociety::~VillageSociety() {}

  int VillageSociety::run() {
    while (window->isOpen()){
      sf::Event event;
      while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window->close();
      }

      window->clear();
      window->draw(*shape);
      window->display();
    }

    return 0;
  }
}
