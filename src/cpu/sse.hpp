#pragma once

#include "types.hpp"


namespace cpu
{
class SSE
{
public:
    static void paddw(UInt *a, UInt *b);
    static void paddd(ULong *a, ULong *b);
};
};