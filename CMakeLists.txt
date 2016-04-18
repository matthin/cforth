cmake_minimum_required(VERSION 2.6)
project(cforth)

add_subdirectory(src)
include_directories(include)

add_library(
  cforth
  STATIC
  ${cforthSourceFiles}
)

add_definitions(-std=c11)

add_executable(cforthApp src/cforth.c)
target_link_libraries(cforthApp cforth)
