/**
 * Brief: Main function to test sorting algorithms with randomly generated vectors
 * Author: Adam Graham
*/
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include "sorting.hh"

using namespace std;

#define ARRAY_SIZE 15

// Generate a random vector
vector<int> randVec(int n){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);  
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = dist(gen);
    }
    return arr;
}
//Print the vector
void printVec(const vector<int> v){
    for (int i : v)
        cout << i << ", ";
    cout << endl;
}

int main(void){
    vector<int> arr = randVec(ARRAY_SIZE);
    cout << setw(15) << "Unsorted:\t";
    printVec(arr);

    vector<int> arr1 = arr;
    bubbleSort(arr1);
    cout << setw(15) << "Bubble Sort:\t";
    printVec(arr1);

    vector<int> arr2 = arr;
    bubbleSort(arr2);
    cout << setw(15) << "Selection Sort:\t";
    printVec(arr2);

    vector<int> arr3 = arr;
    bubbleSort(arr3);
    cout << setw(15) << "Insertion Sort:\t";
    printVec(arr3);

    vector<int> arr4 = arr;
    mergeSort(arr4);
    cout << setw(15) << "Merge Sort:\t";
    printVec(arr4);

    vector<int> arr5 = arr;
    quickSort(arr5);
    cout << setw(15) << "Quicksort:\t";
    printVec(arr5);
    return 0;    
}