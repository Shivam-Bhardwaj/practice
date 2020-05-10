#include <iostream>
#include <map>
#include "vector"
#include "cassert"

using namespace std;

int removeDuplicates(vector<int> &nums) {
  int ctr = 0;
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    if (nums[ctr] != nums[i + 1]) {
      nums[ctr] = nums[i];
      ctr++;
    }
  }
// not here 4
  for (int j = 0; j < ctr; ++j) {
    printf("%d ", nums[j]);
  }

  return ctr;
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  vector<int> list = {{0, 1, 2, 2, 4, 4, 5}};
  printf("\n%d", removeDuplicates(list));
  return EXIT_SUCCESS;
}