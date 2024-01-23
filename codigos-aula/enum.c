#include <stdio.h>

#define TRUE 0
#define FALSE 1

//Enumeração - Enum


int main(void){
    int resposta;
    printf("Você gosta de algoritmos? \n 0 - true \n 1 - false \n");
    scanf("%d", &resposta);

    if(resposta == TRUE){
        printf("Boa escolha\n");
    } else if(resposta == FALSE){
        printf("Que pena!\n");
    }

    return 0;
}