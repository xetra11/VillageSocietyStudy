/**
 * The game engine
 *
 * @file engine.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "config.hpp"
#include "initializer.hpp"
#include "villager.hpp"
#include "zone.hpp"

namespace X11 {
  class Engine {
  private:
    std::vector<Zone*> zones;
    std::vector<Villager*> villagers;
    void drawZones(sf::RenderWindow* window);
    void drawVillagers(sf::RenderWindow* window);
  public:
    Engine();
    virtual ~Engine();
    void initialize();
    void update();
    void draw(sf::RenderWindow* window);
  };

};

#endif
