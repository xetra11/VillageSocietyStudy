/**
 * Initializes VilSoc assets
 *
 * @file initializer.cpp
 * @author Patrick Charles H. | xetra11
 */

#include "initializer.hpp"
#include <iostream>
#include <string>

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
      sf::CircleShape* estate = new sf::CircleShape(10.f);
      cout << "estate is " << estate << endl;
      estate->setFillColor(sf::Color::Red);
      Position randomPos = randomPositions[i];
      estate->setPosition(randomPos.x, randomPos.y);
      estates[i] = estate;
    }
    return estates;
  }

  std::vector<Position> Initializer::getRandomPositions(int amount) {
    std::vector<Position> randomPositions(amount, Position(0,0));
    for (int i = 0; i < amount; i++) {
      randomPositions[i] = Position(5,10*i);
    }
    return randomPositions;
  }
}
