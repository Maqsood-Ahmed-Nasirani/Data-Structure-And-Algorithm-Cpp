#include <iostream>
using namespace std;

const int N = 9;

bool isSafe(char a[N][N], int row, int col, char num) {
    // Check if the number is already present in the row or column
    for (int i = 0; i < N; i++) {
        if (a[row][i] == num || a[i][col] == num) {
            return false;
        }
    }

    // Check if the number is already present in the 3x3 subgrid
    int subgridRow = row - row % 3;
    int subgridCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[subgridRow + i][subgridCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(char a[N][N]) {
    int row, col;

    // Find an empty cell
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (a[row][col] == '.') {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // If no empty cell is found, the Sudoku is solved
    if (!isEmpty) {
        return true;
    }

    // Try filling the empty cell with numbers from '1' to '9'
    for (char num = '1'; num <= '9'; num++) {
        if (isSafe(a, row, col, num)) {
            a[row][col] = num;

            // Recursively try to solve the rest of the Sudoku
            if (solveSudoku(a)) {
                return true;
            }

            // If the current configuration does not lead to a solution,
            // backtrack and try the next number
            a[row][col] = '.';
        }
    }

    // If no number can be placed in the current cell, return false
    return false;
}

int main() {
    char sudoku[N][N] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '3', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (solveSudoku(sudoku)) {
        // Print the solved Sudoku
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "No solution exists!" << '\n';
    }

    return 0;
}
