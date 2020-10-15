//
// Created by shivam on 12/26/19.
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
  for (int i = 0; i < n / 2; ++i) {
    for (int j = 0; j < ((n) - (2 * i + 1)); ++j) {
//            swapp(&matrix[i + j][i], &matrix[n - 1 - i][i], &matrix[n - 1 - i][n - 1 - i], &matrix[j][n - 1 - i]);
      int last = n - 1 - i;
//        swapp(&matrix[i][i+j],&matrix[last-i][i+j],&matrix[last-i][last-i],&matrix[last-i][i]);
      swapp(&matrix[i + j][i], &matrix[last][i + j], &matrix[last - j][last], &matrix[i][last - j]);
    }
  }
}


int main() {
//    cout << "here";


//    vector<vector<int>> matrix{{0, 2,  3,  4},
//                               {5, 1,  7,  8},
//                               {1, 10, 11, 12},
//    };

  vector<vector<int>> matrix{{0, 1, 2, 0},
                             {3, 4, 5, 2},
                             {1, 3, 1, 2},
                             {1, 3, 1, 5}};
  cout << matrix[2][3];
//    rotate(matrix);
//    for (int i = 0; i < matrix.size(); i++) {
//        for (int j = 0; j < matrix[i].size(); j++)
//            cout << matrix[i][j] << " ";
//        cout << endl;
//    }


  cin.get();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return 0;
}