//
// Created by shivam on 12/26/19.
//


#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

bool isValidSudoku(vector<vector<char>> &board) {
    unordered_map<char, bool> row[9];
    unordered_map<char, bool> column[9];
    unordered_map<char, bool> box[9];
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char current = board[i][j];
            if (current != '.') {
                // check for column
                if (column[i].find(current) == column[i].end()) {
                    column[i][current] = true;
                } else {
                    return false;
                }
                // Check for row
                if (row[j].find(current) == row[j].end()) {
                    row[j][current] = true;
                } else {
                    return false;
                }
                // Check for box
                int m = i / 3 + 3 * (j / 3);
                if (box[m].find(current) == box[m].end()) {
                    box[m][current] = true;
                } else {
                    return false;
                }

            }
        }
    }
    return true;
}

int main(void) {
    cout << "here\n\n";

//    vector<vector<char>> b{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
//                           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//                           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//                           {'1', '.', '.', '.', '6', '.', '.', '.', '3'},
//                           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//                           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//                           {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//                           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//                           {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//    };

    vector<vector<char>> b{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                           {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                           {'.', '6', '.', '1', '.', '.', '2', '8', '.'},
                           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                           {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << isValidSudoku(b);

    cout << "here";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}
