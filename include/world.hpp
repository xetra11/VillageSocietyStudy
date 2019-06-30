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

  enum class TileType : char { Empty='n', Estate='e', Workshop='w', House='h', Community='c', Villager='v'};
  class Tile {
    sf::RectangleShape tileShape;
    sf::IntRect boundaries;
    TileType type;
    int id;
    std::vector<Tile*> zoneTiles;
  public:
    Tile();
    Tile(sf::Vector2f position);
    bool isSelected;
    virtual ~Tile();
    sf::RectangleShape& getTileShape();
    sf::IntRect getBoundaries();
    void setType(TileType type);
    TileType getType();
    void setId(int id);
    int getId();
    std::vector<Tile*>& getZoneTiles();
    void setZoneTiles(std::vector<Tile*> zoneTiles);
    static void setColorByType(TileType type, sf::Shape& shape);
  };

  class World {
  private:
    std::vector<Tile> grid;
    void drawGrid(sf::RenderWindow& window);
    Tile* selectedTile;
  public:
    World();
    virtual ~World();
    void drawAssets(sf::RenderWindow& window);
    void setWorldGrid(std::vector<Tile> grid);
    std::vector<Tile>&  getWorldGrid();
    Tile* getTileAtPosition(sf::Vector2i position);
    Tile* getSelectedTile();
    void setSelectedTile(Tile* tile);
  };
}


#endif
