/**
 * The game engine
 *
 * @file engine.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ENGINE_CPP
#define ENGINE_CPP

#include "engine.hpp"

namespace X11 {
  Engine::Engine() : villagers{std::vector<Villager*>(ESTATE_COUNT, 0)} {}
  Engine::~Engine() {}

  void Engine::initialize() {
    Initializer initializer = Initializer();
    spdlog::info("initialize zones");
    std::vector<Zone*> allZones;
    std::vector<Zone*> estates = initializer.initVillageEstates();
    std::vector<Zone*> communityAreas = initializer.initCommunityAreas();
    std::vector<Zone*> workspaces = initializer.initWorkspaces(estates);
    std::vector<Zone*> houses = initializer.initHouses(estates);
    spdlog::info("initialize villagers");
    this->villagers = initializer.initVillagers();
    spdlog::info("initialization done");

    allZones.insert(allZones.end(), estates.begin(), estates.end());
    allZones.insert(allZones.end(), communityAreas.begin(), communityAreas.end());
    allZones.insert(allZones.end(), workspaces.begin(), workspaces.end());
    allZones.insert(allZones.end(), houses.begin(), houses.end());
    this->zones = allZones;
  }

  void Engine::update() {}

  void Engine::draw(sf::RenderWindow* window) {
    this->drawZones(window);
    this->drawVillagers(window);
  }

  void Engine::drawZones(sf::RenderWindow* window) {
    for (auto zone : this->zones) {
      if (zone != NULL) {
        sf::Shape* shape = zone->getShape();
        window->draw(*shape);
      } else {
        spdlog::warn("villager rendering failed");
      }
    }
  }

  void Engine::drawVillagers(sf::RenderWindow* window) {
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

  };
}

#endif
