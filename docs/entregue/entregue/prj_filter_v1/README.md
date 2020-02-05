# Introdução

Este projeto implementa a filtragem de um vetor.
Nesta versão o projeto está na forma **monolítica**, ou seja, todo o código
em um único arquivo, `src/drive_filter.cpp`.

Sua missão é reorganizar o código de maneira a separar a função `filter`, transformando-a em uma função-biblioteca.

# Tarefa

Você precisa criar o arquivo `src/filter.cpp`, que deverá conter apenas o código fonte da função `filter()`, ou seja, sua implementação.

Em seguinda, você deve criar o cabeçalho `include/filter.h`, que deverá conter apenas a declaração da função `filter()`, ou seja, a assinatura da função.

O próximo passo é ajustar o arquivo da função principal, `src/drive_filter.cpp`, apagando código da função `filter()` de lá e incluindo o arquivo cabeçalho recém criado.
Lembre-se que o código da função `filter()` agora reside em um arquivo separado!

Por último, você deve ajudar o comando de compilação de maneira que o compilador entenda que o projeto agora é composto por dois arquivos fonte, `src/filter.cpp` e `src/drive_filter.cpp`, e que precisa acessar o cabeçalho `include` para encontrar o cabeçalho da função `filter()`.
