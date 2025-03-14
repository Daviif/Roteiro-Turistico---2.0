#ifndef _ORDENACAO_H
#define _ORDENACAO_H

#include "arvore.h"
 
void Bubble_Sort();
void Selection_Sort();
void Inseron_Sort();
void Shellsort();
void Quicksort();
void Mergesort(TCidades *cidades, int esq, int dir);
void merge(TCidades *cidades, int esq, int meio, int dir);
void Heapsort();
void imprimirAvaliacoes(TCidades *cidades);
#endif 