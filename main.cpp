/**
 * Main for the application
 *
 * @file main.cpp
 * @author Patrick Charles H. | xetra11
 */

#ifndef MAIN_CPP
#define MAIN_CPP

#include <SFML/Graphics.hpp>
#include "vilsoc/vilsoc.hpp"

int main(int argc, char* argv[]){
  X11::VillageSociety vilsoc;
  int exitCode = vilsoc.run();
  return exitCode;
}

#endif
