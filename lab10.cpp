#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to parse a line and extract grades and course names into vectors
pair<vector<string>, vector<string>> extractGrades(const string& line) {
    vector<string> courseNames = {"OOP","CALD","LA","COMM","Isl","ED"};
    vector<string> grades;
    istringstream iss(line);
    string token;
    bool firstToken = true;
    while (getline(iss, token, ',')) {
        if (firstToken) { 
            firstToken = false;
        } else {
            if (!token.empty() && token != "Student") {
                grades.push_back(token);
            }
        }
    }

    return {courseNames, grades};
}


vector<int> mergeSortedVectors(const vector<int>& v1, const vector<int>& v2) {
    vector<int> result;
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(result));
    return result;
}

// Function to apply merge sort on each column
void applyMergeSortOnColumns(const vector<vector<string>>& allGrades) {
    vector<string> courseNames = {"OOP","CALD","LA","COMM","Isl","ED"};
    for (size_t i = 0; i < allGrades[0].size(); ++i) {
        vector<pair<string, string>> column;

        // Create pairs of grades and corresponding student names
        for (size_t j = 0; j < allGrades.size(); ++j) {
            column.push_back({allGrades[j][i], allGrades[j][0]});
        }

        // Sort based on grades
        sort(column.begin(), column.end());

        // Print the course name
        cout << courseNames[i] << ": ";

        // Print the sorted column
        for (const auto& grade : column) {
            cout << grade.first << ", ";
        }
        cout << endl;
    }
}

int main() {
    // Read dataset from a text file
    ifstream inputFile("grades.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    getline(inputFile, line); // Read and ignore the header line

    // Read and process each line
    vector<vector<string>> allGrades;
    while (getline(inputFile, line)) {
        // Extract course names and grades from the line
        auto [courseNames, grades] = extractGrades(line); 

        // Store the grades
        allGrades.push_back(grades);
    }

    cout<<"Got here"<<endl;

    // Apply merge sort on each column and display the results
    applyMergeSortOnColumns(allGrades);

    return 0;
}
