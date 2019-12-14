cmake_minimum_required(VERSION 3.10)
project(Yathzee_beta)

set(CMAKE_CXX_STANDARD 14)

include_directories(Yathzee_beta/Yathzee_beta)

add_executable(Yathzee_beta
        Yathzee_beta/Yathzee_beta/Game.h
        Yathzee_beta/Yathzee_beta/Score.h
        Yathzee_beta/Yathzee_beta/ScoreSheet.h
        Yathzee_beta/Yathzee_beta/Yathzee_beta.cpp)
