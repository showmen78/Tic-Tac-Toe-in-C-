# Tic Tac Toe in C++ with Raylib

This is a simple implementation of the classic Tic Tac Toe game using the Raylib library in C++. The game is designed to provide an interactive and visually engaging experience with a graphical user interface (GUI).

## Features

- **Graphical Interface**: The game displays a 3x3 grid where players can place their moves.
- **Two-Player Mode**: The game allows two players to take turns.
- **Win/Draw Detection**: Automatically detects when a player wins or when the game ends in a draw.
- **Restart Option**: Players can restart the game at any time.

## Prerequisites

To compile and run this game, you need the following:

1. **Raylib**: Ensure Raylib is installed on your system. You can find installation instructions on the [official Raylib website](https://www.raylib.com/).
2. **C++ Compiler**: A C++ compiler such as `g++` or `clang++` that supports C++11 or later.



## Gameplay Instructions

1. **Objective**: The goal is to align three of your symbols (either X or O) horizontally, vertically, or diagonally.
2. **Turns**: Players take turns to click on a cell in the grid to place their symbol.
3. **Winning**: The game announces the winner when three symbols align.
4. **Draw**: If all cells are filled without a winner, the game ends in a draw.


## Code Overview

- **Game Logic**: Implemented in C++ using Raylib for rendering and input handling.
- **Game Board**: Represented as a 2D vector of characters.
- **Game State**: Managed using an enumeration to track ongoing, won, or drawn states.
- **Functions**:
  - `DrawBoard()`: Renders the game grid and player moves.
  - `CheckGameState()`: Determines the current game state.


## Screenshot

![Screenshot](./ss2.PNG)

## Contributions

Feel free to fork this repository and enhance the game! Possible improvements include:

- Adding AI for single-player mode.
- Enhancing the GUI with animations.
- Adding a scoring system.

## License

This project is released under the MIT License. You are free to use, modify, and distribute the code as per the license terms.

## Acknowledgments

This project was developed using the Raylib library. Special thanks to the Raylib community for providing an excellent framework for creating graphical applications in C++.

---

