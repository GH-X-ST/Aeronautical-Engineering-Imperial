// width()
cout << "*" ;
cout.width(4);
cout << 12 << "*" << endl;
// *  12*

// fill()
cout.fill('.');
cout << "*";
cout.width(4);
cout << 12 << "*" << endl; 
// *..12*

// precision()
cout.precision(4);
cout << 3.14159 << endl;
cout << 1234.56789 << endl;
cout << 245.678 << endl;
cout << 12345.0 << endl;
/* 3.142
   1235
   245.7
   1.234e+04   
*/