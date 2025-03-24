#include "../include/cidade.h"
#include "../include/ordenacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void Armazenar_Cidades(char *cidade){
    char *cidades[] =   {"Betim", "Uberlandia", "Juiz de Fora", "Ouro Preto", "Montes Claros", "Patos de Minas", 
    "Divinopolis", "Ipatinga", "Muriae", "Uberaba", "Contagem", "Sabara", "Nova Lima", "Teofilo Otoni", "Varginha",
    "Sete Lagoas", "Lavras", "Araxa", "Pocos de Caldas", "Governador Valadares", "Passos", "Ituiutaba", "Barbacena",
    "Sao Joao del Rei", "Januaria", "Carangola", "Curvelo", "Alfenas", "Araguari", "Pirapora", "Sao Gotardo",
    "Tres Coracoes", "Diamantina", "Capelinha", "Manhuacu", "Santa Luzia", "Ouro Branco", "Paracatu", "Almenara", "Itabira"};

    int numCidades = sizeof(cidades) / sizeof(cidades[0]);

    strcpy(cidade, cidades[rand() % numCidades]);

}


void preencherCidades(TCidades *cidades){
    int i;
    for (i = 0; i < max_c; i++) {
        bool duplicado;
        
        do {
            duplicado = false;
            Armazenar_Cidades(cidades[i].nome);
            
            for(int j = 0; j < i; j++){
                if(strcmp(cidades[i].nome, cidades[j].nome) == 0){
                    duplicado = true;
                    break;
                }
            }
        } while(duplicado);

        cidades[i].index_c = i + 1;

        for (int j = 0; j < max_e; j++) {
            Armazenar_Eventos(cidades[i].eventos[j].nome);  
            cidades[i].eventos[j].avaliacao = (rand() % 101) / 10.0; 
            cidades[i].eventos[j].index_e = j;
        }
    }
}


void ListarEvento(TCidades *cidades, int index){
    printf("\nEventos na cidade de %s:\n", cidades[index].nome);
    printf("----------------------------------\n");
    for (int j = 0; j < max_e; j++)
    {
        printf("%d. %s - Nota: %.1f\n", cidades[index].eventos[j].index_e + 1, cidades[index].eventos[j].nome, cidades[index].eventos[j].avaliacao);
    }
    printf("----------------------------------");
}


void Buscar_EventosA(TCidades *cidades, int avaliacao){
    bool encontrado = false;

    for (int i = 0; i < max_c; i++){
        for (int j = 0; j < max_e; j++){
            if((int)cidades[i].eventos[j].avaliacao == avaliacao){
                
                printf("%s",cidades[i].eventos[j].nome);
                printf(" na cidade de %s", cidades[i].nome);
                printf(" com avaliação %.1f\n", cidades[i].eventos[j].avaliacao);
                encontrado = true;
            }
        }
    }

    if (!encontrado){
        printf("Evento com classificação %d nao encontrado\n", avaliacao);
        printf("Eventos com classficação proxima:\n");
        for (int i = 0; i < max_c; i++){
            for (int j = 0; j < max_e; j++){
                if((int)cidades[i].eventos[j].avaliacao == avaliacao - 1 || (int)cidades[i].eventos[j].avaliacao == avaliacao + 1){
                    printf("%s",cidades[i].eventos[j].nome);
                    printf(" na cidade de %s", cidades[i].nome);
                    printf(" com avaliação %.1f\n", cidades[i].eventos[j].avaliacao);
                }
            }
        }
    }
    
}

void RemoverRoteiro(TCidades *cidades,int *tamanho, int index_c){
    for(int i = index_c; i < tamanho - 1; i++){
        cidades[i] = cidades[i + 1];
    }
    (*tamanho)--;
    printf("Cidade %s removida do roteiro.\n",cidades[index_c].nome);

    printf("Roteiro atualizado:\n");
    for (int i = 0; i < *tamanho; i++) {
        printf("%d. %s\n", cidades[i].index_c, cidades[i].nome);
    }
}


