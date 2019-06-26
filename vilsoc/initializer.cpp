/**
 * Initializes VilSoc assets
 *
 * @file initializer.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef INITIALIZER_CPP
#define INITIALIZER_CPP

#include "initializer.hpp"
#include <random>

#define ESTATE_COUNT 5
#define COMMUNITY_COUNT 5

using namespace std;

namespace X11 {

  Initializer::Initializer() {}
  Initializer::~Initializer() {}

  bool Initializer::isOccupied(sf::IntRect rect) {
    for (auto occupied : this->occupiedAreas) {
      if (occupied.intersects(rect)) {
        return true;
      }
    }
    return false;
  }

  std::vector<Zone*> Initializer::initVillageEstates(){
    std::vector<Zone*> estates(ESTATE_COUNT, 0) ;
    sf::Color color(241, 169, 160, 150);
    estates = this->initObjects(ESTATE_COUNT, ESTATE_SHAPE_SIZE, color);
    return estates;
  }

  std::vector<Zone*> Initializer::initCommunityAreas(){
    short communityAreaCount = 2;
    std::vector<Zone*> communityAreas(communityAreaCount, 0) ;
    sf::Color color(102, 204, 153, 150);
    communityAreas = this->initObjects(communityAreaCount, COMMUNITY_SHAPE_SIZE, color);
    return communityAreas;
  }

  std::vector<Zone*> Initializer::initObjects(int objectAmount, int objectSize, sf::Color color) {
    std::vector<Zone*> zones(objectAmount, 0) ;

    for (short i = 0; i < objectAmount;) {
      sf::Vector2i randomPosition = this->getRandomPosition(objectSize);
      Zone* zone = new ZoneCircle(objectSize, randomPosition, color);

      if(this->isOccupied(zone->getRect())) {
        cout << "skipped because occupied position" << endl;
        continue;
      }

      this->occupiedAreas.push_back(zone->getRect());
      zones[i] = zone;
      i++;
    }
    return zones;
  }

  sf::Vector2i Initializer::getRandomPosition(int offsetSize) {
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> distX(0 + offsetSize, WINDOW_WIDTH - offsetSize);
    std::uniform_int_distribution<int> distY(0 + offsetSize, WINDOW_HEIGHT - offsetSize);
    int randX = distX(engine);
    int randY = distY(engine);
    sf::Vector2i randomPos(randX, randY);
    return randomPos;
  }

}

#endif
