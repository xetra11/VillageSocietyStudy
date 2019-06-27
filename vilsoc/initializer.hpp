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
    std::vector<sf::IntRect> occupiedAreas;
    bool isOccupied(sf::IntRect areaRect);
    sf::Vector2i getRandomPosition();
    sf::Vector2i getRandomPosition(sf::IntRect boundaries);
    void affectFillColorRadius(std::vector<Tile*>& grid, sf::Vector2i& center, int radius, sf::Color color);

  public:
    Initializer();
    virtual ~Initializer();

    void initEstates(std::vector<Tile*>& grid);
    void initCommunityAreas();
    void initWorkspaces();
    void initHouses();
    void initVillagers();
    std::vector<Tile*> initWorldGrid();
  };
}

#endif
