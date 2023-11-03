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

        // function to use in merge sort
        void merge(vector<int>& arr, int left, int mid, int right) {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            int L[n1], R[n2];

            for (int i = 0; i < n1; i++) {
                L[i] = arr[left + i];
            }
            for (int i = 0; i < n2; i++) {
                R[i] = arr[mid + 1 + i];
            }

            int i = 0, j = 0, k = left;

            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }

            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        // Calling the merge function recursively
        void mergeSort(vector<int>& arr, int left, int right) {
            if (left < right) {
                int mid = left + (right - left) / 2;

                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);

                merge(arr, left, mid, right);
            }
        }
};

int main() {
    SortTiming srt;
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    // Array sizes
    vector<int> sizes = {100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        vector<int> arrAsc = srt.generateRandomArray(size);
        vector<int> arrDesc = arrAsc;

        clock_t start_time = clock();
        sort(arrAsc.begin(), arrAsc.end());
        clock_t end_time = clock();
        double stdSortAscendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for sort (descending order)
        start_time = clock();
        sort(arrDesc.rbegin(), arrDesc.rend());
        end_time = clock();
        double stdSortDescendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        start_time = clock();
        srt.bubbleSort(arrAsc, size);
        end_time = clock();
        double bubbleSortAscendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for Bubble Sort
        start_time = clock();
        srt.bubbleSort(arrDesc, size);
        end_time = clock();
        double bubbleSortDescendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for Selection Sort
        start_time = clock();
        srt.selectionSort(arrAsc, size);
        end_time = clock();
        double selectionSortAscendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for Selection Sort
        start_time = clock();
        srt.selectionSort(arrDesc, size);
        end_time = clock();
        double selectionSortDescendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for Insertion Sort
        start_time = clock();
        srt.insertionSort(arrAsc, size);
        end_time = clock();
        double insertionSortAscendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for Insertion Sort
        start_time = clock();
        srt.insertionSort(arrDesc, size);
        end_time = clock();
        double insertionSortDescendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for Merge Sort
        start_time = clock();
        srt.mergeSort(arrAsc, 0, size-1);
        end_time = clock();
        double mergeSortAscendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

        // Measure time for Merge Sort
        start_time = clock();
        srt.mergeSort(arrDesc, 0, size-1);
        end_time = clock();
        double mergeSortDescendingTime = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;


        cout << "Array size: " << size << endl; 
        cout << "Bubble Sort Ascending Time: " << bubbleSortAscendingTime << " seconds" << endl;
        cout << "Bubble Sort Descending Time: " << bubbleSortDescendingTime << " seconds" << endl;
        cout << "Selection Sort Ascending Time: " << selectionSortAscendingTime << " seconds" << endl;
        cout << "Selection Sort Descending Time: " << selectionSortDescendingTime << " seconds" << endl;
        cout << "Insertion Sort Ascending Time: " << insertionSortAscendingTime << " seconds" << endl;
        cout << "Insertion Sort Descending Time: " << insertionSortDescendingTime << " seconds" << endl;
        cout << "Merge Sort Ascending Time: " << mergeSortAscendingTime << " seconds" << endl;
        cout << "Merge Sort Descending Time: " << mergeSortDescendingTime << " seconds" << endl;
        cout<<endl;
    }
 

    return 0;
}
