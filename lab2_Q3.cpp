#include <iostream>
#include <string>

using namespace std;

struct Area
{
	private:
        string units;
        float area_value;

    public:
        string getUnits() const {
            return units;
        }

        float getAreaValue() const {
            return area_value;
        }

        void setUnits(const std::string& u) {
            units = u;
        }

        void setAreaValue(float value) {
            area_value = value;
        }

        float computeHalfArea() const {
            return area_value / 2.0;
        }

        float computeQuarterArea() const {
            return area_value / 4.0;
        }
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
	
	dynamicArea->setAreaValue(areaval);
    dynamicArea->setUnits(units);

	/*
	* Compute one-half and one-quarter of the area 
	* and display the results 
	*/
	
    float halfArea = dynamicArea->computeHalfArea();
    float quarterArea = dynamicArea->computeQuarterArea();
	
    cout << "One-Half of the Area: " << halfArea << " " << units << std::endl;
    cout << "One-Quarter of the Area: " << quarterArea << " " << units << std::endl;

	/*
	* Destroy the dynamic variable at the end
	*/
	
	// Add your code here!
	delete dynamicArea;
	
	return 0;
}
