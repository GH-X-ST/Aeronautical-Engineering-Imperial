/*
 * Solution to Exercise 9.3.
 *
 * Demonstrator of using the Matrix class.
 */
#include <iostream>
using namespace std;

#include "Matrix.h"

int main()
{
    unsigned int n = 2;

    Matrix M(n); // only one index is needed since it is a square matrix

    // Fill m
    for(unsigned int i = 0; i < n; ++i) {
        for(unsigned int j = 0; j < n; ++j) {
            M(i, j) = i + j * n + 1;
        }
    }

    cout << "M" << endl;
    cout << M << endl;

    Matrix L = M;
    cout << "L" << endl;
    cout << L << endl;

    Matrix K;

    K = M;
    cout << "K = M" << endl;
    cout << K << endl;

    Matrix A(n);    // Create matrix of size nxn
    A.init(1.5);    // Fill matrix with single value (defailut=0s)
    cout << "A.init()" << endl;
    cout << A << endl;

    A += M;
    cout << "A+=M" << endl;
    cout << A << endl;

    cout << "A+M" << endl;
    cout << A + M << endl;

    Vector v(n);  // Create a vector v
    for (unsigned int i = 0; i < n; i++)  // Fill vector v
        v[i] = i+1;

    Vector v1 = v;      // Make a copy of vector v
    Vector result(n);

    cout << M << endl;
    result = M*v;
    cout << "M*v" << endl;
    for(unsigned int i = 0; i < n; ++i) {
        cout << result[i] << '\t';
    }
    cout << endl;

    return 0;
}
