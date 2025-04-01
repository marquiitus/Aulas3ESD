/*4. TAD Compromisso
4.1 Estrutura
Cada compromisso possui um Timestamp e uma descrição.

Definição da Estrutura:

typedef struct {
  Timestamp *timestamp;
  char descricao[100];
}Compromisso;

4.2 Funcionalidades
Função Descrição
Compromisso *criarCompromisso(int dia, int mes, int ano, int hora, int minuto, char *descricao) Cria um compromisso.
void imprimirCompromisso(void *dado) Exibe os detalhes do compromisso.
void destruirCompromisso(Compromisso *compromisso) Libera memória.
void adiarCompromisso(Compromisso *compromisso, int minutos) Adia um compromisso em minutos.
void anteciparCompromisso(Compromisso *compromisso, int minutos) Antecipar um compromisso.

*/
#include "timestamp.h"

struct compromisso {
  Timestamp *timestamp;
  char descricao[100];
};
typedef struct compromisso Compromisso;

Compromisso *criarCompromisso(int dia, int mes, int ano, int hora, int minuto, char *descricao);  //Cria um compromisso.
void imprimirCompromisso(void *dado);  //Exibe os detalhes do compromisso.
void destruirCompromisso(Compromisso *compromisso);  //Libera memória.
void adiarCompromisso(Compromisso *compromisso, int minutos);  //Adia um compromisso em minutos.
void anteciparCompromisso(Compromisso *compromisso, int minutos);  //Antecipar um compromisso.

char* compromisso_getCompromisso (Compromisso* compromisso);
void compromisso_acessa (Compromisso* compromisso);
void compromisso_atribui (Compromisso* compromisso);