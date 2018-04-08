/**
 * @file /sbw/include/sbw/plugin.hpp
 */
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef sbw_PLUGIN_HPP_
#define sbw_PLUGIN_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <string>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sbw {

/*****************************************************************************
** Interfaces
*****************************************************************************/

class Plugin {
public:
  Plugin(const std::string& plugin_name, const std::string& plugin_type)
           : plugin_name_(plugin_name), plugin_type_(plugin_type) {}
  virtual ~Plugin() {}

  virtual const std::string& pluginName() const;
  virtual const std::string& pluginType() const;

private:
  std::string plugin_name_;
  std::string plugin_type_;
};
/*****************************************************************************
** Trailers
*****************************************************************************/

} // namespace sbw

#endif /* sbw_PLUGIN_HPP_ */
