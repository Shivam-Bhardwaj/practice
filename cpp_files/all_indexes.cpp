//
// Created by shivam on 7/3/2020.
//

#include "iostream"

using namespace std;
int helper(int input[], int size, int x, int *output, int index, int cur_ind) {
    if (cur_ind == size) return index;
    if (input[cur_ind] == x) output[index++] = cur_ind;
    int ind = helper(input, size, x, output, index, cur_ind + 1);
    return ind;
}

int allIndexes(int input[], int size, int x, int *output) {
    int index = helper(input, size, x, output, 0, 0);
    return index;
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    delete [] input;

    delete [] output;


}
