#include "complex.hpp"

/** 
 * Constructor implementation
 */ 
Core::Bmath::Complex::Complex(Double real,Double imaginary){
    this->real=real;
    this->imaginary=imaginary;
};

/**
 * Add complex number
 */
Core::Bmath::Complex& Core::Bmath::Complex::operator+= (const Complex& rightOp){
    this->real+=rightOp.real;
    this->imaginary+=rightOp.imaginary;
    return *this;
};

Core::Bmath::Complex Core::Bmath::Complex::operator+ (const Complex& rightOp){
    return Complex(
        this->real+rightOp.real,
        this->imaginary+rightOp.imaginary
    );
};

Core::Bmath::Complex Core::Bmath::Complex::operator* (const Complex& rigthOp){
    return Complex(
        this->real*rigthOp.real-this->imaginary*rigthOp.imaginary,
        this->imaginary*rigthOp.real+this->real*rigthOp.imaginary
    );
};
