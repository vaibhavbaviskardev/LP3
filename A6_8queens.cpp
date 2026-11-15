// A6: 8-Queens - first queen given by user, rest placed by Backtracking
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 8;
int column[N]; // column[row] is the queen's column, or -1 if the row is empty
int fixedRow;

bool isSafe(int row, int candidateColumn) {
    for (int previousRow = 0; previousRow < N; previousRow++) {
        if (column[previousRow] != -1 &&
            previousRow != row &&
            (column[previousRow] == candidateColumn ||
             abs(column[previousRow] - candidateColumn) ==
                 abs(previousRow - row))) {
            return false;
        }
    }
    return true;
}

bool solve(int row) {
    if (row == N) {
        return true;
    }
    if (row == fixedRow) {
        return solve(row + 1);
    }

    for (int candidateColumn = 0; candidateColumn < N; candidateColumn++) {
        if (isSafe(row, candidateColumn)) {
            column[row] = candidateColumn;
            if (solve(row + 1)) {
                return true;
            }
            column[row] = -1;
        }
    }
    return false;
}

int main() {
    int row;
    int candidateColumn;
    cout << "First queen row col (1-8): ";
    cin >> row >> candidateColumn;

    if (row < 1 || row > N || candidateColumn < 1 ||
        candidateColumn > N) {
        cout << "Invalid row or column\n";
        return 0;
    }

    fill(column, column + N, -1);
    fixedRow = row - 1;
    column[fixedRow] = candidateColumn - 1;

    if (!solve(0)) {
        cout << "No solution\n";
        return 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (column[i] == j ? "Q " : ". ");
        }
        cout << "\n";
    }
}
