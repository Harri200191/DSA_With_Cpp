#include <iostream>
#include <chrono>

using namespace std;

// Recursive factorial function
unsigned long long recursiveFactorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * recursiveFactorial(n - 1);
}

// Iterative factorial function
unsigned long long iterativeFactorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    // Define values of n for which you want to calculate factorial
    int valuesOfN[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 5000, 10000, 20000, 30000, 32000};

    // Log execution times for both recursive and iterative methods
    cout << "n\tRecursive\tIterative" << endl;
    for (int n : valuesOfN) {
        auto start = chrono::high_resolution_clock::now();
        recursiveFactorial(n);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> recursiveTime = end - start;

        start = chrono::high_resolution_clock::now();
        iterativeFactorial(n);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double> iterativeTime = end - start;

        cout << n << "\t\t" << recursiveTime.count()*1000 << "ms\t\t" << iterativeTime.count()*1000 << "ms" << endl;
    }

    return 0;
}
