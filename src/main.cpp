#include "GLFW/glfw3.h"
#include "myproj/greeter.h"
#include <iostream>

int main() {
  myproj::Greeter g("Modern CMake Fan");
  std::cout << g.greet() << std::endl;
  return 0;
}
