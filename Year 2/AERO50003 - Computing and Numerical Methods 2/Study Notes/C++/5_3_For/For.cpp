#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    /* for (initialiser; condition; update)
    {
    statements
    }
    */
    
    for (int n = 10; n > 0; n--)
    {
        cout << n << ", " << flush;                    // wait defined seconds...
        this_thread::sleep_for ( chrono::seconds(1) ); // ...for each counting
    }
    
    cout << "FIRE!" << endl;
	return 0;
}