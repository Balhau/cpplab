#ifndef CORE_CPU_TYPES_H
#define CORE_CPU_TYPES_H

    /*
    * Types for x86 architectures
    */
    #if defined(__x86_64__)
        //Signed type alias
        typedef int Int;
        typedef int Int;
        typedef long Long;
        typedef char Char;
        typedef short Short;

        //IEEE floating point alias
        typedef float Float;
        typedef double Double;

        //Unsigned type alias
        typedef unsigned char UChar;
        typedef unsigned short UShort;
        typedef unsigned int UInt;
        typedef unsigned long ULong;
    #endif
#endif