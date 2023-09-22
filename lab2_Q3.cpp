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

/* int main(void)
{
    int salary[20];
    int i;
    for (i = 0; i < 20; ++i)
    {
        cout << "Enter Salary: ";
        cin >> salary[i];
    }
    for (i = 0; i < 20; ++i)
        salary[i] = salary[i] + salary[i] / (i + 1);

    for (i = 0; i < 20; ++i)
    {
        cout << salary[i]<< " ";
    }

    return 0;
}
 */