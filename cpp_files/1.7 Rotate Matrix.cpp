//
// Created by shivam on 11/25/19.
//


#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

bool is_zero_in_first_row = false;
bool is_zero_in_first_column = false;

void update_is_zero_in_first_row(vector<vector<int>> &matrix, int columns) {
    for (int i = 0; i < columns; ++i) {
        if (matrix[0][i] == 0) {
            is_zero_in_first_row = true;
            break;
        }
    }
}

void update_is_zero_in_first_column(vector<vector<int>> &matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) {
            is_zero_in_first_column = true;
            break;
        }
    }
}

void make_first_zero(vector<vector<int>> &matrix, int rows, int columns) {
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < columns; ++j) {
            if (!matrix[i][j]) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
}

void row_zero(vector<vector<int>> &matrix, int rows, int columns) {
    for (int i = 1; i < rows; ++i) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < columns; ++j) {
                matrix[i][j] = 0;
            }
        }
    }
}

void column_zero(vector<vector<int>> &matrix, int rows, int columns) {
    for (int j = 1; j < columns; ++j) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < rows; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}


void setZeroes(vector<vector<int>> &matrix) {
    int rows, columns;
    rows = matrix.size();
    columns = matrix[0].size();
    update_is_zero_in_first_column(matrix, rows);
    update_is_zero_in_first_row(matrix, columns);
    if (matrix.size() > 0 && matrix[0].size() > 0) {
        make_first_zero(matrix, rows, columns);
        row_zero(matrix, rows, columns);
        column_zero(matrix, rows, columns);
    }
    if (is_zero_in_first_column) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][0] = 0;
        }
    }

    if (is_zero_in_first_row) {
        for (int i = 0; i < columns; ++i) {
            matrix[0][i] = 0;
        }
    }
}

int main() {
//    cout << "here";


//    vector<vector<int>> matrix{{0, 2,  3,  4},
//                               {5, 1,  7,  8},
//                               {1, 10, 11, 12},
//    };
    vector<vector<int>> matrix{{1, 0}
    };
//    vector<vector<int>> matrix{{0, 1, 2, 0},
//                               {3, 4, 5, 2},
//                               {1, 3, 1, 5},
//                               {1, 3, 1, 5}};
    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }



    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}