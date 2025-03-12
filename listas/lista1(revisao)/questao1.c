/*Qual o valor de y no final do programa abaixo?
Escreva um comentário em cada comando de atribuição 
explicando o que ele faz e o valor da variável à esquerda 
do '=' após sua execução.

int main() {

  int y, *p, x;
  y = 0;
  
  p = &y;  p vai receber 0
  x = *p;  
  x = 4;   x vai receber 4
  (*p)++;  p vai receber 1
  x--;     x vai receber 3
  (*p) += x; p vai receber 4
  printf ("y = %i\n", y);
  return(0);
}*/