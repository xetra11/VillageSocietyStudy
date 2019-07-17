/**
 * the resource manager
 *
 * @file resources.hpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include "config.hpp"
#include <SFML/Graphics.hpp>

namespace X11 {
  enum class Font {DejaVuSans};
  class ResourceManager {
  private:
    static ResourceManager* _instance;
    ResourceManager() {
      spdlog::info("loading resources...");
      spdlog::info("loading fonts...");
      sf::Font font;
      if (font.loadFromFile("data/fonts/DejaVuSans.ttf")){
        this->fonts.insert(std::pair<Font, sf::Font>(Font::DejaVuSans, font));
      } else {
        spdlog::error("fonts could not be loaded");
      };
      spdlog::info("resources loaded");
    };
    ResourceManager (const ResourceManager&);
    ~ResourceManager() = default;
  public:
    static ResourceManager* instance();
    std::map<Font, sf::Font> fonts;
  };
}
#endif
