/*3. Propriedades de uma Lista
1. Uma Lista pode ter 0 ou mais nós;
2. Um nó pode ser incluído em qualquer posição da lista;
3. Qualquer nó da lista pode ser eliminado;
4. Qualquer nó da lista pode ser acessado;
5. Podemos visitar cada nó da lista na sua vez.

4. Operações básicas em uma lista
Percurso:
Acesso a um nó:
Inserção:
Retirada: */

//definição de tipo
typedef struct tipo_lista tLista; 

tLista * cria_lista_vazia (int maximo, int classif, int repet);  //cria lista vazia 
int lista_vazia (const tLista *pl);  //lista está vazia?
int lista_cheia (const tLista *pl);  //lista está cheia? 
int lista_repet (const tLista *pl);  //lista com repetição?
int lista_classif ( const tLista *pl);  //lista classificada? 
void percorre (const tLista *pl);  //percorre a lista 