cmake_minimum_required(VERSION 3.6)

project(NN)

add_executable(nn main.cpp)

target_include_directories(nn
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)