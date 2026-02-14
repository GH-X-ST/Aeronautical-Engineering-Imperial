#include <iostream>
#include <string>
#include <limits> // include limits
using namespace std; 

int main() {
    
    // Whitespace delimited
    string input;
    cout << "Enter text (whitespace-delimited): ";
    cin >> input;
    
    cout << "Using stream operators: " << input << endl; 
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // reset the input
    
    // New line delimited
    cout << "Enter text (newline-delimited): ";
    getline(cin, input); 
    
    cout << "Using default getline: " << input << endl;
    
    // Comma delimited
    cout << "Enter text (comma-delimited): ";
    getline(cin, input, ',');
    
    cout << "Using comma separator: " << input << endl;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // reset the input

return 0;
}