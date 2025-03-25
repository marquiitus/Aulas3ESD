/*1. TAD Data
 Representa uma data com dia, mês e ano.
 Permite a soma e subtração de dias, garantindo ajustes de meses e anos corretamente.
 Considera anos bissextos na contagem de dias. x

1.1 Estrutura
O TAD Data é responsável por armazenar e manipular informações de dia, mês e ano. Ele garante que
operações com datas sejam feitas corretamente, considerando o número de dias de cada mês e os anos
bissextos.

Definição da Estrutura:

typedef struct {

int dia, mes, ano;
} Data;

1.2 Funcionalidades
Função Descrição
Data *criarData(int dia, int mes, int ano) Aloca e inicializa uma estrutura Data.
void imprimirData(Data *data) Exibe a data no formato DD/MM/AAAA.
void destruirData(Data *data) Libera a memória alocada para uma estrutura Data.
void somarDias(Data *data, int dias) Adiciona um número de dias à data, ajustando corretamente os meses e anos.
void subtrairDias(Data *data, int dias) Subtrai um número de dias da data, garantindo ajustes corretos.

1.3 Lógica de Operação

1. Criação da Data
o O usuário define dia, mês e ano ao criar a estrutura.

2. Impressão da Data
o A função imprimirData() exibe a data corretamente no formato DD/MM/AAAA.

3. Soma e Subtração de Dias
o A função verifica quantos dias o mês possui e ajusta corretamente a data ao
ultrapassar os limites.

o Para subtração, se a data for anterior ao início do mês, retrocede para o mês anterior,
considerando os dias desse mês.*/

//definição de tipos
typedef struct data Data;

// ******** FUNÇÕES PRICIPAIS ********
Data* criarData (int dia, int mes, int ano);  //Aloca e inicializa uma estrutura Data.
void imprimirData (Data* data);  //Exibe a data no formato DD/MM/AAAA.
void destruirData (Data* data);  //Libera a memória alocada para uma estrutura Data.
void somarDias (Data* data, int dias);  //Adiciona um número de dias à data, ajustando corretamente os meses e anos.
void subtrairDias (Data* data, int dias); //Subtrai um número de dias da data, garantindo ajustes corretos.

// ******** FUNÇÕES AUXILIARES ********
int anoBissexto (int ano);
int diasNoMes (int mes, int ano);