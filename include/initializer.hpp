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
#include "villager.hpp"
#include "layer.hpp"

namespace X11 {

  class Initializer {
  private:
    static sf::Vector2i getRandomPosition(std::vector<Tile>& grid);
    static sf::Vector2i getRandomPosition(sf::IntRect boundaries);
    static void affectRectangle(std::vector<Tile>& grid, sf::Vector2i& topleft, int size, TileType type);
    static bool isRectAreaOccupied(std::vector<Tile>& grid, sf::Vector2i& topleft, int size);

  public:
    static void initObjects(TileType type, std::vector<Tile>& grid, int size, int amount);
    static void initBackgroundLayer(Layer& layer);
  };
}

#endif
