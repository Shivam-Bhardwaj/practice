#include <vector>
#include <assert.h>
using namespace std;
// #define CATCH_CONFIG_MAIN
// #include "catch.hpp"

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  vector<int> buildHeap(vector<int> &vector) {
    // Write your code here.
    size_t p = (vector.size() - 2) / 2;
    for (int i = p; i >=0 ; i--) {
      siftDown(i, vector.size() - 1, vector);
    }
    return vector;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
    // Write your code here.
    int c1 = currentIdx*2 + 1;

    int idx_to_swap = -1;
    while(c1 <= endIdx){
      int c2 = currentIdx*2 + 2 <=endIdx? currentIdx*2 + 2: -1;
      if (c2!= -1 && heap[c2] < heap[c1]){
        idx_to_swap = c2;
      } else{
        idx_to_swap = c1;
      }

      if(heap[idx_to_swap] < heap[currentIdx]){
        swap(heap[idx_to_swap], heap[currentIdx]);
        currentIdx = idx_to_swap;
        c1 = currentIdx*2 + 1;
      } else{
        return;
      }
    }
  }

  void siftUp(int currentIdx, vector<int> &heap) {
    // Write your code here.
    int p = (currentIdx - 1) / 2;
    while(p <=0){
      if(heap[currentIdx] > heap[p]){
        swap(heap[p], heap[currentIdx]);
        currentIdx = p;
        p = (currentIdx - 1) / 2;
      } else{
        return;
      }
    }
  }

  int peek() {
    // Write your code here.
    return heap[0];
  }

  int remove() {
    // Write your code here.
    int x = heap[0];
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    siftDown(0, heap.size() - 1, heap);
    return x;
  }

  void insert(int value) {
    // Write your code here.
    heap.push_back(value);
    siftUp(heap.size() - 1, heap);
  }
};



bool isMinHeapPropertySatisfied(vector<int> array) {
  for (int currentIdx = 1; currentIdx < array.size(); currentIdx++) {
    int parentIdx = (currentIdx - 1) / 2;
    if (parentIdx < 0) {
      return true;
    }
    if (array[parentIdx] > array[currentIdx]) {
      return false;
    }

  }
  return true;
}

int main(){
  MinHeap minHeap({48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41});
   minHeap.insert(76);
   assert(isMinHeapPropertySatisfied(minHeap.heap));
   assert(minHeap.peek() == -5);
   assert(minHeap.remove() == -5);
   assert(isMinHeapPropertySatisfied(minHeap.heap));
   assert(minHeap.peek() == 2);
   assert(minHeap.remove() == 2);
   assert(isMinHeapPropertySatisfied(minHeap.heap));
   assert(minHeap.peek() == 6);
   minHeap.insert(87);
   assert(isMinHeapPropertySatisfied(minHeap.heap));
  return 0;
}
