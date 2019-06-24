/**
 * Initializes VilSoc assets
 *
 * @file initializer.hpp
 * @author Patrick Charles H. | xetra11
 */

#include <SFML/Graphics.hpp>

namespace X11 {
  struct Position {
    int x, y;
    Position(int, int);
  };

  class Initializer {
  private:
    std::vector<Position> getRandomPositions(int amount);
  public:
    Initializer();
    virtual ~Initializer();

    std::vector<sf::CircleShape*> initVillageEstates();
    void initHouses();
    void initVillagers();
    void initWorkspaces();
    void initCommunityAreas();
  };
}
