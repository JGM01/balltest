#include "GLFW/glfw3.h"
#include "webgpu/webgpu_cpp.h"
#include <algorithm>
#include <cstdint>
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

  // Creating a future (promise) by making a request via the instance for an
  // adapter that satisfies some constraints.
  wgpu::Future f1 = instance.RequestAdapter(
      nullptr, wgpu::CallbackMode::WaitAnyOnly,

      // This callback function is ran when the request returns some result
      // (pass or fail, need to handle either).
      [](wgpu::RequestAdapterStatus status, wgpu::Adapter a,
         wgpu::StringView msg) {
        // if bad
        if (status != wgpu::RequestAdapterStatus::Success) {
          printf("Request Adapter: %s\n", msg.data);
          exit(0);
        }

        // if good
        adapter = std::move(a);
      });

  // do the future.
  instance.WaitAny(f1, UINT64_MAX);

  wgpu::DeviceDescriptor desc{};
  desc.SetUncapturedErrorCallback([](const wgpu::Device &,
                                     wgpu::ErrorType errorType,
                                     wgpu::StringView message) {
    printf("Error: %s\nMessage: %s\n", errorType, message.data);
  });

  // Try to use gain access to the device.
  wgpu::Future f2 = adapter.RequestDevice(
      &desc, wgpu::CallbackMode::WaitAnyOnly,
      [](wgpu::RequestDeviceStatus status, wgpu::Device d,
         wgpu::StringView msg) {
        if (status != wgpu::RequestDeviceStatus::Success) {
          printf("Request Device: %s\n", msg.data);
          exit(0);
        }
        device = std::move(d);
      });
  instance.WaitAny(f2, UINT64_MAX);
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
