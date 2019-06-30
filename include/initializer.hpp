/*
 * Initializes VilSoc assets
 *
 * @file initializer.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef INITIALIZER_HPP
#define INTIALIZER_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "villager.hpp"
#include "world.hpp"

namespace X11 {

  class Initializer {
  private:
    sf::Vector2i getRandomPosition(std::vector<Tile>& grid);
    sf::Vector2i getRandomPosition(sf::IntRect boundaries);
    void affectRectangle(std::vector<Tile>& grid, sf::Vector2i& topleft, int size, TileType type);
    bool isRectAreaOccupied(std::vector<Tile>& grid, sf::Vector2i& topleft, int size);

  public:
    Initializer();
    virtual ~Initializer();

    void initObjects(TileType type, std::vector<Tile>& grid, int size, int amount);
    std::vector<Tile> initWorldGrid();
  };
}

#endif
