##############################################################################
# Libraries
##############################################################################

add_library(agent_plugin_framework agent_plugin_base.cpp)

add_library(agents agents.cpp)
target_link_libraries(agents agent_plugin_framework)

install(
  TARGETS
    agent_plugin_framework
    agents
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)
