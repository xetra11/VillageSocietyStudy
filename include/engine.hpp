/**
 * The game engine
 *
 * @file engine.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "config.hpp"
#include "tile.hpp"
#include "game.hpp"
#include "layer.hpp"
#include "gridrenderer.hpp"
#include "initializer.hpp"

#define BACKGROUND 0
#define SCENE 1
#define FOREGROUND 2
#define MENU 3

namespace X11 {

  class Engine {
  private:
    Game game;
    void handle_mouse_button_pressed(sf::RenderWindow& window);
    void handle_events(sf::RenderWindow& window);
    void update();
    std::vector<Layer> render_layer;
  public:
    Engine();
    virtual ~Engine();
    void run();
    Game& get_game();
    Layer& get_background_layer();
    Layer& get_scene_layer();
    Layer& get_foreground_layer();
    Layer& get_menu_layer();
  };

};

#endif
