# Revisão Algoritmos e estrutura de dados I - unidade I

## Ponteiro
#### O que são ponteiros
Ponteiros são variáveis que armazenam o endereço de memória de outras variáveis
- " * " é o operador de ponteiro e de conteúdo. Contudo, para diferenciar sua utilização devemos analisar o escopo de declaração.

        int * ponteiro; - aqui eu declarei um ponteiro 
        * ponteiro = 12; - aqui eu modifiquei o conteúdo do ponteiro

- " & " é o operador de endereço

        int number = 12;
        int * ponteiro = &number; - agora o ponteiro está guardando o valor do endereço de number

- " %p " - é o operador de ponteiro

        int * ponteiro;
        printf("%p", ponteiro); - agora vai exibir o valor do endereço armazenado em ponteiro

#### Ponteiro NULL
- Ponteiro NULL é um ponteiro que não aponta para nenhum objeto
- É usado para indicar ausência de valor

#### Compactibilidade  e conversões de ponteiros

        float number; 
        int * pointer;
        pointer = &number;
        pointer = (int*) &number; - eu estou forçando o endereço da minha variável a ser do tipo inteiro;

#### Aritmética de ponteiros

- permite manipular espaços de memória e modifica-los;
-Considerando que "p" é um ponteiro;

    - Soma de um um inteiro a um ponteiro
        p+2 - se ele estivesse na célula 96 ele andaria 2 células de memória;
    - Subtração de um inteiro a um ponteiro
        p-3 - mesmo esquema da soma;
    - Incremento de ponteiro
        ++p ou p++
    - Decremento de ponteiro
        --p ou p--
    - Subtrações entre dois ponteiros do mesmo tipo
     p-p2 - você tem um valor inteiro e não um endereço

#### Usando funções com ponteiros
- As funções em C podem trabalhar com ponteiros de varias maneiras. Uma maneira é passar um ponteiros como argumentos para uma função, permitindo que a função acesse e altere o valor de uma variável fora e seu próprio escopo.

        void incrementa(int *ponteiro){
            (*ponteiro)++;
        }

        int main(){
            int variavel = 5;
            incrementa(&variavel);

            printf("valor da variavel: %d", variavel);

            return 0;
        }

- Usar ponteiro como retorno de função. Isso permite que uma função retorne um endereço de memória para uma variável. Por exemplo:

        int *cria_variavel(){
            int variavel = 5;
            return &variavel;
        }

        int main(){
            int *ponteiro = cria_variavel();
            printf("valro da variavel: %d", *ponteiro);

            return 0;
        }

- Os ponteiro de função são usados para apontar para uma função específica, permitindo que a função possa ser chamada diretamente.
- Os ponteiros de função também permitem que a função seja passada como parâmetro para outras funções;
- Para declarar um ponteiro de função, você deve especificar o tipo de retorno da função seguindo do nome do ponteiro e o tipo de parâmetro entre parênteses. Por exemplo:

        int(*ponteiro)(int, int);
        /*Isso declara um ponteiro chamado "ponteiro" que é um ponteiro para uma função que tem um tipo de retorno inteiro e dois parâmetros inteiros.*/
#

        int soma(int a, int b){
            return a + b;
        }

        int calcula(int x, int y, int (*operacao)(int, int){
            return(*operacao)(x, y);
        })

        int main(){
            int resultado = calcula(5, 3, soma);
            printf("Resultado: %d", resultado);
            return 0;
        }

#
- Para declararmos o ponteiro de um ponteiro, que seria um ponteiro que guarda o endereço de outro ponteiro, fazemos uso do préfixo - "**";

        float y = 5.0;
        float *p =y
        float **pp;
        pp = &p;
        **pp = 4;

        - No caso da linha 8 nós estariamos acessando com o primeiro "*", o conteúdo de p, e com o outro "*" o conteúdo de p que no caso é y e mudariamos o valor de y de 5.0 para 4.0;
        - Estariamos acessando de forma indireta o conteúdo de y;

#### Usando função com ponteiro

        !CUIDADO - a linguagem C é lida de cima para baixo e da esquerda para a direita:

                                     return ++num != num++
        
        No primeiro caso o incremento é feito antes de retornar;

#### Ponteiro para função
- Os ponteiros de função são usadas para apontar para uma função específica, permitindo que a função possa ser chamada diretamente;
- Armazena o endereço de uma função; 

        #include <stdio.h>

        int incrementa(int valor){
            return ++valor;
        }
        
        int (*inc)(int) = incrementa; - Acabei de criar um ponteiro para minha função que quero criar um ponteiro;

        -Meu segundo () eu coloco os tipos de todos os paramentro que a função para o qual o ponteiro está sendo criado tem;
        -No caso deste exemplo ele vai guardar o enedereço de toda a função;

        ! O PONTEIRO TEM QUE SER DO MESMO TIPO QUE A FUNÇÃO;
        ! QUANDO É PONTEIRO PARA FUNÇÃO PRECISA ESTAR ENTRE ();

