#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatena(char *string1, char *string2) {
    char *newString = malloc(strlen(string1) + strlen(string2) + 1); // +1 para o caractere nulo '\0'
    if (newString == NULL) { 
        exit(1);
    }
    strcpy(newString, string1); // Copio string1 para newString
    strcat(newString, string2); // Concateno string2 em newString
    return newString;
}

int main(void){
    char *string1 = malloc(256 * sizeof(char)); //Eu declarei o 256 como um buffer mais ou menos razoável
    char *string2 = malloc(256 * sizeof(char)); 

    if (string1 == NULL || string2 == NULL) { 
        exit(1);
    }

    scanf(" %[^\n]", string1);
    scanf(" %[^\n]", string2);

    char *concatenated = concatena(string1, string2);
    printf("%s\n", concatenated);

    free(string1);
    free(string2);
    free(concatenated);

    return 0;
}


//escreva uma função que receba duas strings como entrada e retorne uma nova string que seja a concatenação das duas