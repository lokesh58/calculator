cmake_minimum_required(VERSION 3.15...3.31)

project(Calculator VERSION 1.0
                  DESCRIPTION "A simple expression calculator"
                  LANGUAGES CXX)

add_library(calculator_lib src/calculator.cpp)
target_include_directories(calculator_lib PUBLIC include)

add_executable(calculator src/main.cpp)
target_link_libraries(calculator PRIVATE calculator_lib)
