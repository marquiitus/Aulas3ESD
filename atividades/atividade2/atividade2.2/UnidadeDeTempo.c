//Marcos Ferreira de Souza

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "UnidadeDeTempo.h"

//FUNÇÕES PRINCIPAIS
UniTempo *criar (int h, int m, int s) {
  
  //aloco dinamicamente mémoria para criar o Tempo
  UniTempo *t = (UniTempo*) malloc(sizeof(UniTempo));
  
  if(t==NULL) {  //verifica se foi alocado corretamente
    
    printf("\nFalta de Memória!!\n");
    exit(1);
  } 
  
  //coloca as unidades de tempo em seus respectivos endereços dentro do vetor 'tempos'
  t->tempos[0] = h;
  t->tempos[1] = m;
  t->tempos[2] = s;

  normalizarTempo(t);
  return t;
}

void exibir(UniTempo *t) {
  
  printf("%02d:%02d:%02d\n", t->tempos[0], t->tempos[1], t->tempos[2]);
}

int transformaEmSegundos(UniTempo *t) {
  return t->tempos[0] * 3600 + t->tempos[1] * 60 + t->tempos[2];
}

UniTempo *criarDeSegundos(int totalSegundos) {
 
  int h, m, s;
 
  divisaoInteira(totalSegundos, 3600, &h, &totalSegundos);
  divisaoInteira(totalSegundos, 60, &m, &s);
 
  return criar(h, m, s);
}

UniTempo *somarTempos(UniTempo *t1, UniTempo *t2) {
 
  int totalSegundos = transformaEmSegundos(t1) + transformaEmSegundos(t2);
 
  return criarDeSegundos(totalSegundos);
}

UniTempo *subtrairTempos(UniTempo *t1, UniTempo *t2) {
  
  int seg1 = transformaEmSegundos(t1);
  int seg2 = transformaEmSegundos(t2);
  int diferenca;

  if(seg1>seg2) {

    diferenca = seg1 - seg2;
  } else {

    diferenca = seg2 - seg1;
  }
  
  return criarDeSegundos(diferenca);
}

UniTempo *copiarTempo(UniTempo *t) {
  
  return criar(t->tempos[0], t->tempos[1], t->tempos[2]);
}

int comparar_tempos(UniTempo *tempo1, UniTempo *tempo2) {
  
  int seg1 = transformaEmSegundos(tempo1), seg2 = transformaEmSegundos(tempo2);
  
  if(seg1<seg2) {
    
    return -1;
  } else if(seg1==seg2) {
    
    return 0;
  } else {
    
    return 1;
  }
}

//FUNÇÕES AUXILIARES
void liberar(UniTempo *t) {
  if(t!=NULL)
  free(t);
}

void normalizarTempo(UniTempo *t) {

  if(t->tempos[2] >= 60) {  //ajusta segundos para minutos

    t->tempos[1] += t->tempos[2] / 60;
    t->tempos[2] %= 60;
  }

  if (t->tempos[2] < 0) {
  
    t->tempos[1] -= 1;
    t->tempos[2] += 60;
  }

  if (t->tempos[1] >= 60) {  //Ajusta minutos para horas
  
    t->tempos[0] += t->tempos[1] / 60;
    t->tempos[1] %= 60;
  }
  
  if (t->tempos[1] < 0) {
  
    t->tempos[0] -= 1;
    t->tempos[1] += 60;
  }

  if (t->tempos[0] < 0) {  //Evita valores negativos nas horas
  
    t->tempos[0] = (t->tempos[0]%24 + 24) % 24; 
  }
}