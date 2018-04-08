
// testso.cpp

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include <iostream>

#include "../include/sbw/agent_plugin.hpp"
#include "../include/sbw/plugin_manager.hpp"

/*****************************************************************************
 * Main
 ****************************************************************************/

int main(int argc, char **argv) {
  // in real usage, you'd have an external mechanism feed strings
  // to the loading program (e.g. command line arguments, ...) so
  // that you don't have to recompile the loading program
  const std::string plugin_name = "libagents.so";

  sbw::PluginManager plugin_manager;
  sbw::Plugin& plugin = plugin_manager.findPlugin(plugin_name);
  std::cout << "Name: " << plugin.pluginName() << std::endl;
  std::cout << "Type: " << plugin.pluginType() << std::endl;

  if (plugin.pluginType() == "Agent") {
    sbw::AgentPlugin& agent_plugin = dynamic_cast<sbw::AgentPlugin&>(plugin);
    std::cout << "Has this to say: " << agent_plugin.getSayHelloString() << std::endl;
  }

  return 0;
}
