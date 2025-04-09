#include "mergesort.hpp"
#include <stdio.h>
#include <iostream>

int main(int argc, char*argv[]) {

  //insertionsort numbers in a file
  cout << "********Merge Sort********"<< endl;
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
  Mergesort(A, 0, n-1);

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


  return 0;
}

