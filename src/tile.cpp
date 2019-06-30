/**
 * The grid tile class
 *
 * @file tile.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef TILE_CPP
#define TILE_CPP

#include "tile.hpp"

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

  void Tile::setColorByType(TileType type, sf::Shape& shape) {
    switch (type) {
    case TileType::Empty : shape.setFillColor(sf::Color::Transparent); break;
    case TileType::Estate : shape.setFillColor(sf::Color(249, 180, 45, 100)); break; //orange
    case TileType::Workshop : shape.setFillColor(sf::Color(46, 204, 113, 100)); break; // green
    case TileType::House : shape.setFillColor(sf::Color(231, 76, 60, 100)); break; // red
    case TileType::Community : shape.setFillColor(sf::Color(245, 230, 83, 100)); break; //yellow
    case TileType::Villager : shape.setFillColor(sf::Color::White); break;
    }
  }

  sf::RectangleShape& Tile::getTileShape(){return this->tileShape;}
  sf::IntRect Tile::getBoundaries(){return this->boundaries;}
  void Tile::setType(TileType type) {this->type = type;}
  TileType Tile::getType() {return this->type;}
  void Tile::setZoneTiles(std::vector<Tile*> zoneTiles){ this->zoneTiles = zoneTiles;}
  std::vector<Tile*>& Tile::getZoneTiles() {return this->zoneTiles;}
  void Tile::setGridPosition(int gridPosition){ this->gridPosition = gridPosition;}
  int Tile::getGridPosition() {return this->gridPosition;}

}

#endif
