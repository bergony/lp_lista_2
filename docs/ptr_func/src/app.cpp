/*!
 * \file filter.cpp
 * \author Selan
 * \date August, 9th
 */

#include <iostream>
#include <sstream>
#include "../include/filter.h"

std::string print ( int * first_, int * last_ )
{
    std::ostringstream oss;
    oss << "[ ";
    std::copy( first_, last_, std::ostream_iterator<int>( oss, " " ) );
    oss << "]";

    return oss.str();
}

bool predicado_even( const int & a )
{
    return ( a % 2 == 0 );
}


bool predicado_greater_4( const int & a )
{
    return ( a > 4 );
}

bool predicado_odd( const int & a )
{
    return ( a % 2 != 0 );
}
int main()
{
    int A[] { 4, 2, 1, 0, -2, 3, -5, 7, 10 };

    std::cout << " >> A " << print(std::begin(A), std::end(A)) << "\n";

    //auto new_last= filter_lin_even( std::begin(A), std::end(A) );
    auto new_last= filter( std::begin(A), std::end(A), predicado_greater_4 );

    std::cout << " >> A (after filter) " << print(std::begin(A), new_last) << "\n";
}

