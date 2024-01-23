#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar um documento por vez
typedef union documentos{
    char rg[15];
    char cpf[15];
} Documentos;

typedef struct pessoa{
    char nome[20];
    int idade;
    Documentos doc; //Variável para armazenar CPF ou RG
} Pessoa;

typedef union tipo_dados{
    int meu_int;
    float meu_float;
} Dados;

void dados_pessoa(Pessoa *p){
    int opcao;
    printf("Informe o nome:\t");
    scanf("%[^\n]", p -> nome);
    printf("\nInforme a idade:");
    scanf("%d", &p -> idade);
    printf("Digite 1 para CPF ou 0 para RG: \n");
    scanf("%d", &opcao);
    if(opcao){
        scanf("%[^\n]", p->doc.cpf);
    } else {
        scanf("%[^\n]", p->doc.rg);
    }

}

int main(void){
    Pessoa *pessoa = malloc(sizeof(Pessoa));
    dados_pessoa(pessoa);

    free(pessoa);

    return 0;
}