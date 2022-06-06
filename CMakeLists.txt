cmake_minimum_required(VERSION 3.12)

project(boost-geom-tutorial
  VERSION 1.0.0
)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)

add_subdirectory(geometry)
add_executable(uuid uuid/uuid.cpp)
target_include_directories(uuid PUBLIC ${Boost_INCLUDE_DIRS})
