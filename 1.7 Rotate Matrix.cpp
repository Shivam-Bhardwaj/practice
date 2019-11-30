//
// Created by shivam on 11/25/19.
//


#include "iostream"
#include <bits/stdc++.h>
#include "vector"

using namespace std;


void swapp(int *a, int *b, int *c, int *d) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = *d;
    *d = temp;

}

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();



    // Loop for outer layer
    for (int i = 0; i < n / 2; i++) {

        // Last element index for the layer
        int last = n - i - 1;

        // Number of times to perform 4-way swap per layer
        int n_elements = n - 2 * i - 1; // Size - 2*layer - 1

        // Loop for elements in one layer
        for (int j = 0; j < n_elements; j++) {

            // perfomorming the swap
            swapp(&matrix[i + j][i], &matrix[last][i + j], &matrix[last - j][last], &matrix[i][last - j]);
        }

    }
}

    int main() {
//    cout << "here";


        vector<vector<int>> matrix{{5,  1,  9,  11},
                                   {2,  4,  8,  10},
                                   {13, 3,  6,  7},
                                   {15, 14, 12, 16}};
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