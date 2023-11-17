#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
 
class Sorted{
    public:
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

        void countingSort(std::vector<int>& arr) {
            // Find the maximum and minimum values in the array
            int max_val = *std::max_element(arr.begin(), arr.end());
            int min_val = *std::min_element(arr.begin(), arr.end());

            // Create a counting array to store the count of each element
            std::vector<int> count(max_val - min_val + 1, 0);

            // Count the occurrences of each element in the input array
            for (int num : arr) {
                count[num - min_val]++;
            }

            // Reconstruct the sorted array using the counting array
            int index = 0;
            for (int i = min_val; i <= max_val; ++i) {
                while (count[i - min_val] > 0) {
                    arr[index++] = i;
                    count[i - min_val]--;
                }
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
};

int main() { 
    Sorted srt;
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    // Array sizes
    vector<int> sizes = {100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        vector<int> arr = srt.generateRandomArray(size);

        // Measure time for Merge Sort
        clock_t start_time = clock();
        srt.mergeSort(arr, 0, size - 1);
        clock_t end_time = clock();
        double mergeSortTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Restore the original unsorted array
        random_shuffle(arr.begin(), arr.end());

        // Measure time for Quick Sort
        start_time = clock();
        srt.quickSort(arr,  0, size-1);
        end_time = clock();
        double quickSortTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Restore the original unsorted array
        random_shuffle(arr.begin(), arr.end());

        // Measure time for Quick Sort
        start_time = clock();
        srt.countingSort(arr);
        end_time = clock();
        double countingSortTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        cout << "Array size: " << size << endl;
        cout << "Merge Sort time: " << mergeSortTime << endl;
        cout << "Quick Sort time: " << quickSortTime << endl;
        cout << "Counting Sort time: " << countingSortTime << endl;
        
        cout << endl;
    }

    return 0;
}
 
