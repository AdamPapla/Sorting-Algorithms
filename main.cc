#include <iostream>
#include <vector>
#include <random>
#include "sorting.hh"

using namespace std;

#define ARRAY_SIZE 100
int main(void){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 100);  

    std::vector<int> arr(ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = distribution(gen);
    }
    for (int i : arr)
        cout << i << ", ";
    cout << endl << endl;
    quickSort(arr);
    for (int i : arr)
        cout << i << ", ";
    cout << endl;
    return 0;    
}