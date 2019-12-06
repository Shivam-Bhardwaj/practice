//
// Created by shivam on 12/5/19.
//


#include "iostream"
#include <bits/stdc++.h>

using namespace std;

void swapp(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

vector<int> bubbleSort(vector<int> array) {
    // Write your code here.
    bool is_sorted = true;
    int n = array.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i-1; ++j) {
            if (array[j] > array[j + 1]) {
                swapp(&array[j], &array[j + 1]);
                is_sorted = false;
            }
        }
        if (is_sorted) return array;
    }
    return array;
}

int main(void) {
//    cout << "here";
//    vector<int> expected = {1, 2};
//    assert(bubbleSort({1, 2}) == expected);
    vector<int> g1(bubbleSort({28, 3, 4}));

    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";


//    vector<int> arr{1, 3, 2};
//    vector<int> sorted{bubbleSort(arr)};
//    for (int i = 0; i < sorted.size(); ++i) {
//        cout << sorted[i];
//    }

    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

