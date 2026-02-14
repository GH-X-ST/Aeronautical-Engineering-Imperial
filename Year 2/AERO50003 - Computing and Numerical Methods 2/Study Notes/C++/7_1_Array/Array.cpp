/* Array is fixed number of elements of the same datatype

datatype indentifier[size] = {value_list};

*/

// Declaring an array
int vMyArray[5];                              // unintialised array

vMyArray[2] = 3;

int vThirdElement = vMyArray[2]; // array count from 0

int vMyArrayFilled[3] = {1, 2, 3};            // Initialized array

int vMyImplictSizeArray[] = {0, 3, 6, 9 ,12}; // Implicit array size
/* size of the arrays must be known at complie-time for C-style array */
/* better use constant define the size of the arrays */

// Declaring an array as parameter to a function
void myRoutine(double pArray[])
{
    ...
}

double norm2(int pSize, double pArray[])
{
    ...
}

/* use array as an argument */
double testArray[] = {1.0, 2.0, 3.0, 4.0, 5.0};

myRoutine(testArray);

cout << norm2(6, testArray) << endl;