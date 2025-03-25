#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct data {
  int dia, mes, ano;
};

// ******** FUNÇÕES PRICIPAIS ********
Data* criarData (int dia, int mes, int ano) {  //Aloca e inicializa uma estrutura Data.

  Data* d = (Data*) malloc(sizeof(Data));
  if(d==NULL) {

    printf("\n\nMemoria Insuficiente!\n");
    exit(1); 
  }

  d->dia = dia;
  d->mes = mes;
  d->ano = ano;
  return d;
}

void imprimirData (Data* data) {  //Exibe a data no formato DD/MM/AAAA.

  printf("%02d/%02d/%04d", data->dia, data->mes, data->ano);
}

void destruirData(Data *data) {  //Libera a memória alocada para uma estrutura Data.

  if(data!=NULL)
    free(data);
}  

/* A função verifica quantos dias o mês possui e ajusta corretamente a data ao
ultrapassar os limites. */
void somarDias (Data* data, int dias) {  //Adiciona um número de dias à data, ajustando corretamente os meses e anos.


}

void subtrairDias (Data* data, int dias) {  //Subtrai um número de dias da data, garantindo ajustes corretos.

  
}

// ******** FUNÇÕES AUXILIARES ********
int anoBissexto (int ano) {

  return (ano%4 == 0 && ano%100 != 0) || (ano%400 == 0);  //sempre lembrar de pode retornar verdadeiro ou falso com uma linha de código
}

int diasNoMes(int mes, int ano) {  //melhorar isso com um vetor

  if(mes<7) {

    if(mes==2) {

      if(anoBissexto(ano)==0)
      return 28;

      return 29;
    }

    if(mes%2!=0) 
      return 31;
    else
      return 30;
  }

  if(mes%2==0 || mes==7)
    return 31;

  return 30;
}