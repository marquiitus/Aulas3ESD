//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "horario.h"

// ******** FUNÇÕES PRICIPAIS ********
Horario *criarHorario (int hora, int minuto) {  //Cria e inicializa um Horario.

  Horario* novoHorario = (Horario*) malloc(sizeof(Horario));
  if(novoHorario==NULL) {

    printf("\n\nMemoria Insuficiente!\n");
    free(novoHorario);
    exit(1);
  }

  novoHorario->horas = hora;
  novoHorario->minutos = minuto;
}

void imprimirHorario (Horario* horario) {  //Exibe o horário no formato HH:MM.

  printf("%02d:%02d", horario->horas, horario->minutos);
} 

void destruirHorario (Horario* horario) {  //Libera a memória alocada para Horario.

  if(horario!=NULL)
    free(horario);
}

void somarMinutos (Horario* horario, int minutos) {  //Adiciona minutos ao horário, ajustando corretamente as horas.

  horario->minutos += minutos;
  while (horario->minutos >= 60) {  
    horario->minutos -= 60;
    horario->horas++;
  }
}  

void subtrairMinutos (Horario* horario, int minutos) {  //Subtrai minutos, retrocedendo corretamente as horas.

  horario->minutos -= minutos;
  while (horario->minutos < 0) {
    horario->minutos += 60;
    horario->horas--;
  }
}

char* horario_getHorario (Horario* horario) {  //Retorna uma string com os valores do horário

  char* pt = (char*) malloc(6);  //"HH:MM\0" = 6 bytes

  if(pt==NULL) {

    printf("\n\nMemória Insuficiente!\n");
    free(pt);
    exit(1);
  }
  
  sprintf(pt, "%02d:%02d", horario->horas, horario->minutos);
  return pt;
}

void horario_acessa (Horario* horario, int *horas, int *minutos) {   //Retorna os valores de um horário

  *horas = horario->horas;
  *minutos = horario->minutos;
} 

void horario_atribui (Horario* horario, int horas, int minutos) {  //Atribui novos valores à um horário

  horario->horas = horas;
  horario->minutos = minutos;
}