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

  Tile::Tile(){}
  Tile::Tile(sf::Vector2f position){
    sf::Vector2f size(TILE_SIZE, TILE_SIZE);
    this->tileShape = sf::RectangleShape(size);
    this->tileShape.setOutlineColor(sf::Color(255, 255, 255, 100));
    this->tileShape.setOutlineThickness(0.8f);
    this->tileShape.setFillColor(sf::Color::Transparent);
    this->tileShape.setPosition(position);

    sf::Vector2i rectSize(TILE_SIZE, TILE_SIZE);
    sf::Vector2i rectPos(this->tileShape.getPosition().x, this->tileShape.getPosition().y);
    this->boundaries = sf::IntRect(rectPos, rectSize);
  }
  Tile::~Tile(){}
  sf::RectangleShape& Tile::getTileShape(){return this->tileShape;}
  sf::IntRect Tile::getBoundaries(){return this->boundaries;}

  World::World() : villagers{std::vector<Villager*>(ESTATE_COUNT, 0)} {
    spdlog::info("create world");
  }
  World::~World(){}

  void World::drawAssets(sf::RenderWindow& window) {
    this->drawGrid(window);
    // this->drawZones(window);
    // this->drawVillagers(window);
  }

  void World::drawGrid(sf::RenderWindow& window) {
    for (auto tile : this->grid) {
      sf::RectangleShape& shape = tile->getTileShape();
      window.draw(shape);
    }
  }

  void World::drawZones(sf::RenderWindow& window) {
    for (auto zone : this->zones) {
      if (zone != NULL) {
        sf::Shape* shape = zone->getShape();
        window.draw(*shape);
      } else {
        spdlog::warn("villager rendering failed");
      }
    }
  }

  void World::drawVillagers(sf::RenderWindow& window) {
    for (auto villager : this->villagers) {
      if (villager != NULL) {
        sf::Shape* head = villager->getHeadShape();
        sf::Shape* body = villager->getBodyShape();
        window.draw(*head);
        window.draw(*body);
      } else {
        spdlog::warn("villager rendering failed");
      }
    }
  }

  void World::setZones(std::vector<Zone*> zones){this->zones = zones;}
  void World::setVillagers(std::vector<Villager*> villagers) {this->villagers = villagers;}
  void World::setWorldGrid(std::vector<Tile*> grid) {this->grid = grid;}

};

#endif
