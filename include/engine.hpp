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
#include "world.hpp"

namespace X11 {
  class Engine {
  private:
    World world;
    void handleMouseButtonPressed(sf::RenderWindow& window);
    void handleEvents(sf::RenderWindow& window);
    void update();
  public:
    Engine();
    virtual ~Engine();
    void initialize();
    void run();
    World& getWorld();
  };

};

#endif
