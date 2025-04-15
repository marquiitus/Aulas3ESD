//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"

/* Implementação TAD: Ponto (x,y) */
/*definição do tipo exportado*/ 
struct ponto {
  double x;
  double y;
};

/*definição das funções exportadas*/ 
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y){
  
  Ponto* p = (Ponto*) malloc(sizeof(Ponto));
  if (p == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }
  
  p->x = x;
  p->y = y;
  
  return p;
}

/* Função copia -  retorna um novo  ponto com coordenadas do ponto recebido*/
Ponto* pto_copia (Ponto* p){
  return pto_cria(p->x, p->y);
}

Ponto* pto_clona (Ponto* pOrigem) {
  
  Ponto* pClonado = (Ponto*) malloc(sizeof(Ponto));
  if(pClonado==NULL) {
    
    printf("\n\nMemória Insuficiente!\n");
    exit(1);
  }
  
  pClonado->x = pOrigem->x;
  pClonado->y = pOrigem->y;
}           

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(Ponto* p) {
  free(p);
}

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y) {
  *x=p->x;
  *y=p->y;
}

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y) {
  p->x=x;
  p->y=y;
}

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2) {
  
  float dx = p2->x - p1->x;
  float dy = p2->y - p1->y;
  
  return sqrt(dx*dx + dy*dy);
}

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto (Ponto* p1) {
  
  char* pt;
  int tam = sizeof(*p1)+ 8;
  pt = (char*)malloc(tam);
  
  sprintf(pt,"( %.2f , %.2f )", p1->x, p1->y);
  
  return pt;
}

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe (Ponto* p) {
  printf(" (%f,%f) ", p->x, p->y);
}

/* Função menorque -recebe dois pontos e retorna 1 se o pt1 está mais próximo da origem, 0 cc*/
int pto_menorque (Ponto* pt1, Ponto* pt2){
  
  Ponto * origem=pto_cria(0,0);
  float distpt1_Orig=pto_distancia(pt1,origem);
  float distpt2_Orig=pto_distancia(pt2,origem);
  pto_libera(origem);
 
  return distpt1_Orig<distpt2_Orig;
}