#include <iostream> 
#include <fstream>
#include <cctype>

using namespace std; 





int main() {
    
    ifstream file("input_03.txt");
   
    int total_result = 0;
    int first_number = 0;
    int second_number = 0;
    char c;

    size_t i = 0;

    while (file.get(c)) {   // Read and check one char at a time
        if (c == 'm' && file.get(c)) {
            if (c == 'u' && file.get(c)) {
                if (c == 'l' && file.get(c)) {
                    if (c == '(' && file.get(c) && isdigit(c)) { // Once we have "mul(" we get the first number
                        do{
                            first_number *= 10;
                            first_number += ((c - '0'));
                            i++;
                        }
                        while(file.get(c) && isdigit(c) && i < 3);
                        cout << "first number is: " << first_number;
                        i = 0;

                        if ((c == ',' && file.get(c) && isdigit(c))) { // If we have ',' we get also the second number
                            do{
                                second_number *= 10;
                                second_number += (c - '0');
                                i++;
                            }
                            while(file.get(c) && isdigit(c) && i < 3);
                            cout << "; second number is: " << second_number;
                            i = 0;

                            if (c == ')') {
                                total_result += (first_number * second_number); // If we have ')' we get the result of the multiplication
                                cout << ";  " << first_number << " " << second_number << endl;
                            }
    
                        }
                        
                    }
                }
            }
        }

        first_number = 0;
        second_number = 0;
    }

    file.close();

    cout << "The sum of all the results is:" << total_result << endl;
    return 0; 
}