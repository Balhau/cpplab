#include "complex.hpp"

/** 
 * Constructor implementation
 */
BMath::Complex::Complex(Double real, Double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
};

BMath::Complex::Complex(const Complex &other)
{
    this->real = other.real;
    this->imaginary = other.imaginary;
}

/**
 * Add complex number
 */
BMath::Complex &BMath::Complex::operator+=(const Complex &rightOp)
{
    this->real += rightOp.real;
    this->imaginary += rightOp.imaginary;
    return *this;
};

BMath::Complex BMath::Complex::operator-(const Complex &rightOp)
{
    return Complex(
        this->real-rightOp.real,
        this->imaginary-rightOp.imaginary
    );
};

BMath::Complex BMath::Complex::operator+(const Complex &rightOp)
{
    return Complex(
        this->real + rightOp.real,
        this->imaginary + rightOp.imaginary);
};

BMath::Complex BMath::Complex::operator*(const Complex &rigthOp)
{
    return Complex(
        this->real * rigthOp.real - this->imaginary * rigthOp.imaginary,
        this->imaginary * rigthOp.real + this->real * rigthOp.imaginary);
};
