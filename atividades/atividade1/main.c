/*Nome completo: Marcos Ferreira de Souza*/

//importação de bibliotecas
#include <stdio.h>
#include "Conjunto.c"

int main() {
    
  //declaração de variáveis
  Conjunto *diasJose = conj_cria(), *diasValeria = conj_cria(), *diasMarlene = conj_cria();
    
  //inserindo elementos nos conjuntos de dias de cada pessoa
  for(int i=2; i<29; i++) 
  conj_insere(diasJose, i);
    
  for(int i=1; i<26; i++)
  conj_insere(diasValeria, i);
      
  for(int i=5; i<31; i++) 
  conj_insere(diasMarlene, i);
    
  //realizando as operações para saber quais dias são válidos
  Conjunto *diasPossiveis = conj_intersecao(diasValeria, diasMarlene);
  diasPossiveis = conj_intersecao(diasPossiveis, diasJose);
    
  //exibindo o resultado
  printf("\n\nLogo, os dias possiveis para todos puderem viajar eh: \n");
  conj_exibe(diasPossiveis);

  return 0;
}