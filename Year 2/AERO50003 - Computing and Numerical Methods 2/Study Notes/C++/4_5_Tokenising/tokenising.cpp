#include <iostream>
#include <sstream> // include stringstream
using namespace std;

int main()
{
    stringstream s; // tokenising the string
    s.str("1 2 3 4 5");
    cout << "The stringstream holds: " << s.str() << endl;
    cout << "Read at position: " << s.tellg() << endl; // tellg() to see which character position we are in the string
	
    int one, two, three;
    s >> one >> two >> three; // simillar to cin
    
    cout << one << ", " << two << ", " << three << endl;
    cout << "The stringstream holds: " << s.str() << endl;
    cout << "Read at position: " << s.tellg() << endl; // in the string, 0 = 1, 1 =  , 2 = 2, 3 =  , 4 = 3, 5 =  ...
    
    return 0;
}

// could be used for ifstream
// see exercise 5.6