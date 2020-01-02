#include <cassert>
#include "iostream"

using namespace std;

template <typename T>
T sum(T a, T b){
    return a + b;
}

int main(){
    cout << sum(2,3);
    cout << sum(2.3, 4.3);
    cout << sum('a','a');
//    cout << sum("aaa", "bbb");

}