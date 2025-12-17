#include "GLFW/glfw3.h"
#include "webgpu/webgpu_cpp.h"
#include <cstdio>
#include <cstdlib>

constexpr int viewWidth = 512;
constexpr int viewHeight = 512;

// An instance creates an opening for the program
// to communicate with the OS and determine the underlying
// graphics APIs to use.
wgpu::Instance instance;

// An adapter is what lets you pick the actual hardware you
// want to use. The adapter returns a *promise*, not a device. No
// allocations, no shaders, just information about the potential device.
wgpu::Adapter adapter;

// Where code is ran, and failures can occur. Gives the ability to act.
wgpu::Device device;

void init() {
  const auto timedWaitAnyFeature = wgpu::InstanceFeatureName::TimedWaitAny;
  const auto instanceDescriptor = wgpu::InstanceDescriptor{
      .requiredFeatureCount = 1,
      .requiredFeatures = &timedWaitAnyFeature,
  };
  instance = wgpu::CreateInstance(&instanceDescriptor);
}

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

  init();
  start();

  return EXIT_SUCCESS;
}
