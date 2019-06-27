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
    void drawGrid(sf::RenderWindow& window);
  public:
    World();
    virtual ~World();
    void drawAssets(sf::RenderWindow& window);
    void setWorldGrid(std::vector<Tile*> grid);
    std::vector<Tile*>&  getWorldGrid();
  };
}

#endif
