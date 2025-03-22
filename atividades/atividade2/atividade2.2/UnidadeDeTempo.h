//Marcos Ferreira de Souza

/* Tipo Exportado */
typedef struct tempo {
  int tempos[3];
} UniTempo;

//protótipos das funções
// ******** FUNÇÕES PRINCIPAIS ********
UniTempo* criar (int h, int m, int s);
UniTempo* criarDeSegundos (int totalSegundos);
UniTempo* somarTempos (UniTempo *t1, UniTempo *t2);
UniTempo* subtrairTempos (UniTempo *t1, UniTempo *t2);
UniTempo* copiarTempo (UniTempo *t);

// ******** FUNÇÕES AUXILIARES ********
void exibir (UniTempo *t);
int comparar_tempos (UniTempo *tempo1, UniTempo *tempo2);
int transformaEmSegundos (UniTempo *t);
void liberar (UniTempo *t);
void normalizarTempo (UniTempo *t);