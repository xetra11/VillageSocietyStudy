/**
 * the game system
 *
 * @file game.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include "assets.hpp"


namespace X11 {
  typedef std::vector<Villager> VillagerList;
  class Game {
  private:
    VillagerList villager_list;
    int selected_tile_position;
  public:
    int get_selected_tile_position();
    void set_selected_tile_position(int grid_index);
    VillagerList& get_villagers() {return this->villager_list;}
    void add_villager(Villager villager_ref) {
      this->villager_list.push_back( std::move(villager_ref));
    }
    void move_villagers(int speed);
  };
}

#endif
