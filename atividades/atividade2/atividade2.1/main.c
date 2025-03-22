//Marcos Ferreira de Souza

//importação de bibliotecas
#include <stdio.h>
#include "ponto.h"

int main() {

  ponto *p1 = pto_cria(2.0, 7.2), *p2 = pto_cria(4.6, 1.3);

  pto_exibe(p1);
  pto_exibe(p2);
  
  int resultado = pto_menorque(p1, p2);
  
  if(resultado==1) {
      
    printf("\nPonto 1 está mais proximo da origem!\n");  
  } else {
      
    printf("\nPonto 1 está mais distante da origem!\n"); 
  }

  return 0;
}