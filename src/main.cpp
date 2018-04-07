
// testso.cpp

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include <dlfcn.h>
#include <iostream>

/*****************************************************************************
 * Main
 ****************************************************************************/

int main(int argc, char **argv) {
  const std::string plugin_name = "agents";

  std::cerr << "Before dlopen()...\n";
  ::dlerror();
  void* _handle(::dlopen(plugin_name.c_str(), RTLD_GLOBAL | RTLD_NOW));
  std::cerr << "After dlopen()...\n";
  if (!_handle) {
      std::cerr << "Error: " << ::dlerror() << ", exiting...\n";
      return 2;
  }
  ::dlclose(_handle);
  std::cerr << "After dlclose()...\n";
  return 0;
}
