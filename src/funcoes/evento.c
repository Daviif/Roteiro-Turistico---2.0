#include "../include/evento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Armazenar_Eventos(char *evento){
    char *eventos[] = {
        "Corrida de Rua", "Campeonato de Mountain Bike", "Torneio de Futebol Amador", "Maratona",
        "Campeonato de Skate", "Hackathon de Startups", "Feira de Tecnologia e Inovacao", "Workshop de Inteligencia Artificial",
        "Conferencia de Robotica", "Simposio de Programacao","Exposicao de Arte Contemporanea", "Sarau Literario",
        "Mostra de Fotografia", "Competicao de Cosplay", "Festival de Danca Folclorica", "Palestra sobre Sustentabilidade",
        "Feira de Empreendedorismo", "Treinamento de Lideranca", "Workshop de Gestao Empresarial", "Conferencia de Saude Mental",
        "Feira de Vinhos", "Festival de Cerveja Artesanal", "Competicao de Culinaria", "Feira de Produtos Organicos", "Festival de Gastronomia Mineira",
        "Show de Stand-up", "Concerto de Orquestra", "Show de Magica", "Batalha de Bandas", "Festival de Musica Eletronica", "Feira de Antiguidades",
        "Corrida de Drones", "Exibicao de Documentarios", "Simulacao de Bolsa de Valores", "Competicao de Memoria",
        "Aula de Yoga ao Ar Livre", "Workshop de Meditacao", "Treinamento de Defesa Pessoal", "Corrida de Obstaculos", "Palestra sobre Nutricao e Saude",
        "Campeonato de Volei de Praia", "Torneio de Tenis", "Corrida de Aventura", "Campeonato de Natacao", "Torneio de Basquete", "Feira de Startups",
        "Workshop de Realidade Virtual", "Conferencia de Ciberseguranca", "Simposio de Big Data", "Hackathon de Desenvolvimento de Jogos", "Exposicao de Esculturas",
        "Festival de Teatro de Rua", "Mostra de Cinema Independente", "Competicao de Grafite", "Festival de Musica Classica", "Palestra sobre Marketing Digital",
        "Feira de Carreiras", "Workshop de Financas Pessoais", "Conferencia de Educacao", "Treinamento de Vendas", "Feira de Queijos e Vinhos", "Festival de Comida de Rua",
        "Competicao de Baristas", "Feira de Produtos Artesanais", "Festival de Doces Mineiros", "Show de Ilusionismo", "Concerto de Musica de Camara", "Show de Humor",
        "Festival de Musica Indie", "Festival de Cultura Pop", "Feira de Livros", "Competicao de Robotica", "Exibicao de Curtas-Metragens", "Simulacao de Negociacoes Internacionais",
        "Competicao de Debates", "Aula de Pilates ao Ar Livre", "Workshop de Aromaterapia", "Treinamento de Primeiros Socorros", "Corrida Noturna", "Palestra sobre Saude Preventiva"
    };
    int numEventos = sizeof(eventos) / sizeof(eventos[0]);
    
    strcpy(evento, eventos[rand() % numEventos]);
} 

void Mensagens_Especiais(){
    char *mensagens[] = {
        "Dica: Priorize os eventos com avaliações acima de 9.0",
        "Super Dica: Reserve ingressos para shows com notas acima de 9.0!",
        "Imperdível: Mostra de Arte Contemporânea – Altamente recomendada!",
        "Programe-se: Exposição Fotográfica – Encante-se com as imagens!",
        "Evento Top: Festival de Música – Imperdível!",
        "Lembre-se: Eventos ao ar livre podem ser afetados pelo clima!",
        "Economia: Reserve seus ingressos com antecedência para garantir melhores preços!"
    };

    int indice = rand() % 7;
    printf("\nMENSAGEM ESPECIAL: %s\n", mensagens[indice]);
}
