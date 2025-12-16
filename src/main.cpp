#include "GLFW/glfw3.h"
#include <cstdio>
#include <cstdlib>

constexpr int viewWidth = 512;
constexpr int viewHeight = 512;

void start() {
  if (!glfwInit())
    return;

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  auto *window =
      glfwCreateWindow(viewWidth, viewHeight, "Ball Sim", nullptr, nullptr);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }
}

int main() {
  printf("Starting sim...\n");

  start();

  return EXIT_SUCCESS;
}
