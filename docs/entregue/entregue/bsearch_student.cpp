#include <cstdlib>
#include <iostream>

// Definição do tipo Estudante.
struct Student {
    std::string m_Name;
    unsigned int m_CPF;
    //! Sobrecarga do operador <<, que faz com que Student seja impresso.
    /*! @param _os Output stream, normalmente o <CODE>cout</code>.
     *  @param _s O estudante a ser impresso.
     *  @return A pr&oacute;pria <CODE>os</code> recebida como par&acirc;metros (para permitir encadeamento).
     */
    inline friend std::ostream &operator<< ( std::ostream& _os, const Student& _s )
    {
        _os << "(" << _s.m_Name << "," << _s.m_CPF << ")";
        return _os;
    }
};

int main( )
{
    Student arr[] = { { "paulo", 123056 },
                      { "saulo", 123456 },
                      { "cesar", 654321 },
                      { "thais", 777677 },
                      { "paulo", 987654 }
    };

    std::cout << ">>> Data array: [ ";
    for( const auto &e : arr )  std::cout << e << " ";
    std::cout << "]\n";

    const auto ARR_SIZE = sizeof( arr ) / sizeof( *arr );

    Student key1= { "paulo", 987654 };
    auto *p1 = (Student *) std::bsearch(&key1, arr, ARR_SIZE, sizeof(arr[0]), compare);
    if(p1)
        std::cout << "value " << key1 << " found at position " << (p1 - arr) << '\n';
    else
        std::cout << "value " << key1 << " not found\n";

    Student key2 = { "alberto", 4444444 };
    auto *p2 = (Student *) std::bsearch(&key2, arr, ARR_SIZE, sizeof(arr[0]), compare);
    if(p2)
        std::cout << "value " << key2 << " found at position " << (p2 - arr) << '\n';
    else
        std::cout << "value " << key2 << " not found\n";
}
