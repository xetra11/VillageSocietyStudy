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
#include "game.hpp"

#define BACKGROUND 0
#define SCENE 1
#define FOREGROUND 2

namespace X11 {
  class Engine {
  private:
    Game game;
    World world;
    void handleMouseButtonPressed(sf::RenderWindow& window);
    void handleEvents(sf::RenderWindow& window);
    void update();
    std::vector<std::vector<Tile>> renderLayer;
  public:
    Engine();
    virtual ~Engine();
    void initialize();
    void run();
    World& getWorld();
    Game& getGame();
    std::vector<Tile>& getBackgroundGrid();
    std::vector<Tile>& getSceneGrid();
    std::vector<Tile>& getForegroundGrid();
  };

};

#endif
