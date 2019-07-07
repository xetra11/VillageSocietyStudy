/**
 * The game engine
 *
 * @file engine.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ENGINE_CPP
#define ENGINE_CPP

#include "engine.hpp"
#include <iostream>

namespace X11 {
  Engine::Engine() : render_layer{std::vector<Layer>(3)}, game{Game()} {
    spdlog::info("setup engine");
    spdlog::info("init background layer");
    Initializer::init_background_layer(this->get_background_layer());
    spdlog::info("init scene layer");
    Initializer::init_scene_layer(this->get_scene_layer());
    spdlog::info("init foreground layer");
    Initializer::init_layer(this->get_foreground_layer());
    spdlog::info("init game");
    Initializer::init_game(this->game);
  }

  Engine::~Engine() = default;

  void Engine::update() {
    // update routines for normal tiles
    Grid& background_grid = this->get_background_layer().get_grid();
    Grid& scene_grid = this->get_scene_layer().get_grid();
    Grid& foreground_grid = this->get_foreground_layer().get_grid();
    GridRenderer::empty_tiles(background_grid);
    GridRenderer::empty_tiles(scene_grid);
    GridRenderer::empty_tiles(foreground_grid);

    // update selected tile
    int selected_tile_index = this->get_game().get_selected_tile_position();
    if (selected_tile_index == -1) {
      spdlog::info("no tile selected");
    } else {
      // highlight still in background layer because there are zones rendered
      Tile& bg_selected_tile = background_grid[selected_tile_index];
      std::vector<Tile*> zone_tiles = bg_selected_tile.get_zone_tiles();
      for (Tile* zone_tile : zone_tiles) {
        GridRenderer::highlight_tile(*zone_tile);
      }

      // select marker in scene layer
      Tile& fg_selected_tile = foreground_grid[selected_tile_index];
      GridRenderer::outline_tile(fg_selected_tile);
    }
  }

  void Engine::run() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "VilSoc");
    while (window.isOpen()) {
      this->handle_events(window);
      this->update();
      window.clear();
      this->get_background_layer().draw_layer(window);
      this->get_scene_layer().draw_layer(window);
      this->get_foreground_layer().draw_layer(window);
      for (Villager villager : this->game.get_villagers()) {
        for (sf::Shape* shape : villager.get_shapes()) {
          window.draw(*shape);
        }
      }
      window.display();
    }
  }

  Game& Engine::get_game() { return this->game; }

  void Engine::handle_mouse_button_pressed(sf::RenderWindow& window) {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::Vector2f coord_pos = window.mapPixelToCoords(mouse_pos);
    int grid_pos_index = GridRenderer::map_coords_to_grid_pos(coord_pos);
    if (grid_pos_index >= MAX_GRID_INDEX) {
      spdlog::error("mouse cursor is out of grid bounds");
      spdlog::info("grid index was {}", grid_pos_index);
    } else {
      this->game.set_selected_tile_position(grid_pos_index);
    }
  }

  void Engine::handle_events(sf::RenderWindow& window) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::MouseButtonPressed) {
        this->handle_mouse_button_pressed(window);
      }
    }
  }

  Layer& Engine::get_background_layer() { return this->render_layer[BACKGROUND]; }

  Layer& Engine::get_scene_layer() { return this->render_layer[SCENE]; }

  Layer& Engine::get_foreground_layer() { return this->render_layer[FOREGROUND]; }

}

#endif
