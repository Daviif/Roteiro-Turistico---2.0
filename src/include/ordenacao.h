#ifndef _ORDENACAO_H
#define _ORDENACAO_H

#include "arvore.h"
void imprimirAvaliacoes(TCidades *cidades);
float mediaAvaliacoes(TCidades cidades);
void Bubble_SortCi(TCidades *cidades);
void Bubble_Sort(TCidades *cidades);
void Selection_Sort(TCidades *cidades);
void Insertion_Sort(TCidades *cidades);
void Shell_Sort(TCidades *cidades);
int Particao(TEvento *eventos, int baixo, int alto);
void QuickSortEv(TEvento *eventos, int baixo, int alto);
void Quick_Sort(TCidades *cidades);
void Merge(TEvento *eventos, int esq, int meio, int dir);
void MergeSortEv(TCidades *cidades, int esq, int dir);
void Merge_Sort(TCidades *cidades, int esq, int dir);
void Empilhar(TEvento *eventos, int n, int i);
void HeapSortEv(TEvento *eventos);
void Heap_Sort(TCidades *cidades);

#endif