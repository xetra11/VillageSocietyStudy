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
  VillageSociety::VillageSociety() {
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works");
    initializer = new Initializer();
  }

  VillageSociety::~VillageSociety() {}

  int VillageSociety::run() {
    std::vector<Zone*> allZones;
    std::vector<Zone*> estates = initializer->initVillageEstates();
    std::vector<Zone*> communityAreas = initializer->initCommunityAreas();
    std::vector<Zone*> workspaces = initializer->initWorkspaces();

    allZones.insert(allZones.end(), estates.begin(), estates.end());
    allZones.insert(allZones.end(), communityAreas.begin(), communityAreas.end());
    allZones.insert(allZones.end(), workspaces.begin(), workspaces.end());

    cout << "size of drawable objects " << allZones.size() << endl;

    while (window->isOpen()){
      sf::Event event;
      while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window->close();
      }

      window->clear();

      for (auto zone : allZones) {
        if (zone != NULL) {
          sf::Shape* shape = zone->getShape();
          window->draw(*shape);
        } else {
          cout << "could not draw estate "<< zone << endl;
        }
      }

      window->display();
    }

    return 0;
  }
}

#endif
