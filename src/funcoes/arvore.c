
#include "../include/arvore.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

    int ordem = strcasecmp((*x) -> item.cidade.nome, Item.cidade.nome);

    if(ordem > 0){
        Inserir(&(*x) -> esq, (*x), Item);
        return;
    }   
    if (ordem <= 0){
        Inserir(&(*x) -> dir, (*x), Item);
        return;
    }
}

void inOrdem(TNo *x){
    printf("------------------------------------");
    if (x != NULL){
        inOrdem(x -> esq);
        printf("\nCidade: %s\n", x -> item.cidade.nome);
        printf("Eventos: \n");
        for (int j = 0; j < max_e; j++){
            printf("%d. %s - Nota: %.1f\n",x -> item.cidade.eventos[j].index_e + 1, x -> item.cidade.eventos[j].nome, x -> item.cidade.eventos[j].avaliacao);
        }
        inOrdem(x -> dir);
    }
}

void preOrdem(TNo *x){
    printf("------------------------------------");
    if (x != NULL){
        printf("\nCidade: %s\n", x -> item.cidade.nome);
        for (int j = 0; j < max_e; j++){
            printf("%d. %s - Nota: %.1f\n",x -> item.cidade.eventos[j].index_e + 1, x -> item.cidade.eventos[j].nome, x -> item.cidade.eventos[j].avaliacao);
        }
        preOrdem(x -> esq);
        preOrdem(x -> dir);
    }
}

void posOrdem(TNo *x){
    printf("------------------------------------");
    if (x != NULL){
        posOrdem(x -> esq);
        posOrdem(x -> dir);
        printf("\nCidade: %s\n", x -> item.cidade.nome);
        for (int j = 0; j < max_e; j++){
            printf("%d. %s - Nota: %.1f\n",x -> item.cidade.eventos[j].index_e + 1, x -> item.cidade.eventos[j].nome, x -> item.cidade.eventos[j].avaliacao);
        }
    }
}

TNo *Pesquisar(TNo *x, char *NomeCidade){
    if(x == NULL) {
        printf("Nó NULL alcançado. Cidade não encontrada: %s\n", NomeCidade);
        return x;
    }

    int ordem = strcasecmp(x -> item.cidade.nome, NomeCidade);

    if (ordem == 0)
    {   
            printf("Cidade encontrada! ");
            printf("%s", x -> item.cidade.nome);
            printf("\nEventos:\n");
            for (int j = 0; j < max_e; j++){
                printf("%d. %s - Nota: %.1f\n",x->item.cidade.eventos[j].index_e + 1,
                                               x->item.cidade.eventos[j].nome,
                                               x->item.cidade.eventos[j].avaliacao);
            }
        return x;
    }
    
    if (ordem > 0){
        return Pesquisar(x -> esq, NomeCidade);
    }
    else {
        return Pesquisar(x -> dir, NomeCidade);
    }
}


TNo *PesquisarEv(TNo *x, char *NomeEv){
    if(x == NULL) {
        return NULL;
    }

    for (int j = 0; j < max_e; j++){
        if (strcasecmp(x ->item.cidade.eventos[j].nome, NomeEv) == 0){
            printf("%s",x -> item.cidade.eventos[j].nome);
            printf(" na cidade de %s",x -> item.cidade.nome);
            printf(" com avaliação %.1f\n", x -> item.cidade.eventos[j].avaliacao);
            return x;
        }            
    }
        
    TNo *encontrado = PesquisarEv(x -> esq, NomeEv);
        
    if (encontrado != NULL){
        return encontrado;
    }
    
    encontrado = PesquisarEv(x -> dir, NomeEv);
    return encontrado;
}


