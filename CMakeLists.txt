cmake_minimum_required(VERSION 2.8)

project(test)
set(CMAKE_CXX_STANDARD 17)

# find_package(Torch REQUIRED)

add_executable(${PROJECT_NAME} "test.cc")