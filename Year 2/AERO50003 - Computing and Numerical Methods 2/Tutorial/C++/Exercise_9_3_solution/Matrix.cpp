/*
 * Solution to Exercise 9.3.
 *
 * Matrix class implementation.
 */

#include <cstring>  // for memcpy
#include <iostream> // for ostream
#include <iomanip>  // for io manipulation routines (e.g. setw)

#include "Matrix.h"

Matrix::Matrix()
    : size_(0)
{
    data_ = nullptr;
}

Matrix::Matrix(const unsigned size)
    : size_(size)
{
    if (size == 0) {
        // Triggers an exception. We can catch this in the calling program
        // using a 'try' and 'catch' block.
        throw std::length_error("Matrix constructor has 0 size");
    }
    data_ = new double[size * size];
}

Matrix::Matrix(const Matrix& rhs)
{
    size_ = rhs.size_;
    data_ = new double[size_ * size_];
    // efficient memory copy routine
    memcpy(data_, rhs.data_, size_ * size_ * sizeof(double));
}

Matrix::~Matrix()
{
    delete[] data_;
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
    // check we are not attempting self-assignment
    if(this != &rhs) {
        size_ = rhs.size_;
        data_ = new double[size_ * size_];
        memcpy(data_, rhs.data_, size_ * size_ * sizeof(double));
    }
    return *this;
}

// used to fill values
double& Matrix::operator()(unsigned row, unsigned col)
{
    if(row >= size_ || col >= size_)
        throw std::out_of_range("Matrix subscript out of bounds");
    return data_[row + col * size_]; // store columnwise
}

// used to retrieve values, when the matrix is a const matrix
double Matrix::operator()(unsigned row, unsigned col) const
{
    if(row >= size_ || col >= size_)
        throw std::out_of_range("const Matrix subscript out of bounds");
    return data_[row + col * size_];
}

// used to fill values of the linear array
double& Matrix::operator[](unsigned ind)
{
    if(ind >= size_ * size_)
        throw std::out_of_range("index out of bounds");
    return data_[ind];
}

// used to retrieve values of the linear array
double Matrix::operator[](unsigned ind) const
{
    if(ind >= size_ * size_)
        throw std::out_of_range("index out of bounds");
    return data_[ind];
}

unsigned Matrix::size() const
{
    return size_;
}

double* Matrix::data() const
{
    return data_;
}

// initialises all entries of the matrix to a single value
void Matrix::init(double val)
{
    if(size_ == 0)
        throw std::length_error("Cannot initialize matrix of 0 size");
    for(unsigned int i = 0; i < size_ * size_; ++i)
        data_[i] = val;

}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
    if(size_ == 0)
        throw std::length_error("Matrix of 0 size");
    for(unsigned int i = 0; i < size_ * size_; ++i)
        data_[i] += rhs.data_[i];
    return *this;
}

Matrix Matrix::operator+(const Matrix& rhs) const
{
    Matrix x = *this;
    return x += rhs;
}

std::ostream& operator<<(std::ostream& o, const Matrix& rhs)
{
    if(rhs.size() == 0) {
        return o << "[empty]" << std::endl;
    } else {
        for(unsigned int i = 0; i < rhs.size(); ++i) {
            for(unsigned int j = 0; j < rhs.size(); ++j) {
                o << std::setw(8) << std::setprecision(5) << rhs(i, j);
            }
            o << std::endl;
        }
        return o;
    }
}

Vector Matrix::operator*(Vector& rhs)
{
    if(rhs.getSize() != size_)
        throw std::length_error("Matrix and vector should have same size");

    Vector v1(size_);
    for (unsigned int i = 0; i < size_; ++i) {
        for (unsigned int k  = 0; k < size_; ++k) {
            v1[k] += rhs[i] * data_[k + i*size_];
        }
    }
    return std::move(v1);
}

