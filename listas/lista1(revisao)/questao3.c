/* 3. Construa o programa a seguir.

a. Faça a função horario que receba um parâmetro (inteiro por valor) com o total de
minutos de um evento e receba também dois parâmetros (inteiros por referência) no
qual deve preencher a quantidade de hora e de minutos equivalente. Por exemplo:
145 minutos equivale a 2 h e 25 min. Esta função deverá OBRIGATORIAMENTE chamar
a função DivisaoInteira

b. Faça um programa que leia o tempo de treino (em minutos) de 10 atletas, mostrando
a cada um, o tempo de treino no formato hh:mm. (utilize a função do item a).
No final deve ser exibido o maior tempo de treino e quantos atletas o fizeram  

Incluir o nome na struct, 
ordenar o vetor por tempo/nome
métodos possíveis: bolha, seleção (menor ou maior) , insertion */

struct tat{

	int tempo, cod;
};
typedef struct tat tAtleta;

void obtemAtleta(int num, tAtleta *atleta){

  printf("\nDigite o código do %dº atleta: ", num);
	scanf("%i", &atleta->cod);  // (*atleta).cod   pode ser escrito como atleta->cod
	
	printf("\nDigite o tempo do %dº atleta: ", num);
	scanf("%i", &atleta->tempo);
	
  return;
}

tAtleta leAtleta(int num){
	
  tAtleta atleta;
  printf("\nDigite o código do %dº atleta:",num);
	scanf("%i",&atleta.cod);
	
	printf("\nDigite o tempo do %dº atleta:",num);
	scanf("%i",&atleta.tempo);
	
  return atleta;
}

int main(void) {
	
  tAtleta vAtletas[TAM];

	int tempo_horas, tempo_minutos;
	int maiorTempo = -1, qtMaior= 0, contador, op;
  
  for(contador=0;contador<TAM;contador++){
    //atleta=leAtleta(contador+1);
    obtemAtleta(contador+1, &vAtletas[contador]);

	  horario(vAtleta[contador].tempo,&tempo_horas, &tempo_minutos);
	  printf("\nTempo do %dº atleta foi %02i:%02ih", contador + 1, tempo_horas,tempo_minutos);
	}

	return 0;
}

int divisaoInteira(int dividendo, int divisor, int* quoc, int*resto){
    
  if (divisor==0)
  if (dividendo==0)
    return -1;
  else
    return 0;
  else{
    *quoc= dividendo/divisor;
    *resto=dividendo%divisor;
    return 1;
  }
}

void horario(int tempo, int *horas, int *minutos) {
	
  divisaoInteira(tempo,60, horas,minutos);
	return;
}