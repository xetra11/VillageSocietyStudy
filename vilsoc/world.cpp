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

  Tile::Tile() : type{TileType::Empty} {}
  Tile::Tile(sf::Vector2f position) : type{TileType::Empty} {
    sf::Vector2f size(TILE_SIZE, TILE_SIZE);
    this->tileShape = sf::RectangleShape(size);
    // this->tileShape.setOutlineColor(sf::Color(255, 255, 255, 50));
    // this->tileShape.setOutlineThickness(0.5f);
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
    case Empty : this->tileShape.setFillColor(sf::Color::Transparent); break;
    case Estate : this->tileShape.setFillColor(sf::Color(249, 180, 45, 100)); break; //orange
    case Workshop : this->tileShape.setFillColor(sf::Color(46, 204, 113, 255)); break; // green
    case House : this->tileShape.setFillColor(sf::Color(231, 76, 60, 255)); break; // red
    case Community : this->tileShape.setFillColor(sf::Color::Yellow); break; //yellow
    case Villager : this->tileShape.setFillColor(sf::Color::White); break;
    }
  }

  World::World() {
    spdlog::info("create world");
  }
  World::~World(){}

  void World::drawAssets(sf::RenderWindow& window) {
    this->drawGrid(window);
  }

  void World::drawGrid(sf::RenderWindow& window) {
    for (auto tile : this->grid) {
      sf::RectangleShape& shape = tile->getTileShape();
      window.draw(shape);
    }
  }

  void World::setWorldGrid(std::vector<Tile*> grid) {this->grid = grid;}
  std::vector<Tile*>& World::getWorldGrid() {return this->grid;}
};

#endif
