/*
 * Initializes VilSoc assets
 *
 * @file initializer.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef INITIALIZER_HPP
#define INTIALIZER_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <SFML/Graphics.hpp>
#include <random>
#include "config.hpp"
#include "layer.hpp"
#include "game.hpp"

namespace X11 {

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

    static void init_game(Game& game);
    static void init_villagers(Game& game);
  };
}

#endif
