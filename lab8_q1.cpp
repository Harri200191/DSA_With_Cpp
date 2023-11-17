#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
 
// Function to implement quick sort partitions
int partition(vector<int>& arr, int low, int high) {

    // Select the pivot element
    int pivot = arr[high];  
    int i = low - 1;  

    // Move all elements smaller than pivot to the left
    for (int j = low; j < high; j++) { 
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
 
    // Move pivot to its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
 
// Function to implement quick sort
void quickSort(vector<int>& arr, int low, int high) {

    // Base case
    if (low < high) { 
        int pivotIndex = partition(arr, low, high); 

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to use in merge sort
void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    vector<int> left(n1);
    vector<int> right(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    // Merge the temporary arrays back into arr
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if there are any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(vector<int>& arr, int low, int high) {

    // Base case
    if (low < high) {
        int mid = (low + high) / 2;

        // Recursively sort the left and right halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// Function to generate a random array of size 'size'
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);

    // Generate random numbers between 1 and 100
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }

    return arr;
}

int main() { 
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    // Array sizes
    vector<int> sizes = {100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        vector<int> arr = generateRandomArray(size);

        // Measure time for Merge Sort
        clock_t start_time = clock();
        mergeSort(arr, 0, size - 1);
        clock_t end_time = clock();
        double mergeSortTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Restore the original unsorted array
        random_shuffle(arr.begin(), arr.end());

        // Measure time for Quick Sort
        start_time = clock();
        quickSort(arr,  0, size-1);
        end_time = clock();
        double quickSortTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        cout << "Array size: " << size << endl;
        cout << "Merge Sort time: " << mergeSortTime << endl;
        cout << "Quick Sort time: " << quickSortTime << endl;
        cout << endl;
    }

    return 0;
}
 
