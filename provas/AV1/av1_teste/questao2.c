/* QUESTÃO 3) 2.0 pontos
Construa uma função que receba duas listas, caso a primeira seja sublista da segunda, retire-a da segunda
Ex: l1�� {1,3,5,7} l2-&gt; {1,2,3,4,5,6,7} l não é uma sublista de l2
l1�� {1,4,2,} l2-&gt; {1,2,,4,5,1,4,2,7} l1 é uma sublista de l2 */

#include <stdio.h>

int subLista(int l1[], int tam1, int l2[], int tam2);

int main(void) {

  int lista1[7] = {1,2,3,4,5,6,7}, lista2[8] = {1,2,4,5,1,4,2,7};
  
  if(subLista(lista1, 7, lista2, 8)==0) {

    printf("lista");
  } else{


  }
}

int subLista(int l1[], int tam1, int l2[], int tam2) {

  int ini, fim, cont=0;

  for(int j=0; j<tam2; j++) {
    for(int i=0; i<tam1; i++) {

      if(l2[j]==l1[i]) {

        ini = i;
        cont++;
      } else {

        
      }
    }
  }
}