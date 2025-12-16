#include "myproj/greeter.h"
#include <format>

namespace myproj {

Greeter::Greeter(std::string name) : name_(std::move(name)) {}

std::string Greeter::greet() const { return std::format("Hello, {}!", name_); }

void Greeter::set_name(std::string_view name) { name_ = name; }

} // namespace myproj
