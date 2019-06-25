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
    std::vector<Position> randomPositions = this->getRandomPositions(estateSize, ESTATE_SHAPE_SIZE);
    sf::Color color(241, 169, 160, 150);

    estates = this->initObjects<sf::CircleShape>(estateSize, ESTATE_SHAPE_SIZE, color);
    return estates;
  }

  std::vector<sf::CircleShape*> Initializer::initCommunityAreas(){
    short communityAreaCount = 5;
    std::vector<sf::CircleShape*> communityAreas(communityAreaCount, 0) ;
    std::vector<Position> randomPositions = this->getRandomPositions(communityAreaCount, ESTATE_SHAPE_SIZE);
    sf::Color color(102, 204, 153, 150);

    communityAreas = this->initObjects<sf::CircleShape>(communityAreaCount, COMMUNITY_SHAPE_SIZE, color);
    //for (auto communityArea : communityAreas) {communityArea->setPointCount(5);}

    return communityAreas;
  }

  std::vector<Position> Initializer::getRandomPositions(int amount, int offsetSize) {
    std::vector<Position> randomPositions(amount, Position(0,0));
    for (int i = 0; i < amount; i++) {
      std::random_device seeder;
      std::mt19937 engine(seeder());
      std::uniform_int_distribution<int> distX(0 + offsetSize, WINDOW_WIDTH - offsetSize);
      std::uniform_int_distribution<int> distY(0 + offsetSize, WINDOW_HEIGHT - offsetSize);
      int randX = distX(engine);
      int randY = distY(engine);
      randomPositions[i] = Position(randX, randY);
    }
    return randomPositions;
  }

}
