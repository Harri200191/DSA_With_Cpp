#include <iostream>
#include <chrono>

using namespace std;
 
long long recursiveFibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

long long iterativeFibonacci(int n) {
    long long a = 0, b = 1, c;

    if (n == 0){
        return a;
    } 

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
 
    auto startRec = chrono::high_resolution_clock::now();
    long long recursiveResult = recursiveFibonacci(n);
    auto stopRec = chrono::high_resolution_clock::now();
    auto durationRec = chrono::duration_cast<chrono::milliseconds>(stopRec - startRec);

    // Measure time for iterative Fibonacci
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
