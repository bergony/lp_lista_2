#include <iostream>
#include <sstream>
#include <random>
#include <algorithm>
#include <functional>
#include <limits>


//
// Constant expressions.
//
constexpr auto N_DEFAULT( 20u ); // Default number of elements.
constexpr auto N_MAX( 100u );    // Max number of elements in the array.


/**!
 *  This function fills up an integer array with random numbers picked from
 *  the specified range [lower, upper].
 *
 *  @param V_ The array we want to fill in.
 *  @param arrSz_ The array length.
 *  @param lower_ The lower limit (inclusive) for the range of random numbers.
 *  @param upper_ The upper limit (inclusive) for the range of random numbers.
 *  @param seed_ The seed we use to generate the (pseudo) random numbers.
 */
void randomFill( int *V_, std::size_t arrSz_,
                 const int lower_, const int upper_,
                 const unsigned int seed_ )
{
    //use the default random engine and an uniform distribution
    std::default_random_engine eng( seed_ );
    std::uniform_real_distribution<double> distr( lower_, upper_ );

    // Fill up vector
    for ( auto i(0) ; i < arrSz_ ; ++i )
        V_[ i ] = distr( eng );
}

/**!
 * This function `compacts` at the beginning of an array all the non-zero
 * positive integers.
 * By `compacting` an array we mean shifting to the beginning of the array
 * all the elements selected according to a certain criterion.
 * In this case the selection criterion is to preserve only integer numbers
 * greater than zero.
 * The relative order of the selected elements must be preserved during the
 * process.
 * 
 * The elements that do not satisfy the selection criterion are overwritten
 * during the `compacting` process.
 * Consequentely, the array may have a different (smaller) logical length
 * after the process is finished.
 *
 * @precondition We always receive a valid array with at least one element.
 * @param V_ The array we want to compact.
 * @param count_ The array's length.
 *
 * @return The new array length, which may be the same or smaller.
 */
std::size_t compacta( int * V_, std::size_t count_ )
{
    auto iSlow(0ul);
    auto iFast(0ul);
    for( /* empty */ ; iFast < count_ ; ++iFast )
    {
        if( V_[ iFast ] > 0 )
            V_[ iSlow++ ] = V_[ iFast ];
    }

    return iSlow; // New vector size.
}


//
// Main program.
//
int main( int argc, char * argv[] )
{
    auto arrSz( N_DEFAULT ); // Initialize vector size.

    // Process any command line arguments.
    if ( argc > 1 ) // In case the user has provided a value for us.
    {
        std::stringstream( argv[1] ) >> arrSz;
    }

    // Do we have a valid array size so far?
    if ( arrSz <= 0  || arrSz > N_MAX )
    {
        std::cout << "\n\n>>> Invalid argument provided!\n"
                  << "    Correct sintax: " << argv[0] << " [N > 0 and N <= " << N_MAX << "]\n"
                  << "    Assuming N = " << N_DEFAULT << " for this run.\n";
        arrSz = N_DEFAULT; // Back to the default value.
    }

    std::cout << "\n\n>>> Required array size is: " << arrSz << "\n\n";

    int *V = new int[ arrSz ];


#ifdef RANDOM
    // Seed with a real random value, if available.
    std::random_device r;
    // Fill it up with random integers.
    randomFill( V, arrSz, -100, 100, r() );
#else
    // Fill it up with random integers.
    randomFill( V, arrSz, -100, 100, 7 );
#endif

    // Printing out the array, just to make sure we've got random integers.
    std::cout << ">>> ORIGINAL Vet = [ ";
    for( auto i(0) ; i < arrSz ; ++i )
        std::cout << V[i] << " ";
    std::cout << "], Size = " << arrSz << "\n\n";

    //================================================================================
    std::cout << ">>> Compacting now...\n\n";
    auto newSz = compacta( V, arrSz );
    //================================================================================
        
    // Printing compacted array, with new size.
    std::cout << ">>> COMPACTED Vet = [ ";
    for( auto i(0) ; i < newSz ; ++i )
        std::cout << V[i] << " ";
    std::cout << "], Size = " << newSz << "\n\n";

    return EXIT_SUCCESS;
}

