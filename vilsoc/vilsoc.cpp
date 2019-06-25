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
    std::vector<sf::Shape*> allObjects;
    std::vector<sf::CircleShape*> estates = initializer->initVillageEstates();
    std::vector<sf::CircleShape*> communityAreas = initializer->initCommunityAreas();

    allObjects.insert(allObjects.end(), estates.begin(), estates.end());
    allObjects.insert(allObjects.end(), communityAreas.begin(), communityAreas.end());
    cout << "size of drawable objects " << allObjects.size() << endl;

    while (window->isOpen()){
      sf::Event event;
      while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window->close();
      }

      window->clear();

      for (auto object : allObjects) {
        if (object != NULL) {
          window->draw(*object);
        } else {
          cout << "could not draw estate "<< object << endl;
        }
      }

      window->display();
    }

    return 0;
  }
}
