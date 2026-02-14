// tellg() // Position of the next read operation
// tellp() // Position of the next write operation

// seekg()                 // Seek to an absolute position
// seekg(offset, position) // Seek an offset from a position
// position                // ios:beg, ios:end, ios:cur

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Create input file stream
    ifstream vMyFile("data.txt");
    
    // Use tellg() function
    string vBuffer;
    
    vMyFile >> vBuffer; // read word from the file till next space
    
    cout << vBuffer << endl;
    
    cout << vMyFile.tellg() << endl; // print the position in file
    
    cout << "\n" << endl;
    
    getline (vMyFile, vBuffer); // read first line from the file
    
    cout << vBuffer << endl;
    
    cout << vMyFile.tellg() << endl; // print the position in file
    
    // Use seekg() function
    unsigned int vBegin, vEnd;
    
    vMyFile.seekg(0, ios::beg); // go to the begin of the file
    vBegin = vMyFile.tellg();   // get current position
    
    vMyFile.seekg(0, ios::end); // go to the end of the file
    vEnd = vMyFile.tellg();     // get current position
    
    cout << "\n" << endl;
    
    cout << "File length is " << (vEnd - vBegin)
         << " bytes long." << endl;
         
    vMyFile.close(); // close the file
    
	return 0;
}
