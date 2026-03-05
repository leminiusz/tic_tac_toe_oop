cmake_minimum_required(VERSION 3.10)

project(TicTacToe_AI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(tictactoe 
    src/main.cpp 
    src/board.cpp 
    src/gameplay.cpp 
    src/minimax.cpp
)