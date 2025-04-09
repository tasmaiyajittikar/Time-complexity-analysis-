#include "minheap.hpp"
#include <stdio.h>
#include <iostream>

int main(int argc, char*argv[]) {
/*
  //demo functions of the minheap class
  MinHeap* myheap = new MinHeap();
  cout << "========================================" << endl;
  cout << "Trying some methods from the MinHeap class ...." << endl;
  cout << "You must check that the output is correct manually (or write code that does it automatically)" << endl ;
  cout << "========================================" << endl;
  myheap->insert(700);
  cout << "insert 700" << endl;
  myheap->display();
  myheap->insert(500);
  cout << "insert 500" << endl;
  myheap->display();
  myheap->insert(100);
  cout << "insert 100" << endl;
  myheap->display();
  myheap->insert(800);
  cout << "insert 800" << endl;
  myheap->display();
  myheap->insert(200);
  cout << "insert 200" << endl;
  myheap->display();
  myheap->insert(400);
  cout << "insert 400" << endl;
  myheap->display();
  myheap->insert(900);
  cout << "insert 900" << endl;
  myheap->display();
  int heapSize = myheap->size();
  cout << "size: " << heapSize << endl;
  for ( int i = 0; i < heapSize/2; i++ ) {
    cout << "Get and delete min element: " << myheap->extractMin() << endl;
    myheap->display();
  }
  cout << "========================================" << endl;

  delete myheap;
*/
  
  //heapsorting numbers in a file
  vector<int> A;
  if(argc!=2) {
    cout<<"Provide an input file as argument";
  } else {
    FILE *file = fopen(argv[1], "r");
    if(file == 0){
      cout << "ERROR: file does not exist" << endl;
      return -1;
    }
    else {
      int x;
      fscanf(file, "%d", &x);
      while(!feof(file)) {
	A.push_back(x);
	fscanf(file, "%d", &x);
      }
      fclose(file);
    }
  }
  
  int n = A.size();

  cout << endl << endl;
  cout << "========================================" << endl;
  cout << "Checking if HeapSort works ..." << endl;
  cout << "Input size: " << n << endl;
  cout << "========================================" << endl;
  if (n <= 10) {
    cout << "This it the input:" << endl;
    for(int i=0; i<n; ++i) {
      cout << A[i] << " ";
    }
    cout << endl;
  }
  else{
    cout << "Input is too large to display" << endl;
  }
  MinHeap *myheap2 = new MinHeap();
  myheap2->heapsort(A,n);

  if (n <= 10) {
    cout << "And this is the sorted output:" << endl;
    for(int i=0; i<n; ++i) {
      cout << A[i] << " ";
    }
    cout << endl;
  }
  else {
    cout << "Sorted output is too large to display" << endl;
  }

  cout << "Checking if the output is actually sorted ..." << endl;
  bool sorted = true;
  for (int i=1; i<n; ++i) {
    if (A[i-1] > A[i]){
      cout << "Output is NOT SORTED: " << A[i-1] << " is greater than " <<
	A[i] << "(index " << i << ")" << endl;
      sorted = false;
    }
  }
  if (sorted) {
    cout << "\tThe output is sorted" << endl;  
  }
  cout << "========================================" << endl << endl << endl << endl;

  
  delete myheap2;

  return 0;
}
