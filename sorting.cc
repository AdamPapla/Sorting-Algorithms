#include <iostream>
#include <vector>
#include <iomanip>

#include "sorting.hh"
using namespace std;

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

void quickSort(vector<int>& arr){
    int n = arr.size();
    if (n < 2){
        return;
    }
    int pivot = arr[n-1];
    int i=-1;
    for (int j=0; j<n-1; ++j){
        if (arr[j] >= pivot)
            continue;
        else {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[n-1] = arr[i+1];
    arr[i+1] = pivot;
    auto pivotIt = arr.begin();
    advance(pivotIt, i+1);
    vector<int> left (arr.begin(), pivotIt);
    vector<int> right (++pivotIt, arr.end());

    quickSort(left);
    quickSort(right);
    int lSize = left.size();
    int rSize = right.size();
    for (int i=0; i<lSize; ++i)
        arr[i] = left[i];
    for (int i=0; i<rSize; ++i)
        arr[i + lSize + 1] = right[i];
}
