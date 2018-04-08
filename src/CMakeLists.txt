##############################################################################
# Subdirectories
##############################################################################

add_subdirectory(lib)

##############################################################################
# Binaries
##############################################################################

add_executable(world main.cpp)
target_link_libraries(world plugin_manager plugins)

install(
  TARGETS
    world
  RUNTIME DESTINATION
    bin
  )
