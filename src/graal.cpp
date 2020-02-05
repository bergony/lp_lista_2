#include <iostream>

#include "../include/graal.h"

namespace graal{
   
    typedef unsigned char byte;

    bool  p(const void *min, const void *max)
    {
        const int * maxCast = (const int *) max;
        const int * minCast = (const int *) min;

        std::cout << *minCast << " > " << *maxCast << "\n";
        if(*minCast > *maxCast)
        {
            return true;

        }

        return false;
    }

    const void *min( const void *first, const void *last, size_t size, bool (*p)(const void *, const void *))
    {

        byte *first_cast = (byte *) first;
        byte *last_cast = (byte *) last;
        byte *min = (byte *) first_cast;

        while(first_cast != last_cast)
        {
            if(p(min, first_cast))
            {
                *min = *first_cast;
            }
            first_cast += size;
        }

        return min;
    }
}
