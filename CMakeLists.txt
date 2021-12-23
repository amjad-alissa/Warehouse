cmake_minimum_required(VERSION 3.15)
project(WareHouse)

set(CMAKE_CXX_STANDARD 17)

add_executable(WareHouse main.cpp Article.cpp Article.h Stock.cpp Stock.h main.h)