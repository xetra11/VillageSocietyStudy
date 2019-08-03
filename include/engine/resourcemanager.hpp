#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include "config.hpp"

namespace X11 {
  template<typename Derived, typename T>
  class ResourceManager {
  public:
    ResourceManager(const std::string& resourceConfigPath) {
      load_paths(resourceConfigPath);
    }

    virtual ~ResourceManager() {}
    T* get_resource(const std::string& id);
    std::string get_path(const std::string& id);
    std::string require_resource(const std::string& id);
    std::string release_resource(const std::string& id);
    std::string purge_resource();
  protected:
    bool load(T* resource, const std::string& path);
  private:
    void load_paths(const std::string& resourceConfigPath);
  };
}

#endif
