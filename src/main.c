#include "funcoes/arvore.c"
#include "funcoes/cidade.c"
#include "funcoes/evento.c"
#include "funcoes/ordenacao.c"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

int main(){
    
    srand(time(NULL));
    setlocale(LC_ALL, "pt_BR.utf8");

    TCidades *cidades;
    cidades = (TCidades *)malloc(max_c * sizeof(TCidades));
    TArvore Arvore;
    Arvore.raiz = NULL;
    bool exit = false;

    printf("=== SISTEMA DE TURISMO ===\nSeja bem-vindo!\n\n");

    preencherCidades(cidades);

    printf("As cidades disponíveis sao:\n");
    for (int i = 0; i < max_c; i++) {
        TItem novoItem;
        novoItem.cidade = cidades[i]; 
        Inserir(&Arvore.raiz, NULL, novoItem);
        printf("%d. %s\n",cidades[i].index_c, cidades[i].nome);
    }

    do{
        printf("\n=== MENU ===\n");
        printf("1 - Listar Eventos\n2 - Visualizar cidades por percurso\n3 - Ordenar os eventos de uma cidade\n"
        "4 - Buscar Cidade\n5 - Buscar Eventos\n6 - Criar Roteiro Turistico\n7 - Sair\n");
        int opcao;
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                printf("Digite o número da cidade que deseja visualizar os eventos: ");
                int index;
                scanf("%d", &index);
                ListarEvento(cidades, index-1);
                Mensagens_Especiais();
                break;
            case 2:
                printf("1 - Listar inOrdem\n2 - Listar em Pre-Ordem\n3 - Listar em Pos-Ordem\n");
                int opListar;
                scanf("%d", &opListar);
                switch (opListar){
                    case 1:
                        printf("Ordenados in Ordem(Central):\n");
                        inOrdem(Arvore.raiz);
                        break;
                    case 2:
                        printf("Ordenados pre-Ordem:\n");
                        preOrdem(Arvore.raiz);
                        break;
                    case 3:
                        printf("Ordenados pos-Ordem:\n");
                        posOrdem(Arvore.raiz);
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                printf("\n1 - Bubble Sort\n2 - Selection Sort\n3 - Insertion Sort\n4 - Shell Sort\n5 - Quick Sort\n6 - Merge Sort\n7 - Heap Sort\n");
                int opOrdenar;
                scanf("%d", &opOrdenar);
                switch (opOrdenar){
                    case 1:
                        Bubble_Sort(cidades);
                        break;
                    case 2:
                        Selection_Sort(cidades);
                        break;
                    case 3:
                        Insertion_Sort(cidades);
                        break;
                    case 4:
                        Shell_Sort(cidades);
                        Mensagens_Especiais();
                        break;
                    case 5:
                        Quick_Sort(cidades);
                        break;
                    case 6:
                        Merge_Sort(cidades, 0, max_c - 1);
                        break;
                    case 7:
                        Heap_Sort(cidades);
                        Mensagens_Especiais();
                        EventosAleatorios(cidades);
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                getchar();
                char nome[100];
                printf("Digite o nome da cidade: ");
                fgets(nome, 100, stdin);
                if (nome[strlen(nome)-1] == '\n'){
                    nome[strlen(nome)-1] = '\0';
                }
                
                Pesquisar(Arvore.raiz, nome);
                EventosAleatorios(cidades);
                break;
            case 5:
                printf("Voce deseja buscar eventos por:\n1 - Nome\n2 - Avaliacaoo\n");
                int opBusca;
                scanf("%d", &opBusca);
                getchar();
                if (opBusca == 1){
                    printf("Digite o nome do Evento: ");
                    char nomeEvento[100];
                    fgets(nomeEvento, 100, stdin);
                    if (nomeEvento[strlen(nomeEvento)-1] == '\n'){
                        nomeEvento[strlen(nomeEvento)-1] = '\0';
                    }

                    TNo *x = PesquisarEv(Arvore.raiz, nomeEvento);

                    if ((x == NULL) || (Arvore.raiz -> item.cidade.eventos->disponivel == false)){
                        printf("Evento nao encontrado! Que pena!\n");
                        printf("Verifique se ele está realmente disponivel.\n");
                    }
                    Mensagens_Especiais();
                    EventosAleatorios(cidades);
                }
                else if (opBusca == 2){
                    printf("Digite a avaliacao do Evento: (0 a 10)\n");
                    int avaliacao;
                    scanf("%d", &avaliacao);
                    Buscar_EventosA(cidades, avaliacao);
                    Mensagens_Especiais();
                    EventosAleatorios(cidades);
                }
                break;
            case 6:
                CriarRoteiroViagem(cidades);
                EventosAleatorios(cidades);
                EventosAleatorios(cidades);
                break;
            case 7:
                printf("Obrigado por utilizar nosso sistema!\n");
                printf("Tenha uma boa viagem!\n");
                printf("Ate mais!\n");
                exit = true;
                break;
        } 
    } while (exit == false);
    
    return 0;
} 