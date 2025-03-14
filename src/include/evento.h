#ifndef _EVENTO_H
#define _EVENTO_H

typedef struct {
    char nome[100];
    float avaliacao;
    int index_e;
} TEvento;


void Armazenar_Eventos(char *evento);

#endif