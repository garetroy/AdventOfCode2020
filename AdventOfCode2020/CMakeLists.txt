cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(AdventOfCode2020)

find_package(folly CONFIG REQUIRED)

# add the executable
add_executable(Main Main.cxx)
