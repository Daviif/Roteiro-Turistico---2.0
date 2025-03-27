#ifndef _EVENTO_H
#define _EVENTO_H
#include <stdbool.h>

typedef struct {
    char nome[100];
    float avaliacao;
    int index_e;
    bool disponivel;
} TEvento;

void Armazenar_Eventos(char *evento);
void Mensagens_Especiais();


#endif