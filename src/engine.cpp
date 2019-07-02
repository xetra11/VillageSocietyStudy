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
  Engine::Engine() : renderLayer{std::vector<Layer>(3)}, game{Game()} {
    spdlog::info("setup engine");
    spdlog::info("init background layer");
    Initializer::initBackgroundLayer(this->getBackgroundLayer());
  }
  Engine::~Engine() {}

  void Engine::update() {
    // update routines for normal tiles
    std::vector<Tile>& tileGrid = this->getBackgroundLayer().getGrid();
    GridRenderer::emptyTiles(tileGrid);

    // update selected tile
    int selectedTileIndex = this->getGame().getSelectedTilePosition();
    if (selectedTileIndex == -1) {
      spdlog::info("no tile selected");
    } else {
      Tile& selectedTile = tileGrid[selectedTileIndex];
      selectedTile.getTileShape().setOutlineColor(sf::Color::White);
      selectedTile.getTileShape().setOutlineThickness(0.8f);

      std::vector<Tile*> zoneTiles = selectedTile.getZoneTiles();
      for(Tile* zoneTile : zoneTiles){
        sf::RectangleShape& tileShape = zoneTile->getTileShape();
        sf::Color color = tileShape.getFillColor();
        color.a = 255;
        tileShape.setFillColor(color);
      }
    }
  }

  void Engine::run() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "VilSoc");
    while (window.isOpen()){
      this->handleEvents(window);
      this->update();
      window.clear();
      this->getBackgroundLayer().drawLayer(window);
      window.display();
    }
  }

  Game& Engine::getGame() {return this->game;}

  void Engine::handleMouseButtonPressed(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    sf::Vector2f coordPos = window.mapPixelToCoords(mousePos);
    int gridPosIndex = GridRenderer::mapCoordsToGridPos(coordPos);
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
