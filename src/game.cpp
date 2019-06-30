/**
 * the game system
 *
 * @file game.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef GAME_CPP
#define GAME_CPP

#include "game.hpp"

namespace X11 {

  void Game::setSelectedTilePosition(int x, int y){
    this->setSelectedTilePosition(sf::Vector2i(x,y));
  }
  void Game::setSelectedTilePosition(sf::Vector2i gridPosition){ this->selectedTilePosition = gridPosition;}
  sf::Vector2i Game::getSelectedTilePosition() { return this->selectedTilePosition;}

}
#endif
