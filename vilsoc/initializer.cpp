/**
 * Initializes VilSoc assets
 *
 * @file initializer.cpp
 * @author Patrick Charles H. | xetra11
 */

#include "initializer.hpp"
#include <random>

using namespace std;

namespace X11 {

  Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
  }

  Initializer::Initializer() {}
  Initializer::~Initializer() {}

  std::vector<sf::CircleShape*> Initializer::initVillageEstates(){
    short estateSize = 5;
    std::vector<sf::CircleShape*> estates(estateSize, 0) ;
    std::vector<Position> randomPositions = this->getRandomPositions(estateSize);

    for ( short i = 0; i < estateSize; i++) {
      cout << "creating estate no " << i << endl;
      sf::CircleShape* estate = new sf::CircleShape(ESTATE_SHAPE_SIZE);
      cout << "estate is " << estate << endl;
      estate->setFillColor(sf::Color(241, 169, 160, 150));
      Position randomPos = randomPositions[i];
      cout << "random pos is " << randomPos.x << ":" << randomPos.y << endl;
      estate->setPosition(randomPos.x, randomPos.y);
      estates[i] = estate;
    }
    return estates;
  }

  std::vector<Position> Initializer::getRandomPositions(int amount) {
    std::vector<Position> randomPositions(amount, Position(0,0));
    for (int i = 0; i < amount; i++) {
      std::random_device seeder;
      std::mt19937 engine(seeder());
      std::uniform_int_distribution<int> distX(0, WINDOW_WIDTH);
      std::uniform_int_distribution<int> distY(0, WINDOW_HEIGHT);
      int randX = distX(engine);
      int randY = distY(engine);
      randomPositions[i] = Position(randX, randY);
    }
    return randomPositions;
  }
}
