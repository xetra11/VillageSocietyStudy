/**
 * Initializes VilSoc assets
 *
 * @file initializer.hpp
 * @author Patrick Charles H. | xetra11
 */

#include <SFML/Graphics.hpp>

namespace X11 {
  class Initializer {
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
