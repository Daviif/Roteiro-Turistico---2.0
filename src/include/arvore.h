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

TNo *criaNo(TItem Item);
void Inserir(TNo **x, TNo *pai, TItem Item);
void inOrdem(TNo *x);
void preOrdem(TNo *x);
void posOrdem(TNo *x);
TNo *Pesquisar(TNo *x, char *NomeCidade);
TNo *PesquisarEv(TNo *x, char *NomeCidade);



#endif 