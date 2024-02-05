# Tipos abstratos de dados 
### Módulo
- Ideia Central
    * Encapsular de quem usa um determinado tipo a forma concreta com que ele foi implementado;
- Benefícios:
    * Desacoplamento da implementação do uso;
    * Facilidade de manutenção;
    * Aumento de reuso;
### Módulos e compilação em separado
- Módulo (básicamente separar o meu programa em arquivos)
    * Arquivo com funções que representam parte de uma implementação;
    * A implementação de um programa pode ser composta por um ou mais módulos;
- Programa composto por vários módulos:
    * Cada um compilado separadamente (.o ou .obj);
    * O ligador (linker) reúne todos os arquivos objeto em um único arquivo executável;
- Para programas de médio e grande porte, a sua divisão em vários módulos é fundamental;
## Para o sistema operacional reconher temos que compilar separadamente

        >gcc -c str.c
        >gcc -c prog1.c
        >gcc -o prog1.exe strc.o prog1.o - geração do programa executável

- Exemplo do uso de módulos em C
    * Um programa pode utilizar as funções de str.c desde que conheça os seus protótipos;
    * problema com a repetição de protótipos;
    * Todo módulo de funções em C constuma ter associado um arquivo interface com extenção ' .h '

            Posso chamar meu módulo como:

            #include "nome_da_interface"
### TAD - Tipo Abstrato de Dados
- Não encapsula somente funções, mas novos tipos de dados