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

  std::vector<Zone<sf::CircleShape>*> Initializer::initVillageEstates(){
    std::vector<Zone<sf::CircleShape>*> estates(ESTATE_COUNT, 0) ;
    std::vector<sf::Vector2i> randomPositions = this->getRandomPositions(ESTATE_COUNT, ESTATE_SHAPE_SIZE);
    sf::Color color(241, 169, 160, 150);

    estates = this->initObjects<sf::CircleShape>(ESTATE_COUNT, ESTATE_SHAPE_SIZE, color);
    return estates;
  }

  std::vector<Zone<sf::CircleShape>*> Initializer::initCommunityAreas(){
    short communityAreaCount = 2;
    std::vector<Zone<sf::CircleShape>*> communityAreas(communityAreaCount, 0) ;
    std::vector<sf::Vector2i> randomPositions = this->getRandomPositions(communityAreaCount, ESTATE_SHAPE_SIZE);
    sf::Color color(102, 204, 153, 150);

    communityAreas = this->initObjects<sf::CircleShape>(communityAreaCount, COMMUNITY_SHAPE_SIZE, color);
    //for (auto communityArea : communityAreas) {communityArea->setPointCount(5);}

    return communityAreas;
  }

  // std::vector<sf::RectangleShape*> Initializer::initWorkspaces(){
  //   short workspaceCount = ESTATE_COUNT;
  //   std::vector<sf::RectangleShape*> workspaces(workspaceCount, 0) ;
  //   std::vector<Position> randomPositions = this->getRandomPositions(workspaceCount, WORKSPACE_SHAPE_SIZE);
  //   sf::Color color(25, 181, 254, 255);

  //   workspaces = this->initObjects<sf::RectangleShape>(workspaceCount, WORKSPACE_SHAPE_SIZE, color);

  //   return workspaces;
  // }

  std::vector<sf::Vector2i> Initializer::getRandomPositions(int amount, int offsetSize) {
    std::vector<sf::Vector2i> randomPositions(amount, sf::Vector2i(150, 150));
    for (int i = 0; i < amount; i++) {
      std::random_device seeder;
      std::mt19937 engine(seeder());
      std::uniform_int_distribution<int> distX(0 + offsetSize, WINDOW_WIDTH - offsetSize);
      std::uniform_int_distribution<int> distY(0 + offsetSize, WINDOW_HEIGHT - offsetSize);
      int randX = distX(engine);
      int randY = distY(engine);
      randomPositions[i] = sf::Vector2i(randX, randY);
    }
    return randomPositions;
  }

}

#endif
