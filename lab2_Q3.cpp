#include <iostream>
#include <string>

using namespace std;

struct Area
{
	private:
        string units;
        float area_value;
};

int main()
{
    float areaval;
    string units;
	/*
	* Modify program to create a dynamic variable of type Area.
	*/
	
	Area* dynamicArea = new Area();

	/*
	* Input from the keyboard the area_value and its units.
	*/
	
	cout<< "Enter area value: ";
    cin>> areaval;
    cout<<endl;
    cout<< "Enter units: ";
    cin>> units;
	
	
	/*
	* Compute one-half and one-quarter of the area 
	* and display the results 
	*/
	
	// Add your code here!
	

	/*
	* Destroy the dynamic variable at the end
	*/
	
	// Add your code here!
	delete dynamicArea;
	
	return 0;
}
