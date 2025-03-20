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
        printf("\n");
    }
    
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

void Bubble_SortCi(TCidades *cidades){
    int i, j;
    TCidades aux;
    for (i = 0; i < max_c - 1; i++){
        for (j = 0; j < max_c - i - 1; j++){
            if (mediaAvaliacoes(cidades[j]) < mediaAvaliacoes(cidades[j+1])){
                aux = cidades[j];
                cidades[j] = cidades[j+1];
                cidades[j+1] = aux;
            }
        }
    }

    printf("\nCidades ordenadas por avaliação dos eventos:\n\n");
    for (int i = 0; i < max_c; i++){
        printf("%d. %s - Média de avaliação: %.1f\n",cidades[i].index_c, cidades[i].nome, mediaAvaliacoes(cidades[i]));
    }
    printf("\n");
}
void Bubble_Sort(TCidades *cidades){
    int i, j;

    Bubble_SortCi(cidades);

    TEvento aux;
    for (i = 0; i < max_c; i++){
        for (j = 0; j < max_e - 1; j++){
            for (int k = 0; k < max_e - j - 1; k++){
                if (cidades[j].eventos[j].avaliacao < cidades[j].eventos[j+1].avaliacao){
                    aux = cidades[j].eventos[j];
                    cidades[j].eventos[j] = cidades[j].eventos[j+1];
                    cidades[j].eventos[j+1] = aux;
                }
            }
        }
    }

    imprimirAvaliacoes(cidades);
}

void Selection_Sort(TCidades *cidades){
    Bubble_SortCi(cidades);

    for (int i = 0; i < max_c; i++){
        for (int j = 0; j < max_e - 1; j++){
            int max = j;
            for (int k = j + 1; k < max_e; k++){
                if (cidades[i].eventos[k].avaliacao > cidades[i].eventos[max].avaliacao){
                    max = k;
                }
            }
            TEvento aux = cidades[i].eventos[j];
            cidades[i].eventos[j] = cidades[i].eventos[max];
            cidades[i].eventos[max] = aux;
        }
    }

    imprimirAvaliacoes(cidades);
}

void Insertion_Sort(TCidades *cidades){
    Bubble_SortCi(cidades);

    for (int i = 0; i < max_c; i++){
        for (int j = 1; j < max_e; j++){
            TEvento aux = cidades[i].eventos[j];
            int k = j - 1;
            while (k >= 0 && cidades[i].eventos[k].avaliacao < aux.avaliacao){
                cidades[i].eventos[k+1] = cidades[i].eventos[k];
                k--;
            }
            cidades[i].eventos[k+1] = aux;
        }
    }

    imprimirAvaliacoes(cidades);
}

void Shell_Sort(TCidades *cidades){
    Bubble_SortCi(cidades);

    for (int i = 0; i < max_c; i++){
        for (int gap = max_e/2; gap > 0; gap /= 2){
            for (int j = gap; j < max_e; j++){
                TEvento aux = cidades[i].eventos[j];
                int k = j;
                while (k >= gap && cidades[i].eventos[k-gap].avaliacao < aux.avaliacao){
                    cidades[i].eventos[k] = cidades[i].eventos[k-gap];
                    k -= gap;
                }
                cidades[i].eventos[k] = aux;
            }
        }
    }

    imprimirAvaliacoes(cidades);
}

int Particao(TCidades *cidades, int baixo, int alto){
    float pivor;
    pivor = cidades[0].eventos[alto].avaliacao;
    int i = baixo - 1;


        for (int j = baixo; j < alto; j++){
            if(cidades[0].eventos[j].avaliacao >= pivor){
                i++;
                TEvento aux = cidades[0].eventos[k];
                cidades[0].eventos[i] = cidades[0].eventos[j];
                cidades[0].eventos[j] = aux;
            }
        }
    
    
    TEvento aux = cidades[0].eventos[i + 1];
    cidades[0].eventos[i + 1] = cidades[0].eventos[alto];
    cidades[0].eventos[alto] = aux;

    return i + 1;
}

void Quick_Sort(TCidades *cidades, int baixo, int alto){
    Bubble_SortCi(cidades);

    if (baixo < alto){
        int pi = Particao(cidades, baixo, alto);

        Quick_Sort(cidades, baixo, pi-1);
        Quick_Sort(cidades, pi+1, alto);
    }
    

    imprimirAvaliacoes(cidades);
}