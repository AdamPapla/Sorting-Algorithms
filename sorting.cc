/**
 * Brief: Contains implementations of some of the most popular sorting algorithms.
 * Author: Adam Graham
*/
#include <iostream>
#include <vector>
#include <iomanip>

#include "sorting.hh"
using namespace std;
/**
 * Bubble sort
 * Iteratively swaps pairs of elements to bubble the largest entry to the end of the array
 * Space complexity: O(1)
 * Time complexity: O(n^2) 
 * Use cases: Small, almost sorted arrays
*/
void bubbleSort(vector<int>& arr){
    int n = arr.size();
    for (int i=0; i<n; ++i){
        for (int j=1; j<n-i; ++j){
            if (arr[j-1] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

/**
 * Insertion sort
 * Iterates through the array. At each iteration i, iterates j back towards the start. 
 * Pushes all elements arr[j] to the right until arr[i] >= arr[j]
 * 
 * Space complexity: O(1)
 * Time complexity: O(n^2)
 * Use cases: Small, almost sorted arrays. 
*/
void insertionSort(vector<int>& arr){
    int n = arr.size();
    for (int i=1; i<n; ++i){
        int j = i-1;
        int temp = arr[i];
        while (j >= 0 && temp < arr[j]){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = temp;
    }
}

/**
 * Selection sort
 * Iterates through the array, finding the minimum element of the remaining unsorted array
 * and swapping it to its correct position
 * 
 * Space complexity: O(1)
 * Time complexity: O(n^2)
 * Use cases: Small array with limited memory- uses minimum possible swaps
*/
void selectionSort(vector<int>& arr){
    int n = arr.size();
    for (int i=0; i < n; ++i){
        int temp = arr[i];
        int min = i;
        for (int j=i+1; j < n; ++j){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

/**
 * Helper function for merge sort. 
 * Merges the two arrays on either side of the pivot to create a sorted array
*/
void merge(vector<int>& left, vector<int>& right, vector<int>& arr){
    int leftInd = 0;
    int rightInd = 0;
    int lSize = left.size();
    int rSize = right.size();
    int n = arr.size();
    for (int i=0; i<n; ++i){
        if (leftInd >= lSize){
            arr[i] = right[rightInd];
            ++rightInd;
        }      
        else if (rightInd >= rSize){
            arr[i] = left[leftInd];
            ++leftInd;
        }
        else if ( left[leftInd] < right[rightInd]){
            arr[i] = left[leftInd];
            ++leftInd;
        }
        else {
            arr[i] = right[rightInd];
            ++rightInd;
        }
    }
}

/**
 * Merge sort
 * Breaks array down recursively to one element blocks. Combines 
 * them back up into a sorted array
 * 
 * Space complexity: O(n)
 * Time complexity: Best - O(n*log(n))
 *                  Average - O(n*log(n))
 *                  Worst - O(n*log(n))
 * Use cases:   Linked lists, cases where data is sequentially accessible rather than
 *              accessible with random access iterators
*/
void mergeSort(vector<int>& arr){
    int n = arr.size();
    if (n <= 1)
        return;
    int middle = n/2;
    auto midIt = arr.begin();
    std::advance(midIt, middle);
    vector<int> left (arr.begin(), midIt);
    vector<int> right (midIt, arr.end());
    mergeSort(left);
    mergeSort(right);
    merge(left, right, arr);
}

/**
 * Quick sort
 * Pivots around an element to place all elements larger to the right 
 * and all smaller to the left. Proceeds recursively on the subarrays to the left
 * and right of the pivot.
 * 
 * Space complexity: Worst - O(n), Average - O(log(n))
 * Time complexity: Best - O(n*log(n))
 *                  Average - O(n*log(n))
 *                  Worst - O(n^2)
 * Use cases: Often fastest when data fits in memory
*/
void quickSort(vector<int>& arr){
    int n = arr.size();
    if (n <= 1){ // Done in this case
        return;
    }
    int pivot = arr[n-1];   // Choose pivot at end of array
    int i=-1;
    for (int j=0; j<n-1; ++j){
        if (arr[j] >= pivot)
            continue;
        else {
            // If pivot is greater than element, increment i and perform swap
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Insert pivot into correct location
    arr[n-1] = arr[i+1];
    arr[i+1] = pivot;
    // Create subarrays on either side of pivot
    auto pivotIt = arr.begin();
    advance(pivotIt, i+1);
    vector<int> left (arr.begin(), pivotIt);
    vector<int> right (++pivotIt, arr.end());
    quickSort(left);
    quickSort(right);
    // Merge sorted subarrays back into array
    int lSize = left.size();
    int rSize = right.size();
    for (int i=0; i<lSize; ++i)
        arr[i] = left[i];
    for (int i=0; i<rSize; ++i)
        arr[i + lSize + 1] = right[i];
}
