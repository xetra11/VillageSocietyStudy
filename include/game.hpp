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
    sf::Vector2i selectedTilePosition;
  public:
    sf::Vector2i getSelectedTilePosition();
    void setSelectedTilePosition(int x, int y);
    void setSelectedTilePosition(sf::Vector2i gridPosition);
  };
}

#endif
