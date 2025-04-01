//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "data.h"

// ******** FUNÇÕES PRICIPAIS ********
Data* criarData (int dia, int mes, int ano) {  //Aloca e inicializa uma estrutura Data

  Data* novoDia = (Data*) malloc(sizeof(Data));
  if(novoDia==NULL) {

    printf("\n\nMemoria Insuficiente!\n");
    free(novoDia);
    exit(1); 
  }

  novoDia->dia = dia;
  novoDia->mes = mes;
  novoDia->ano = ano;
  return novoDia;
}

void imprimirData (Data* data) {  //Exibe a data no formato DD/MM/AAAA

  printf("%02d/%02d/%02d", data->dia, data->mes, data->ano);
}

void destruirData(Data *data) {  //Libera a memória alocada para uma estrutura Data

  if(data!=NULL)
    free(data);
}  

// A função verifica quantos dias o mês possui e ajusta corretamente a data ao ultrapassar os limites
void somarDias (Data* data, int dias) {  //Adiciona um número de dias à data, ajustando corretamente os meses e anos

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

void subtrairDias (Data* data, int dias) {  //Subtrai um número de dias da data, garantindo ajustes corretos

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

char* data_getData (Data* data) {  //Retorna uma string com os valores da data

  char* pt = (Data*) malloc(11);  // DD/MM/AAAA\0 = 11 bytes
  if(pt==NULL) {

    printf("\n\nMemoria Insuficiente!\n");
    free(pt);
    exit(1);
  }

  sprintf(pt, "%02d/%02d/%04d", data->dia, data->mes, data->ano);
  return pt;
}

void data_acessa (Data* data, int *dia, int *mes, int *ano) {  //Retorna os valores de uma data
  *dia = data->dia;
  *mes = data->mes;
  *ano = data->ano;
}

void data_atribui (Data* data, int dia, int mes, int ano) {  //Atribui novos valores à uma data
  data->dia = dia;
  data->mes = mes;
  data->ano = ano;
}

// ******** FUNÇÕES AUXILIARES ********
int anoBissexto (int ano) {
  return (ano%4 == 0 && ano%100 != 0) || (ano%400 == 0);
}

int diasNoMes(int mes, int ano) { 
  int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
  
  if (mes == 2 && ehBissexto(ano)) return 29; 
    return diasMes[mes - 1]; 
} 