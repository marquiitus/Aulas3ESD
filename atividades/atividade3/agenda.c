#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

Agenda *criarAgenda(int capacidadeInicial) {
  if (capacidadeInicial <= 0) {
    capacidadeInicial = 10; // Capacidade padrão
  }
    
  Agenda *novaAgenda = (Agenda *)malloc(sizeof(Agenda));
  if (novaAgenda == NULL) {
    return NULL; // Falha na alocação de memória
  }
    
  novaAgenda->compromissos = (Compromisso **)malloc(capacidadeInicial * sizeof(Compromisso *));
  if (novaAgenda->compromissos == NULL) {
    free(novaAgenda);
    return NULL; // Falha na alocação de memória
  }
    
  novaAgenda->tamanho = 0;
  novaAgenda->capacidade = capacidadeInicial;
    
  return novaAgenda;
}

void adicionarCompromisso(Agenda *agenda, Compromisso *compromisso) {
  if (agenda == NULL || compromisso == NULL) {
    return;
  }
    
  // Verifica se precisa redimensionar o vetor
  if (agenda->tamanho >= agenda->capacidade) {
    int novaCapacidade = agenda->capacidade * 2;
    Compromisso **novosCompromissos = (Compromisso **)realloc(agenda->compromissos, 
                                                             novaCapacidade * sizeof(Compromisso *));
    if (novosCompromissos == NULL) {
      return; // Falha no redimensionamento
    }
        
    agenda->compromissos = novosCompromissos;
    agenda->capacidade = novaCapacidade;
  }
  agenda->compromissos[agenda->tamanho] = compromisso;
  agenda->tamanho++;
}

void listarCompromissos(Agenda *agenda) {
  if (agenda == NULL) {
    return;
  }
    
  printf("\nLista de Compromissos (%d):\n", agenda->tamanho);
  for (int i = 0; i < agenda->tamanho; i++) {
    printf("%d. ", i + 1);
    imprimirCompromisso(agenda->compromissos[i]);
  }
    
  if (agenda->tamanho == 0) {
    printf("Nenhum compromisso agendado.\n");
  }
}

void removerCompromisso(Agenda *agenda, int indice) {
  if (agenda == NULL || indice < 0 || indice >= agenda->tamanho) {
    return;
  }
    
  // Libera a memória do compromisso
  destruirCompromisso(agenda->compromissos[indice]);
    
  // Desloca os compromissos para preencher o espaço
  for (int i = indice; i < agenda->tamanho - 1; i++) {
    agenda->compromissos[i] = agenda->compromissos[i + 1];
  }
    
  agenda->tamanho--;
}

void consultarCompromissosPorData(Agenda *agenda, int dia, int mes, int ano) {
  if (agenda == NULL) {
    return;
  }
    
  printf("\nCompromissos em %02d/%02d/%04d:\n", dia, mes, ano);
  int encontrados = 0;
    
  for (int i = 0; i < agenda->tamanho; i++) {
    Compromisso *comp = agenda->compromissos[i];
    if (comp->timestamp->data->dia == dia && 
        comp->timestamp->data->mes == mes && 
        comp->timestamp->data->ano == ano) {
          printf("%d. ", encontrados + 1);
          imprimirCompromisso(comp);
          encontrados++;
    }
  }
    
  if (encontrados == 0) {
    printf("Nenhum compromisso encontrado nesta data.\n");
  }
}

void alterarHorarioCompromisso(Agenda *agenda, int indice, int minutos, int adiar) {
  if (agenda == NULL || indice < 0 || indice >= agenda->tamanho || minutos <= 0) {
    return;
  }
    
  Compromisso *comp = agenda->compromissos[indice];
    
  if (adiar) {
    adiarCompromisso(comp, minutos);
  } else {
    anteciparCompromisso(comp, minutos);
  }
}

void destruirAgenda(Agenda *agenda) {
  if (agenda == NULL) {
    return;
  }
    
  // Libera a memória de cada compromisso
  for (int i = 0; i < agenda->tamanho; i++) {
    destruirCompromisso(agenda->compromissos[i]);
  }
    
  // Libera o vetor de compromissos e a agenda
  free(agenda->compromissos);
  free(agenda);
}