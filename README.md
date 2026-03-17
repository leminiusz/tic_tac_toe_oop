# Tic-Tac-Toe (OOP, C++)

A console Tic-Tac-Toe game written in C++ with an object-oriented structure.

## Features
- Two game modes: local 2-player and player vs computer.
- Computer opponent uses Minimax.
- Input validation and replay option.

## Build and Run

### CMake
```bash
cmake -S . -B build
cmake --build build
./build/tictactoe
```

### Windows (MinGW GCC)
```bash
g++ -std=c++17 src/main.cpp src/board.cpp src/gameplay.cpp src/minimax.cpp -o tictactoe.exe
./tictactoe.exe
```

## Notes
- The in-game menu and messages are currently in Polish.