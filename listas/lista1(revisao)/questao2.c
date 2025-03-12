/*2. A divisão no conjunto de inteiros, produz 2 valores: o quociente e o resto.
No entanto, quando o divisor é zero há duas situações: impossível – quando apenas o
divisor é zero e indeterminada quando o dividendo e o divisor são zeros.

a. Faça a função divisaoInteira(...) , que recebe dois valores (o dividendo e o
divisor) e dois endereços de variáveis, um para armazenar o quociente e outro
para o resto. Esta função realiza a operação de divisão, se for possível,
preenchendo adequadamente o quociente e o resto, e retorna o valor 1
(sucesso). Caso a operação não possa ser realizada, a função deve retornar 0 ,
quando a divisão é impossível e -1 quando é indeterminada.

b. Utilize sua função adequadamente na main abaixo:
int main (void) {

  int a, b, q, r, st;
  
  printf(&quot;Digite dois valores: &quot;);
  scanf (&quot;%d%d&quot;,&amp;a,&amp;b);
  
  if (DivisaoInteira (.....................)==1){
    printf (&quot;%d /%d = %d com resto %d\n&quot;,
    a,b,q,r);
  } else {
    
    printf (&quot;Erro- divisor eh 0 \n&quot;);
  }

  return 0;
} */

