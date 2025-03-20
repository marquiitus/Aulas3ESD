/*1) Altere a implementação do TAD Ponto, armazenando os atributos(x,Y) em um vetor */

#include <stdio.h>
#include "ponto.h"

int main() {

  Ponto *p1 = pto_cria(2,7), *p2 = pto_cria(4,1);

  pto_exibe(p1);
  pto_exibe(p2);

  return 0;
}