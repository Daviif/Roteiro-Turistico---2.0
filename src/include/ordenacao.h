#ifndef _ORDENACAO_H
#define _ORDENACAO_H

#include "arvore.h"
 
void Bubble_Sort(TCidades *cidades);
void Selection_Sort(TCidades *cidades);
void Insertion_Sort(TCidades *cidades);
void Shell_Sort(TCidades *cidades);
void Quick_Sort(TCidades *cidades, int baixo, int alto);
int Particao(TCidades *cidades, int baixo, int alto);
void Merge_Sort(TCidades *cidades, int esq, int dir);
void merge(TCidades *cidades, int esq, int meio, int dir);
void Heap_Sort();
void imprimirAvaliacoes(TCidades *cidades);
float mediaAvaliacoes(TCidades cidades);
void Bubble_SortCi(TCidades *cidades);

#endif 