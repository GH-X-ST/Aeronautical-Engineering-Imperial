#include <iostream>
using namespace std;

int main()
{
    float number, sum = 0.0;
    
    while (true)
    {
        cout << "Enter a positive number (0 to stop): ";
        cin >> number;
        
        if (number > 0.0)
        {
            sum += number;
        }
        
        else if (number < 0.0)
        {
            cout << "Only positive numbers allowed!" << endl;
            continue; // terminates the current iteration of a loop and begin next iteration
        }
        
        else
        {
            break; // breaks out of the inter-most loop
        }
    }
    cout << "The sum is: " << sum << endl;
	return 0;
}
