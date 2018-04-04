// testso.cpp
#include <dlfcn.h>
#include <iostream>

int main(int argc, char* argv[])
{
    if ( argc < 2 ) {
        std::cerr << "Usage: " << argv[0] << "library-name\n";
        return 1;
    }
    std::cerr << "Before dlopen()...\n";
    ::dlerror();
    void* _handle(::dlopen(argv[1], RTLD_GLOBAL | RTLD_NOW));
    std::cerr << "After dlopen()...\n";
    if (!_handle) {
        std::cerr << "Error: " << ::dlerror() << ", exiting...\n";
        return 2;
    }
    ::dlclose(_handle);
    std::cerr << "After dlclose()...\n";
    return 0;
}
