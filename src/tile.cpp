/**
 * The grid tile class
 *
 * @file tile.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef TILE_CPP
#define TILE_CPP

#define PERSPECTIVE_DELTA TILE_SIZE - (TILE_SIZE * 0.25)

#include "tile.hpp"

namespace X11 {

  Tile::Tile() : type{TileType::Empty}, zone_tiles{std::vector<Tile*>()}, grid_position{0}, is_selected{false} {}

  Tile::Tile(sf::Vector2f position) : type{TileType::Empty}, zone_tiles{std::vector<Tile*>()}, grid_position{0},
                                      is_selected{false} {
    sf::Vector2f size(TILE_SIZE, TILE_SIZE);
    this->tile_shape = sf::RectangleShape(size);
    this->tile_shape.setFillColor(sf::Color::Transparent);
    this->tile_shape.setPosition(position);

    sf::Vector2i rectSize(TILE_SIZE, TILE_SIZE);
    sf::Vector2i rectPos(this->tile_shape.getPosition().x, this->tile_shape.getPosition().y);
    this->boundaries = sf::IntRect(rectPos, rectSize);
  }

  Tile::~Tile() = default;

  void Tile::set_color_by_type(TileType type, sf::Shape& shape) {
    switch (type) {
      case TileType::Empty :
        shape.setFillColor(sf::Color::Transparent);
        break;
      case TileType::Estate :
        shape.setFillColor(sf::Color(249, 180, 45, 100));
        break; //orange
      case TileType::Workshop :
        shape.setFillColor(sf::Color(46, 204, 113, 100));
        break; // green
      case TileType::House :
        shape.setFillColor(sf::Color(231, 76, 60, 100));
        break; // red
      case TileType::Community :
        shape.setFillColor(sf::Color(245, 230, 83, 100));
        break; //yellow
      case TileType::Villager :
        shape.setFillColor(sf::Color::White);
        break;
    }
  }

  sf::RectangleShape& Tile::get_tile_shape() { return this->tile_shape; }

  sf::IntRect Tile::get_boundaries() { return this->boundaries; }

  void Tile::set_type(TileType type) { this->type = type; }

  TileType Tile::get_type() { return this->type; }

  void Tile::set_zone_tiles(std::vector<Tile*> zone_tiles) { this->zone_tiles = std::move(zone_tiles); }

  std::vector<Tile*>& Tile::get_zone_tiles() { return this->zone_tiles; }

  void Tile::set_grid_position(int grid_index) { this->grid_position = grid_index; }

  int Tile::get_grid_position() { return this->grid_position; }

  void Tile::place_onto(sf::Shape* shape) {
    spdlog::warn("Tile::place_onto(sf::Shape* shape) not yet implented");
  }

  void Tile::place_onto(Villager& villager) {
    sf::Vector2f tile_pos = this->get_tile_shape().getPosition();
    sf::Vector2f size = this->get_tile_shape().getSize();
    sf::Vector2f tile_center_pos = sf::Vector2f(tile_pos.x + size.x / 2, tile_pos.y + size.y / 2);
    sf::Vector2f villager_pos = sf::Vector2f(tile_center_pos.x, tile_center_pos.y - PERSPECTIVE_DELTA);
    villager.set_destination(*this);
  }

}

#endif
