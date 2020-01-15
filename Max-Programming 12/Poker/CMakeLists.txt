cmake_minimum_required(VERSION 3.10)
project(Poker)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp func.cpp)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(Poker main.cpp Card.h Deck.h Player.h)