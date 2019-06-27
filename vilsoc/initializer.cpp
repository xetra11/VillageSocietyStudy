/**
 * Initializes VilSoc assets
 *
 * @file initializer.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef INITIALIZER_CPP
#define INITIALIZER_CPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
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
    estates = this->initObjects<ZoneCircle>(ESTATE_COUNT, ESTATE_SHAPE_SIZE, color);
    return estates;
  }

  std::vector<Zone*> Initializer::initCommunityAreas(){
    short communityAreaCount = 2;
    std::vector<Zone*> communityAreas(communityAreaCount, 0) ;
    sf::Color color(102, 204, 153, 150);
    communityAreas = this->initObjects<ZoneCircle>(communityAreaCount, COMMUNITY_SHAPE_SIZE, color);
    return communityAreas;
  }

  std::vector<Zone*> Initializer::initWorkspaces(std::vector<Zone*> parentZones){
    short workspaceCount = ESTATE_COUNT;
    std::vector<Zone*> workspaces(workspaceCount, 0) ;
    sf::Color color(25, 181, 254, 255);
    std::vector<sf::IntRect> rects(workspaceCount);
    for (int i = 0; i < workspaceCount; i++) {
      rects[i] = (parentZones[i])->getRect();
    }
    workspaces = this->initObjects<ZoneRectangle>(workspaceCount, WORKSPACE_SHAPE_SIZE, color, rects);
    return workspaces;
  }

  std::vector<Zone*> Initializer::initHouses(std::vector<Zone*> parentZones) {
    short workspaceCount = ESTATE_COUNT;
    std::vector<Zone*> workspaces(workspaceCount, 0) ;
    sf::Color color(245, 230, 83, 255);
    std::vector<sf::IntRect> rects(workspaceCount);
    for (int i = 0; i < workspaceCount; i++) {
      rects[i] = (parentZones[i])->getRect();
    }
    workspaces = this->initObjects<ZoneCircle>(workspaceCount, HOUSE_SHAPE_SIZE, color, rects);
    return workspaces;
  }

  std::vector<Villager*> Initializer::initVillagers() {
    std::vector<Villager*> villagers(ESTATE_COUNT, 0);
    for (int i = 0; i < ESTATE_COUNT; i++) {
      villagers[i] = new Villager();
    }
    return villagers;
  }

  std::vector<Tile> Initializer::initWorldGrid() {
    std::vector<Tile> worldGrid(GRID_WIDTH * GRID_HEIGHT);
    for (int height = 0; height < GRID_HEIGHT; height++) {
      for (int width = 0; width < GRID_WIDTH; width++) {
        sf::Vector2f position(width * TILE_SIZE, height * TILE_SIZE);
        Tile newTile(position);
        worldGrid[width + (height * GRID_WIDTH)] = newTile;
      }
    }
    return worldGrid;
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

  sf::Vector2i Initializer::getRandomPosition(sf::IntRect boundaries) {
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> distX(boundaries.left, boundaries.left + boundaries.width);
    std::uniform_int_distribution<int> distY(boundaries.top, boundaries.top + boundaries.height);
    int randX = distX(engine);
    int randY = distY(engine);
    sf::Vector2i randomPos(randX, randY);
    return randomPos;
  }

}

#endif
