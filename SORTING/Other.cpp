#include <iostream>
using namespace std;

class sorting
{
    public:
        // Function to implement bubble sort. Used swap() in all
        void bubbleSort(int arr[], int n)
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }

        // Function to implement selection sort
        void selectionSort(int arr[], int n)
        {
            for (int i = 0; i < n - 1; i++)
            {
                int minIndex = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] < arr[minIndex])
                    {
                        minIndex = j;
                    }
                }
                swap(arr[i], arr[minIndex]);
            }

            for (int i = n-1; i>0; i--)
            {
                int maxIndex = i;
                for (int j = 0; j<i;j++)
                {
                    if (arr[j] > arr[maxIndex])
                    {
                        maxIndex = j;
                    }
                }
                swap(arr[i], arr[maxIndex]);
            }
        }

        // Function to implement bubble sort
        void insertionSort(int arr[], int n)
        {
            for (int i = 1; i < n; i++)
            {
                int key = arr[i];
                int j = i - 1;

                while (j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }

                arr[j + 1] = key;
            }
        }

        // function to use in merge sort
        void merge(int arr[], int left, int mid, int right)
        {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            int L[n1], R[n2];

            for (int i = 0; i < n1; i++)
            {
                L[i] = arr[left + i];
            }
            for (int i = 0; i < n2; i++)
            {
                R[i] = arr[mid + 1 + i];
            }

            int i = 0, j = 0, k = left;

            while (i < n1 && j < n2)
            {
                if (L[i] <= R[j])
                {
                    arr[k] = L[i];
                    i++;
                }
                else
                {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1)
            {
                arr[k] = L[i];
                i++;
                k++;
            }

            while (j < n2)
            {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        // Calling the merge function recursively
        void mergeSort(int arr[], int left, int right)
        {
            if (left < right)
            {
                int mid = left + (right - left) / 2;

                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);
                merge(arr, left, mid, right);
            }
        }
};

int main()
{
    sorting Sorts;
    // Calling bubble sort and displaying output
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    Sorts.bubbleSort(arr, n);

    cout << "BUBBLE SORT: " << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl << endl;

    // Calling Insertion sort and displaying output
    int arr2[] = {12, 11, 13, 5, 6};
    n = sizeof(arr2) / sizeof(arr2[0]);

    Sorts.insertionSort(arr2, n);

    cout << "INSERTION SORT: " << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }

    // Calling Selection sort and displaying output
    int arr3[] = {64, 25, 12, 22, 11};
    n = sizeof(arr3) / sizeof(arr3[0]);

    Sorts.selectionSort(arr3, n);

    cout << endl
         << endl;
    cout << "SELECTION SORT: " << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr3[i] << " ";
    }

    // Calling bubble sort and displaying output
    int arr4[] = {64, 34, 25, 12, 22, 11, 90, 23, 55, 12, 55};
    n = sizeof(arr4) / sizeof(arr4[0]);

    cout << endl
         << endl;

    Sorts.mergeSort(arr4, 0, n - 1);

    cout << "MERGE SORT: " << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr4[i] << " ";
    }

    cout << endl
         << endl;

    return 0;
}
