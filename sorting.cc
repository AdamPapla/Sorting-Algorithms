#include <iostream>
#include <vector>
using namespace std;
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