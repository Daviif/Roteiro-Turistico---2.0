#ifndef _CIDADE_H
#define _CIDADE_H

#define max_c 5
#define max_e 3

#include "evento.h"

typedef struct cidade{
    char nome[100];
    TEvento eventos[max_e];
} TCidades;

void Armazenar_Cidades(char *cidade);
void preencherCidades(TCidades cidade[]);

#endif