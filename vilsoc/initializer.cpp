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
  Initializer::Initializer() {}
  Initializer::~Initializer() {}

  std::vector<sf::CircleShape*> Initializer::initVillageEstates(){
    short estateSize = 5;
    std::vector<sf::CircleShape*> estates(estateSize, 0) ;

    for ( short i = 0; i < estateSize; i++) {

      cout << "creating estate no " << i << endl;
      sf::CircleShape* estate = new sf::CircleShape(10.f);
      cout << "estate is " << estate << endl;
      estate->setFillColor(sf::Color::Red);
      estate->setPosition(10*i, 20*i);
      estates[i] = estate;
    }
    return estates;
  }
}
