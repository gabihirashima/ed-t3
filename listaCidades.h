#ifndef LISTACIDADES_H_
#define LISTACIDADES_H_

#include "lista.h"

/*define listaCidade como ponteiro void*/
typedef void *listaCidade;

/*Inicia todas as listas pertencentes a lista de cidades*/ 
listaCidade iniciaListaCidade();

/*Retorna a lista de Formas*/
listaStruct getListaFormas(listaCidade lista);

/*Retorna a lista de Objetos*/
listaStruct getListaObjetos(listaCidade lista);

/*Retorna a lista de Quadra*/
listaStruct getListaQuadras(listaCidade lista);

/*Retorna a lista de Regioes*/
listaStruct getListaRegioes(listaCidade lista);

/*Retorna a lista de Postos de Saude*/
listaStruct getListaPostos(listaCidade lista);

/*Retorna a lista de Casos de Covid*/
listaStruct getListaCasosCovid(listaCidade lista);

/*Compara a id recebida com as ids dos objetos na lista, se encontra um correspondente, retorna este*/
Node comparaIdObjetos(listaCidade lista, char *id);

/*Compara o cep recebido com os ceps das quadras na lista, se encontra um correspondente, retorna este*/
Node comparaCepQuadra(listaCidade lista, char *id);

/*Compara a id recebida com as ids das formas na lista, se encontra um correspondente, retorna este*/
Node comparaIdFormas(listaCidade lista, int id);

/*Compara o endereço recebido com as ids dos objetos na lista, se encontra um correspondente, retorna este*/
Node comparaEnderecoCasosCovid(listaCidade lista, char *cep, char face, int num);

#endif