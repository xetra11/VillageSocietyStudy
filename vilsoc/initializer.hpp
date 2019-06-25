/**
 * Initializes VilSoc assets
 *
 * @file initializer.hpp
 * @author Patrick Charles H. | xetra11
 */

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"

namespace X11 {
  struct Position {
    int x, y;
    Position(int, int);
  };

  class Initializer {
  private:
    std::vector<Position> getRandomPositions(int amount, int offsetSize);

    template <class T>
    std::vector<T*> initObjects(int objectAmount, int objectSize, sf::Color color) {
      std::vector<T*> objects(objectAmount, 0) ;
      std::vector<Position> randomPositions = this->getRandomPositions(objectAmount, objectSize);

      for ( short i = 0; i < objectAmount; i++) {
        T* object = new T(objectSize);
        object->setFillColor(color);
        Position randomPos = randomPositions[i];
        object->setPosition(randomPos.x, randomPos.y);
        objects[i] = object;
      }
      return objects;
    }
  public:
    Initializer();
    virtual ~Initializer();

    std::vector<sf::CircleShape*> initVillageEstates();
    void initHouses();
    void initVillagers();
    void initWorkspaces();
    std::vector<sf::CircleShape*> initCommunityAreas();
  };
}
