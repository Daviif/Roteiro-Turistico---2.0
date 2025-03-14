#include "../include/ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void merge(TCidades *cidades, int esq, int meio, int dir){
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    TCidades *L = (TCidades *)malloc(n1 * sizeof(TCidades));
    TCidades *R = (TCidades *)malloc(n2 * sizeof(TCidades));

    int index_l = 0;
    for (i = 0; i < n1; i++){
        for (int e = 0; e < max_e; e++)
        {
            L[index_l] = cidades[esq + i];
            index_l++;
        }
    }
    int index_r = 0;
    for (j = 0; j < n2; j++){
        for (int e = 0; e < max_e; e++)
        {
            R[index_r] = cidades[meio + 1 + j];
            index_r++;
        }
        
    }

    for (i = 0; i < index_l - 1; i++) {
        for (j = 0; j < index_l - i - 1; j++) {
            if (L[j].eventos->avaliacao > L[j+1].eventos->avaliacao) {
                TCidades temp = L[j];
                L[j] = L[j+1];
                L[j+1] = temp;
            }
        }
    }
    
    for (i = 0; i < index_r - 1; i++) {
        for (j = 0; j < index_r - i - 1; j++) {
            if (R[j].eventos -> avaliacao > R[j+1].eventos -> avaliacao) {
                TCidades temp = R[j];
                R[j] = R[j+1];
                R[j+1] = temp;
            }
        }
    }

    i = 0;
    j = 0;
    k = esq;
    
    TCidades *temp = (TCidades *)malloc((n1+n2) * max_e * sizeof(TCidades));
    while (i < n1 && j < n2){
        if (L[i].eventos->avaliacao <= R[j].eventos -> avaliacao){
            
            temp[k] = L[i];
            i++;
            
        }
        else{
            temp[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < index_l){
        temp[k] = L[i];
        i++;
        k++;
    }
    while (j < index_r){
        temp[k] = R[j];
        i++;
        k++;
    }

    int event_index = 0;
    for (i = esq; i <= dir; i++) {
        for (j = 0; j < max_e; j++) {
            if (event_index < k) {
                cidades[i].eventos[j] = temp[event_index].eventos[j];
                event_index++;
            }
        }
    }

    free(L);
    free(R);
    free(temp);
}
void Mergesort(TCidades *cidades, int esq, int dir){

    if (esq < dir){

        int meio = esq + (dir - esq) / 2;

        Mergesort(cidades, esq, meio);
        Mergesort(cidades, meio + 1, dir);

        merge(cidades, esq, meio, dir);
    }

}

void imprimirAvaliacoes(TCidades *cidades) {
    for (int i = 0; i < max_c; i++){
        for (int j = 0; j < max_e; j++){
            printf(" %s - Nota: %.1f\n", cidades[i].eventos[j].nome, cidades[i].eventos[j].avaliacao);
        }
    }
    printf("\n");
}
