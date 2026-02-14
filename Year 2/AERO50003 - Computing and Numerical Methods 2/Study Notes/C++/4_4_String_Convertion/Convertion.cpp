#include <iostream>
using namespace std; 

int main() {
    string s         = "42.1230615472480 is what we want to call";
    int         num  = stoi(s); // convert to an integer
    float       numf = stof(s); // convert to a float
    double      numd = stod(s); // convert to a double
    
    cout << num << endl;
    cout << numf << endl;
    cout << numd << endl;
}
