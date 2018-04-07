##############################################################################
# Subdirectories
##############################################################################

add_subdirectory(lib)

##############################################################################
# Binaries
##############################################################################

add_executable(world main.cpp)
target_link_libraries(world agent_plugin_framework dl)

install(
  TARGETS
    world
  RUNTIME DESTINATION
    bin
  )
