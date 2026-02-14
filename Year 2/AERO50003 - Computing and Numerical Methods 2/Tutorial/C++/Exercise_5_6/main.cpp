// Read the file created in the Exercise 5.5

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream f_in("/home/hl3422/C++/Notes and Exercises/Exercise_5_5/sine.txt"); // read the file
    
    // Print head title
    cout << setw(10) << setprecision(5) << "x"
    << setw(10) << setprecision(5) << "sin(x)" << endl;
    
    // Print the information
    while (!f_in.eof())
    {
        
        float var1, var2 = 0.0;
        
        f_in >> var1 >> var2;
        
        cout << setw(10) << setprecision(5) << var1
        << setw(10) << setprecision(5) << var2 << endl;
 
    }
    
    cout << endl;
    cout << "Finish reading" << endl;
    
    f_in.close();
    
	return 0;
}