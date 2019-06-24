/**
 * Entry of game engine for the village society AI study
 *
 * @file vilsoc.cpp
 * @author Patrick Charles H. | xetra11
 */

#include "vilsoc.hpp"

using namespace std;

namespace X11 {
  VillageSociety::VillageSociety() {
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works");
    initializer = new Initializer();
  }

  VillageSociety::~VillageSociety() {}

  int VillageSociety::run() {
    std::vector<sf::CircleShape*> estates = initializer->initVillageEstates();

    while (window->isOpen()){
      sf::Event event;
      while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window->close();
      }

      window->clear();
      for (auto estate : estates) {
        if (estate != NULL) {
          window->draw(*estate);
        } else {
          cout << "could not draw estate "<< estate << endl;
        }
      }
      window->display();
    }

    return 0;
  }
}
