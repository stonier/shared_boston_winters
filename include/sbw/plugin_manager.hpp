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

#include <functional>
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
** Interfaces
*****************************************************************************/

/**
 * TODO: Should this be a singleton class? What happens if two
 * managers try and load separately from the same dynamically loadable
 * library?
 *
 * @tparam PluginType the plugin type, e.g. AgentPlugin
 */
template <typename PluginType>
class PluginManager {
public:
  PluginManager();

  PluginType* findPlugin(const std::string& name)
    throw (SharedLibraryException);

private:
  struct PluginInfo {
    std::unique_ptr<SharedLibrary> library;
    Plugin* plugin;
    std::string library_name;

    PluginInfo() : library(nullptr), plugin(nullptr) {}
    ~PluginInfo() { delete plugin; }
  };

  std::map<std::string, PluginInfo* > plugin_map_;
};

/*****************************************************************************
** Template Implementation
*****************************************************************************/

template <typename PluginType>
PluginManager<PluginType>::PluginManager()
{
}

template <typename PluginType>
PluginType* PluginManager<PluginType>::findPlugin(const std::string& name)
    throw (SharedLibraryException)
{
  if (plugin_map_.count(name) > 0) {
    return dynamic_cast<sbw::AgentPlugin*>(plugin_map_[name]->plugin);
  }

  PluginInfo* plugin_info = new PluginInfo;
  plugin_info->library = std::make_unique<SharedLibrary>(name);

  std::function<Plugin*()> create_plugin{
    plugin_info->library->template findSymbol<Plugin*()>("create_plugin")
  };
  plugin_info->plugin = create_plugin();

  if (!plugin_info->plugin) {
    delete plugin_info;
    throw SharedLibraryException("create_plugin error");
  }
  plugin_map_[name] = plugin_info;

  // TODO: A means to check that it has the correct plugin->pluginType() value

  return dynamic_cast<sbw::AgentPlugin*>(plugin_info->plugin);
}



/*****************************************************************************
** Trailers
*****************************************************************************/

} // namespace sbw

#endif /* sbw_PLUGIN_MANAGER_HPP_ */
