#include "../include/cidade.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void Armazenar_Cidades(char *cidade){
    char *cidades[] =   { "Sao Paulo", "Rio de Janeiro", "Belo Horizonte", "Brasilia", "Salvador",
        "Curitiba", "Fortaleza", "Recife", "Porto Alegre", "Manaus", "Belem", "Goiania", "Florianopolis", 
        "Vitoria", "Cuiaba", "Joao Pessoa", "Teresina", "Natal", "Aracaju", "Maceio", "Porto Velho", 
        "Rio Branco", "Macapa", "Boa Vista", "Palmas", "Paris", "Londres", "Nova York", "Toquio", "Pequim",
        "Sydney", "Cidade do Mexico", "Toronto", "Barcelona", "Roma", "Amsterda", "Berlim", "Viena", "Praga", 
        "Lisboa"};

    int numCidades = sizeof(cidades) / sizeof(cidades[0]);

    strcpy(cidade, cidades[rand() % numCidades]);

}


void preencherCidades(TCidades cidades[]){
    for (int i = 0; i < max_c; i++) {
        bool duplicado;
        
        do {
            duplicado = false;
            Armazenar_Cidades(cidades[i].nome);
            
            for(int j = 0; j < i; j++){
                if(strcmp(cidades[i].nome, cidades[j].nome) == 0){
                    duplicado = true;
                    break;
                    cidades[i].index_c = i;
                }

            }
        } while(duplicado);

        
        for (int j = 0; j < max_e; j++) {
            Armazenar_Eventos(cidades[i].eventos[j].nome);  
            cidades[i].eventos[j].avaliacao = (rand() % 101) / 10.0; 
            cidades[i].eventos[j].index_e = j;
        }
    }
}

void *Buscar(char *Nomecidade, TCidades *cidades){
    
    for (int i = 0; i < max_c; i++)
    {
        if(strcmp(cidades[i].nome, Nomecidade) == 0){
            printf("Cidade encontrada!\n");
            printf("%s",cidades[i].nome);
            
            printf("\nEventos:\n");
            for (int j = 0; j < max_e; j++)
            {
                printf("%s - Nota: %.1f\n", cidades[i].eventos[j].nome, cidades[i].eventos[j].avaliacao);
            }
            
        }
    }
    
}

void MelhorAv(TCidades *cidades){
    float melhorEv = 0.0;

    for (int i = 0; i < max_c; i++)
    {
        for (int j = 0; j < max_e; j++)
        {
            if(cidades[i].eventos[j].avaliacao > melhorEv){
                melhorEv = cidades[i].eventos[j].avaliacao;
            }
        }
        
    }

    for (int i = 0; i < max_c; i++)
    {
        /* code */
    }
    
    

}
