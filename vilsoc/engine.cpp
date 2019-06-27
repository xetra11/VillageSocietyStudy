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
  Engine::Engine() : world{new World()} {
    spdlog::info("setup engine");
  }
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
    this->world->setVillagers(initializer.initVillagers());
    spdlog::info("initialization done");

    allZones.insert(allZones.end(), estates.begin(), estates.end());
    allZones.insert(allZones.end(), communityAreas.begin(), communityAreas.end());
    allZones.insert(allZones.end(), workspaces.begin(), workspaces.end());
    allZones.insert(allZones.end(), houses.begin(), houses.end());
    this->world->setZones(allZones);
  }

  void Engine::update() {}
  World* Engine::getWorld() {return this->world;}
}

#endif
