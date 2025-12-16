cmake_minimum_required(VERSION 4.0...4.2)
project(MyProj VERSION 0.0.1 DESCRIPTION "Gonna use this as boilerplate :)" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTING "Build the tests" ON)

set(DAWN_FETCH_DEPENDENCIES ON CACHE BOOL "" FORCE)
set(TINT_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(DAWN_BUILD_SAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(external/dawn)

add_library(myproj STATIC
    src/greeter.cpp
    include/myproj/greeter.h
)

target_include_directories(myproj
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        src
)

add_library(myproj::myproj ALIAS myproj)


add_executable(myapp src/main.cpp)
target_link_libraries(myapp PRIVATE myproj::myproj)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/GoogleTest.cmake)

target_link_libraries(myapp PRIVATE webgpu_dawn webgpu_glfw glfw)

if(BUILD_TESTING)
    enable_testing()
	
    add_executable(test_greeter tests/test_greeter.cpp)
    target_link_libraries(test_greeter PRIVATE myproj::myproj GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(test_greeter)
endif()

