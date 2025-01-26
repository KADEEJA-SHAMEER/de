#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printZigzagPattern(const string& s, int numRows) {
    if (numRows == 1 || numRows >= s.size()) {
        cout << s << endl;
        return;
    }

    // Create a grid to store the zigzag pattern
    vector<vector<char>> grid(numRows, vector<char>(s.size(), ' '));

    int row = 0, col = 0;
    bool goingDown = true;

    // Fill the grid with characters in zigzag order
    for (char c : s) {
        grid[row][col] = c;

        if (goingDown) {
            row++; // Move downward
            if (row == numRows) { // Change direction at the bottom
                row -= 2;
                col++;
                goingDown = false;
            }
        } else {
            row--; // Move upward diagonally
            col++;
            if (row < 0) { // Change direction at the top
                row += 2;
                col--;
                goingDown = true;
            }
        }
    }

    // Print the zigzag pattern
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <= col; ++j) {
            cout << grid[i][j]<<" ";
        }
        cout << endl;
    }
}

int main() {
    string s;
    int numRows;

    // Read the string and the number of rows from the user
    cout << "Enter the string: ";
    getline(cin, s);
    cout << "Enter the number of rows: ";
    cin >> numRows;

    cout << "Zigzag Pattern:" << endl;
    printZigzagPattern(s, numRows);

    return 0;
}