# Eight Queens Problem Solver

A C++ implementation of the classic **Eight Queens Problem** using backtracking and recursion. The program places eight queens on a chessboard such that no two queens threaten each other.

## Features
- **Customizable Input**: Allows the user to input the initial coordinates for the first queen.
- **Backtracking Algorithm**: Ensures valid placement of queens while exploring all possible configurations.
- **Safety Checks**: Validates queen placements across rows, columns, and diagonals.
- **Visualization**: Outputs the final chessboard with all eight queens placed.

---

## Problem Statement
The Eight Queens Problem is a chess puzzle where the objective is to place eight queens on an 8×8 chessboard so that no two queens threaten each other. This means:
- No two queens share the same row, column, or diagonal.

---

## How It Works
1. **Input**: 
   - The user specifies the coordinates of the initial queen.
   - Example: `(4, 5)` places a queen at row 4, column 5.
2. **Backtracking Algorithm**:
   - Starts with the user-defined queen and recursively places the remaining queens.
   - Backtracks whenever a conflict is detected to explore alternative placements.
3. **Output**:
   - Displays the final chessboard with queens marked as `Q` and empty squares as `-`.

---

## Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/eight-queens-solver.git


## Resume Bullet Points
Eight Queens Calculator (C++/Recursion) | Data Structures and Algorithms            

* Designed a C++ program to solve a modified leetcode hard problem revolving recursion and backtracking
* Places 7 queens on a full 8x8 chessboard after user picks first location in a way that no queen is attacking each other

