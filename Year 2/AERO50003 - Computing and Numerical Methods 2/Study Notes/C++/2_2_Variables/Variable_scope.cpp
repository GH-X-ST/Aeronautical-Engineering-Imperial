/* Naming scheme

v // (local) variable

m // class member

p // function parameter

g // global variable

*/


bool vTest = true;
if ( vTest == true ) 
    {
    int vNum = 3;
    for (int i = 0; i < 10; i++) 
        {
        vNum++;
        }
}
cout << "The boolean is: " << vTest
<< " and the number is " << vNum << endl;
// vNum is out of the scope, which only available inside the if block