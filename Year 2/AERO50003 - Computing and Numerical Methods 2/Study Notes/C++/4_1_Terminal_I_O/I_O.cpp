#include <iostream>

using namespace std;

int main()
{
    string vName;                // a sequence of characters
    unsigned int vAge;
    unsigned int vOption;
    
    cout << "Enter your name: "; // output data to the terminal
    cin >> vName;                // read data input into the terminal
    
    cout << "Enter your age: ";
    cin >> vAge;
    
    cout << "Please select an option: " << endl; // start a new line
    cout << " 1. Option 1" << endl;
    cout << " 2. Option 2" << endl;
    cout << " 3. Quit" << endl;
    cout << " Enter option:" << endl;
    cin >> vOption;
    
    cout << "Name: " << vName << ", Age: " 
    << vAge << ", Option: " << vOption << endl;
}

