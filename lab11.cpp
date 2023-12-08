#include <iostream>
#include <math.h>

using namespace std;

// Function to swap two integers
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Heap Class
class Heap
{
    public:
        int values[30];
        int size;

    public:
        // Constructor
        Heap()
        {
            size = 0;
        }

        // Checks if empty
        bool isEmpty()
        {
            return size == 0;
        }

        // checks if full
        bool isFull()
        {
            return size == 30;
        }

        // returns the index of the parent of the node at index i
        int top()
        {
            if (isEmpty())
            {
                cout << "Heap is empty!\n";
                return -1;
            }
            else
            {
                return values[1];
            }
        }

        // Adds the value to the heap based on the heap property
        void push(int value)
        {
            if (isFull())
            {
                cout << "Heap is full!\n";
                return;
            }
            else
            {
                    size++;
                    int i = size;

                    while (i > 1 && value < values[i / 2])
                    {
                        values[i] = values[i / 2];
                        i /= 2;
                    }

                    values[i] = value;
            }
        }


        // creates a heap from an array
        void heapify(int index)
        {
            int smallest = index;
            int left = 2 * index;
            int right = 2 * index + 1;

            if (left <= size && values[left] < values[smallest])
            {
                smallest = left;
            }

            if (right <= size && values[right] < values[smallest])
            {
                smallest = right;
            }

            if (smallest != index)
            {
                swap(values[index], values[smallest]);
                heapify(smallest);
            }
           
        }

        // creates a heap from an array
        void buildheap()
        {
            for (int i = size / 2; i >= 1; i--)
            {
                heapify(i);
            }

        }

        // creates a heap from an array
        void buildheapfromarray(int* arr, int size)
        {
            for (int i = 0; i < size; i++)
                push(arr[i]);
            buildheap();
        }

        // deletes the minimum value from the heap
        void deleteMin()
        {
            if (isEmpty())
            {
                cout << "Heap is empty!\n";
                return;
            }

            values[1] = values[size];
            size--;
            heapify(1);
            buildheap();	
        }

        // return the element at index and reshuffle the heap
        int pop(int index)
        {
            if (index < 1 || index > size)
            {
                cout << "Invalid index!\n";
                return -1;
            }
            else
            {
                int poppedValue = values[index];
                values[index] = values[size];
                size--;
                heapify(index);
                return poppedValue;
            }
        }


        // prints the heap
        void print()
        {
            if (isEmpty())
            {
                cout << "Heap is empty!\n";
                return;
            }
            for (int i = 1; i <= size; i++)
            {
                cout << values[i] << " ";
                if (i==1 || i==3 || i==7 || i==15)
                    cout << endl;
            }
            cout << endl;
        }
        
        // returns the size of the heap
        int getSize()
        {
            return size;
        }

        // returns the height of the heap
        int getHeight()
        {
            return static_cast<int>(log2(size)) + 1;
        }
};

int main()
{
    // Create a heap
	Heap myHeap = Heap();
	const int arraySize = 15;
	int array[arraySize];

    // Fill the array with random values
	for (int i = 0; i < arraySize; i++)
		array[i] = (rand() % 100) + 1;

    // Build the heap from the array
	myHeap.buildheapfromarray(array, arraySize); 

    // Create the menu
	int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Print Heap\n";
        cout << "2. Get Top\n";
        cout << "3. Push Element\n";
        cout << "4. Pop Element\n";
        cout << "5. Get Size\n";
        cout << "6. Get Height\n";
        cout << "7. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Heap:\n";
            myHeap.print();
            break;
        case 2:
            cout << "Top Element: " << myHeap.top() << endl;
            break;
        case 3:
            int value;
            cout << "Enter value to push: ";
            cin >> value;
            myHeap.push(value);
            cout << "Value pushed.\n";
            break;
        case 4:
            int index;
            cout << "Enter index to pop: ";
            cin >> index;
            cout << "Popped Element: " << myHeap.pop(index) << endl;
            break;
        case 5:
            cout << "Size of Heap: " << myHeap.getSize() << endl;
            break;
        case 6:
            cout << "Height of Heap: " << myHeap.getHeight() << endl;
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

	getchar();
	return 0;
}
