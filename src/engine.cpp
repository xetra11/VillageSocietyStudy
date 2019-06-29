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
  Engine::Engine() : world{World()} {
    spdlog::info("setup engine");
  }
  Engine::~Engine() {}

  void Engine::initialize() {
    Initializer initializer = Initializer();
    spdlog::info("initialize world grid");
    this->world.setWorldGrid(initializer.initWorldGrid());
    spdlog::info("initialize zones");
    std::vector<Tile>& worldGrid = this->world.getWorldGrid();
    initializer.initObjects(TileType::Estate, worldGrid, 4, ESTATE_COUNT);
    initializer.initObjects(TileType::Community, worldGrid, 2, COMMUNITY_COUNT);
    initializer.initObjects(TileType::Workshop, worldGrid, 1, ESTATE_COUNT);
    initializer.initObjects(TileType::House, worldGrid, 1, ESTATE_COUNT);
    spdlog::info("initialization done");
  }

      void Engine::update() {}
    void Engine::run() {
      sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "VilSoc");
      while (window.isOpen()){
        this->handleEvents(window);
        window.clear();
        this->world.drawAssets(window);
        window.display();
      }
    }

    World& Engine::getWorld() {return this->world;}

    void Engine::handleMouseButtonPressed(sf::RenderWindow& window) {
      sf::Vector2i mousePos = sf::Mouse::getPosition();
      sf::Vector2f coordPos = window.mapPixelToCoords(mousePos);
      Tile* tile = this->getWorld().getTileAtPosition(sf::Vector2i(coordPos.x, coordPos.y));
      if (tile == NULL) {
        spdlog::warn("no tile under mouse cursor");
      } else {
        spdlog::info("tile type {}", static_cast<char>(tile->getType()));
        spdlog::info("tile id {}", tile->getId());
        if (tile->getZoneTiles().size() > 0) {
          for (Tile* zoneTile : tile->getZoneTiles()) {
            sf::RectangleShape& tileShape = zoneTile->getTileShape();
            tileShape.setOutlineColor(sf::Color(255, 255, 255, 50));
            tileShape.setOutlineThickness(0.5f);
          }
        } else {
          spdlog::info("no adjacent zone tiles for this tile");
        }
      }
    }

    void Engine::handleEvents(sf::RenderWindow& window) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
          this->handleMouseButtonPressed(window);
        }
      }
    }
  }

#endif
