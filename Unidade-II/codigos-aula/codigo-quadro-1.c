#include <stdio.h>

int main(void) {
    int c;
    int nlinhas = 0;
    FILE *fp;

    // Abre o arquivo para leitura
    fp = fopen("entrada.txt", "rt");
    if(fp == NULL) {
        printf("Não foi possível abrir o arquivo! \n");
        return 1;
    }

    // Lê caractere a caractere
    while((c = fgetc(fp)) != EOF) { //end on file - código no final do arquivo 
        if(c == '\n') {
            nlinhas++;
        }
    }

    // Fecha arquivo
    fclose(fp);

    // Exibe resultado na tela
    printf("Número de linhas = %d\n", nlinhas);

    return 0;
}
