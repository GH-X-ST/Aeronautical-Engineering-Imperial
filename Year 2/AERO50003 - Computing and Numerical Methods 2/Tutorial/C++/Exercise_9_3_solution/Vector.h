/*
 * Solution to Exercise 9.2.
 *
 * Class representing a vector of arbitrary size.
 */
class Vector {
    public:
        Vector() = delete;                  // Do not allow vector without size
        Vector(const unsigned int pSize);   // Create zero vector of given size
        Vector(const Vector& pSrc);         // Copy another vector
        Vector(Vector&& pSrc);              // Move another vector

        double& operator[](unsigned int i); // Access entries in vector

        Vector& operator=(const Vector& pSrc);
        Vector operator+(const Vector& pSrc);
        Vector operator-(const Vector& pSrc);
        Vector operator*(const double factor);
        Vector operator/(const double factor);

        unsigned int getSize() { return size; }
        double normL1();
        double normL2();
        double dot(const Vector& pSrc);

    private:
        double* data = nullptr;             // Data held privately
        unsigned int size = 0;
};
