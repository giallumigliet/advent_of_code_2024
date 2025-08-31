#include <iostream> 
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std; 



// Oblique search
bool search_primary_diagonal(const vector<string>& matrix, size_t i, size_t j){
    bool is_present = false;
    if (matrix[i-1][j-1] == 'M'){
        if (matrix[i+1][j+1] == 'S'){
            is_present = true;
        }
    }
    if (matrix[i-1][j-1] == 'S'){
        if (matrix[i+1][j+1] == 'M'){
            is_present = true;
        }
    }
    return is_present;
}


bool search_secondary_diagonal(const vector<string>& matrix, size_t i, size_t j){
    bool is_present = false;
    if (matrix[i-1][j+1] == 'M'){
        if (matrix[i+1][j-1] == 'S'){
            is_present = true;
        }
    }
    if (matrix[i-1][j+1] == 'S'){
        if (matrix[i+1][j-1] == 'M'){
            is_present = true;
        }
    }
    return is_present;
}




int main() {
    
    ifstream file("input_04.txt");
    string line;
   
    int total_XMAS = 0;
    char c;
    vector<string> matrix;

    while (getline(file, line)) {
        matrix.push_back(line);      
    }


    // Search
    for (size_t i = 1; i < matrix.size()-1; i++){   // Rows
        for(size_t j = 1; j < matrix[i].size()-1; j++){ // Columns of each row (of each line)

            if (matrix[i][j] == 'A'){
                if(search_primary_diagonal(matrix,i,j) && search_secondary_diagonal(matrix,i,j)) total_XMAS++;
            }
        }
    }


    file.close();

    cout << "The word XMAS appears " << total_XMAS << " times" << endl;
    return 0; 
}