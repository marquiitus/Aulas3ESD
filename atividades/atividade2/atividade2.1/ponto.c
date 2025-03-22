//Marcos Ferreira de Souza

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

/* Implementação TAD: Ponto (x,y) */

/*definição das funções exportadas*/ 
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
ponto *pto_cria (float x, float y) {
  
  ponto *p = (ponto*) malloc(sizeof(ponto));
  if (p == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }
  
  (*p)[0] = x;
  (*p)[1] = y;
  return p;
}

/* Função copia -  retorna um novo  ponto com coordenadas do ponto recebido*/
ponto *pto_copia(ponto *p){
  return pto_cria((*p)[0], (*p)[1]);
}

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(ponto *p){
  free(p);
}   

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(ponto *p, float *x, float *y) {
  *x = (*p)[0];
  *y = (*p)[1];
}

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(ponto *p, float x, float y) {
  (*p)[0] = x;
  (*p)[1] = y;
}

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(ponto *p1, ponto *p2) {
  
  float dx = (*p2)[0] - (*p1)[0];
  float dy = (*p2)[1] - (*p1)[1];

  return sqrt(dx*dx + dy*dy);
}

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(ponto *p1) {
  
  char *pt;
  int tam = sizeof(*p1) + 8;
  
  pt = (char*) malloc(tam);
  sprintf(pt,"( %.2f , %.2f )", (*p1)[0], (*p1)[1]);
  
  return pt;
}

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(ponto *p) {
  printf(" (%f, %f) ", (*p)[0], (*p)[1]);
}

/* Função menorque -recebe dois pontos e retorna 1 se o pt1 está mais pr´ximo da origem, 0 cc*/
int pto_menorque(ponto *pt1, ponto *pt2){
  
  ponto *origem = pto_cria(0,0);
  
  float distpt1_Orig = pto_distancia(pt1,origem);
  float distpt2_Orig = pto_distancia(pt2,origem);
  
  pto_libera(origem);
 
  return distpt1_Orig < distpt2_Orig;
}