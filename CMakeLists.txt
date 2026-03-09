cmake_minimum_required(VERSION 3.9)
project(CLICalculator)

set(CMAKE_CXX_STANDARD 20)



# fetch google test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# make an executable program google test for GunitTest
add_executable(GoogleTests
        GunitTest.cpp

        Calculator.cpp
        Calculator.h
        OhmCalculator.cpp
        OhmCalculator.h)
# eftersom Clion uppdaterar inte namnet på exekveringen så heter den "Test"
add_executable(CliCalculator main.cpp Calculator.cpp Calculator.h
        OhmCalculator.cpp
        OhmCalculator.h
        InputHandler.cpp
        InputHandler.h
        ResProCalculator.cpp
        ResProCalculator.h)

# link the library to GoogleTests executable

target_link_libraries(GoogleTests GTest::gtest GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(GoogleTests)