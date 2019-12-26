//
// Created by shivam on 12/26/19.
//

#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;

void rotate(vector<vector<int>>& matrix) {

}


int main() {
//    cout << "here";


//    vector<vector<int>> matrix{{0, 2,  3,  4},
//                               {5, 1,  7,  8},
//                               {1, 10, 11, 12},
//    };

    vector<vector<int>> matrix{{0, 1, 2, 0},
                               {3, 4, 5, 2},
                               {1, 3, 1, 5},
                               {1, 3, 1, 5}};

    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }



    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}