void processar(TCidades *cidades, int *tamanho, char *input){

    if(isdigit(input[0])){
        int index_c = atoi(input);
        if (index_c >= 0 && index_c < *tamanho){
            RemoverRoteiro(cidades, tamanho, index_c);
        }
        else{
            printf("Indice invalido!");
        }
    }
    else{
        int encontrou = -1; 
        for (int i = 0; i < max_c; i++)
        {
            if(strcasecmp(cidades[i].nome, input) == 0){
                encontrou = i;
                break;
            }
        }
        if(encontrou != -1){
            RemoverRoteiro(cidades, tamanho, encontrou);
        }
        else{
            printf("Cidade n�o encontrada");
        }
        
    }
}
void CriarRoteiroViagem(TCidades *cidades){
    int tamanho = max_c;
    printf("Deseja ver a nossa sugestão de roteiro de viagem?(Sim/Não)\n");
    char esc[4];
    fflush(stdin);
    fgets(esc, 4, stdin);
    if (esc[strlen(esc)-1] == '\n'){
        esc[strlen(esc)-1] = '\0';
    }
    if(strcmp(esc, "Sim") == 0){
        printf("Roteiro sugerido!\n");
        
        Bubble_Sort(cidades);

        printf("Deseja seguir esse roteiro ou modifica-lo?(S/M)\n");
        char esc2[2];
        fflush(stdin);
        fgets(esc2, 2, stdin);
        if (esc2[strlen(esc2)-1] == '\n'){
            esc2[strlen(esc2)-1] = '\0';
        }
        if(strcmp(esc2, "S") == 0){
            printf("Roteiro seguido!\n");
            for (int i = 0; i < max_c; i++){
                printf("%d. %s\n", cidades[i].index_c, cidades[i].nome);
            }
        }
        else if(strcmp(esc2, "M") == 0){
            printf("Oque você deseja fazer?\n");
            printf("1 - Remover cidade\n2 - Trocar cidade\n");
            int op;
            scanf("%d", &op);
            getchar();


            if (op == 1){
                TCidades Roteiro[tamanho];
                for (int i = 0; i < max_c; i++){
                    Roteiro[i] = cidades[i];
                }

                int cidadesc[100];
                printf("Essas s�o as cidades e indices.\n");
                for (int i = 0; i < max_c; i++){
                    printf("%d. %s\n", Roteiro[i].index_c, Roteiro[i].nome);
                }
                printf("Digite qual cidade deseja remover(Indice ou Nome): ");
                fgets(cidadesc, 100, stdin);
                if (cidadesc[strlen(cidadesc)-1] == '\n'){
                    cidadesc[strlen(cidadesc)-1] = '\0';
                }

                processar(Roteiro, &tamanho, cidadesc);

            }
            else if (op == 2){

            }
        }
        else{
            printf("Op��o invalida!\n");
        }

    }
    else if(strcmp(esc, "N�o") == 0){
        printf("Tudo bem! Crie o seu próprio roteiro a seguir!\n");

        int numSelecionar;
        printf("Quantas cidades você deseja incluir no seu roteiro?\n");
        scanf("%d", &numSelecionar);
        getchar();

        if(numSelecionar < 1){
            printf("Número de cidades inválido\n");
            return;
        }
        else if(numSelecionar > max_c){
            printf("Número de cidades excede o limite\nO numero máximo de cidades é %d\n", max_c);
            return;
        }

        int cidadesSelecionadas[numSelecionar];
        printf("Selecione as cidades de acordo com seu índice:\n");
        for (int i = 0; i < max_c; i++){
            printf("%d. %s\n", cidades[i].index_c, cidades[i].nome);
        }
        for(int j = 0; j < numSelecionar;j++){
            printf("Selecione a %dª cidade: ", j + 1);
            scanf("%d", &cidadesSelecionadas[j]);
            cidadesSelecionadas[j]--;
        }
    }
    else{
        printf("Opção inválida!\n");
    }
    
}