# Number Guessing Game

A simple interactive command-line Number Guessing Game written in C++11.

## Overview

The **Number Guessing Game** is a console application where the computer randomly selects a secret number between **1 and 100**, and the player attempts to guess it. After each guess, the game gives feedback indicating whether the guess was too high or too low, helping the player narrow down the correct answer.

## Features

- **Random Target Generation**: Generates a random number between 1 and 100 using C++ standard random utilities seeded with current time.
- **Input Validation**: Safely handles invalid or non-numeric input, allowing the player to retry without crashing or freezing.
- **Score Tracking**: Counts and reports the number of valid attempts taken to find the target number.
- **Multi-Round Support**: Prompts the player at the end of a round to decide whether to play again.

## Prerequisites

- C++ Compiler with C++11 support or higher (e.g., `g++`, `clang++`, or MSVC).

## Compilation

To compile the source code using `g++`, open your terminal in the repository directory and run:

```bash
g++ -Wall -Wextra -std=c++11 main.cpp -o guessing_game
```

## How to Play

1. Run the compiled executable:

   ```bash
   ./guessing_game
   ```

2. Read the instructions displayed on the screen.
3. Enter an integer guess between 1 and 100 when prompted.
4. Adjust your next guess based on the feedback:
   - **Too high! Try again.**
   - **Too low! Try again.**
5. Once you guess correctly, your total attempt count will be displayed.
6. Enter `y` to play another round or `n` to exit.

## Project Structure

```text
.
├── main.cpp    # Source code containing game logic, input handling, and main loop
└── README.md   # Project documentation
```
