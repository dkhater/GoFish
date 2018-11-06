cmake_minimum_required(VERSION 3.12)
project(GoFish)

set(CMAKE_CXX_STANDARD 11)

add_executable(GoFish main.cpp player.h card.h deck.h card.cpp deck.cpp player.cpp)