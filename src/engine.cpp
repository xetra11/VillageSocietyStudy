/**
 * The game engine
 *
 * @file engine.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ENGINE_CPP
#define ENGINE_CPP

#include "engine.hpp"
#include <iostream>

namespace X11 {
  Engine::Engine() : renderLayer{std::vector<Layer>(3)}, game{Game()} {
    spdlog::info("setup engine");
    spdlog::info("init background layer");
    Initializer::initBackgroundLayer(this->getBackgroundLayer());
    Initializer::initSceneLayer(this->getSceneLayer());
    Initializer::initLayer(this->getForegroundLayer());
  }
  Engine::~Engine() {}

  void Engine::update() {
    // update routines for normal tiles
    std::vector<Tile>& backgroundGrid = this->getBackgroundLayer().getGrid();
    std::vector<Tile>& sceneGrid = this->getSceneLayer().getGrid();
    std::vector<Tile>& foregroundGrid = this->getForegroundLayer().getGrid();
    GridRenderer::emptyTiles(backgroundGrid);
    GridRenderer::emptyTiles(sceneGrid);
    GridRenderer::emptyTiles(foregroundGrid);

    // update selected tile
    int selectedTileIndex = this->getGame().getSelectedTilePosition();
    if (selectedTileIndex == -1) {
      spdlog::info("no tile selected");
    } else {
      // highlight still in background layer because there are zones rendered
      Tile& bgSelectedTile = backgroundGrid[selectedTileIndex];
      std::vector<Tile*> zoneTiles = bgSelectedTile.getZoneTiles();
      for(Tile* zoneTile : zoneTiles){
        GridRenderer::highlightTile(*zoneTile);
      }

      // select marker in scene layer
      Tile& fgSelectedTile = foregroundGrid[selectedTileIndex];
      GridRenderer::outlineTile(fgSelectedTile);
    }
  }

  void Engine::run() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "VilSoc");
    while (window.isOpen()){
      this->handleEvents(window);
      this->update();
      window.clear();
      this->getBackgroundLayer().drawLayer(window);
      this->getSceneLayer().drawLayer(window);
      this->getForegroundLayer().drawLayer(window);
      window.display();
    }
  }

  Game& Engine::getGame() {return this->game;}

  void Engine::handleMouseButtonPressed(sf::RenderWindow& window) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::Vector2f coord_pos = window.mapPixelToCoords(mouse_pos);
    int grid_pos_index = GridRenderer::mapCoordsToGridPos(coord_pos);
    if (grid_pos_index >= MAX_GRID_INDEX) {
      spdlog::error("mouse cursor is out of grid bounds");
      spdlog::info("grid index was {}", grid_pos_index);
    } else {
      this->game.setSelectedTilePosition(grid_pos_index);
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

  Layer& Engine::getBackgroundLayer() { return this->renderLayer[BACKGROUND]; }
  Layer& Engine::getSceneLayer(){ return this->renderLayer[SCENE]; }
  Layer& Engine::getForegroundLayer(){ return this->renderLayer[FOREGROUND]; }

}

#endif
