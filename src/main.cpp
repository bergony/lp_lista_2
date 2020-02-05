#include <iostream>
#include <cstdlib>
#include <iterator>
#include <cstring> 
typedef unsigned char byte; //Valor de 1 byte

//Retorn menor volar de vetor  conforme paramentro bool;
const void *min ( const void *, const void *, size_t, bool (*cmp)(const void *, const void *));
// Reverte  o vetor
void reverse ( void * first , void * last , size_t size );
//Copy um vetor para oturo;
void * copy ( const void * first , const  void * last , const void * d_first , size_t size );
//
void * clone ( const void * first , const void * last , size_t size );
//
const void * find_if ( const void * first , const void * last , size_t size , bool (*p)(const void *) );
//
const void * find ( const void * first , const void * last , size_t size , const void * value , bool (*eq)( const void *, const void * ) );
//
bool all_of ( const void * first , const void * last , size_t size , bool (*p)(const void *) );
bool any_of ( const void * first , const void * last , size_t size , bool (*p)(const void *) );
bool none_of ( const void * first , const void * last , size_t size , bool (*p)(const void *) );
//
void * unique ( void * first , void * last , size_t size , bool (*eq)( const void *, const void * )  );
//
void * partition ( void * first , void * last , size_t size ,  bool (*p)(const void *) );
//Imprimer o vetor
void printffor(const int * first, const int * last)
{
    std::cout << "Vetor = [ ";
    while(first != last)
    {
        std::cout << *first << " ";
        first++;
    }
    std::cout << "]"<< std::endl;
}
bool cmp ( const void * , const void * );
bool p ( const void * );
bool eq ( const void * , const void * );
/* Funcoes */
//CMP Se Paran 1 > Paran 2 Verdade se nao false
bool cmp(const void *min, const void *max)
{
    const int * maxCast = (const int *) max;
    const int * minCast = (const int *) min;
    //std::cout << "B:" << *minCast << "A:" << *maxCast << "\n";
    if(*minCast > *maxCast)
    {
        return true;
    }
    return false;
}
//se o elementor e negativo;
bool p (const void *a)
{
    int *a_cast = (int *) a;

    return (*a_cast < 0);
}
//se a = b retorna verdade
bool eq (const void *a, const void *b)
{
    int *a_cast = (int *) a;
    int *b_cast = (int *) b;

    return(*a_cast == *b_cast);
}
//Retornar o menor valor de  1 vetor
const void *min( const void *first, const void *last, size_t size, bool (*cmp)(const void *, const void *))
{
    byte *first_cast = (byte *) first;
    byte *last_cast = (byte *) last;
    byte *min{first_cast};

    while(first_cast != last_cast)
    {
        if( cmp( min, first_cast ) )
        {
            min = first_cast;
        }
        first_cast += size;
    }

    return  min;
}
//Reveter o valor do vetor
void reverse ( void * first , void  * last, size_t size)
{
    byte *first_cast = (byte *) first;
    byte *last_cast = (byte *) last;
    int aux{0};
    int *auxPOnt = &aux;

    while(first_cast <= last_cast)
    {
        last_cast -= size;
        *auxPOnt = *first_cast;
        *first_cast = *last_cast;
        *last_cast = *auxPOnt;
        first_cast += size;
    }
}

