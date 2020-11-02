#ifndef LISTACIDADES_H_
#define LISTACIDADES_H_

#include "lista.h"

typedef void *listaCidade;

listaCidade iniciaListaCidade();

listaStruct getListaFormas(listaCidade lista);

listaStruct getListaObjetos(listaCidade lista);

listaStruct getListaQuadras(listaCidade lista);

listaStruct getListaRegioes(listaCidade lista);

listaStruct getListaPostos(listaCidade lista);

Node comparaIdObjetos(listaCidade lista, char *id);

Node comparaCepQuadra(listaCidade lista, char *id);

Node comparaIdFormas(listaCidade lista, int id);

#endif