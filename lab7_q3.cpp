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

        // Function to implement bubble sort. Used swap() in all
        void bubbleSort(vector<int>& arr, int n) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }

        // Function to implement selection sort
        void selectionSort(vector<int>& arr, int n) {
            for (int i = 0; i < n - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < n; j++) {
                    if (arr[j] < arr[minIndex]) {
                        minIndex = j;
                    }
                }
                swap(arr[i], arr[minIndex]);
            }
        }

        // Function to implement bubble sort
        void insertionSort(vector<int>& arr, int n) {
            for (int i = 1; i < n; i++) {
                int key = arr[i];
                int j = i - 1;

                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }

                arr[j + 1] = key;
            }
        }
};

int main() {
    SortTiming srt;
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    // Array sizes
    vector<int> sizes = {100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        vector<int> arr = srt.generateRandomArray(size);

        // Measure time for Bubble Sort
        clock_t start_time = clock();
        srt.bubbleSort(arr, size);
        clock_t end_time = clock();
        double bubbleSortTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Restore the original unsorted array
        random_shuffle(arr.begin(), arr.end());

        // Measure time for Selection Sort
        start_time = clock();
        srt.selectionSort(arr,  size);
        end_time = clock();
        double selectionSortTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Restore the original unsorted array
        random_shuffle(arr.begin(), arr.end());

        // Measure time for Insertion Sort
        start_time = clock();
        srt.insertionSort(arr, size);
        end_time = clock();
        double insertionSortTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        cout << "Array size: " << size << endl;
        cout << "Bubble Sort Time: " << bubbleSortTime << " seconds" << endl;
        cout << "Selection Sort Time: " << selectionSortTime << " seconds" << endl;
        cout << "Insertion Sort Time: " << insertionSortTime << " seconds" << endl;
        cout << endl;
    }
 

    return 0;
}
