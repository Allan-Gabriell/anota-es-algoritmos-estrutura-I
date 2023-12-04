# Ponteiros
## Exclusívo do C, permite manipular o endereço de memória
 - Endereço de memória é a célula de um espaço de memória;
 
    int valor
    scanf("%d", &valor) 
    
     & = operador de endereço;

## "*" este é o operador de ponteiro - é uma variável que guarda endereço

    int* ponteiro; - declarei essa variável ponteiro;
    ponteiro = &valor; = esta variável está guardando o endereço da variável valor;

    float* pont_real; - declarei um ponteiro do tipo real;
    char* pont_caracter; - declarei um ponteiro do tipo caracter;

## "%p% formatador do tipo ponteiro
## * também é um operador de conteúdo

    float var = 3.14;
    float* point = &var;
    float pi = *point; - nessa linha eu estou acessando o conteúdo
    *point = 1.31456; - aqui o conteúdo do ponteito "point" foi modificado

    Dentro do escopo de declaração representa um ponteiro, fora do escopo de declaração representa um operador de conteúdo.

## Ponteiro NULL
    - Um ponteiro null é um ponteiro que não aponta para nenhum objeto;
    - É usado para indicar ausência de um valor válido;
### comumente ultilizado para inicializar ponteiro

    ! "#define" - é usado também para criar uma constante;

## Compatibilidade e conversões entre ponteiros
    
    float number; 
    int * pointer;
    pointer = &number;
    pointer = (int*) &number; - eu estou forçando o endereço da minha variável a ser do tipo inteiro;

# Aritmética de ponteiros
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

# Usando funções com ponteiros
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
        /*Isso declara um ponteiro chamado "ponteiro" que é um ponteiro para uma funçãi que tem um tipo de retorno inteiro e dois parâmetros inteiros.*/
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