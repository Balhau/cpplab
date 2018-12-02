#ifndef CORE_BMATH_COMPLEX
#define CORE_BMATH_COMPLEX

#include "../cpu/types.hpp"
#include <iostream>

using namespace std;

namespace Core{
    namespace Bmath{
        class Complex{
            private:
                Long real;
                Long imaginary;
            
            public:
                Complex(Long real,Long imaginary);
                Complex& operator+=(const Complex& rightOp);
                Complex operator+(const Complex &rightOp);
                Complex operator*(const Complex &rightOp);
                
                //Overload to enable toString operations
                friend std::ostream& operator<<(std::ostream &stream, Core::Bmath::Complex const &c){
                    return stream << "(" << c.real << ", " << c.imaginary << "i)";
                }
        };
    };
};

#endif