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

  printf("%02d/%02d/%02d", data->dia, data->mes, data->ano);
}

void destruirData(Data *data) {  //Libera a memória alocada para uma estrutura Data.

  if(data!=NULL)
    free(data);
}  

/* A função verifica quantos dias o mês possui e ajusta corretamente a data ao
ultrapassar os limites. */
void somarDias (Data* data, int dias) {  //Adiciona um número de dias à data, ajustando corretamente os meses e anos.

  while (dias > 0) {
    
    int diasRestantes = diasNoMes(data->mes, data->ano) - data->dia;
    if (dias > diasRestantes) {
    
      dias -= (diasRestantes + 1);
      data->dia = 1;
    
      if (++data->mes > 12) {
        data->mes = 1;
        data->ano++;
      }
    } else {
      data->dia += dias;
      dias = 0;
    }
  }
}

void subtrairDias (Data* data, int dias) {  //Subtrai um número de dias da data, garantindo ajustes corretos.

  while (dias > 0) {
  
    if (dias >= data->dia) {
  
      dias -= data->dia;
      if (--data->mes < 1) {
        data->mes = 12;
        data->ano--;
      }
      data->dia = diasNoMes(data->mes, data->ano);

    } else {
      data->dia -= dias;
      dias = 0;
    }
  }  
}

// ******** FUNÇÕES AUXILIARES ********
int anoBissexto (int ano) {

  return (ano%4 == 0 && ano%100 != 0) || (ano%400 == 0);
}

int diasNoMes(int mes, int ano) {

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