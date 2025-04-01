/*5. TAD Agenda
 Gerencia uma coleção de compromissos.
 Permite:
o Adicionar compromissos à agenda.
o Listar compromissos armazenados.
o Remover compromissos por índice.
o Consultar compromissos em uma data específica.
o Alterar o horário de um compromisso, permitindo antecipação e adiamento.

Funcionalidades:
1. Registrar compromissos com data e horário.
2. Consultar compromissos de uma data específica.
3. Listar todos os compromissos armazenados na agenda.
4. Remover um compromisso da agenda.
5. Alterar um compromisso existente, permitindo:
o Adiá-lo (aumentando minutos no horário).
o Antecipá-lo (reduzindo minutos no horário).

*/

#include "compromisso.h"

struct agenda {
  Compromisso **compromissos;
  int tamanho;
  int capacidade;
};
typedef struct agenda Agenda;

Agenda *criarAgenda (int capacidadeInicial);  // Cria uma agenda dinâmica.
void adicionarCompromisso (Agenda *agenda, Compromisso *compromisso);  // Adiciona um compromisso.
void listarCompromissos (Agenda *agenda);  // Exibe todos os compromissos armazenados.
void removerCompromisso (Agenda *agenda, int indice);  // Remove um compromisso pelo índice.
void consultarCompromissosPorData (Agenda *agenda, int dia, int mes, int ano);  // Busca compromissos em uma data específica.
void alterarHorarioCompromisso (Agenda *agenda, int indice, int minutos, int adiar);  // Altera o horário do compromisso.
void destruirAgenda (Agenda *agenda);  // Libera memória da agenda.