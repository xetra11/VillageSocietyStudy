/**
 * Entry of game engine for the village society AI study
 *
 * @file vilsoc.hpp
 * @author Patrick Charles H. | xetra11
 */

#include <SFML/Graphics.hpp>

namespace X11 {
  class VillageSociety {
    private:
      sf::RenderWindow* window;
      sf::CircleShape* shape;

    public:
      VillageSociety();
      virtual ~VillageSociety();
      int run();
  };
}
