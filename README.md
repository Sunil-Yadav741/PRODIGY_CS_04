### Task 4: Sudoku Solver

#### Overview
This is a simple Sudoku solver implemented in C++. The program automatically solves a given Sudoku puzzle using the backtracking algorithm. The user provides an input grid representing the unsolved Sudoku puzzle, and the program fills in the missing numbers to complete the puzzle.

#### Features
- **Automatic Puzzle Solving**: The program uses the backtracking algorithm to explore all possible solutions and find the correct arrangement of numbers for the puzzle.
- **Input Flexibility**: The program can handle standard 9x9 Sudoku puzzles with missing numbers represented by zeroes.
- **Display of Solution**: Once the puzzle is solved, the program displays the completed Sudoku grid.

#### How It Works
The Sudoku solver uses a recursive backtracking approach to solve the puzzle:

1. **Find an empty cell**: The algorithm searches for an empty cell (denoted by 0) in the grid.
2. **Try possible numbers**: It tries filling the empty cell with numbers from 1 to 9, checking if the number is valid according to Sudoku rules (no repeating numbers in the same row, column, or 3x3 subgrid).
3. **Backtrack if necessary**: If no valid number is found, the algorithm backtracks to the previous cell and tries a different number.
4. **Repeat until solved**: The process continues until the entire grid is filled correctly, at which point the solution is displayed.

#### Requirement
- C++
