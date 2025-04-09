#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>  
#include <iomanip> 

using namespace std;

int main(int argc, char*argv[]) {

  // Selection sort numbers in a file
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

  // ========== SELECTION SORT IMPLEMENTATION HERE ==========

  int n = A.size();

//  auto start_time = chrono::high_resolution_clock::now();

  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (A[j] < A[minIndex]) {
        minIndex = j;
      }
    }
    swap(A[i], A[minIndex]);
  }

//  auto end_time = chrono::high_resolution_clock::now();
//  chrono::duration<double> elapsed = end_time - start_time;

  // ====================================================

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

//  cout << fixed << setprecision(6);
//  cout << "Run Time: " << elapsed.count() << " s" << endl;

  cout << "========================================" << endl << endl << endl;

  return 0;
}
