


void inserir( void );       // 0
void consultar( void );     // 1
void remover( void );       // 2
void listar( void );        // 3
void consolidar( void );    // 4
void sair( void );          // 5

typedef void (*pFuncVoid)( void );

pFuncVoid opcoes[] = { inserir, consultar, remover, listar, consolidar, sair };


int main()
{
    opcoes[0] = inserir;
    opcoes[1]
    int op(0);

    std::cin >> op;
    while ( op!= 5 )
    {
        if( op >= 0 && op <= 5)
            opcoes[ op ]();
        else 
            std::cout ">> Opcao invalida!\n";
    }
}
