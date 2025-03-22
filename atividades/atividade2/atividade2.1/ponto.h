//Marcos Ferreira de Souza

/* Tipo exportado */
typedef float ponto[2];  //mudando o struct para um vetor

/* Funções exportadas */
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
ponto* pto_cria(float x, float y);

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(ponto *p);

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(ponto *p, float *x, float *y);

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(ponto *p, float x, float y);

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(ponto *p);

/* Função copia -  retorna um novo  ponto com coordenadas do ponto recebido*/
ponto* pto_copia(ponto *p);

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(ponto *p);

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(ponto *p1, ponto *p2);

/* Função menorque - recebe dois pontos e retorna 1 se o pt1 está mais próximo da origem, 0 cc*/
int pto_menorque(ponto *pt1, ponto *pt2);