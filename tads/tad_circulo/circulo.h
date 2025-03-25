//TAD CÍRCULO
//Tipo Exportado
typedef struct circulo Circulo;

//protótipos das funções
Circulo* cir_cria (float x, float y, float r);

Circulo* cir_libera (Circulo* c);

float cir_area (Circulo* c);

void circ_exibir (Circulo* c);

char* circ_getCirculo (Circulo* c);

//TAD PONTO
/* Tipo exportado */
typedef struct ponto Ponto;

/* Funções exportadas */
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria (float x, float y);

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera (Ponto* p);

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa (Ponto* p, float* x, float* y);

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui (Ponto* p, float x, float y);

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exib (Ponto* p);

/* Função copia -  retorna um novo  ponto com coordenadas do ponto recebido*/
Ponto* pto_copia (Ponto* p);

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto (Ponto* p);

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia (Ponto* p1, Ponto* p2);

/* Função menorque -recebe dois pontos e retorna 1 se o pt1 está mais pr´ximo da origem, 0 cc*/
int pto_menorque (Ponto* pt1, Ponto* pt2);