#include <iostream>
#include <string>

using namespace std;

void analyze_pointer(int *ptr) {
    std::cout << "Memory Location: " << ptr << std::endl;
    std::cout << "Value: " << *ptr << std::endl;
}


int main() {
    int iValue = 42; 
    int *stackPtr = &iValue; 
    analyze_pointer(stackPtr); 

    int *heapPtr = new int; 
    *heapPtr = 73; 
    analyze_pointer(heapPtr); 

    delete heapPtr;

    return 0;
}
