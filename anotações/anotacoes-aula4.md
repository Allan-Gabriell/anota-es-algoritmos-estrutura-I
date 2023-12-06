# Passando vetor para função
- Crie uma função que recebe um vetor e calcula a média;

        float media(int tamanho, int *vetor){ - também posso passar o vetor como vetor[];
            int soma = 0;
            int cont;

            for(cont = 0; cont < tamanho; cont ++){
                soma  += vetor[cont]; - ou *(vetor+cont)
            }

            return soma/tamanho;
        }

# Declarando Matrizes

        int matriz [2][2] = {{0, 1}, {3, 2}}; - inicializei a matriz - &matriz[0][0]
        


        m = [0 1 - 3 2]
        0 = [0][0]
        1 = [0][1]
        3 = [1][0]
        4 = [1][1]