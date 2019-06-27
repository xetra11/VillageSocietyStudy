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
    spdlog::info("initialize world grid");
    std::vector<Tile*> worldGrid = initializer.initWorldGrid();
    spdlog::info("initialize zones");
    initializer.initEstates(worldGrid);
    //spdlog::info("initialize villagers");
    spdlog::info("initialization done");
    this->world->setWorldGrid(worldGrid);
  }

  void Engine::update() {}
  void Engine::run() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "VilSoc");
    while (window.isOpen()){
      sf::Event event;

      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window.close();
      }

      window.clear();
      this->world->drawAssets(window);
      window.display();
    }
  }

  World* Engine::getWorld() {return this->world;}
}

#endif
