#pragma once

#include "types.hpp"

using namespace std;


namespace Cpu
{
class SSE
{
public:
    static void paddw(UInt *a, UInt *b);
    static void paddd(ULong *a, ULong *b);
};
};