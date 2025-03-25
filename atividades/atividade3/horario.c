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
  return h;  //sempre retornar no final da criação
}

void imprimirHorario (Horario* horario) {  //Exibe o horário no formato HH:MM.

  while(horario->horas>23 || horario->minutos>59) {

    int horasRestantes = horario->horas;
  }

  printf("%02d:%02d", horario->horas, horario->minutos);
} 

void destruirHorario (Horario* horario) {  //Libera a memória alocada para Horario.

  if(horario!=NULL)
    free(horario);
}

//reforçar entendimento
void somarMinutos (Horario* horario, int minutos) {  //Adiciona minutos ao horário, ajustando corretamente as horas.

  horario->minutos += minutos;
  while(horario->minutos>=60) {

    horario->minutos -= 60;
    horario->horas++;
  }
}  

//reforçar entendimento
void subtrairMinutos (Horario* horario, int minutos) {  //Subtrai minutos, retrocedendo corretamente as horas.

  horario->minutos -= minutos;
  while(horario->minutos<0) {

    horario->minutos += 60;
    horario->horas--;
  }
}

void acessarHorario (Horario* novoHorario, int *hora, int *minuto) {

  *hora = novoHorario->horas;
  *minuto = novoHorario->minutos;
}

void atribuirHorario (Horario* novoHorario, int hora, int minuto) {

  novoHorario->horas = hora;
  novoHorario->minutos = minuto;
}

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* horario_getHorario (Horario* horario) {

  char* pt;
  int tam = sizeof(*p1)+ 8;
  
  pt = (char*)malloc(tam);
  sprintf(pt,"( %.2f , %.2f )", p1->x, p1->y);
  
  return pt;
}