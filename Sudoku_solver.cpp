#include <iostream>
using namespace std;

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

// Function to check if placing a number in a cell is safe
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if 'num' is not in the current row, column, and 3x3 subgrid
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num || 
            grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num)
            return false;
    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int grid[N][N], int row, int col) {
    // If we've reached the 9th row, the puzzle is solved
    if (row == N - 1 && col == N)
        return true;

    // Move to the next row if we've reached the end of the current row
    if (col == N) {
        row++;
        col = 0;
    }

    // If the current cell is already filled, move to the next cell
    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    // Try placing numbers 1-9 in the current cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            // Recursively try to solve the rest of the grid
            if (solveSudoku(grid, row, col + 1))
                return true;
            // Backtrack if the current number doesn't lead to a solution
            grid[row][col] = 0;
        }
    }

    // Return false if no number can be placed in the current cell
    return false;
}

int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        cout << "No solution exists." << endl;

    return 0;
}