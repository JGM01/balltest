#include <gtest/gtest.h>
#include <myproj/greeter.h>

TEST(GreeterTest, DefaultName) {
  myproj::Greeter g;
  EXPECT_EQ(g.greet(), "Hello, World!");
}

TEST(GreeterTest, CustomName) {
  myproj::Greeter g("Alice");
  EXPECT_EQ(g.greet(), "Hello, Alice!");
}

TEST(GreeterTest, ChangeName) {
  myproj::Greeter g;
  g.set_name("Bob");
  EXPECT_EQ(g.greet(), "Hello, Bob!");
}
