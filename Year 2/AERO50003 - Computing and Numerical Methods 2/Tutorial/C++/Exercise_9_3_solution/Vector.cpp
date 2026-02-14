/*
 * Solution to Exercise 9.2.
 *
 * Class representing a vector of arbitrary size.
 */
#include <cmath>
#include <cstring>
#include <stdexcept>
using namespace std;

#include "Vector.h"

// Creates a new vector of the given size and initialises all values to zero.
Vector::Vector(const unsigned int pSize) {
    if (pSize == 0) throw std::logic_error("Vector size must be > 0.");

    size = pSize;
    data = new double[pSize];
    memset(data, 0, pSize*sizeof(double));
}

// Copies an existing vector. First we allocate a new block of memory of the
// same size, and then copy the data from pSrc into it.
Vector::Vector(const Vector& pSrc) {
    size = pSrc.size;
    data = new double[pSrc.size];
    memcpy(data, pSrc.data, size*sizeof(double));
}

// "Moves" an existing vector. In this case, we transfer ownership of the
// existing block of data from pSrc to this newly created vector. This avoids
// copying the data. In pSrc, we set the data pointer to nullptr, which is why
// pSrc is not passed as a const parameter.
//
// Note that this is mainly used for efficiency reasons, particular when
// returning temporary objects created in the operator functions below, by
// value.
Vector::Vector(Vector&& pSrc) {
    size = pSrc.size;
    data = pSrc.data;
    pSrc.data = nullptr;
    pSrc.size = 0;
}

// Return a reference to a double so that the calling routine can set values in
// the array, as well as read from them.
double& Vector::operator[](unsigned int i) {
    if (i >= size) throw std::logic_error("Index out of range.");

    return data[i];
}

// Assignment operation. If the vectors are of different sizes, we need to
// deallocate our current storage, allocate new storage of the correct size,
// before finally copying the data across.
Vector& Vector::operator=(const Vector& pSrc) {
    if (pSrc.size != size) {
        delete[] data;
        size = pSrc.size;
        data = new double[size];
    }
    memcpy(data, pSrc.data, size*sizeof(double));
    return *this;
}

// Add two vectors together. First create a new temporary vector to hold the
// result. Perform the addition, element-by-element. Then return the temporary
// object explicitly using move semantics, since the temporary object 'result'
// is about to be destroyed anyway as it goes out of scope.
Vector Vector::operator+(const Vector& pSrc) {
    if (pSrc.size != size) throw std::logic_error("Vectors are different size.");
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] + pSrc.data[i];
    }
    return std::move(result);
}

Vector Vector::operator-(const Vector& pSrc) {
    if (pSrc.size != size) throw std::logic_error("Vectors are different size.");
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] - pSrc.data[i];
    }
    return std::move(result);
}

Vector Vector::operator*(const double factor) {
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] * factor;
    }
    return std::move(result);
}

Vector Vector::operator/(const double factor) {
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] / factor;
    }
    return std::move(result);
}

// Calculate L1 norm (sum of elements)
double Vector::normL1() {
    double l1 = 0.0;
    for (int i = 0; i < size; ++i) {
        l1 += data[i];
    }
    return l1;
}

// Calculate L2 norm (Euclidean norm)
double Vector::normL2() {
    double l2 = 0.0;
    for (int i = 0; i < size; ++i) {
        l2 += data[i]*data[i];
    }
    return sqrt(l2);
}

// Calculate dot product of this vector with another.
double Vector::dot(const Vector& pSrc) {
    if (pSrc.size != size) throw std::logic_error("Vectors are different size.");
    double dot = 0.0;
    for (int i = 0; i < size; ++i) {
       dot += data[i] * pSrc.data[i];
    }
    return dot;
}
