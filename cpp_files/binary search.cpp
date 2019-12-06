#include <vector>
#include <limits>
#include "iostream"

using namespace std;

int binarySearch(vector<int> array, int target) {
    // Write your code here.
    int start, mid, end;
    start = 0;
    end = array.size() - 1;
    mid = (start + end) / 2;

    while (start <= end) {
        cout << start << mid << end << endl;
        if (array[mid] == target) return mid;
        else if (array[mid] < target) {
            start = mid + 1;
            mid = (start + end) / 2;
        } else if (array[mid] > target) {
            end = mid - 1;
            mid = (start + end) / 2;
        }
    }
    // cout << "here";
    return -1;
}

int main() {
    vector<int> a{1, 5, 23, 111};
    cout << binarySearch(a, 111);
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

