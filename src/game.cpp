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

  void Game::setSelectedTilePosition(int gridIndex){ this->selectedTilePosition = gridIndex;}
  int Game::getSelectedTilePosition() { return this->selectedTilePosition;}

}
#endif
