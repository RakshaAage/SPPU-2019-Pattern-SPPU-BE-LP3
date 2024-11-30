// Design n-Queens matrix having first Queen placed. Use backtracking to place remaining Queens to generate the final n-queen’s matrix.

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<int>& solution) {
    for (int i = 0; i < row; i++) {
        if (solution[i] == col || solution[i] - i == col - row || solution[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void solveNQueensUtil(int row, int n, vector<int>& solution, int& count) {
    if (row == n) {
        // Found a solution, print it and increment the count
        count++;
        cout << "Solution " << count << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (solution[i] == j) {
                    cout << "Q ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, solution)) {
            solution[row] = col;
            solveNQueensUtil(row + 1, n, solution, count);
            // Backtrack: remove the queen from this position
            solution[row] = -1;
        }
    }
}

void solveNQueens(int n, int firstRow, int firstCol) {
    if (firstRow < 0 || firstRow >= n || firstCol < 0 || firstCol >= n) {
        cout << "Invalid position for the first queen." << endl;
        return;
    }

    vector<int> solution(n, -1);
    int count = 0;
    solution[firstRow] = firstCol;  
    solveNQueensUtil(0, n, solution, count);  // Start from the first row

    if (count == 0) {
        cout << "No solutions found." << endl;
    } else {
        cout << "Total solutions: " << count << endl;
    }
}

int main() {
    int n, firstRow, firstCol;
    cout << "Enter the number of queens: ";
    cin >> n;
    cout << "Enter the row (0 to " << n-1 << ") for the first queen: ";
    cin >> firstRow;
    cout << "Enter the column (0 to " << n-1 << ") for the first queen: ";
    cin >> firstCol;

    solveNQueens(n, firstRow, firstCol);
    return 0;
}



// Enter the size of the board (n): 4
// Enter the initial row and column for the first queen (0-indexed): 0 1

// Solutions to the 4-Queens problem:
// 0 1 0 0 
// 0 0 0 1 
// 1 0 0 0 
// 0 0 1 0 

// 0 1 0 0 
// 0 0 1 0 
// 0 0 0 1 
// 1 0 0 0 
