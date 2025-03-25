#include <stdio.h>
#include <stdlib.h>
#include "horario.h"

struct horario {
  int horas, minutos;
};

Horario *criarHorario (int hora, int minuto) {  //Cria e inicializa um Horario.

  Horario* h = (Horario*) malloc(sizeof(Horario));
  if(h==NULL) {

    printf("\n\nMemoria Insuficiente!\n");
    exit(1);
  }

  h->horas = hora;
  h->minutos = minuto;
}

void imprimirHorario (Horario* horario) {  //Exibe o horário no formato HH:MM.

  printf("%02d:%02d", horario->horas, horario->minutos);
} 

void destruirHorario (Horario* horario) {  //Libera a memória alocada para Horario.

  if(horario!=NULL)
    free(horario);
}

void somarMinutos (Horario* horario, int minutos) {  //Adiciona minutos ao horário, ajustando corretamente as horas.


}  

void subtrairMinutos (Horario* horario, int minutos) {  //Subtrai minutos, retrocedendo corretamente as horas.


}