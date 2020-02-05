/*!
 * \file filter.cpp
 * \author Selan
 * \date August, 9th
 */

#include "../include/filter.h"


int *  filter(  int * first_, // inicio do range
                int * last_,  // antes do final do range
                bool (*p) ( const int & )  // funcao predicado para selecionar elementos.
             )
{
    auto slow(first_);
    auto fast(first_);
    while( fast != last_ )
    {
        if ( p( *fast ) )
        {
            *slow++ = *fast;
        }
        fast++;
    }
    return slow;
}
