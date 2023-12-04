# Anotações organização de computadores
 - Devemos ao máximo fazer uso do barramento, por que ele é compartilhado por todas as unidades do computador e por sua vez dependendo da ordem de trafego de dados as vezes pode demorar mais o tempo de processamento;
 - "Uma variável do tipo inteiro é o menor tipo de dado que existe";

## "Em questão de DESEMPENHO, devemos ao máximo evitar o barramento";

# - Memória principal

        - Surge o conceito de palavras;
            Traz uma organização numa estrutura de palavra, maioria das palvras tem geralmente de (4-16 kilobytes);

            Seria como uma repartição na memória por célular de memória;

##

        - Por que o conceito foi criado?
            Quando a CPU solicita por exemplo os dados contidos na célula de endereço 0, a memória retorna o conteúdo da palavra com o conteúdo da palavra que começa com o a célula de endereço 0;

            NOTA: A memória principal NUNCA responde o conteúdo de uma única célula de memória, mas sim, o conteúdo de uma palavra, ou seja, recebe um endereço e responde uma palavra;

                                         <------------
                     MEMÓRIA   ENDEREÇO                 PALAVRA  CPU
                                         ------------>

            ! A palavra nem pode ser muito grande nem muito pequena;
                - Se fosse muito pequena = menos informação ela consegue armazenar, logo mais acesos são nescessários para obter uma informação;
                - Se a palavra for muito grande = mais informação consegue armazenar, logo menos acesos são nescessários para ibter uma informação. O problema é que por ser uma informação muito grande, será nescessário um processamento na CPU para descartar os dados desnecessários;

## Memória Cache - agiliza a vida da CPU evitando que ela faça uso do barramento
- Ojetivo - agilizar o acesso a memória principal evitando perda de desempenho e execução de programas
- Tamanho - pequena, bem menor que a memória principal, ela é a menor de todas na casa dos megasbytes;
- Velocidade - rápida, tempo compatível com o processamento da CPU;
- Preço - Mais cara que as demais memória da hierarquia;

- Está entre a CPU e o barramento. Uma vez que a CPU não tem acesso direto ao barramento, mas sim, a memória cache;

        - Linha de cache - agrupamento de palavras;
        - O conceito de linhas de cache só existe na memória cache, na memória principal a divisão é feita em palavras;
        - CACHE HIT (acerto de cache) - Quando uma informação que a CPU precisa já está na memória cache;
        - CACHE MISS (falha de cache) - Quando a CPU busca uma informação que não está na memória cache.Nestes casos a memória cache recorre a memória principal, não só trazendo o dado nescessário, mas toda a linha de cache em que o dado está contido, assim respondendo a requisição da CPU;