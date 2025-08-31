#include <iostream> 
#include <fstream>
#include <sstream>
#include <vector>

using namespace std; 

int main() {
    
    ifstream file("input_01.csv");
    vector<int> array1, array2;
    string line;


    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        if (getline(ss, value, ',')) array1.push_back(stoi(value));
        if (getline(ss, value, ',')) array2.push_back(stoi(value));
    }

    // Print to verify input numbers
    for (size_t i = 0; i < array1.size(); i++) cout << array1[i] << " " << array2[i] << endl;

    
    // Initialization
    vector<bool> is_used1(array1.size(), false);
    vector<bool> is_used2(array2.size(), false);
    
    int sum = 0;


    // Search
    for (size_t j = 0; j < array1.size(); j++) {  

        int min1 = 1000000;
        int min2 = 1000000;

        size_t min_index1 = 0;
        size_t min_index2 = 0;

        for (size_t i = 0; i < array1.size(); i++) { // search for un-used minimum in array1
            if (array1[i] < min1 && is_used1[i] == false){
                min1 = array1[i];
                min_index1 = i;
            }
        }
        is_used1[min_index1] = true;

        for (size_t  i = 0; i < array2.size(); i++) { // search for un-used minimum in array2
            if (array2[i] < min2 && is_used2[i] == false){
                min2 = array2[i];
                min_index2 = i;
            }
        }
        is_used2[min_index2] = true;


        sum += abs(min1-min2);
    }

    cout << "The total distance is:" << sum << endl;
    return 0; 
}