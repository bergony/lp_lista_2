#include <cstdlib>
#include <iostream>

/*
 * void* bsearch( const void* key, const void* ptr, std::size_t count,
 * std::size_t size, int (*comp)(const void*, const void*) );
 *
 */


 
int main( )
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    const auto ARR_SIZE = sizeof( arr ) / sizeof (*arr) ;

    std::cout << ">>> Data array: [ ";
    for ( const auto &e : arr ) std::cout << e << " ";
    std::cout << "]\n";

    int key1 = 4;
    std::cout << "\n>>> Looking for key = " << key1 << "...\n";
    int *p1 = (int *) std::bsearch(&key1, arr, ARR_SIZE, sizeof(arr[0]), compare);
    if(p1)
        std::cout << "value " << key1 << " found at position " << (p1 - arr) << '\n';
    else
        std::cout << "value " << key1 << " not found\n";

    int key2 = 9;
    std::cout << "\n>>> Looking for key = " << key2 << "...\n";
    int *p2 = (int *) std::bsearch(&key2, arr, ARR_SIZE, sizeof(arr[0]), compare);
    if(p2)
        std::cout << "value " << key2 << " found at position " << (p2 - arr) << '\n';
    else
        std::cout << "value " << key2 << " not found\n";
}
