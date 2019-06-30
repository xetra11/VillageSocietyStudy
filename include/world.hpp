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
#include "tile.hpp"

namespace X11 {

  class World {
  private:
    std::vector<Tile> grid;
    void drawGrid(sf::RenderWindow& window);
  public:
    World();
    virtual ~World();
    void drawAssets(sf::RenderWindow& window);
    void setWorldGrid(std::vector<Tile> grid);
    std::vector<Tile>&  getWorldGrid();
    Tile* getTileAtPosition(sf::Vector2i position);
  };
}


#endif
