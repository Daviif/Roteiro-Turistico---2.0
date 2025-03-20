#include "../include/ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void imprimirAvaliacoes(TCidades *cidades) {
    for (int i = 0; i < max_c; i++){
        printf("%d. %s;\n",cidades[i].index_c, cidades[i].nome);
        for (int j = 0; j < max_e; j++){
            printf("%s - Nota: %.1f\n", cidades[i].eventos[j].nome, cidades[i].eventos[j].avaliacao);
        }
    }
    printf("\n");
}
float mediaAvaliacoes(TCidades cidades){
    float soma = 0, cont = 0;
    
    for(int i = 0; i < max_c; i++){
        for (int j = 0; j < max_e; j++){
            soma += cidades.eventos[j].avaliacao;
            cont++;
        }
    }

    if (cont > 0){
        return soma/cont;
    }
    else{
        return 0;
    }
}

