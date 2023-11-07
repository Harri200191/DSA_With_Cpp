#include <iostream>

class CircularQueue {
private:
    int* arr;
    int front, rear, size;
    int capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[cap];
        front = rear = -1;
        size = 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cerr << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot peek." << std::endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue myQueue(5);

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element: " << myQueue.peek() << std::endl;

    while (!myQueue.isEmpty()) {
        std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;
    }

    return 0;
}
