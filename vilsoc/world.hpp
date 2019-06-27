/**
 * The world container
 *
 * @file world.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef WORLD_HPP
#define WORLD_HPP

#include "config.hpp"
#include "villager.hpp"
#include "zone.hpp"

namespace X11 {

  class Tile {
  private:
    sf::RectangleShape tileShape;
    sf::IntRect boundaries;
  public:
    Tile();
    Tile(sf::Vector2f position);
    virtual ~Tile();
    sf::RectangleShape& getTileShape();
    sf::IntRect getBoundaries();
  };

  class World {
  private:
    std::vector<Tile*> grid;
    std::vector<Zone*> zones;
    std::vector<Villager*> villagers;
    void drawGrid(sf::RenderWindow& window);
    void drawZones(sf::RenderWindow& window);
    void drawVillagers(sf::RenderWindow& window);
  public:
    World();
    virtual ~World();
    void drawAssets(sf::RenderWindow& window);
    void setZones(std::vector<Zone*> zones);
    void setVillagers(std::vector<Villager*> villagers);
    void setWorldGrid(std::vector<Tile*> grid);
  };
}

#endif
