/**
 * @file /sbw/src/lib/agent_foo.cpp
 */
/*****************************************************************************
** Includes
*****************************************************************************/

#include "../../include/sbw/agent_foo.hpp"

#include <drake/systems/framework/leaf_system.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sbw {

class FooSystem : public drake::systems::LeafSystem<double> {
public:
  DRAKE_NO_COPY_NO_MOVE_NO_ASSIGN(FooSystem)
  FooSystem() {
    std::cout << "Drake System Foo" << std::endl;
  }
};

/*****************************************************************************
** Implementation
*****************************************************************************/

FooAgentPlugin::FooAgentPlugin() : AgentPlugin("Foo")
{
  FooSystem foo_system;
}
FooAgentPlugin::~FooAgentPlugin() {}

const char* FooAgentPlugin::getSayHelloString() const
{
  return "Hello, World from Foo!";
}

/*****************************************************************************
 ** Trailers
 *****************************************************************************/

} // namespace sbw
