#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    int n;
    string vInput;
    
    cout << "Enter a starting number: " << endl;
    getline(cin, vInput);
    n = stoi(vInput);
    
    if (n < 0)
    {
        cout << "Invalid number entered." << endl;
    }
    else
    {
         /* while (condition)
         * {
         * statements
         * }
         */
    
        while (n > 0)
        {
            cout << n << ", "<< flush;                    // wait defined seconds...
        this_thread::sleep_for ( chrono::seconds(1) ); // ...for each counting
            
            n--;
        }
        cout << "FIRE!" << endl;
        
         /* Alternative method
         * do
         * {
         * statements;
         * }
         * while (condition)
         */
    }
    
	return 0;
}
