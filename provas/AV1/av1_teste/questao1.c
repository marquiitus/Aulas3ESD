/* QUESTÃO 1) 1.0 ponto
Uma montadora de automóveis produz carros sob encomenda. Um carro tem modelo, chassi, relação de
componentes e de clientes que estão aguardando. Um cliente possui nome e endereço e são atendidos em ordem
de chegada do pedido. Os componentes possuem características como: nome, quantidade, cor, preço e fornecedor.
Qualquer componente pode ser consultado ou ter seu preço modificado. Um fornecedor da montadora tem CNPJ e
razão social. Defina o tipo de dados (e respetivas estruturas) que representa este carro. */

#define MAX 5

typedef struct {
    char cnpj[15];
    char razaoSocial[40];
} TFornecedor;


struct carro {
  char modelo[40];
  char chassi[40];
  char relacaoComponentes[40];
  char relacaoClientesAguardando[40];
};

typedef struct carro TCarro;

typedef struct {
  char nome[40];
  char endereco[40];
} TNo;

typedef struct {
  TNo vNos[MAX];
  int F, R;
  int maximo;
} TFila;

struct componentes{
  char nome[30];
  int quant;
  char cor[40];
  double preco;
  TFornecedor fornecedor;
};

typedef struct componentes TComponentes;
