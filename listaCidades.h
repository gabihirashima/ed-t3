#ifndef LISTACIDADES_H_
#define LISTACIDADES_H_

typedef void *listaCidade;

listaCidade iniciaListaCidade();

listaStruct getListaFormas(listaCidade lista);

listaStruct getListaObjetos(listaCidade lista);

listaStruct getListaQuadras(listaCidade lista);

void liberaListasCidade(listaCidade lista);

#endif