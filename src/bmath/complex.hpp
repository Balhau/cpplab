#pragma once

#include "../cpu/types.hpp"
#include <iostream>

using namespace std;
namespace BMath
{
class Complex
{
private:
    Double real;
    Double imaginary;

public:
    Complex(Double real, Double imaginary);
    Complex(const Complex &other);
    Complex &operator+=(const Complex &rightOp);
    Complex operator+(const Complex &rightOp);
    Complex operator-(const Complex &rigthOp);
    Complex operator*(const Complex &rightOp);

    //Overload to enable toString operations
    friend std::ostream &operator<<(std::ostream &stream, BMath::Complex const &c)
    {
        return stream << "(" << c.real << "+" << c.imaginary << "i)";
    }
};
}; // namespace Bmath