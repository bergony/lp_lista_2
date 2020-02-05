#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>

namespace ft {
    /// Types of food
    enum food_t : int { NATURAL=0, PROCESSED=1 };

    /// Basic representation of a food.
    struct Food {
        // Nutrition facts per 100g.
        food_t type;        //!< Food type.
        std::string name;   //!< Food name.
        int calories;       //!< Calories per 100g
        float sugar;        //!< Sugar per 100g
        float fiber;        //!< Fiber amount per 100g
    };

    /// A way of extracting the food information to a stream.
    std::ostream& operator<<( std::ostream& os, const Food & f )
    {
        os << std::left << "<\"" << std::setw(12) << f.name << "\""
            << ", cal=" << std::setw(4) << f.calories
            << ", sug=" << std::setw(6) << std::fixed << std::setprecision(1) << f.sugar
            << ", fib=" << f.fiber
            << ">";
        return os;
    }
}

/// A print function for a range of integers.
std::string print_int( const int* first, const int* last )
{
    std::ostringstream oss;
    while( first != last )
        oss << *first++ << " ";

    return oss.str();
}

/// A print function for a range of foods
std::string print_food( const ft::Food* first, const ft::Food* last )
{
    std::ostringstream oss;
    while( first != last )
        oss << *first++ << "\n";

    return oss.str();
}

/// Find and return the first occurrence of the samllest element in the range [first;last).
const int *min( const int* first, const int* last )
{
    // Avoid invalid input.
    if ( first == nullptr )  return first;

    auto s{ first++ }; // Points to the smallest element.

    // Traverse the range
    while( first != last )
    {
        if ( *first < *s ) // content of `first` is smaller than content of `s`.
            s = first; // update pointer to smallest element so far.
        first++;
    }

    return s;
}



int main( void )
{
    // A simple array of integers.
    int A[] { 5, 6, 2, 1, 3, 7, 4 };

    // A simple array of food.
    ft::Food bag[]
        {
          {
            ft::food_t::NATURAL,
            "orange", // 100g
            47,   // calories
            9.f,  // sugar
            2.4f, // fiber
          },
          {
            ft::food_t::NATURAL,
            "orange juice",
            45,   // calories
            8.f,  // sugar
            0.2f // fiber
          },
          { ft::food_t::PROCESSED,
            "regular coke",
            139,
            10.9f,
            0.f
          },
          { ft::food_t::PROCESSED,
              "fried egg",
              196,
              1.1f,
              0.f
          },
          { ft::food_t::NATURAL,
              "banana",
              89,
              12.f,
              2.6f
          },
          {
              ft::food_t::PROCESSED,
              "white bread",
              256,
              5.f,
              2.7f
          }
        };


    // Prints out the integer array.
    std::cout << ">>> A = [" << print_int(std::begin(A), std::end(A)) << "]" << std::endl;
    // Find the smallest element.
    auto result =  min( std::begin(A), std::end(A) );
    // Print the smallest found.
    std::cout << ">>> The smallest element in A is \"" << *result << "\"" << std::endl;


    // Just prints out the list of food in the bag.
    std::cout << ">>> Bag = [\n" << print_food(std::begin(bag), std::end(bag)) << "]" << std::endl;

    return EXIT_SUCCESS;
}
