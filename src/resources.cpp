/**
 * the resource manager
 *
 * @file resources.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef RESOURCES_CPP
#define RESOURCES_CPP

#include "resources.hpp"

namespace X11 {
  ResourceManager* ResourceManager::_instance = 0;
  ResourceManager* ResourceManager::instance() {
    if (!ResourceManager::_instance)
      ResourceManager::_instance = new ResourceManager();
    return ResourceManager::_instance;
  }
}

#endif
