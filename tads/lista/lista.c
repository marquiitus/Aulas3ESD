//importação de bibliotecas 
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Em seguida, um tipo para a lista */ 
struct tipo_lista {
  int* vNos; 
  int qtNos; 
  int maximo; 
  int ehClassificada; // 1: classificada; 0: não classificada 
  int temRepeticao; // 1: com repetição; 0: sem repetição 
}; 

/*cria lista vazia*/ 
tLista * cria_lista_vazia(int maximo, int classif, int repet) {
    
  tLista *pl = (tLista*) malloc(sizeof(tLista));
	
  pl->vNos = (int*) malloc(sizeof(int) * maximo);  //antes o que era apenas um ponteiro para um inteiro, virou um vetor...
	pl->qtNos = 0;
  pl->maximo = maximo;
  pl->ehClassificada = classif;
  pl->temRepeticao = repet; 
  
  return pl;
} 
 
int lista_vazia (const tLista *pl){  //lista está vazia?
  return ( pl->qtNos == 0); 
}

int lista_cheia (const tLista *pl){  //lista está cheia? 
  return ( pl->qtNos == pl->maximo); 
} 
 
int lista_repet (const tLista *pl) {  //lista com repetição?
  return ( pl->temRepeticao == 1); 
} 
 
int lista_classif( const tLista *pl){  //lista classificada?
  return ( pl->ehClassificada == 1); 
} 
 
void percorre(const tLista *pl) {  //percorre a lista e imprimi seus elementos
  for(int i = 0; i < pl->qtNos; i++) 
    printf("\n%d", pl->vNos[i]); 
} 

// ******** FUNÇÕES AUXILARES ********
int busca_des_srep(tLista *pl, int chave, int *pos) {  //Busca DESORDENADA sem repetição  
  
  int i; 
  for(i=0; (i<pl->qtNos)&&(pl->vNos[i]!=chave); i++)
    (*pos) = i; 

  return(i < pl->qtNos); 
} 

int busca_bin(tLista *pl, int chave, int *pos) {  //Busca Binária
  
  int inicio = 0, meio, fim = pl->qtNos - 1, achou = 0; 
  
  while((inicio <= fim) && (!achou)) { 
   
    meio = (inicio + fim) / 2; 
    if(pl->vNos[meio] == chave) 
      achou = 1; 
    else if(pl->vNos[meio] > chave) 
      fim = meio - 1; 
    else 
      inicio = meio + 1; 
  } 

  if(achou) 
    (*pos) = meio; 
  else 
    (*pos) = inicio; 
    
  return achou; 
} 

void chegaparaca(tLista *pl, int pos, int qt) {  //Para a esquerda

  int qtd = pl->qtNos - pos - qt;

  memcpy(&pl->vNos[pos], &pl->vNos[pos + qtd], sizeof(int) * qtd);
} 

void chegaparala(tLista *pl, int pos) {  //Para a direita

  int qtd = pl->qtNos - pos;

  memcpy(&pl->vNos[pos+1], pl->vNos[pos], sizeof(int) * qtd);  
}