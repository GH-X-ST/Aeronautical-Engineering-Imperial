#include <iomanip> // include manipulators

// setw()
cout << "*" << setw(4)
  << 12 << "*" << endl;
// *  12*


// setfill()
cout << setfill('.')
  << "*" << setw(4)
  << 12 << "*" << endl; 
// *..12*


// setprecision()
cout << serprecision(4)
  << 3.14159    << endl
  << 1234.56789 << endl
  << 245.678    << endl
  << 12345.0    << endl
/* 3.142
   1235
   245.7
   1.234e+04   
*/