/**
 * @file /sbw/include/sbw/shared_library.hpp
 */
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef sbw_SHARED_LIBRARY_HPP_
#define sbw_SHARED_LIBRARY_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <dlfcn.h>

#include <exception>
#include <functional>
#include <string>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sbw {

/*****************************************************************************
** Interfaces
*****************************************************************************/

class SharedLibraryException : public std::exception {
public:
  SharedLibraryException(const std::string& error) : error_(error) { }
  const char* what() const noexcept { return error_.c_str(); }
private:
  std::string error_;
};

class SharedLibrary {
public:
  SharedLibrary(const std::string& name) throw(SharedLibraryException);
  ~SharedLibrary();

  template<typename T>
  std::function<T> findSymbol(const std::string& name) const
    throw(SharedLibraryException);
private:
  void* handle_;
};

/*****************************************************************************
** Template Implementations
*****************************************************************************/

template<typename T>
std::function<T> SharedLibrary::findSymbol(const std::string& name) const
  throw (SharedLibraryException)
{
  dlerror(); // clear error flags
  void* symbol_address = dlsym(handle_, name.c_str());
  if ( dlerror() ) {
    throw SharedLibraryException(std::string("Symbol Not Found [") + name + std::string("]"));
  }
  return reinterpret_cast<T*>(symbol_address);
}

/*****************************************************************************
** Trailers
*****************************************************************************/

} // namespace sbw

#endif /* sbw_SHARED_LIBRARY_HPP_ */
