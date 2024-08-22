#include <iostream>
#define N 4

using namespace std;

// Function to print the solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        cout << endl;
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Utility function to solve the N-Queen problem using backtracking
bool solvenNQueens(int board[N][N], int col) {
    // Base case: If all queens are placed, then return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if placing queen at board[i][col] is safe
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solvenNQueens(board, col + 1))
                return true;

            // If placing queen at board[i][col] doesn't lead to a solution, then backtrack
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen can't be placed in any row in this column col, then return false
    return false;
}

// Main function to solve the N-Queen problem
int main() {
    int board[N][N] = {0};

    if (solvenNQueens(board, 0)) {
        printSolution(board);
        
    }
    cout << "Solution does not exist" << endl;
        return 0;

    printSolution(board);
    return 0;
}
