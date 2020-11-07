#ifndef LISTA_H_
#define LISTA_H_

/*define listaStruct como ponteiro void*/
typedef void *listaStruct;

/*define tipo como ponteiro void*/
typedef void *tipo;

/*define Node como ponteiro void*/
typedef void *Node;

/*inicia a lista apontado para NULL*/
listaStruct criaLista();

/*Insere elemento ao final da lista encadeada*/
listaStruct insertElemento(listaStruct lista, tipo elemento);

/*Insere elemento antes do elemento_2 na lista encadeada*/
listaStruct insertBefore(listaStruct lista, tipo elemento, tipo elemento_2);

/*Insere elemento após elemento_2 na lista encadeada*/
listaStruct insertAfter(listaStruct lista, tipo elemento, tipo elemento_2);

/*remove elemento da lista encadeada*/
listaStruct removeElemento(listaStruct lista, tipo elemento);

/*libera lista encadeada*/
void liberaLista(listaStruct lista);

/*retorna o primeiro elemento da lista*/
Node getFirst(listaStruct lista);

/*retorna o ultimo elemento da lista*/
Node getLast(listaStruct lista);

/*retorna elemento anterior ao elemento passado*/
Node getPrevious(Node elemento);

/*retorna o próximo elemento ao elemento passado*/
Node getNext(Node elemento);

/*retorna elemento*/
tipo getElemento(Node elemento);

/*retorna o tamanho da lista*/
int tamanhoLista(listaStruct lista);

#endif