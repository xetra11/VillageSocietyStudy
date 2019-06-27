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

  class World {
  private:
    std::vector<Zone*> zones;
    std::vector<Villager*> villagers;
    void drawZones(sf::RenderWindow& window);
    void drawVillagers(sf::RenderWindow& window);
  public:
    World();
    virtual ~World();
    void drawAssets(sf::RenderWindow& window);
    void setZones(std::vector<Zone*> zones);
    void setVillagers(std::vector<Villager*> villagers);
  };

};

#endif
