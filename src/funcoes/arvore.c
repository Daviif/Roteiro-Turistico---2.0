
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

int NumNos(TNo *raiz){
    if (raiz == NULL){
        return 0;
    }
    return 1 + NumNos(raiz -> esq) + NumNos(raiz -> dir);
    
}

void Inserir(TNo **x, TNo *pai, TItem Item){

    printf("Comparando: atual = %s, novo = %s\n", (*x) -> item.cidade.nome, Item.cidade.nome);
    if((*x) == NULL){
        (*x) = criaNo(Item);
        if(pai != NULL){
            (*x) -> pai = pai;            
        }
        return;
    }

    int ordem = strcasecmp((*x) -> item.cidade.nome, Item.cidade.nome);

    printf("Ordem calculada: %d. Indo para %s\n", ordem, (ordem > 0 ? "esquerda" : "direita"));

    if(ordem > 0){

        Inserir(&(*x) -> esq, (*x), Item);
        return;
    }   
    if (ordem <= 0){

        Inserir(&(*x) -> dir, (*x), Item);
        return;
    }

    printf("Novo nó criado: %s\n", Item.cidade.nome);

}

void inOrdem(TNo *x){
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

    printf("Pesquisando: atual = %s, buscada = %s\n", x -> item.cidade.nome, NomeCidade);


    if(x == NULL) {
        printf("Nó NULL alcançado. Cidade não encontrada: %s\n", NomeCidade);
        return x;
    }

    int ordem = strcasecmp(x -> item.cidade.nome, NomeCidade);

    printf("Movendo para %s. Ordem calculada: %d\n", (ordem > 0 ? "esquerda" : "direita"), ordem);

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
    char *input = converterString(NomeEv);

    if(x == NULL) {
        free(input);
        return NULL;
    }

    for (int j = 0; j < max_e; j++){
        char *nomearm = converterString(x ->item.cidade.eventos[j].nome);

        if (strcasecmp(nomearm, input) == 0){
            printf("%s",x -> item.cidade.eventos[j].nome);
            printf(" na cidade de %s",x -> item.cidade.nome);
            printf(" com avaliação %.1f\n", x -> item.cidade.eventos[j].avaliacao);

            free(nomearm);
            free(input);
            return x;
        }            
        free(nomearm);
    }
        
    TNo *encontrado = PesquisarEv(x -> esq, NomeEv);
        
    if (encontrado != NULL){
        free(input);
        return encontrado;
    }
    
    encontrado = PesquisarEv(x -> dir, NomeEv);
    free(input);
    return encontrado;
}

char *converterString(char *Texto) {
    const char antes[] = "ÄÅÁÂÀÃäáâàãÉÊËÈéêëèÍÎÏÌíîïìÖÓÔÒÕöóôòõÜÚÛüúûùÇç";
    const char depois[] = "AAAAAAaaaaaEEEEeeeeIIIIiiiiOOOOOoooooUUUUuuuuCc";

    char *letra = Texto;

    while (*letra != 0) {
        char *alvo = (char *)antes; // Array dos caracteres com acento
        while (*alvo != 0) {        
            if (*letra == *alvo) { // Substituir por equivalente sem acento
                *letra = *(depois + (alvo - antes));
                break;
            }
            alvo += 1;
        }
        letra += 1; // Avança para o próximo caractere
    }
    return Texto; // Retorna o texto convertido
}


