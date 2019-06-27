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
    World* world;
  public:
    Engine();
    virtual ~Engine();
    void initialize();
    void update();
    void run();
    World* getWorld();
  };

};

#endif
