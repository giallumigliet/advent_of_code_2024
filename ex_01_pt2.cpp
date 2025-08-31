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
    int sum = 0;

    // Search  
    for (size_t j = 0; j < array1.size(); j++) {  

        int occurrencies = 0;

        for (size_t i = 0; i < array1.size(); i++) { // search for occurrencies
            if (array1[j] == array2[i]){
                occurrencies++;
            }
        }
        sum += (array1[j] * occurrencies);
    }

    cout << "The total similarity score is:" << sum << endl;
    return 0; 
}

