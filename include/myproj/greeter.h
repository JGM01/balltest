#pragma once
#include <string>
#include <string_view>

namespace myproj {

class Greeter {
public:
  explicit Greeter(std::string name = "World");
  std::string greet() const;

  void set_name(std::string_view name);

private:
  std::string name_;
};

} // namespace myproj
