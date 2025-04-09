#include "minheap.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Utility function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Constructor: Initializes a MinHeap with given capacity
MinHeap::MinHeap(int size) {
    heap_size = 0;
    capacity = size;
    harr = new int[size];
}

// Destructor: Deletes dynamically allocated array
MinHeap::~MinHeap() {
    delete[] harr;
}

// Returns index of left child of node at index `parent`
int MinHeap::left(int parent) {
    int i = 2 * parent + 1;
    return (i < heap_size) ? i : -1;
}

// Returns index of right child of node at index `parent`
int MinHeap::right(int parent) {
    int i = 2 * parent + 2;
    return (i < heap_size) ? i : -1;
}

// Returns index of parent of node at index `child`
int MinHeap::parent(int child) {
    if (child == 0) return -1; // Root has no parent
    return (child - 1) / 2;
}

// Returns the number of elements in the heap
int MinHeap::size() {
    return heap_size;
}

// Inserts a new element into the MinHeap
void MinHeap::insert(int element) {
    if (heap_size == capacity) {
        cout << "Heap overflow! Cannot insert more elements." << endl;
        return;
    }

    // Insert new element at the end
    int i = heap_size;
    harr[i] = element;
    heap_size++;

    // Restore the min-heap property
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Extracts and returns the minimum element from the heap
int MinHeap::extractMin() {
    if (heap_size <= 0) {
        return INT_MAX; // Indicates an empty heap
    }
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    // Remove the root and replace it with the last element
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;

    // Restore heap property
    MinHeapify(0);

    return root;
}

// Recursive function to maintain the min-heap property
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l != -1 && harr[l] < harr[smallest]) {
        smallest = l;
    }
    if (r != -1 && harr[r] < harr[smallest]) {
        smallest = r;
    }

    // Swap and continue heapifying if needed
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// Displays the elements of the heap
void MinHeap::display() {
    cout << "MinHeap: ";
    for (int i = 0; i < heap_size; i++) {
        cout << harr[i] << " ";
    }
    cout << endl;
}

// HeapSort: Sorts the given array using a MinHeap
void MinHeap::heapsort(vector<int>& A, int n) {
    MinHeap heap(n);

    // Insert all elements into the heap
    for (int i = 0; i < n; i++) {
        heap.insert(A[i]);
    }

    // Extract elements in sorted order
    for (int i = 0; i < n; i++) {
        A[i] = heap.extractMin();
    }
}
