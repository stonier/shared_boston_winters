/**
 * @file /sbw/include/sbw/agents.hpp
 */
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef sbw_AGENTS_HPP_
#define sbw_AGENTS_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include "agent_plugin_base.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sbw {

/*****************************************************************************
** Interfaces
*****************************************************************************/

class Foo : public AgentPluginBase {
public:
  Foo();
  virtual ~Foo();
  void init() override;
  void update() override;
};

/*****************************************************************************
** Trailers
*****************************************************************************/

} // namespace sbw

#endif /* sbw_AGENTS_HPP_ */
