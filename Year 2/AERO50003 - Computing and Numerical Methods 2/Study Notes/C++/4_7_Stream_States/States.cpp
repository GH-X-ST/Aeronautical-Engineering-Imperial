// good() // Tests if a file is ready for reading or writing

// eof()  // Tests if the end of the file has been reached

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream vMyFile("data.txt");
    string vTemp;
    
    if (vMyFile.good()) // check file opened ok
    {
        while (true)                 // keep trying...
        {
            getline(vMyFile, vTemp); // ...to read file
            
            if (vMyFile.eof()) // test if end of file is reached // or while (!vMyFile.eof())
            {
                break;         // ... and stop if it is
            }
            cout << vTemp << endl; // print what we read
        }
                vMyFile.close();
    }
    else
    {
    cout << "Failed to open file" << endl;
    
    return 1; // non-zero error code
    }
    
    return 0;
}