#include <iostream>
using namespace std;

int main()
{
    int *salArray= new int[20]; 
    int i;

    for (i = 0; i < 20; ++i)
    {
        cout << "Enter Salary: ";
        cin >> *(salArray+i);
    }

    for (i = 0; i < 20; ++i)
        *(salArray+i) = *(salArray+i) + *(salArray+i) / (i + 1);

    for (i = 0; i < 20; ++i)
    {
        cout << *(salArray+i)<< " ";
    }
    delete [] salArray;
    return 0;
}
