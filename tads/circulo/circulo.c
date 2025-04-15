//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

//definição de constantes
#define PI 3,14159

//definição de struct
struct circulo {
  Ponto* ponto;
  float raio;
};

Circulo* cir_cria (float x, float y, float r) {

  Circulo* c = (Circulo*) malloc(sizeof(Circulo));
  
  if(c==NULL) {
    printf("\n\nMemoria insuficiente!\n");
    exit(1);
  }
  
  c->ponto = pto_cria(x, y);
  c->raio = r;
}

Circulo* cir_libera (Circulo *c) {
  pto_libera(c->ponto);
  free(c);
}

float cir_area (Circulo* c) {
  
  return PI * c->raio * c->raio;
}

int circ_interior (Circulo* c, Ponto* p) {
  float d = pto_distancia (c->ponto, p);
  return (d < c->raio);
}

void circ_exibir (Circulo* c) {
  
  printf("Centro: %s; Raio: %.2f", c->ponto, c->raio);
  pto_getPonto(c->ponto), c->raio;
}

Circulo* circ_clona (Circulo *cOrigem) {
  
  Circulo* cClonado = (Circulo*) malloc(sizeof(Circulo));
  if(cClonado == NULL) {
    printf("\n\nMemoria Insuficiente!\n");
    exit(1);
  }
  
  cClonado->ponto = pto_clona (cOrigem->ponto);
  cClonado->raio = cOrigem->raio;
  return cClonado;
}