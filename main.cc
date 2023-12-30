#include <iostream>
#include <vector>

#include "sorting.hh"

using namespace std;

int main(void){
    vector<int> arr {9,3,2,5,1,4,8,7,6};
    selectionSort(arr);
    for (int i : arr)
        cout << i << ", ";
    cout << endl;
    return 0;    
}