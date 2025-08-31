#include <iostream> 
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std; 



// N=north, S=south, W=west, E=east search
void search_N(int &total_XMAS, const vector<string>& matrix, size_t i, size_t j){
    if (matrix[i-1][j] == 'M'){
        if (matrix[i-2][j] == 'A'){
            if (matrix[i-3][j] == 'S'){
                total_XMAS++;
            }
        }
    }
}


void search_S(int &total_XMAS, const vector<string>& matrix, size_t i, size_t j){
    if (matrix[i+1][j] == 'M'){
        if (matrix[i+2][j] == 'A'){
            if (matrix[i+3][j] == 'S'){
                total_XMAS++;
            }
        }
    }
}


void search_W(int &total_XMAS, const vector<string>& matrix, size_t i, size_t j){
    if (matrix[i][j-1] == 'M'){
        if (matrix[i][j-2] == 'A'){
            if (matrix[i][j-3] == 'S'){
                total_XMAS++;
            }
        }
    }
}

void search_E(int &total_XMAS, const vector<string>& matrix, size_t i, size_t j){
    if (matrix[i][j+1] == 'M'){
        if (matrix[i][j+2] == 'A'){
            if (matrix[i][j+3] == 'S'){
                total_XMAS++;
            }
        }
    }
}




// Oblique search
void search_NE(int &total_XMAS, const vector<string>& matrix, size_t i, size_t j){
    if (matrix[i-1][j+1] == 'M'){
        if (matrix[i-2][j+2] == 'A'){
            if (matrix[i-3][j+3] == 'S'){
                total_XMAS++;
            }
        }
    }
}


void search_NW(int &total_XMAS, const vector<string>& matrix, size_t i, size_t j){
    if (matrix[i-1][j-1] == 'M'){
        if (matrix[i-2][j-2] == 'A'){
            if (matrix[i-3][j-3] == 'S'){
                total_XMAS++;
            }
        }
    }
}


void search_SE(int &total_XMAS, const vector<string>& matrix, size_t i, size_t j){
    if (matrix[i+1][j+1] == 'M'){
        if (matrix[i+2][j+2] == 'A'){
            if (matrix[i+3][j+3] == 'S'){
                total_XMAS++;
            }
        }
    }
}


void search_SW(int &total_XMAS, const vector<string>& matrix, size_t i, size_t j){
    if (matrix[i+1][j-1] == 'M'){
        if (matrix[i+2][j-2] == 'A'){
            if (matrix[i+3][j-3] == 'S'){
                total_XMAS++;
            }
        }
    }
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
    for (size_t i = 0; i < matrix.size(); i++){   // Rows
        for(size_t j = 0; j < matrix[i].size(); j++){ // Columns of each row (of each line)

            if (matrix[i][j] == 'X'){
                // N,S,W,E search
                if (i > 2) search_N(total_XMAS,matrix,i,j);
                if (i < matrix.size()-3) search_S(total_XMAS,matrix,i,j);
                if (j > 2) search_W(total_XMAS,matrix,i,j);
                if (j < matrix[i].size()-3) search_E(total_XMAS,matrix,i,j);

                // Oblique search
                if (i > 2 && j > 2) search_NW(total_XMAS,matrix,i,j);
                if (i > 2 && j < matrix[i].size()-3) search_NE(total_XMAS,matrix,i,j);
                if (i < matrix.size()-3 && j > 2) search_SW(total_XMAS,matrix,i,j);
                if (i < matrix.size()-3 && j < matrix[i].size()-3) search_SE(total_XMAS,matrix,i,j);
            }
        }
    }


    file.close();

    cout << "The word XMAS appears " << total_XMAS << " times" << endl;
    return 0; 
}