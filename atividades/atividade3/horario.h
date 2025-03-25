/* 2. TAD Horário
 Representa um horário com horas e minutos.
 Permite a soma e subtração de minutos, ajustando automaticamente a hora ao ultrapassar
24h.

2.1 Estrutura
O TAD Horário gerencia horas e minutos, permitindo operações de soma e subtração de tempo.

Definição da Estrutura:
typedef struct {
  int hora, minuto;
} Horario;

2.2 Funcionalidades

Função Descrição
Horario *criarHorario (int hora, int minuto) Cria e inicializa um Horario.
void imprimirHorario (Horario *horario) Exibe o horário no formato HH:MM.
void destruirHorario (Horario *horario) Libera a memória alocada para Horario.
void somarMinutos (Horario *horario, int minutos) Adiciona minutos ao horário, ajustando corretamente as horas.
void subtrairMinutos (Horario *horario, int minutos) Subtrai minutos, retrocedendo corretamente as horas.

2.3 Lógica de Operação

1. Criação do Horário
o O usuário fornece hora e minuto ao criar a estrutura.

2. Impressão do Horário
o imprimirHorario() exibe corretamente no formato HH:MM.

3. Soma e Subtração de Minutos
Se ultrapassar 60 minutos, os minutos são convertidos em horas.
Se ultrapassar 24 horas, o horário reseta e pode indicar necessidade de ajuste na data.
A subtração lida com minutos negativos, ajustando corretamente as horas. */

typedef struct horario Horario;

Horario* criarHorario (int hora, int minuto);  //Cria e inicializa um Horario.
void imprimirHorario (Horario* horario);  //Exibe o horário no formato HH:MM.
void destruirHorario (Horario* horario);  //Libera a memória alocada para Horario.
void somarMinutos (Horario* horario, int minutos);  //Adiciona minutos ao horário, ajustando corretamente as horas.
void subtrairMinutos (Horario* horario, int minutos);  //Subtrai minutos, retrocedendo corretamente as horas.