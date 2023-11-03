#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
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

void insertionSort(int arr[], int n) {
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

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout<< "BUBBLE SORT: "<<endl;
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout<<endl;

    int arr2[] = {12, 11, 13, 5, 6};
    n = sizeof(arr2) / sizeof(arr2[0]);

    insertionSort(arr2, n);

    cout<< "INSERTION SORT: "<<endl;
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }

    int arr3[] = {64, 25, 12, 22, 11};
    n = sizeof(arr3) / sizeof(arr3[0]);

    selectionSort(arr, n);

    cout<<endl;
    cout<< "SELECTION SORT: "<<endl;    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr3[i] << " ";
    }

    return 0;
}
