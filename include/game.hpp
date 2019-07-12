/**
 * the game system
 *
 * @file game.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include "assets.hpp"
#include "utils.hpp"
#include "layer.hpp"

namespace X11 {
  typedef std::vector<Villager> VillagerList;
  enum class TaskState  {Home, Work, Community};
  class Game {
  private:
    int selected_tile_position;
    VillagerList villager_list;
  public:
    int get_selected_tile_position();
    void set_selected_tile_position(int grid_index);
    VillagerList& get_villagers() {return this->villager_list;}
    void add_villager(Villager villager_ref) {
      this->villager_list.push_back( villager_ref);
    }
    void move_villagers();
    void update_daily_tasks(Layer& background_layer);
    long int tick;
    TaskState daily_state = TaskState::Home;
    std::vector<Tile*> homes;
    std::vector<Tile*> workplaces;
    std::vector<Tile*> community_areas;
  };
}

#endif
