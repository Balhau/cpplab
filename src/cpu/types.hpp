#pragma once
/*
    * Types for x86 architectures
    */
#if defined(__x86_64__)
//Signed type alias
typedef int Int;
typedef long Long;
typedef char Char;
typedef short Short;

typedef union {
    struct
    {
        Int value : 31;
        Int signal : 1;
    } int_with_msb;
    Int signed_int;
} SignedInt;

//IEEE floating point alias
typedef float Float;
typedef double Double;

//Unsigned type alias
typedef unsigned char UChar;
typedef unsigned short UShort;
typedef unsigned int UInt;
typedef unsigned long ULong;

//SSE DataTypes
#define INT_LEN_64 2
#define INT_LEN_128 4
#define INT_LEN_256 8
#define INT_LEN_512 16

#define LONG_LEN_64 1
#define LONG_LEN_128 2
#define LONG_LEN_256 4
#define LONG_LEN_512 8

//Masks
#define MASK_32 0xFFFFFFFF
#define MASK_16 0xFFFF
#define MASK_8 0xFF

//Shifts
#define SHIFT_32 32
#define SHIFT_16 16
#define SHIFT_8 8
#endif