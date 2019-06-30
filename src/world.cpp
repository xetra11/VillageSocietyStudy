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

  Tile::Tile() : type{TileType::Empty}, zoneTiles{std::vector<Tile*>()} {}
  Tile::Tile(sf::Vector2f position) : type{TileType::Empty}, zoneTiles{std::vector<Tile*>()} {
    sf::Vector2f size(TILE_SIZE, TILE_SIZE);
    this->tileShape = sf::RectangleShape(size);
    this->tileShape.setFillColor(sf::Color::Transparent);
    this->tileShape.setPosition(position);

    sf::Vector2i rectSize(TILE_SIZE, TILE_SIZE);
    sf::Vector2i rectPos(this->tileShape.getPosition().x, this->tileShape.getPosition().y);
    this->boundaries = sf::IntRect(rectPos, rectSize);
  }
  Tile::~Tile(){}
  sf::RectangleShape& Tile::getTileShape(){return this->tileShape;}
  sf::IntRect Tile::getBoundaries(){return this->boundaries;}

  void Tile::setType(TileType type) {
    this->type = type;
    this->setColorByType(type);
  }

  TileType Tile::getType() {return this->type;}

  void Tile::setColorByType(TileType type) {
    switch (type) {
    case TileType::Empty : this->tileShape.setFillColor(sf::Color::Transparent); break;
    case TileType::Estate : this->tileShape.setFillColor(sf::Color(249, 180, 45, 100)); break; //orange
    case TileType::Workshop : this->tileShape.setFillColor(sf::Color(46, 204, 113, 100)); break; // green
    case TileType::House : this->tileShape.setFillColor(sf::Color(231, 76, 60, 100)); break; // red
    case TileType::Community : this->tileShape.setFillColor(sf::Color(245, 230, 83, 100)); break; //yellow
    case TileType::Villager : this->tileShape.setFillColor(sf::Color::White); break;
    }
  }

  void Tile::setId(int id) {this->id = id;}
  int Tile::getId() { return this->id;}
  void Tile::setZoneTiles(std::vector<Tile*> zoneTiles){ this->zoneTiles = zoneTiles;}
  std::vector<Tile*>& Tile::getZoneTiles() {return this->zoneTiles;}

  World::World() : selectedTile{0} {
    spdlog::info("create world");
  }
  World::~World(){}

  void World::drawAssets(sf::RenderWindow& window) {
    this->drawGrid(window);
  }

  void World::drawGrid(sf::RenderWindow& window) {
    for (auto tile : this->grid) {
      sf::RectangleShape& shape = tile.getTileShape();
      window.draw(shape);
    }
  }

  void World::setWorldGrid(std::vector<Tile> grid) {this->grid = grid;}
  std::vector<Tile>& World::getWorldGrid() {return this->grid;}

  Tile* World::getTileAtPosition(sf::Vector2i position){
    sf::Vector2i gridVector((position.x/TILE_SIZE), (position.y/TILE_SIZE-1));
    spdlog::info("gridvector x {0} y {1}", gridVector.x, gridVector.y);
    Tile& tile = this->grid[gridVector.x + (gridVector.y * GRID_WIDTH)];
    return &tile;
  }

  Tile* World::getSelectedTile() { return this->selectedTile;}
  void World::setSelectedTile(Tile* tile) { this->selectedTile = tile;}
};

#endif
