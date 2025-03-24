#ifndef _ARVORE_H
#define _ARVORE_H

#include "cidade.h"

typedef struct item{
    TCidades cidade;
}TItem;


typedef struct no{
    TItem item;
    struct no *pai;
    struct no *esq;
    struct no *dir;

} TNo;

typedef struct Arvore{
    TNo *raiz;
} TArvore;

void inOrdem(TNo *x);
void preOrdem(TNo *x);
void posOrdem(TNo *x);
TNo *Pesquisar(TNo *x, char *NomeCidade);
TNo *PesquisarEv(TNo *x, char *NomeCidade);
void Inserir(TNo **x, TNo *pai, TItem Item);
int NumNos(TNo *raiz);
TNo *criaNo(TItem Item);
char *converterString(char *Texto);

#endif 