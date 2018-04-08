##############################################################################
# Libraries
##############################################################################

add_library(plugins plugin.cpp)

add_library(plugin_manager plugin_manager.cpp shared_library.cpp)
target_link_libraries(plugin_manager plugins dl drake::drake)

add_library(agents agent_foo.cpp)
target_link_libraries(agents plugins drake::drake)

##############################################################################
# Installs
##############################################################################

install(
  TARGETS
    plugins
    plugin_manager
    agents
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)
