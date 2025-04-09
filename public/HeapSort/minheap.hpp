#include <vector>
using namespace std;


class MinHeap {
private:
  int *harr;
  int capacity; //maximum possible size of minheap
  int heap_size; //current number of elements in min heap 
public:
  MinHeap(int capacity = 1000000);
  ~MinHeap();
  int parent(int i);
  int left(int i);
  int right(int i);
  void insert(int element);
  int extractMin();
  void MinHeapify(int i);
  void display();
  void heapsort(vector<int>& A,int n);
  int size();
};
