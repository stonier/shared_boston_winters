/**
 * @file /sbw/src/lib/plugin_manager.cpp
 */
/*****************************************************************************
** Includes
*****************************************************************************/

#include "../../include/sbw/plugin_manager.hpp"

#include <functional>
#include <iostream>

#include "../../include/sbw/plugin.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sbw {

/*****************************************************************************
** Implementation
*****************************************************************************/

PluginManager* PluginManager::instance_ = nullptr;

PluginManager& PluginManager::instance()
{
  if (! instance_) {
    instance_ = new PluginManager();
  }
  return *instance_;
}

Plugin& PluginManager::findPlugin(const std::string& name)
    throw (SharedLibraryException)
{
  if (plugin_map_.count(name) > 0) {
    return *(plugin_map_[name])->plugin;
  }

  PluginInfo* plugin_info = new PluginInfo;
  plugin_info->library = std::make_unique<SharedLibrary>(name);

  std::function<Plugin*()> plugin_init{
    plugin_info->library->findSymbol<Plugin*()>("plugin_init")
  };
  plugin_info->plugin = plugin_init();

  if (!plugin_info->plugin) {
    delete plugin_info;
    throw SharedLibraryException("plugin_init error");
  }
  plugin_map_[name] = plugin_info;
  return *(plugin_info->plugin);
}

/*****************************************************************************
 ** Trailers
 *****************************************************************************/

} // namespace sbw
