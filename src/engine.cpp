/**
 * The game engine
 *
 * @file engine.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef ENGINE_CPP
#define ENGINE_CPP

#define FPS (1.0f/60.0f)

#include "engine.hpp"
#include <iostream>

namespace X11 {
  Engine::Engine() : render_layer{std::vector<Layer>(4)}, game{Game()} {
    spdlog::info("setup engine");
    spdlog::info("init layer");

    Initializer::init_background_layer(this->get_background_layer());
    Initializer::init_scene_layer(this->get_scene_layer());
    Initializer::init_foreground_layer(this->get_foreground_layer());
    Initializer::init_menu_layer(this->get_menu_layer());

    Initializer::init_game(this->game, this->get_background_layer());
  }

  Engine::~Engine() = default;

  void Engine::update() {
    // update routines for normal tiles
    Grid& background_grid = this->get_background_layer().get_grid();
    // Grid& scene_grid = this->get_scene_layer().get_grid();
    Grid& foreground_grid = this->get_foreground_layer().get_grid();
    GridRenderer::empty_tiles(background_grid);
    // GridRenderer::empty_tiles(scene_grid);
    // GridRenderer::empty_tiles(foreground_grid);

    // update selected tile
    int selected_tile_index = this->get_game().get_selected_tile_position();
    if (selected_tile_index > -1) {
      // highlight still in background layer because there are zones rendered
      Tile& bg_selected_tile = background_grid[selected_tile_index];
      std::vector<Tile*> zone_tiles = bg_selected_tile.get_zone_tiles();
      for (Tile* zone_tile : zone_tiles) {
        GridRenderer::highlight_tile(*zone_tile);
      }
      // select marker in scene layer
      GridRenderer::outline_tile(bg_selected_tile);
    }
    this->game.change_daily_state();
    this->game.update_destination();
    this->game.move_villagers();
  }

  void Engine::run() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "VilSoc");
    this->main_view = sf::View(sf::FloatRect(0.f, 0.f, WINDOW_WIDTH, WINDOW_HEIGHT));
    this->main_view.setViewport(sf::FloatRect(0.25f, 0.25f, 0.5f, 0.5f));
    this->minimap_view = sf::View(sf::FloatRect(0.f, 0.f, WINDOW_WIDTH*2, WINDOW_HEIGHT*2));
    this->minimap_view.setViewport(sf::FloatRect(0.8f, 0.f, 0.1f, 0.1f));

    while (window.isOpen()) {
      window.clear();
      this->handle_events(window);
      this->update();
      this->render(window, this->main_view); // draw logic
//      this->render(window, this->minimap_view); // draw logic
      window.display();
    }
  }

  Game& Engine::get_game() { return this->game; }

  void Engine::on_mouse_button(sf::RenderWindow& window) {
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

  void Engine::on_key(sf::Event& event, sf::RenderWindow& window) {
    switch (event.key.code) {
      case sf::Keyboard::A :
      case sf::Keyboard::Left :
        this->move_main_view(Direction::Left, window);
        break;
      case sf::Keyboard::D :
      case sf::Keyboard::Right :
        this->move_main_view(Direction::Right, window);
        break;
      case sf::Keyboard::S :
      case sf::Keyboard::Down :
        this->move_main_view(Direction::Down, window);
        break;
      case sf::Keyboard::W :
      case sf::Keyboard::Up :
        this->move_main_view(Direction::Up, window);
        break;
      default :
        break;
    }
  }

  void Engine::move_main_view(Direction direction, sf::RenderWindow& window) {
    sf::View view = window.getView();
    switch (direction) {
      case Direction::Left :
        this->main_view.move(-100.f, 0.f);
        break;
      case Direction::Right :
        this->main_view.move(100.f, 0.f);
        break;
      case Direction::Down :
        this->main_view.move(0.f, 100.f);
        break;
      case Direction::Up :
        this->main_view.move(0.f, -100.f);
        break;
    }
    window.setView(this->main_view);
  }

  void Engine::handle_events(sf::RenderWindow& window) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::MouseButtonPressed) {
        this->on_mouse_button(window);
      }
      if (event.type == sf::Event::KeyPressed) {
        this->on_key(event, window);
      }
    }
  }

  Layer& Engine::get_background_layer() { return this->render_layer[BACKGROUND]; }

  Layer& Engine::get_scene_layer() { return this->render_layer[SCENE]; }

  Layer& Engine::get_foreground_layer() { return this->render_layer[FOREGROUND]; }

  Layer& Engine::get_menu_layer() { return this->render_layer[MENU]; }

  void Engine::render(sf::RenderWindow& window, sf::View& view) {
    window.setView(view);
    this->get_background_layer().draw_layer(window);
    this->get_menu_layer().draw_layer(window);

    for (Villager villager : this->game.get_villagers()) {
      for (sf::Shape* shape : villager.get_shapes()) {
        window.draw(*shape);
      }
    }
  }

}

#endif
