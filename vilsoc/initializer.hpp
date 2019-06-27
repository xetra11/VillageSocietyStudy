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

using namespace std;

namespace X11 {

  class Initializer {
  private:
    sf::Vector2i getRandomPosition();
    sf::Vector2i getRandomPosition(sf::IntRect boundaries);
    void affectRectangle(std::vector<Tile*>& grid, sf::Vector2i& topleft, int size, TileType type);

  public:
    Initializer();
    virtual ~Initializer();

    void initEstates(std::vector<Tile*>& grid);
    void initCommunityAreas(std::vector<Tile*>& grid);
    void initWorkspaces(std::vector<Tile*>& grid);
    void initHouses(std::vector<Tile*>& grid);
    void initVillagers(std::vector<Tile*>& grid);
    std::vector<Tile*> initWorldGrid();
  };
}

#endif
