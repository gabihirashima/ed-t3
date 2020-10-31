#ifndef LISTA_H_
#define LISTA_H_

typedef void *listaStruct;

typedef void *tipo;

typedef void *Node;

listaStruct criaLista();

listaStruct insertElemento(listaStruct lista, tipo elemento);

listaStruct insertBefore(listaStruct lista, tipo elemento, tipo elemento_2);

listaStruct insertAfter(listaStruct lista, tipo elemento, tipo elemento_2);

listaStruct removeElemento(listaStruct lista, tipo elemento);

void liberaLista(listaStruct lista);

Node getFirst(listaStruct lista);

Node getLast(listaStruct lista);

Node getPrevious(Node elemento);

Node getNext(Node elemento);

tipo getElemento(Node elemento);

int tamanhoLista(listaStruct lista);

#endif