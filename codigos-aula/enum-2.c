#include <stdio.h>

//Enumeração - Enum
typedef enum bool{
    True,
    False
}Bool;

int main(void){
    Bool resposta;
    printf("Você gosta de algoritmos? \n 0 - true \n 1 - false \n");
    scanf("%d", &resposta);

    if(resposta == True){
        printf("Boa escolha\n");
    } else if(resposta == False){
        printf("Que pena!\n");
    }

    return 0;
}
