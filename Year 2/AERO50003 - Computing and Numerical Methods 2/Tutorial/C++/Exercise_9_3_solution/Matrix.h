/*
 * Solution to Exercise 9.3.
 *
 * Matrix class.
 */
#ifndef MATRIX_H
#define MATRIX_H

#include <iosfwd>
#include <vector>

#include "Vector.h"

class Matrix
{
public:
    Matrix();                                       // default constructor
    Matrix(unsigned size);                          // default constructor
    Matrix(const Matrix& rhs);                      // Copy constructor
    ~Matrix();                                      // Destructor

    Matrix& operator = (const Matrix& rhs);
    Matrix& operator += (const Matrix & rhs);
    Matrix  operator + (const Matrix & rhs) const;
    Vector operator*(Vector& rhs);

    double& operator () (unsigned row, unsigned col);
    double  operator () (unsigned row, unsigned col) const;

    double& operator [] (unsigned ind);
    double  operator [] (unsigned ind) const;

    void init(double val=0);
    unsigned int size() const;  // get size
    double* data() const;       // get raw data array

private:
    unsigned int size_;
    double* data_;
};

// for std::cout
std::ostream & operator << (std::ostream & o, const Matrix & rhs);


#endif // MATRIX_H
