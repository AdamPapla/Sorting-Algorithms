#ifndef SORTING_HH_
#define SORTING_HH_ 
#include <vector>

void bubbleSort(std::vector<int>& arr);

void insertionSort(std::vector<int>& arr);

void selectionSort(std::vector<int>& arr);

void mergeSort(std::vector<int>& arr);
void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& arr);

void quickSort(std::vector<int>& arr);
#endif