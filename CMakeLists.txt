cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(shared_boston_winters)

##############################################################################
# Development Configuration
##############################################################################

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INSTALL_PREFIX ../install)
set(BUILD_SHARED_LIBS ON)

##############################################################################
# Project Configuration
##############################################################################

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

##############################################################################
# Sources
##############################################################################

add_subdirectory(src)

##############################################################################
# Installs
##############################################################################

install(PROGRAMS setup.bash DESTINATION ${CMAKE_INSTALL_PREFIX})
