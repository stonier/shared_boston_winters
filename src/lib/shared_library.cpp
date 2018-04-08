/**
 * @file /sbw/src/lib/shared_library.cpp
 */
/*****************************************************************************
** Includes
*****************************************************************************/

#include "../../include/sbw/shared_library.hpp"

#include <iostream>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sbw {

/*****************************************************************************
** Implementation
*****************************************************************************/

SharedLibrary::SharedLibrary(const std::string& name)
    throw (SharedLibraryException)
    : handle_(nullptr)
{

  handle_ = ::dlopen(name.c_str(), RTLD_GLOBAL | RTLD_NOW);
  if (!handle_) {
    const char* s = ::dlerror();
    throw SharedLibraryException(s ? s : "Exact Error Not Reported");
  }
}

SharedLibrary::~SharedLibrary()
{
  ::dlclose(handle_);
}

/*****************************************************************************
 ** Trailers
 *****************************************************************************/

} // namespace sbw
