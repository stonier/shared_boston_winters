/**
 * @file /sbw/include/sbw/plugin_manager.hpp
 */
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef sbw_PLUGIN_MANAGER_HPP_
#define sbw_PLUGIN_MANAGER_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <map>
#include <memory>
#include <string>

#include "plugin.hpp"
#include "shared_library.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sbw {

/*****************************************************************************
** Methods
*****************************************************************************/

typedef Plugin* (*plugin_init_func)(void);

/*****************************************************************************
** Interfaces
*****************************************************************************/

class PluginManager {
public:
  static PluginManager& instance();

  Plugin& findPlugin(const std::string& name)
    throw (SharedLibraryException);

private:
  struct PluginInfo {
    std::unique_ptr<SharedLibrary> library;
    Plugin* plugin;
    std::string library_name;

    PluginInfo() : library(nullptr), plugin(nullptr) {}
    ~PluginInfo() { delete plugin; }
  };

  PluginManager() {}
  static PluginManager* instance_;
  std::map<std::string, PluginInfo* > plugin_map_;
};



/*****************************************************************************
** Trailers
*****************************************************************************/

} // namespace sbw

#endif /* sbw_PLUGIN_MANAGER_HPP_ */
