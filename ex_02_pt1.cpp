#include <iostream> 
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std; 

int main() {
    
    ifstream file("input_02.csv");
    string line;

    int total_safe = 0;

    while (getline(file, line)) {
        
        
        vector<int> report;
        stringstream ss(line);
        string value;
        while (getline(ss, value, ',')) {
            if (value.empty()) {
                break;
            }
            try {
                report.push_back(stoi(value));
            } catch (const invalid_argument& ia) {
                cerr << "NOT VALID VALUE IN LINE '" << line << "': '" << value << "'" << endl;
                break; 
            }

        }

        // Print to verify input numbers
        for (int val : report) cout << val << " ";
        cout << endl;

        // Initialization
        bool is_safe = true;
        int last_direction = report[0] - report[1];
        
        // Check safe
        for (size_t i = 0; i < report.size()-1; i++) {
            if (abs(report[i] - report[i+1]) > 3 || abs(report[i] - report[i+1]) < 1) is_safe = false; // Check the difference step
            
            if ((report[i] - report[i+1]) * last_direction < 0) is_safe = false; // Check the direction
            
            if (!is_safe) break;
            
            last_direction = report[i] - report[i+1];
        }

        if (is_safe) {
            total_safe++;
            cout << "Safe" << endl;
        }

    }


    cout << "The total number of safe reports is:" << total_safe << endl;
    return 0; 
}