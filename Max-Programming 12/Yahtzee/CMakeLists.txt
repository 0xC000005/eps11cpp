cmake_minimum_required(VERSION 3.10)
project(Yahtzee)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(Yahtzee main.cpp Score.h ScoreSheet.h Game.h)
