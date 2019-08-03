#ifndef FONTMANAGER_HPP
#define FONTMANAGER_HPP

#include "config.hpp"

namespace X11 {
  class FontManager : public ResourceManager<FontManager, sf::Font> {
  public:
    TextureManager() : ResourceManager("fonts.cfg"){}
  }
}

#endif
