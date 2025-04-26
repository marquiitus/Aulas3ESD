/* QUESTÃO 3) 2.0 pontos
Construa uma função que receba duas listas, caso a primeira seja sublista da segunda, retire-a da segunda
Ex: L1 - {1,3,5,7} L2 -> {1,2,3,4,5,6,7} L1 não é uma sublista de L2
L1 - {1,4,2,} L2-> {1,2,,4,5,1,4,2,7} L1 é uma sublista de L2 */

#include <stdio.h>

#define MAX 100

int subLista(int l1[], int tam1, int l2[], int *tam2) {

  int achou, posicao = -1;

  for (int i = 0; i <= *tam2 - tam1; i++) {  //ve se l1 é sub de l2

    achou = 1; // Assume que encontrou
    for (int j = 0; j < tam1; j++) {
      if (l2[i + j] != l1[j]) {
        achou = 0; // Quebrou a sequência
        break;
      }
    }

      if (achou == 1) {
          posicao = i;
          break; // Sai do loop, sublista achada
      }
  }

  // Se encontrou a sublista, remove ela
  if (posicao != -1) {
      for (i = posicao + tam1; i < *tam2; i++) {
          l2[i - tam1] = l2[i];
      }
      *tam2 = *tam2 - tam1;
      return 1; // Remoção feita
  }

  return 0; // Sublista não encontrada
}

int main() {
  int l1[] = {1, 4, 2};
  int l2[MAX] = {1, 2, 4, 5, 1, 4, 2, 7};
  int tam1 = 3, tam2 = 8;
  int i;

  printf("Antes:\nL2 = ");
  for (i = 0; i < tam2; i++) {
      printf("%d ", l2[i]);
  }

  if (subLista(l1, tam1, l2, &tam2)) {
      printf("\n\nSublista encontrada e removida!\n");
  } else {
      printf("\n\nSublista NAO encontrada!\n");
  }

  printf("\nDepois:\nL2 = ");
  for (i = 0; i < tam2; i++) {
      printf("%d ", l2[i]);
  }

  printf("\n");

  return 0;
}