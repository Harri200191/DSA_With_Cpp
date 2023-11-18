#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class SortTiming{
    public:
    // Function to generate an array of random numbers in the range 1 to 100
        vector<int> generateRandomArray(int size) {
            vector<int> arr(size);
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 100 + 1;
            }
            return arr;
        }

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
};

int main() {
    // Create an object of the SortTiming class
    SortTiming srt;

    // Set the seed for the random number generator
    srand(static_cast<unsigned>(time(0)));  

    // Array sizes
    vector<int> sizes = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000};

    for (int size : sizes) {
        // Generate random arrays
        vector<int> arrAsc = srt.generateRandomArray(size);
        vector<int> arrDesc = arrAsc;

        // Measure time for sort (ascending order)
        clock_t start_time = clock();
        sort(arrAsc.begin(), arrAsc.end());
        clock_t end_time = clock();
        double stdSortAscendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for sort (descending order)
        start_time = clock();
        sort(arrDesc.rbegin(), arrDesc.rend());
        end_time = clock();
        double stdSortDescendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for quick sort (ascending order)
        start_time = clock();
        srt.quickSort(arrAsc, 0, size - 1);
        end_time = clock();
        double quickSortAscendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for quick sort (descending order)
        start_time = clock();
        srt.quickSort(arrDesc, 0, size - 1);
        end_time = clock();
        double quickSortDescendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for count sort (ascending order)
        start_time = clock();
        srt.countingSort(arrAsc);
        end_time = clock();
        double countingSortAscendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for count sort (descending order)
        start_time = clock();
        srt.countingSort(arrDesc);
        end_time = clock();
        double countingSortDescendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Display the results
        cout << "Array size: " << size << endl; 
        cout << "Quick Sort (ascending order) time: " << quickSortAscendingTime << endl;
        cout << "Quick Sort (descending order) time: " << quickSortDescendingTime << endl;
        cout << "Counting Sort (ascending order) time: " << countingSortAscendingTime << endl;
        cout << "Counting Sort (descending order) time: " << countingSortDescendingTime << endl;

        cout<<endl;
    }
 

    return 0;
}
