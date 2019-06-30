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
  Engine::Engine() : world{World()}, game{Game()} {
    spdlog::info("setup engine");
    spdlog::info("init background layer");
    this->renderLayer[BACKGROUND] = Initializer::initBackgroundLayer();
    // spdlog::info("init scene layer");
    // this->renderLayer[SCENE] = Initializer::initWorldGrid();
    // spdlog::info("init foreground layer");
    // this->renderLayer[FOREGROUND] = Initializer::initWorldGrid();
  }
  Engine::~Engine() {}

  void Engine::initialize() {
    spdlog::info("initialize world grid");
    this->world.setWorldGrid(Initializer::initBackgroundLayer());
    spdlog::info("initialize zones");
    std::vector<Tile>& worldGrid = this->world.getWorldGrid();
    Initializer::initObjects(TileType::Estate, worldGrid, 4, ESTATE_COUNT);
    Initializer::initObjects(TileType::Community, worldGrid, 2, COMMUNITY_COUNT);
    Initializer::initObjects(TileType::Workshop, worldGrid, 1, ESTATE_COUNT);
    Initializer::initObjects(TileType::House, worldGrid, 1, ESTATE_COUNT);
    spdlog::info("initialization done");
  }

  void Engine::update() {
    // update routines for normal tiles
    std::vector<Tile>& worldGrid = this->getWorld().getWorldGrid();
    for (Tile& tile : worldGrid) {
      Tile::setColorByType(tile.getType(), tile.getTileShape());
      tile.getTileShape().setOutlineColor(sf::Color::Transparent);
    }

    // update selected tile
    int selectedTileIndex = this->getGame().getSelectedTilePosition();
    if (selectedTileIndex == -1) {
      spdlog::info("no tile selected");
    } else {
      Tile& selectedTile = this->world.getWorldGrid()[selectedTileIndex];
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
      this->world.drawAssets(window);
      window.display();
    }
  }

  World& Engine::getWorld() {return this->world;}
  Game& Engine::getGame() {return this->game;}

  void Engine::handleMouseButtonPressed(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    sf::Vector2f coordPos = window.mapPixelToCoords(mousePos);
    Tile* tile = this->getWorld().getTileAtPosition(sf::Vector2i(coordPos.x, coordPos.y));
    if (tile == NULL) {
      spdlog::warn("no tile under mouse cursor");
    } else {
      spdlog::info("tile type {}", static_cast<char>(tile->getType()));
      tile->isSelected = true;
      this->game.setSelectedTilePosition(tile->getGridPosition());
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

  std::vector<Tile>& Engine::getBackgroundGrid() { return this->renderLayer[BACKGROUND]; }
  std::vector<Tile>& Engine::getSceneGrid(){ return this->renderLayer[SCENE]; }
  std::vector<Tile>& Engine::getForegroundGrid(){ return this->renderLayer[FOREGROUND]; }

}

#endif
