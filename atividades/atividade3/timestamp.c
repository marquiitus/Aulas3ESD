//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "horario.h"
#include "timestamp.h"

//definição de struct
typedef struct timestamp{
  Data* data;
  Horario* horario;
};

// ******** FUNÇÕES PRINCIPAIS ********
Timestamp* criarTimestamp (int dia, int mes, int ano, int hora, int minuto) {  //Cria um timestamp com Data e Horário.

  Timestamp* novoTimestamp = (Timestamp*) malloc(sizeof(Timestamp));
  if(novoTimestamp==NULL) {

    printf("\n\nMemoria Insuficiente!\n");
    free(novoTimestamp);
    exit(1);
  }

  novoTimestamp->data = criarData(dia, mes, ano);
  if(novoTimestamp->data==NULL) {

    printf("\n\nMemoria Insuficiente!\n");
    free(novoTimestamp->data);
    free(novoTimestamp);
    exit(1);
  }

  novoTimestamp->horario = criarHorario(hora, minuto);
  if(novoTimestamp->horario==NULL) {

    printf("\n\nMemoria Insuficiente!\n");
    free(novoTimestamp->horario);
    free(novoTimestamp->data);
    free(novoTimestamp);
    exit(1);
  }

  return novoTimestamp;
}

void imprimirTimestamp (Timestamp* timestamp) {  //Exibe data e horário no formato DD/MM/AAAA HH:MM.
  imprimirData(timestamp->data);
  printf(" ");
  imprimirHorario(timestamp->horario);
}

void destruirTimestamp (Timestamp* timestamp) {  //Libera memória da estrutura Timestamp.
  if(timestamp!=NULL)
    destruirData(timestamp->data);
    destruirHorario(timestamp->horario);
    free(timestamp);
}

void somarMinutosTimestamp (Timestamp* timestamp, int minutos) {  //Adiciona minutos ao timestamp, ajustando data e horário.

  int hora, minuto, vezes;
  somarMinutos(timestamp->horario, minutos);

  horario_acessa(timestamp->horario, &hora, &minuto);
  if(hora>24) {

    vezes = hora%24;
    subtrairMinutos(timestamp->horario, 1440 * vezes);
    somarDias(timestamp->data, 1 * vezes);
  }
}

void subtrairMinutosTimestamp (Timestamp* timestamp, int minutos) {  //Subtrai minutos, garantindo consistência entre data e horário.

  int hora, minuto, vezes;
  subtrairMinutos(timestamp->horario, minutos);
  
  horario_acessa(timestamp->horario, &hora, &minuto);
  if(hora<0) {

    vezes = 24 - hora;
    subtrairDias(timestamp->data, 1 * vezes);
    somarMinutos(timestamp->horario, 60 * vezes);
  }
}

char* timestamp_getTimestamp (Timestamp* timestamp) {

  char* dataStr = data_getData(timestamp->data);  
  char* horarioStr = horario_getHorario(timestamp->horario);  

  char* pt = (char*) malloc(17);  // "DD/MM/AAAA HH:MM\0" = 17 bytes
  if (pt == NULL) {
    printf("\n\nMemória Insuficiente!\n");
    free(dataStr);
    free(horarioStr);
    exit(1);
  }

  sprintf(pt, "%s %s", dataStr, horarioStr);

  free(dataStr);  // Libera a memória das strings temporárias
  free(horarioStr);

  return pt; 
}

void timestamp_acessa (Timestamp* timestamp, int *horas, int *minutos) {
  timestamp->horario->horas = *horas;
  timestamp->horario->minutos = *minutos;
}

void timestamp_atribui (Timestamp* timestamp, int horas, int minutos) {
  timestamp->horario->horas = horas;
  timestamp->horario->minutos = minutos;
}