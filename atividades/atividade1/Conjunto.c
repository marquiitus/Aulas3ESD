/*Nome completo: Marcos Ferreira de Souza*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "Conjunto.h"

//definição de constantes
#define TAM 80

//definição de tipos
struct conj {
    int vetor[80];
    int quant;
};

// ******** FUNÇÕES ********
int buscar(Conjunto *c, int num);

Conjunto * conj_cria(void) {
    
  Conjunto *conju = malloc(sizeof(Conjunto));
  if (conju == NULL) {  
        
    printf("Sem memória!");
    exit(1);
  }

  conju->quant = 0;

  return conju;
}

void conj_exibe(Conjunto *lst) {
    
  printf("{");
    
  //exibindo os elementos através do loop for
  for(int i=0; i < lst->quant-1;i++) {
        
    printf("%d, ", lst->vetor[i]);
  }
    
  printf("%d}", lst->vetor[lst->quant - 1]);
}

Conjunto* conj_excluir(Conjunto *conj, int valor) {
    
  int posicao = buscar(conj, valor);
    
  if (posicao != -1) {
        
    for (int i = posicao; i < conj->quant - 1; i++) {
            
      conj->vetor[i] = conj->vetor[i + 1];
    }
        
    conj->quant--;
  }
    
  return conj;
}

Conjunto * conj_uniao(Conjunto *a, Conjunto *b) {
    
  Conjunto *resultado = conj_cria();
    
  for (int i = 0; i < a->quant; i++) {
        
    conj_insere(resultado, a->vetor[i]);
  }

  for (int i = 0; i < b->quant; i++) {
        
    conj_insere(resultado, b->vetor[i]);
  }

  return resultado;
}


Conjunto * conj_intersecao(Conjunto* a, Conjunto* b) {
    
  Conjunto *interseccao = conj_cria();
    
  for (int i=0; i<a->quant; i++) {
        
    if (buscar(b, a->vetor[i]) != -1) {
            
      conj_insere(interseccao, a->vetor[i]);
    }
  }

  return interseccao;
}


Conjunto* conj_insere (Conjunto* conj, int valor) {

  if (buscar(conj, valor) == -1 && conj->quant < TAM) {
        
    conj->vetor[conj->quant++] = valor;
  }
  
  return conj;
}


//******** FUNÇÕES AUXILIARES ********
int buscar(Conjunto *c, int num) {
    
  for (int i=0; i<c->quant; i++) {
        
    if (c->vetor[i] == num) {
            
      return i;  //se achar, retorna sua posição
    } 
  }
    
  return -1;  //se não achar nenhum elemento igual
}