#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot peek." << std::endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element: " << myQueue.peek() << std::endl;

    while (!myQueue.isEmpty()) {
        std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;
    }

    return 0;
}