# Alocação Dinâmica
Um processo de alocar e liberar memória durante a execução do programa
- A alocação dinâmica de vetores é feita usando funções como malloc()
- Otimizar uso de memória conforme necessidade

### Alocação estática

        int main(){
            int vetor[3] = {2, 4, 6};
            return 0;
        }

        - Neste caso temos uma alocação estática de memória, pois não é possível aumentar ou diminuir o
        tamanho da memória alocada de uma variável;

### Alocação dinâmica
#### Função "malloc()"

- Retorna um endereço;

- A função malloc() em C, que significa alocação de memória, é usada para alocar um bloco de memória dinamicamente. Ela faz parte da biblioteca stdlib.h e recebe como argumento números inteiros positivos (size_t), que representam o número de bytes que serão alocados;

- A função retorna um ponteiro contendo o endereço do bloco de memória alocado1. Este ponteiro retornado geralmente é do tipo void, pois a função malloc() pode ser usada para declarar qualquer tipo de dado, seja int, float, double ou uma struct criada por você;

        #include <stdlib.h>

        int main(void){
        int * vetor = malloc(3*sizeof(int)); // A função malloc vai retornar o endereço do primeiro elemento do vetor
    
    
        if(vetor == NULL){ //Não foi possível alocar e preciso abortar o processo
            printf("Erro na alocacao de memoria \n");
            exit(1);
        } else {
            printf("Alocacao bem sucedida \n");
        }
        free(vetor); // Sempre preciso limpar/esvaziar o vetor
        return 0;
        }
    
#### Sempre depois de usar o vetor é preciso esvazialo e para isso usamos o - free(nome_da_variável)

#### Função "calloc()"

- Reserva um espaço de memória e inicializa o vetor com zeros;

- Garante que não vai haver nenhum LIXO nas posições do vetor;

- A função calloc() em C, que significa alocação contígua, é usada para alocar um bloco de memória dinamicamente. Ela faz parte da biblioteca stdlib.h e recebe como argumentos dois números inteiros positivos (size_t), que representam a quantidade de elementos que serão alocados e o tamanho em bytes de cada elemento;

- A função retorna um ponteiro contendo o endereço do bloco de memória alocado1. Este ponteiro retornado geralmente é do tipo void, pois a função calloc() pode ser usada para declarar qualquer tipo de dado, seja int, float, double ou uma struct criada por você;

#### Função "realloc()"

- É feita para realocar o tamanho da memória de um vetor seja para mais ou para menos;

# Alocação de matriz 

        #include <stdio.h>
        #include <stdlib.h>

        int main(void){
            int linhas = 3, colunas = 3, i, j;
            //Alocando vetor de ponteiro;
            int **matriz= (int**) malloc(linhas*sizeof(int*)); //matriz é um ponteiro de ponteiro;
            //Como é dois ** ele vai ser um ponteiro que armazena vetores;

            // Alocando cada linha da matriz;
            for(i = 0; i<linhas; i++){
                matriz[i] = (int*) malloc(colunas*sizeof(int));
            }
        //Eu acabo de criar uma matriz 3X3;
        //liberando memória alocada;

        for(i=0; i<linhas; i++){
            free(matriz[i]); //Primero apago as linhas do vetor
        }

        free(matriz); //Apago o resto da matriz

        return 0;
        }

        //Posso acessar os dados por meio - *(*(matriz+i)+j) ou matriz[i][j];

# Tipo estrutura
- Uma estrutura, em C, serve basicamente para agrupar diversas variáveis dentro de um único contexto
- Exemplo: estrutura ponto

        struct ponto{
            float x;
            float y;
        }

- Ponteiro para estrutura

        struct ponto *pp;

        (*pp).x = 12.0;
        pp -> x = 12.0;

- Passagem de estruturas para funções

        int main(void){
                struct ponto p;
                captura(&p); - & por que é um operador de endereço
                imprime(&p);
                return 0;
        }

        int main(void){
                struct ponto *p = malloc(sizeof(struct ponto));
                captura(p);
                imprime(p);
                free(p);
                return 0;
        }

Ambos os códigos acima fazem a mesma coisa, só muda o uso do &

        - unsigned - é uma palavra reservada do c que aumenta a faixa de representação; usigned int, contudo neste caso só será exibido números positivos
