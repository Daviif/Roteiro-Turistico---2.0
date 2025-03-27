#include "../include/ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void imprimirAvaliacoes(TCidades *cidades) {
    
    for (int i = 0; i < max_c; i++){
        printf("---------------------------------------------\n");
        printf("%d. %s;\n",cidades[i].index_c, cidades[i].nome);
        for (int j = 0; j < max_e; j++){
            printf("%s - Nota: %.1f\n", cidades[i].eventos[j].nome, cidades[i].eventos[j].avaliacao);
        }
        printf("---------------------------------------------");
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

                cidades[j].index_c = j + 1;
                cidades[j + 1].index_c = j + 2;
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
                if (cidades[i].eventos[k].avaliacao < cidades[i].eventos[k+1].avaliacao){
                    aux = cidades[i].eventos[k];
                    cidades[i].eventos[k] = cidades[i].eventos[k+1];
                    cidades[i].eventos[k+1] = aux;
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
int Particao(TEvento *eventos, int baixo, int alto) {
    float pivo = eventos[alto].avaliacao;
    int i = baixo - 1;
    
    for (int j = baixo; j < alto; j++) {
        if (eventos[j].avaliacao >= pivo) {
            i++;
    
            TEvento aux = eventos[i];
            eventos[i] = eventos[j];
            eventos[j] = aux;
        }
    }

    TEvento aux = eventos[i + 1];
    eventos[i + 1] = eventos[alto];
    eventos[alto] = aux;
    
    return i + 1;
}

void QuickSortEv(TEvento *eventos, int baixo, int alto) {
    if (baixo < alto) {
        int pi = Particao(eventos, baixo, alto);
        
        QuickSortEv(eventos, baixo, pi - 1);
        QuickSortEv(eventos, pi + 1, alto);
    }
}

void Quick_Sort(TCidades *cidades) {
    Bubble_SortCi(cidades);
    
    for (int i = 0; i < max_c; i++) {
        QuickSortEv(cidades[i].eventos, 0, max_e - 1);
    }
    
    imprimirAvaliacoes(cidades);
}
void Merge(TEvento *eventos, int esq, int meio, int dir){
    int tam1 = meio - esq + 1;
    int tam2 = dir - meio;

    TEvento *metEsq = (TEvento*)malloc(tam1 * sizeof(TEvento));
    TEvento *metDir = (TEvento*)malloc(tam2 * sizeof(TEvento));

    for (int i = 0; i < tam1; i++){
        metEsq[i] = eventos[esq + i];
    }
    for(int j = 0; j < tam2; j++){
        metDir[j] = eventos[meio + 1 + j];
    }

    int i = 0, j = 0, k = esq;

    while (i < tam1 && j < tam2){
        if (metEsq[i].avaliacao >= metDir[j].avaliacao){
            eventos[k] = metEsq[i];
            i++;
        }
        else{
            eventos[k] = metDir[j];
            j++;
        }
        k++;
    }
    
    while (i < tam1){
        eventos[k] = metEsq[i];
        i++;
        k++;
    }
    
    while (j < tam2){
        eventos[k] = metDir[j];
        j++;
        k++;
    }

    free(metEsq);
    free(metDir);
}

void MergeSortEv(TCidades *cidades, int esq, int dir){

    if(esq < dir){
        int meio = esq + (dir - esq) / 2;

        MergeSortEv(cidades, esq, meio);
        MergeSortEv(cidades, meio + 1, dir);

        Merge(cidades->eventos, esq, meio, dir);
    }
}

void Merge_Sort(TCidades *cidades, int esq, int dir){
    Bubble_SortCi(cidades);

    for (int i = 0; i < max_c; i++){
        MergeSortEv(cidades, esq, dir);
    }

    imprimirAvaliacoes(cidades);
}

void Empilhar(TEvento *eventos, int n, int i){
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if(esq < n && eventos[esq].avaliacao < eventos[menor].avaliacao){
        menor = esq;
    }

    if(dir < n && eventos[dir].avaliacao < eventos[menor].avaliacao){
        menor = dir;
    }

    if(menor != i){
        TEvento aux = eventos[i];
        eventos[i] = eventos[menor];
        eventos[menor] = aux;

        Empilhar(eventos, n, menor);
    }
}

void HeapSortEv(TEvento *eventos){
    for(int i = max_e / 2 - 1; i >= 0; i--){
        Empilhar(eventos, max_e, i);
    }

    for(int i = max_e - 1; i > 0; i--){
        TEvento aux = eventos[0];
        eventos[0] = eventos[i];
        eventos[i] = aux;

        Empilhar(eventos, i, 0);
    }
}

void Heap_Sort(TCidades *cidades){
    Bubble_SortCi(cidades);

    for (int i = 0; i < max_c; i++){
        HeapSortEv(cidades[i].eventos);
    }

    imprimirAvaliacoes(cidades);
}
