#include "../include/arvore.h"

#include <stdio.h>
#include <stdlib.h>

TNo *criaNo(TItem Item){
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    if(novo == NULL){
        printf("Erro de alocação\n");
    }

    novo -> item = Item;
    novo -> esq = NULL;
    novo -> dir = NULL;
    novo -> pai = NULL;
    return novo;
}

void Inserir(TNo **x, TNo *pai, TItem Item){
    if((*x) == NULL){
        (*x) = criaNo(Item);
        if(pai != NULL){
            (*x) -> pai = pai;
        }
        return;
    }
    if((*x) -> item.cidade.eventos[0].avaliacao > Item.cidade.eventos[0].avaliacao){
        Inserir(&(*x) -> esq, (*x), Item);
        return;
    }
    else{
        Inserir(&(*x) -> dir, (*x), Item);
        return;
    }
}

TNo *Pesquisar(TNo *x, TItem Item){
    if((x == NULL) || (x -> item.cidade.nome == Item.cidade.nome)){
        return x;
    }

    if(Item.cidade.nome < x -> item.cidade.nome){
        return Pesquisar(x -> esq, Item);
    }
    else if(Item.cidade.nome > x -> item.cidade.nome){
        return Pesquisar(x -> dir, Item);
    }
    return NULL;
}

void inOrdem(TNo *x){
    if (x != NULL){
        inOrdem(x -> esq);
        printf("\nCidade: %s\n", x -> item.cidade.nome);
        printf("Eventos: \n");
        for (int j = 0; j < 3; j++){
        printf(" %s - Nota: %.1f\n", x -> item.cidade.eventos[j].nome, x -> item.cidade.eventos[j].avaliacao);
        }
        inOrdem(x -> dir);
    }
}

void preOrdem(TNo *x){
    if (x != NULL){
        printf("Cidade: %s\nEventos: %s - Nota: %.1f.\n\n",x -> item.cidade.nome, x -> item.cidade.eventos[0].nome, x -> item.cidade.eventos[0].avaliacao);
        preOrdem(x -> esq);
        preOrdem(x -> dir);
    }
}

void posOrdem(TNo *x){
    if (x != NULL){
        posOrdem(x -> esq);
        posOrdem(x -> dir);
        printf("Cidade: %s\nEventos: %s - Nota: %.1f.\n\n",x -> item.cidade.nome, x -> item.cidade.eventos[0].nome, x -> item.cidade.eventos[0].avaliacao);
    }
}