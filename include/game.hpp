/**
 * the game system
 *
 * @file game.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

namespace X11 {
  class Game {
  private:
    int selectedTilePosition;
  public:
    int getSelectedTilePosition();
    void setSelectedTilePosition(int gridIndex);
  };
}

#endif
