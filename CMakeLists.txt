cmake_minimum_required(VERSION 3.14)

project(passgen LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(passgen
  main.cpp
)
target_link_libraries(passgen)

install(TARGETS passgen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
