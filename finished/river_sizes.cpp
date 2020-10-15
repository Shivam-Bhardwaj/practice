//
// Created by shivam on 10/7/20.
//
//
// Created by shivam on 9/21/20.
//

#include "iostream"
#include "vector"
#include "cassert"
#include "algorithm"


using namespace std;

void traverse(int i, int j, vector<vector<int>> &matrix, vector<vector<bool>> &visited, vector<int> &rivers);

vector<vector<int>> can_be_traversed(int current_i, int current_j, vector<vector<bool>> &visited);

void traverse(int i, int j, vector<vector<int>> &matrix, vector<vector<bool>> &visited, vector<int> &rivers) {
  int current_river_size{0};
  vector<vector<int>> s{vector<int>{i, j}};
  while (!s.empty()) {
    int current_i = s.back().at(0);
    int current_j = s.back().at(1);
    s.pop_back();
    if (visited.at(current_i).at(current_j)) {
      continue;
    } else {
      visited.at(current_i).at(current_j) = true;
      if (matrix.at(current_i).at(current_j) == 0) {
        continue;
      } else {
        current_river_size++;
        vector<vector<int>> to_be_traversed = can_be_traversed(current_i, current_j, visited);
        for (auto &k : to_be_traversed) {
          s.push_back(k);
        }
      }
    }
  }
  if (current_river_size) rivers.push_back(current_river_size);
}

vector<vector<int>> can_be_traversed(int i, int j, vector<vector<bool>> &visited) {
  vector<vector<int>> to_be_traversed;
  if (i > 0 && !visited.at(i - 1).at(j)) {
    to_be_traversed.push_back({i - 1, j});
  }
  if (i < visited.size() - 1 && !visited.at(i + 1).at(j)) {
    to_be_traversed.push_back({i + 1, j});
  }
  if (j > 0 && !visited.at(i).at(j - 1)) {
    to_be_traversed.push_back({i, j - 1});
  }
  if (j < visited.at(0).size() - 1 && !visited.at(i).at(j + 1)) {
    to_be_traversed.push_back({i, j + 1});
  }
  return to_be_traversed;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
  // Write your code here.
  vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix.at(0).size(), false));
  vector<int> rivers;
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix.at(0).size(); ++j) {
      if (visited.at(i).at(j)) {
        continue;
      } else {
//        visited.at(i).at(j) = true;
        traverse(i, j, matrix, visited, rivers);
      }
    }
  }
  return rivers;
}

int main() {
  {
    vector<vector<int>> testInput{
      {1, 0, 0, 1, 0},
      {1, 0, 1, 0, 0},
      {0, 0, 1, 0, 1},
      {1, 0, 1, 0, 1},
      {1, 0, 1, 1, 0},
    };
    vector<int> expected{1, 2, 2, 2, 5};
    vector<int> output = riverSizes(testInput);
    sort(output.begin(), output.end());
    for (int i : output) {
      cout << i << " ";
    }
    assert(output == expected);
    cout << "TEST 0 PASS";
  }
}


