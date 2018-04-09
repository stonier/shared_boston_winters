
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

  sbw::PluginManager<sbw::AgentPlugin> plugin_manager;
  sbw::AgentPlugin* agent_plugin = plugin_manager.findPlugin(plugin_name);
  std::cout << "Agent Plugin has this to say: " << agent_plugin->getSayHelloString() << std::endl;

  return 0;
}
