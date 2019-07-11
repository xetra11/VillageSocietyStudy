/**
 * Util functions
 *
 * @file utils.cpp
 * @author Patrick Charles H. | xetra11
 */

#include <utils.hpp>

namespace X11 {
  float Utils::random_float(float min, float max) {
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(min, max);
    int randX = dist(engine);
    return randX;
  }
}

