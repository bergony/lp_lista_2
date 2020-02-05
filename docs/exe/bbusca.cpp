#include <iostream>
#include <string>
#include <cassert>


typedef unsigned char byte;
bool comp_ints(const void *a, const void *b)
{
    const int * aa = (const int *) a;
    const int * bb = static_cast < const int * > (b);
    return *aa < *bb;
}

bool comp_strs(const void *a, const void *b)
{
    const std::string * aa = (const std::string *) a;
    const std::string * bb = static_cast < const std::string * > (b);
    return *aa < *bb;
}

void *bbinaria(const void *key, const void *ptr, size_t count, size_t size, bool (*comp)(const void *a, const void *b))
{
    size_t left(0);
    size_t right(count-1);

    byte *A = (byte*) ptr;

    while( left <= right )
    {
        size_t mid = (left + right )/ 2;

        if(not comp( (A + mid*size) , key) and
           not comp( key, (A + mid*size )))
           {
                return A + mid*size;
           }

       // if( ptr[mid] == key) return mid;
       // if(*(A + mid*size) == key) return mid;
        else if( comp( key, A + mid*size )) right = mid-1;
        else left = mid+1;
    }

    return nullptr;
}

int main ()
{
    int A[] = {6, 2 , 3 , 4, 5, 6};
    size_t size_A =  sizeof(A)/sizeof(A[0]);
    int key_A{ 2 };
    int * resustA = (int *)bbinaria( & key_A, A, size_A, sizeof(int), comp_ints );

    std::cout << "chave = " << key_A << " = " << *resustA << "\n";
    assert ( *resustA == key_A);
/*
    std::string B[]{ "aaa", "bbb", "ccc", "ddd", "eee", "fffi"};
    size_t size_B =  sizeof(B)/sizeof(B[0]);
    std::string key_B{ "eee" };
    std::string * resustB = (std::string *)bbinaria( & key_B, B, size_B, sizeof(std::string), comp_strs );


    assert ( *resustA == key_A);

    std::string key_C{ "zzz" };
    std::string * resustC = (std::string *)bbinaria( & key_C, B, size_B, sizeof(std::string), comp_strs );

    assert ( *resustC == key_C);
*/
    return 0;
}
