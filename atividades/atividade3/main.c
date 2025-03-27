/* Em muitos sistemas, como agendas pessoais, softwares de produtividade, sistemas de gerenciamento
de tarefas e calendários eletrônicos, há a necessidade de:

1. Registrar compromissos com data e horário específicos.
2. Consultar compromissos marcados para uma determinada data.
3. Remover compromissos da agenda caso sejam cancelados.
4. Ajustar horários de compromissos, seja para adiá-los ou antecipá-los.
Esse problema envolve manipulação de datas e horários, exigindo operações matemáticas que levem
em consideração:

 Variações no número de dias dos meses.
 Anos bissextos. x
 Mudanças de dias ao ultrapassar a meia-noite (00:00).

--> Todos os TADs devem possuir as funcionalidades: getNaFormaTexto, acessa e atribui além das funcionalidade especificadas no arquivo TAD TimeStamp Compromisso Agenda
--> Complete  o TAD  Data com as funcionalidades  getNaFormaTexto, acessa e atribui
--> Complete o TAD Horario com a funcionalida getNaFormaTexto */

#include <stdio.h>
#include "data.h"
#include "horario.h"
#include "timestamp.h"

int main(void) {

  Horario* h1 = criarHorario(12, 40);

  printf("\n\n");
  imprimirHorario(h1);
}