// Copia o vetor
void * copy ( const void * first , const  void * last , const void * d_first , size_t size )
{
    byte *first_cast = (byte *) first;
    byte *last_cast = (byte *) last;
    byte *d_last_cast = (byte *) d_first;

    while(first_cast != last_cast)
    {
        *d_last_cast = *first_cast;
        d_last_cast += size;
        first_cast += size;
    }
    return d_last_cast;
}
//Clona um vetor
void * clone ( const void * first , const void * last , size_t size, size_t size_array )
{
    byte *first_cast = (byte *) first;
    byte *last_cast = (byte *) last;
    byte full_size = size*size_array;
    byte *clone = new byte [full_size];
    int index{0};

    while(first_cast != last_cast)
    {
        *(clone+(size*index)) = *first_cast;
        first_cast += size;
        index++;
    }
    return clone;
}
//Encontra pelo paramentro P
const void * find_if ( const void * first, const void *last , size_t size , bool (*p)(const void *))
{
    byte *first_cast = (byte *) first;
    byte *last_cast = (byte *) last;

    while(first_cast != last)
    {
        if(p(first_cast) == true)
        {
            return first_cast;
        }
        first_cast += size;
    }

    return last_cast;

}
//Encontra se valor é igual.
const void * find ( const void * first, const void * last, size_t size, const void * value, bool (*eq)(const void *, const void *))
{
    byte *first_cast = (byte *) first;
    byte *last_cast = (byte *) last;
    byte *value_cast = (byte *) value;

    while(first_cast != last)
    {
        if( eq( value_cast , first_cast) == true)
        {
            return value_cast;
        }
        first_cast += size;
    }
    return last_cast;
}
///Se todos sao comforme o paramento(Se for valor
bool all_of( const void *first , const void * last, size_t size , bool(*p)(const void *))
{
    byte *first_cast = (byte *) first;
    byte *last_cast = (byte *) last;
    bool all_of_is{true};

    while(first_cast != last_cast)
    {
        if(  p(first_cast) == false)
        {
            all_of_is = false;
        }
        first_cast += size;
    }

    return all_of_is;
}
/// Se pelo menos 1 for verdade pelo paraemtro(se valor for negativo)
bool any_of( const void *first , const void * last, size_t size , bool(*p)(const void *))
{
    byte *first_cast = (byte *) first;
    byte *last_cast = (byte *) last;
    bool any_of_is{false};

    while(first_cast != last_cast)
    {
        if(  p(first_cast) == true)
        {
            any_of_is = true;
        }
        first_cast += size;
    }

    return any_of_is;
}
/// Se todos forem false pelo paraemtro(se valor for negativo)
bool none_of( const void *first , const void * last, size_t size , bool(*p)(const void *))
{
    byte *first_cast = (byte *) first;
    byte *last_cast = (byte *) last;
    bool none_of_is{true};

    while(first_cast != last_cast)
    {
        if(  p(first_cast) == true)
        {
            none_of_is = false;
        }
        first_cast += size;
    }

    return none_of_is;
}
int main( void )
{
    std::cout << "q1 Min" << "\n";
    int A[] = {25, 2, 3, 1, 5, 6, 7};
    printffor(std::begin(A), std::end(A));
    int * b = (int  *) min(std::begin(A), std::end(A), sizeof(int), cmp);
    std::cout << "Menor Do vetor e: " << *b << "\n";

    std::cout << "q2 Rever" << "\n";
    int C[] = {3,3,3, 1 , 5 , 4 , 6, 0 , 5 };
    printffor(std::begin(C), std::end(C));
    reverse(std::begin(C), std::end(C), sizeof(int));
    printffor(std::begin(C), std::end(C));

    std::cout << "q3 Copia" << "\n";

    printffor(std::begin(A), std::end(A));
    int size_array = std::distance(std::begin(A), std::end(A));
    int * B = new int[size_array];
    int *bEnd = (int *) copy(std::begin(A), std::end(A), B, sizeof(int));
    std::cout << "Begin A[]" << &A[0] << " " << "Begin B[]" << b << "\n";
    printffor(B, bEnd);


    std::cout << "q4 Clone" << "\n";
    printffor(std::begin(A), std::end(A));
    int * b_clone =  (int *) clone( std::begin(A) , std::end(A) , sizeof(int) , size_array );
    printffor(b_clone, b_clone+size_array );

    std::cout << "q5 find if" << "\n";
    printffor(std::begin(A), std::end(A));
    int * neg = (int *) find_if (std::begin(A), std::end(A), sizeof(int) , p);
    std::cout << "Valor :" << *neg << ""<<"\nNume Valor Mem: "  << neg << "\nLast Valor Men: " << std::end(A) << "\n";

    std::cout << "q6 find" << "\n";
    printffor(std::begin(A), std::end(A));
    int value{0};
    std::cout << "Digite Valor a ser procurado :";
    std::cin >> value;
    int * valor = (int *) find(std::begin(A), std::end(A), sizeof(int), &value, eq);
    std::cout << "Valor :" << *valor << ""<<"\nNume Valor Mem: "  << valor << "\nLast Valor Men: " << std::end(A) << "\n";

    std::cout << "q7 find" << "\n";
    printffor(std::begin(A), std::end(A));
    std::cout << "All_of  1:true / 0:false: " << all_of(std::begin(A), std::end(A), sizeof(int), p) << "\n";
    std::cout << "Any_of  1:true / 0:false: " << any_of(std::begin(A), std::end(A), sizeof(int), p) << "\n";
    std::cout << "None_of 1:true / 0:false: " << none_of(std::begin(A), std::end(A), sizeof(int), p) << "\n";

    return 0;
}
