/**
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
#include "zone.hpp"

namespace X11 {

  class Initializer {
  private:
    std::vector<sf::IntRect> occupiedAreas;
    bool isOccupied(sf::IntRect areaRect);
    sf::Vector2i getRandomPosition(int offsetSize);
    std::vector<Zone*> initObjects(int objectAmount, int objectSize, sf::Color color);

  public:
    Initializer();
    virtual ~Initializer();

    std::vector<Zone*> initVillageEstates();
    std::vector<Zone*> initCommunityAreas();
    void initHouses();
    void initVillagers();
    // std::vector<sf::RectangleShape*> initWorkspaces();
  };
}

#endif
