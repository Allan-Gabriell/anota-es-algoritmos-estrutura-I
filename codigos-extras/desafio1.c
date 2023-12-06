/*Desafio de Programação em C com Ponteiros e Alocação Dinâmica de Memória
Escreva um programa em C que faça o seguinte:
    - Alocação de memória: O programa deve pedir ao usuário para inserir um número n. 
      Em seguida, ele deve alocar dinamicamente um array de n inteiros usando a função malloc().
    - Preenchimento do array: O programa deve então pedir ao usuário para preencher o array com n inteiros.
    - Manipulação do array: O programa deve inverter a ordem dos elementos no array.
      Por exemplo, se o array original for [1, 2, 3, 4, 5], o array invertido será [5, 4, 3, 2, 1].
      Você deve fazer isso usando ponteiros, não índices de array.
    - Exibição do array: Finalmente, o programa deve imprimir o array invertido.*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, cont, vetor_final;

    printf("Por favor informe o tamanho do vetor:\n");
    scanf("%d", &n);

    int * vetor = (int*) malloc(n*sizeof(int));

    if(vetor == NULL){
        printf("Alocacao de memória falhou!");
        exit(1);
    }

    printf("Informe os valores do vetor: \n");
    for(cont = 0; cont < n; cont++){
        scanf("%d", &vetor[cont]);
    }

    for(cont = 0; cont < n/2; cont++){
        vetor_final = vetor[cont];
        vetor[cont] = vetor[n - cont - 1];
        vetor[n - cont - 1] = vetor_final;
    }

    printf("O vetor invertido é: \n");
    for(cont = 0; cont<n; cont++){
        printf("%d ", vetor[cont]);
    }

    free(vetor);

    return 0;
}