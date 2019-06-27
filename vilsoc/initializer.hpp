/**
 * Initializes VilSoc assets
 *
 * @file initializer.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef INITIALIZER_HPP
#define INTIALIZER_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "zone.hpp"
#include "villager.hpp"
#include "world.hpp"

using namespace std;

namespace X11 {

  class Initializer {
  private:
    std::vector<sf::IntRect> occupiedAreas;
    bool isOccupied(sf::IntRect areaRect);
    sf::Vector2i getRandomPosition(int offsetSize);
    sf::Vector2i getRandomPosition(sf::IntRect boundaries);

    template <typename T>
    std::vector<Zone*> initObjects(int objectAmount, int objectSize, sf::Color color) {
      std::vector<Zone*> zones(objectAmount, 0) ;

      for (short i = 0; i < objectAmount;) {
        sf::Vector2i randomPosition = this->getRandomPosition(objectSize);
        Zone* zone = new T(objectSize, randomPosition, color);

        if(this->isOccupied(zone->getRect())) {
          continue;
        }

        this->occupiedAreas.push_back(zone->getRect());
        zones[i] = zone;
        i++;
      }
      return zones;
    }

    template <typename T>
    std::vector<Zone*> initObjects(int objectAmount, int objectSize, sf::Color color, std::vector<sf::IntRect> rects) {
      std::vector<Zone*> zones(objectAmount, 0) ;

      for (short i = 0; i < objectAmount;) {
        sf::Vector2i randomPosition = this->getRandomPosition(rects[i]);
        Zone* zone = new T(objectSize, randomPosition, color);
        this->occupiedAreas.push_back(zone->getRect());
        zones[i] = zone;
        i++;
      }
      return zones;
    }

  public:
    Initializer();
    virtual ~Initializer();

    std::vector<Zone*> initVillageEstates();
    std::vector<Zone*> initCommunityAreas();
    std::vector<Zone*> initWorkspaces(std::vector<Zone*> parentZones);
    std::vector<Zone*> initHouses(std::vector<Zone*> parentZones);
    std::vector<Villager*> initVillagers();
    std::vector<Tile> initWorldGrid();
  };
}

#endif
