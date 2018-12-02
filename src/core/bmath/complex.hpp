#ifndef CORE_BMATH_COMPLEX
#define CORE_BMATH_COMPLEX

#include "../cpu/types.hpp"

namespace Core{
    namespace Bmath{
        class Complex{
            private:
                Long real;
                Long imaginary;
            
            public:
                Complex(Long real,Long imaginary);
                Complex& operator+=(const Complex& rightOp);
                friend Complex operator+(Complex leftOp,const Complex &rightOp);
        };
    };
};

#endif