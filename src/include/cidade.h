#ifndef _CIDADE_H
#define _CIDADE_H

#define max_c 6
#define max_e 5

#include "evento.h"

typedef struct cidade{
    char nome[100];
    TEvento eventos[max_e];
    int index_c;
} TCidades;

void Armazenar_Cidades(char *cidade);
void preencherCidades(TCidades *cidade);
void ListarEvento(TCidades *cidades, int index);
void Buscar_EventosA(TCidades *cidades, int avaliacao);
TCidades *RemoverRoteiro(TCidades *cidades, TCidades *Roteiro, int index, int tamanho, int *novo_tamanho);
void Trocar(TCidades *cidades, int index1, int index2, int *tamanho);
void CriarRoteiroViagem(TCidades *cidades);
void EventosAleatorios(TCidades *cidades);

#endif