#include "funcoes/arvore.c"
#include "funcoes/cidade.c"
#include "funcoes/evento.c"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
int main(){
    
    srand(time(NULL));

    TCidades cidades[max_c];
    TArvore Arvore;
    Arvore.raiz = NULL;
    bool exit = false;

    printf("Cidades geradas na Arvore.\n");

    preencherCidades(cidades);

    for (int i = 0; i < max_c; i++) {
        TItem novoItem;
        novoItem.cidade = cidades[i]; 
        Inserir(&Arvore.raiz, NULL, novoItem);

        printf("\nCidade: %s\n", cidades[i].nome);
        printf("Eventos: \n");
        for (int j = 0; j < max_e; j++)
        {
            printf(" %s - Nota: %.1f\n", cidades[i].eventos[j].nome, cidades[i].eventos[j].avaliacao);
        }
        
    }

    do
    {
        printf("\n1 - Visualizacao - Listar em Ordem\n2 - Metodos de Ordenacao\n3 - Buscar na Arvore\n5 - Navegar na arvore\n6 - Sair\n");
        int opcao;
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                printf("1 - Listar inOrdem\n2 - Listar em Pre-Ordem\n3 - Listar em Pos-Ordem\n");
                int opcao2;
                scanf("%d", &opcao2);
                switch (opcao2){
                    case 1:
                        inOrdem(Arvore.raiz);
                        break;
                    case 2:
                        preOrdem(Arvore.raiz);
                        break;
                    case 3:
                        posOrdem(Arvore.raiz);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                printf("\n1 - Bubble Sort\n2 - Selection Sort\n3 - Insertion Sort\n4 - Shell Sort\n5 - Quick Sort\n6 - Merge Sort\n7 - Heap Sort\n");
                /*int opcao3;
                scanf("%d", &opcao3);
                switch (opcao3){
                    case 1:
                        BubbleSort(cidades);
                        break;
                    case 2:
                        SelectionSort(cidades);
                        break;
                    case 3:
                        InsertionSort(cidades);
                        break;
                    case 4:
                        ShellSort(cidades);
                        break;
                    case 5:
                        QuickSort(cidades);
                        break;
                    case 6:
                        MergeSort(cidades);
                        break;
                    case 7:
                        HeapSort(cidades);
                        break;
                    default:
                        break;
                }
                break;*/
            case 3:
                printf("Você deseja buscar por:\n1 - Cidade\n2 - Evento\n");
                int opcao4;
                scanf("%d", &opcao4);
                if (opcao4 == 1){
                    /* code */
                }
                
                
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                exit = true;
                break;
        } 
    } while (exit == false);
    
    return 0;
} 