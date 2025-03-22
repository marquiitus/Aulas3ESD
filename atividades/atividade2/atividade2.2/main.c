//Marcos Ferreira de Souza

//importação de bibliotecas
#include <stdio.h>
#include "UnidadeDeTempo.h"

//definição de constantes
#define TAM 3

//definição de tipos
struct tat {
    char nome[30];
    int cod;
    UniTempo *tempo;
};
typedef struct tat tAtleta;

//protótipos das funções
void obtemAtleta (int num, tAtleta *atleta);
void horario (UniTempo *tempo, int *horas, int *minutos, int *segundos);
int divisaoInteira (int dividendo, int divisor, int* quoc, int* resto);

int main() {
  
  //declaração de variáveis
  tAtleta vAtletas[TAM];
  int tempo_horas, tempo_minutos, tempo_segundos;
    
  for (int contador = 0; contador < TAM; contador++) {  //pedindo ao usuário as informações de cada atleta
    
    obtemAtleta(contador + 1, &vAtletas[contador]);
  
    horario(vAtletas[contador].tempo, &tempo_horas, &tempo_minutos, &tempo_segundos);
    printf("\nTempo do %dº atleta foi %02ih:%02im:%02is\n", contador + 1, tempo_horas, tempo_minutos, tempo_segundos);
    }

  for (int i = 0; i < TAM; i++)  //liberando memória dos tempos alocados dinamicamente
  liberar(vAtletas[i].tempo);
    
  return 0;
}

//Funções
void obtemAtleta(int num, tAtleta *atleta) {
  
  int horas, minutos, segundos;

  printf("\nEntre com o nome do atleta: ");
  scanf(" %s", atleta->nome);

  printf("\nEntre com o código do %dº atleta: ", num);
  scanf("%d", &atleta->cod);

  printf("\nEntre com o tempo do %dº atleta (horas minutos segundos): ", num);
  scanf("%d %d %d", &horas, &minutos, &segundos);

  atleta->tempo = criar(horas, minutos, segundos);
}

void horario(UniTempo* tempo, int *horas, int *minutos, int *segundos) {
  
  int totalSegundos = tempo->tempos[0] * 3600 + tempo->tempos[1] * 60 + tempo->tempos[2];

  divisaoInteira(totalSegundos, 3600, horas, &totalSegundos);
  divisaoInteira(totalSegundos, 60, minutos, segundos);
}

int divisaoInteira(int dividendo, int divisor, int *quoc, int *resto) {
  
  if (divisor == 0) {
    
    return (dividendo == 0) ? 0 : -1;  //operador ternário
  }
  
  *quoc = dividendo / divisor;
  *resto = dividendo % divisor;
  return 1;
}