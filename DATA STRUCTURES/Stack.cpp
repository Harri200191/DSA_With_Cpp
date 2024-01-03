#include <iostream>
#include <vector>

using namespace std;

class Stack {
    private:
        vector<int> stack;

    public:
        // Push an element onto the stack
        void push(int value) {
            stack.push_back(value);
        }

        // Pop and return the top element from the stack
        int pop() {
            if (isEmpty()) {
                cerr << "Stack is empty. Cannot pop." << endl;
                return -1;  // Return a default value (you can customize this)
            }
            int topValue = stack.back();
            stack.pop_back();
            return topValue;
        }

        // Return the top element of the stack without removing it
        int peek() {
            if (isEmpty()) {
                cerr << "Stack is empty. Cannot peek." << endl;
                return -1;  // Return a default value (you can customize this)
            }
            return stack.back();
        }

        // Check if the stack is empty
        bool isEmpty() {
            return stack.empty();
        }

        // Get the size of the stack
        size_t size() {
            return stack.size();
        }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element: " << myStack.peek() << endl;
    cout << "Stack size: " << myStack.size() << endl;

    while (!myStack.isEmpty()) {
        cout << "Popped element: " << myStack.pop() << endl;
    }

    return 0;
}
