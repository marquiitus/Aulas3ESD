#include <stdio.h>

#define TAM 10

int buscaBinaria(int n, int vetor[], int quant);

int main(void) {

  int vetor[TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, num, resultado;

  printf("\n\nEntre com um número a ser encontrado num vetor linear: ");
  scanf("%d", &num);

  resultado = buscaBinaria(num, vetor, TAM);

  if(resultado>=0) {

    printf("\n\nSeu numero foi encontrado na posicao %d\n", resultado);
  } else {

    printf("\n\nSeu numero nao foi encontrado em nenhum posicao do vetor!\n");
  }
}

int buscaBinaria(int n, int vetor[], int quant) {

  for(int i=(quant/2)-1; ; i++) {


  }

  while() {


  }

  return -1;
}