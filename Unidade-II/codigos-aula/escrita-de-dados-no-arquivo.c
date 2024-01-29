#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE* fp;

    fp = fopen("escrita.txt", "wrt"); // r - para ler e W para escrita
    if(fp == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    printf("Arquivo criado!\n");

    fputc('a', fp); //escreve um caractere
    fputs("\nHello World!\n", fp); //escreve uma string
    fprintf(fp, "Meu texto"); //escreve uma string
    

    if(fclose(fp) == 0){
        printf("Arquivo fechado com sucesso! \n");
    }

    return 0;
}