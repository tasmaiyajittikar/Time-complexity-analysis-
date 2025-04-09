#include <stdio.h>
#include <iostream>
#include <vector>

#include <chrono>  
#include <iomanip> 

using namespace std;

int main(int argc, char* argv[]) {

  // Insertionsort numbers in a file
  vector<int> A;

  if (argc != 2) {
    cout << "Provide an input file as argument." << endl;
    return -1;
  } else {
    FILE *file = fopen(argv[1], "r");
    if (file == 0) {
      cout << "ERROR: file does not exist" << endl;
      return -1;
    } 
      else {
      int x;
      fscanf(file, "%d", &x);
      while (!feof(file)) {
        A.push_back(x);
        fscanf(file, "%d", &x);
      }
      fclose(file);
    }
  }

  // ========== INSERTION SORT IMPLEMENTATION HERE ==========

  int n = A.size();
  
  if (n == 0) {
    cout << "ERROR: Input file is empty" << endl;
    return -1;
  }

//  auto start_time = chrono::high_resolution_clock::now();

  for (int i = 1; i < n; i++) {
    int key = A[i]; 
    int j = i - 1;

    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j = j - 1;
    }
    A[j + 1] = key; 
  }

//  auto end_time = chrono::high_resolution_clock::now();
//  chrono::duration<double> elapsed = end_time - start_time;

  // ====================================================


  if (n <= 10) {
    cout << "\nAnd this is the sorted output:" << endl;
    for (int i = 0; i < n; ++i) {
      cout << A[i] << " ";
    }
    cout << endl;
  } 
  
  else {
    cout << "Sorted output is too large to display" << endl;
  }

  cout << "Checking if the output is actually sorted ..." << endl;
  bool sorted = true;
  for (int i = 1; i < n; ++i) {
    if (A[i - 1] > A[i]) {
      cout << "Output is NOT SORTED: " << A[i - 1] << " is greater than "
           << A[i] << " (index " << i << ")" << endl;
      sorted = false;
    }
  }
  
  if (sorted) {
    cout << "\tThe output is sorted" << endl;
  }

//  cout << fixed << setprecision(6);
//  cout << "\nRun Time: " << elapsed.count() << " s\n" << endl;

  cout << "========================================" << endl << endl;

  return 0;
}
