#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE* fp;
    char c[20];
    fp = fopen("entrada.txt", "rt"); // r - para ler
    if(fp == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    printf("Arquivo criado!\n");
    //c = fgetc(fp); //lê um caracter;
    //fgets(c, 20, fp); //lê uma string;
    fscanf(fp, "%[^\n]", c); //lê uma string
    printf("%s\n", c);

    if(fclose(fp) == 0){
        printf("Arquivo fechado com sucesso! \n");
    }

    return 0;
}