#include <iostream>
#include <chrono>
#include <time.h> 

using namespace std;
 
unsigned long long recursiveFibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

unsigned long long iterativeFibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    unsigned long long a = 0;
    unsigned long long b = 1;
    unsigned long long temp;

    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
 
    // Measure time for recursive Fibonacci
    auto startRec = chrono::high_resolution_clock::now(); 
    long long recursiveResult = recursiveFibonacci(n);
    auto stopRec = chrono::high_resolution_clock::now();
    auto durationRec = chrono::duration_cast<chrono::milliseconds>(stopRec - startRec);

    //Measure time for iterative Fibonacci
    auto startIter = chrono::high_resolution_clock::now();
    long long iterativeResult = iterativeFibonacci(n);
    auto stopIter = chrono::high_resolution_clock::now();
    auto durationIter = chrono::duration_cast<chrono::milliseconds>(stopIter - startIter);

    cout << "Recursive Fibonacci Result: " << recursiveResult << endl;
    cout << "Iterative Fibonacci Result: " << iterativeResult << endl;

    cout << "Time taken for Recursive Fibonacci: " << durationRec.count() << "ms" << endl;
    cout << "Time taken for Iterative Fibonacci: " << durationIter.count() << "ms" << endl;

    return 0;
}
