#ifndef _CIDADE_H
#define _CIDADE_H

#define max_c 5
#define max_e 3

#include "evento.h"

typedef struct cidade{
    char nome[100];
    TEvento eventos[max_e];
    int index_c;
} TCidades;

void Armazenar_Cidades(char *cidade);
void preencherCidades(TCidades cidade[]);

void *Buscar(char *Nomecidade, TCidades *cidades);
void Buscar_Eventos();

#endif