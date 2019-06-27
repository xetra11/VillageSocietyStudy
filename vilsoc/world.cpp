/**
 * The world container
 *
 * @file world.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef WORLD_CPP
#define WORLD_CPP

#include "world.hpp"

namespace X11 {
  World::World() : villagers{std::vector<Villager*>(ESTATE_COUNT, 0)} {
    spdlog::info("create world");
  }
  World::~World(){}

  void World::drawAssets(sf::RenderWindow* window) {
    this->drawZones(window);
    this->drawVillagers(window);
  }

  void World::drawZones(sf::RenderWindow* window) {
    for (auto zone : this->zones) {
      if (zone != NULL) {
        sf::Shape* shape = zone->getShape();
        window->draw(*shape);
      } else {
        spdlog::warn("villager rendering failed");
      }
    }
  }

  void World::drawVillagers(sf::RenderWindow* window) {
    for (auto villager : this->villagers) {
      if (villager != NULL) {
        sf::Shape* head = villager->getHeadShape();
        sf::Shape* body = villager->getBodyShape();
        window->draw(*head);
        window->draw(*body);
      } else {
        spdlog::warn("villager rendering failed");
      }
    }
  }

  void World::setZones(std::vector<Zone*> zones){this->zones = zones;}
  void World::setVillagers(std::vector<Villager*> villagers) {this->villagers = villagers;}

};

#endif
