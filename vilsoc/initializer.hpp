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

namespace X11 {

  class Initializer {
  private:
    std::vector<sf::Vector2i> getRandomPositions(int amount, int offsetSize);

    std::vector<Zone*> initObjects(int objectAmount, int objectSize, sf::Color color) {
      std::vector<Zone*> zones(objectAmount, 0) ;
      std::vector<sf::Vector2i> randomPositions = this->getRandomPositions(objectAmount, objectSize);

      for (short i = 0; i < objectAmount; i++) {
        sf::Vector2i position = randomPositions[i];
        Zone* zone = new ZoneCircle(objectSize, position, color);
        zones[i] = zone;
      }
      return zones;
    }

  public:
    Initializer();
    virtual ~Initializer();

    std::vector<Zone*> initVillageEstates();
    std::vector<Zone*> initCommunityAreas();
    void initHouses();
    void initVillagers();
    // std::vector<sf::RectangleShape*> initWorkspaces();
  };
}

// template <>
// inline std::vector<sf::RectangleShape*> X11::Initializer::initObjects<sf::RectangleShape>(int objectAmount, int objectSize, sf::Color color) {
//   std::vector<sf::RectangleShape*> objects(objectAmount, 0) ;
//   std::vector<Position> randomPositions = this->getRandomPositions(objectAmount, objectSize);

//   for ( short i = 0; i < objectAmount; i++) {
//     sf::Vector2f vector(objectSize/2, objectSize/2);
//     sf::RectangleShape* object = new sf::RectangleShape(vector);
//     object->setFillColor(color);
//     Position randomPos = randomPositions[i];
//     object->setPosition(randomPos.x, randomPos.y);
//     objects[i] = object;
//   }
//   return objects;
// }

#endif
