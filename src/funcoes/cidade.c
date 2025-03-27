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
            cidades[i].eventos[j].disponivel = true;
        }
    }
}

void ListarEvento(TCidades *cidades, int index){
    printf("\nEventos na cidade de %s:\n", cidades[index].nome);
    printf("----------------------------------\n");
    for (int j = 0; j < max_e; j++){
        if(cidades[index].eventos[j].disponivel){
            printf("%d. %s - Nota: %.1f\n", cidades[index].eventos[j].index_e + 1, cidades[index].eventos[j].nome, cidades[index].eventos[j].avaliacao);
        }
        else{
            printf("%d. %s - Indisponivel! Fique ligado, ele pode voltar a qualquer momento!\n", cidades[index].eventos[j].index_e + 1, cidades[index].eventos[j].nome);
        }
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

TCidades *RemoverRoteiro(TCidades *cidades, TCidades *Roteiro, int index, int tamanho, int *novo_tamanho){
    
    if(Roteiro == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    int j = 0;

    printf("Cidade %s removida com sucesso do seu roteiro.\n", cidades[index].nome);

    for(int i = 0; i < tamanho; i++){
        if (i != index){
            Roteiro[j] = cidades[i];
            j++;
        }
    }

    *novo_tamanho = tamanho - 1;
    free(cidades);

    printf("Roteiro atualizado:\n");
    for (int i = 0; i < *novo_tamanho; i++) {
        printf("%d. %s\n", Roteiro[i].index_c, Roteiro[i].nome);
    }

    return Roteiro;
}

void Trocar(TCidades *cidades, int index1, int index2, int *tamanho){
    TCidades temp = cidades[index1];
    cidades[index1] = cidades[index2];
    cidades[index2] = temp;

    cidades[index1].index_c = index1 + 1;
    cidades[index2].index_c = index2 + 1;

    for (int i = 0; i < *tamanho; i++){
        printf("%d. %s\n", cidades[i].index_c, cidades[i].nome);
    }
}
void CriarRoteiroViagem(TCidades *cidades){
    TCidades *Roteiro = (TCidades *)malloc(max_c * sizeof(TCidades));
    int tamN = max_c;
    getchar();
    printf("Deseja ver a nossa sugestão de roteiro de viagem?(S/N)\n");
    char esc[4];
    fgets(esc, 4, stdin);
    if (esc[strlen(esc)-1] == '\n'){
        esc[strlen(esc)-1] = '\0';
    }
    if(strcasecmp(esc, "S") == 0){
        printf("\nRoteiro sugerido!");
        Bubble_SortCi(cidades);

        getchar();
        printf("Deseja seguir esse roteiro ou modifica-lo?(S/M)\n");
        char esc2[2];
        fgets(esc2, 2, stdin);
        if (esc2[strlen(esc2)-1] == '\n'){
            esc2[strlen(esc2)-1] = '\0';
        }
        if(strcasecmp(esc2, "S") == 0){
            printf("\nRoteiro seguido!");
            for (int i = 0; i < max_c; i++){
                printf("%d. %s\n", cidades[i].index_c, cidades[i].nome);
            }
        }
        else if(strcasecmp(esc2, "M") == 0){
            getchar();
            int tam = max_c;
            
            bool continuar = true;
            int index;
            do{
                
                printf("Oque você deseja fazer?\n");
                printf("1 - Remover cidade\n2 - Trocar cidade\n3 - Finalizar roteiro\n");
                int op;
                scanf("%d", &op);
                getchar();
                switch(op){
                    case 1:
                        printf("Qual cidade deseja remover?(Indice da cidade)\n");
                        scanf("%d", &index);
                        int index_interno = index - 1;
                        if(index_interno >= 0 && index_interno < tam){
                            cidades = RemoverRoteiro(cidades, Roteiro, index_interno, tam, &tamN);
                        }
                        else{
                            printf("Index invalido!");
                            printf("Digite um valor entre 1 e %d\n", tam);
                            continue;
                        }
                        break;
                    case 2:
                        printf("Qual cidade deseja trocar?(Utilize o índice)\n");
                        int index1, index2;
                        printf("Digite a primeira cidade: ");
                        scanf("%d", &index1);
                        printf("Digite a segunda cidade: ");
                        scanf("%d", &index2);
                        Trocar(cidades, index1 - 1, index2 - 1, &tamN);
                        break;
                    case 3:
                        printf("Roteiro finalizado!\nSeu roteiro:\n");
                        for (int i = 0; i < tamN; i++){
                            printf("%d. %s\n", cidades[i].index_c, cidades[i].nome);
                        }
                        continuar = false;
                        break;
                    default:
                        break;
                }
            } while (continuar == true);
        }
        else{
            printf("Opcao invalida!\n");
        }
    }
    else if(strcasecmp(esc, "N") == 0){
        printf("Tudo bem! Crie o seu proprio roteiro a seguir!\n");

        int numSelecionar;
        printf("Quantas cidades voce deseja incluir no seu roteiro?\n");
        scanf("%d", &numSelecionar);
        getchar();

        if((numSelecionar < 1) && (numSelecionar > max_c)) {
            printf("Número de cidades inválido\n");
            printf("Digte um numero entre 1 a %d", max_c);
            return;
        }

        int cidadesSelecionadas[numSelecionar];
            printf("Selecione as cidades de acordo com seu indice:\n");
            for (int i = 0; i < tamN; i++){
                printf("%d. %s\n", cidades[i].index_c, cidades[i].nome);
            }
            for(int j = 0; j < numSelecionar;j++){
                printf("Selecione a %dº cidade: ", j + 1);
                scanf("%d", &cidadesSelecionadas[j]);
                cidadesSelecionadas[j]--;

                printf("%s adicionada com sucesso!\n", cidades[cidadesSelecionadas[j]].nome);   
            }

            printf("\nRoteiro finalizado!\nSeu roteiro:\n");
            for (int i = 0; i < numSelecionar; i++){
                printf("%d. %s\n", cidades[cidadesSelecionadas[i]].index_c, cidades[cidadesSelecionadas[i]].nome);
                for(int j = 0; j < max_e; j++){
                    if(cidades[cidadesSelecionadas[i]].eventos[j].disponivel){
                        printf("\t%d. %s - %.1f\n", cidades[cidadesSelecionadas[i]].eventos[j].index_e + 1, cidades[cidadesSelecionadas[i]].eventos[j].nome, cidades[cidadesSelecionadas[i]].eventos[j].avaliacao);
                    }
                }
            }
    }
    else{
        printf("Opção inválida!\n");
    }
}

void EventosAleatorios(TCidades *cidades){
    int numCidades = max_c;
    int indiceC = rand() % numCidades;
    int indiceE = rand () % max_e;

    *cidades = cidades[indiceC];

    cidades -> eventos[indiceE].disponivel = !cidades -> eventos[indiceE].disponivel;

    if (cidades->eventos[indiceE].disponivel){
        printf("\nNOTÍCIA: O evento '%s' em %s está disponível novamente!\n", cidades->eventos[indiceE].nome, cidades -> nome);
    } else{
        printf("\nNOTÍCIA: O evento '%s' em %s foi temporariamente cancelado!\n", cidades->eventos[indiceE].nome, cidades -> nome);
    }
}