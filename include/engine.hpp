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
#include "menu.hpp"

#define BACKGROUND 0
#define SCENE 1
#define FOREGROUND 2
#define MENU 3

namespace X11 {
  enum class Direction {Left, Right, Up, Down};

  class Engine {
  private:
    Menu menu;
    Game game;
    void on_mouse_button(sf::RenderWindow& window);
    void on_key(sf::Event& event, sf::RenderWindow& window);
    void move_main_view(Direction direction, sf::RenderWindow& window);

    void handle_events(sf::RenderWindow& window);
    void update();
    std::vector<Layer> render_layer;
  public:
    Engine();
    virtual ~Engine();

    void run();
    void run_main(sf::RenderWindow& window);
    void run_minimap(sf::RenderWindow& window);
    void run_menu(sf::RenderWindow& window);
    void render_game(sf::RenderWindow& window);
    void render_menu(sf::RenderWindow& window);
    void eval_tick(sf::Clock& clock);

    sf::View menu_view;
    sf::View main_view;
    sf::View minimap_view;

    Game& get_game();
    Layer& get_background_layer();
    Layer& get_scene_layer();
    Layer& get_foreground_layer();
    Layer& get_menu_layer();
  };

};

#endif
