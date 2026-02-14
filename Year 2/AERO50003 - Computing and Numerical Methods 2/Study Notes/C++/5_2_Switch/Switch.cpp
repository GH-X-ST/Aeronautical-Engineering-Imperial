#include <iostream>
using namespace std;

int main()
{
    int vItem;
    
    cout << "Select a menu item: " << endl;
    cin >> vItem;
    
    switch (vItem)
    {
        case 1:
        cout << "Select menu item 1" << endl;
        break;
        
        case 2:
        cout << "Select menu item 2" << endl;
        break;
        
        default:
        cout << "Unknown menu item!" << endl;
    }
    
	return 0;
}
