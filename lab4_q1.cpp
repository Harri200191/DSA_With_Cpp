#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        char* data;
        int size;
        int top;

    public:
        Stack(int capacity) {
            size = capacity;
            data = new char[size];
            top = -1;
        }

        ~Stack() {
            delete[] data;
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == size - 1;
        }

        void push(char value) {
            if (isFull()) {
                cerr << "Stack overflow." << endl;
                exit(1);
            }
            data[++top] = value;
        }

        char pop() {
            if (isEmpty()) {
                cerr << "Stack underflow." << endl;
                exit(1);
            }
            return data[top--];
        }
};

bool isBalanced(const string& expression) {
    Stack stack(expression.length());

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } 
        else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty()) {
                return false;
            }

            char top = stack.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

int main() {
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalanced(expression)) {
        cout << "This expression is correct." << endl;
    } else {
        cout << "This expression is NOT correct." << endl;
    }

    return 0;
}
