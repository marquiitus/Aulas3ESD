/*3. TAD Timestamp
 Une a data e o horário em uma única estrutura.
 Permite operações combinadas de tempo, como adicionar minutos e ajustar automaticamente
a data.
 Facilita a manipulação de informações temporais em compromissos.

3. TAD Timestamp (Data + Horário)
3.1 Estrutura
O TAD Timestamp une Data e Horário, permitindo manipular tempo de forma completa.

Definição da Estrutura:

typedef struct {
  Data *data;
  Horario *horario;
}Timestamp;

3.2 Funcionalidades
Função Descrição

Timestamp *criarTimestamp(int dia, int mes, int ano, int hora, int minuto) Cria um timestamp com Data e Horário.
void imprimirTimestamp(Timestamp *timestamp) Exibe data e horário no formato DD/MM/AAAA HH:MM.
void destruirTimestamp(Timestamp *timestamp) Libera memória da estrutura Timestamp.
void somarMinutosTimestamp(Timestamp *timestamp, int minutos) Adiciona minutos ao timestamp, ajustando data e horário.
void subtrairMinutosTimestamp(Timestamp *timestamp, int minutos) Subtrai minutos, garantindo consistência entre data e horário.

3.3 Lógica de Operação
 Operações de soma e subtração de minutos podem alterar a data ao ultrapassar limites de
horas.
 O timestamp é essencial para a gestão de compromissos. */

//definição de tipos
typedef struct timestamp Timestamp;

// ******** FUNÇÕES PRINCIPAIS  ********
Timestamp* criarTimestamp (int dia, int mes, int ano, int hora, int minuto);  //Cria um timestamp com Data e Horário.
void imprimirTimestamp (Timestamp *timestamp);  //Exibe data e horário no formato DD/MM/AAAA HH:MM.
void destruirTimestamp (Timestamp *timestamp);  //Libera memória da estrutura Timestamp.
void somarMinutosTimestamp (Timestamp *timestamp, int minutos);  //Adiciona minutos ao timestamp, ajustando data e horário.
void subtrairMinutosTimestamp (Timestamp *timestamp, int minutos);  //Subtrai minutos, garantindo consistência entre data e horário.

// ******** FUNÇÕES AUXILIARES ********
