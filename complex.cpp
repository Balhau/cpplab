#include <iostream>
#include <string>
#include <iomanip>
#include <sys/time.h>

#include "src/core/bmath/complex.hpp"

using namespace Core::Bmath;
using namespace std;

int main(int argc, char** argcv){
    Complex c1(1,1);
    Complex c2(2,2);
    Complex c3=c1*c2;
    Complex c4=c1+c2;

    cout << c1 << "*" << c2 << "=" << c3 << endl;
    cout << c1 << "+" << c2 << "=" << c4 << endl;

}