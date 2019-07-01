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
#include "tile.hpp"
#include "game.hpp"
#include "layer.hpp"
#include "gridrenderer.hpp"

#define BACKGROUND 0
#define SCENE 1
#define FOREGROUND 2

namespace X11 {

  class Engine {
  private:
    Game game;
    void handleMouseButtonPressed(sf::RenderWindow& window);
    void handleEvents(sf::RenderWindow& window);
    void update();
    std::vector<Layer> renderLayer;
  public:
    Engine();
    virtual ~Engine();
    void run();
    Game& getGame();
    Layer& getBackgroundLayer();
    Layer& getSceneLayer();
    Layer& getForegroundLayer();
  };

};

#endif
