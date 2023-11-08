#include <iostream>
#include <vector>

using namespace std;
 
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;  

    for (int j = low; j < high; j++) { 
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
 
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
 
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) { 
        int pivotIndex = partition(arr, low, high); 
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int n = arr.size();
    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
 
