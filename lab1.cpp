#include <iostream>
using namespace std;

void swap1(int *a, int *b){
    int temp = *a; 
    *a = *b;       
    *b = temp;  
};

void swap2(int **a, int **b){
    int temp = **a; 
    **a = **b;       
    **b = temp;  
};

int main()
{
    int a, *p, *q;
	int arr[4]= {0};

    cout<< arr<<endl;

	p=arr;

    cout<< p<<endl;

	q=p;

    cout<< q<<endl;

	*p=4;

	for(int i=0; i<3; i++){
			a=*p;
			p++;
			*p=(a+i);
	}
	for (int j=0; j<4; j++){

			cout<<*q<<" ";
			q++;
	}


}
