/*
 * Initializes VilSoc assets
 *
 * @file initializer.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef INITIALIZER_HPP
#define INTIALIZER_HPP

#define MAX_RANDOM_TRIES 25

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <SFML/Graphics.hpp>
#include <random>
#include "config.hpp"
#include "layer.hpp"
#include "game.hpp"
#include "menu/menu.hpp"
#include "menu/label.hpp"
#include "resources.hpp"
#include "text.hpp"

namespace X11 {
  class Game;
  class Initializer {
  private:
    static sf::Vector2i get_random_position(Grid& grid);
    static sf::Vector2i getRandomPosition(sf::IntRect boundaries);
    static void affect_rectangle(Grid& grid, sf::Vector2i& topleft, int size, TileType type);
    static bool is_rect_area_occupied(Grid& grid, sf::Vector2i& topleft, int size);

  public:
    static void init_zones(TileType type, Grid& grid, int size, int amount);
    static void init_assets(Layer& layer);
    static void init_layer(Layer& layer);
    static void init_scene_layer(Layer& layer);
    static void init_background_layer(Layer& layer);
    static void init_foreground_layer(Layer& layer);

    static void init_game(Game& game, Layer& layer);
    static void init_left_menu(Menu& menu);
    static void init_right_menu(Menu& menu);
    static void init_bottom_menu(Menu& menu);

    static void init_villagers(Game& game);
    static std::vector<Tile*> get_zones_by_type(TileType type, Layer& layer);

    static void init_tick_text(Menu& menu, const sf::Vector2f& position);
    static void init_tile_info_text(Menu& menu, const sf::Vector2f& position);
  };
}

#endif
