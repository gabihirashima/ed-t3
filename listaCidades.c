#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaCidades.h"

typedef struct cidade{
    listaStruct listaF;
    listaStruct listaO;
    listaStruct listaQ;
}Cidade;

listaCidade iniciaListaCidade(){
    Cidade *lista;
    lista = (Cidade*)malloc(sizeof(Cidade*));

    lista->listaF = criaLista();
    lista->listaQ = criaLista();
    lista->listaO = criaLista();

    return lista; 
}

listaStruct getListaFormas(listaCidade lista){
    Cidade* list = (Cidade*)lista;
    return list->listaF;
}

listaStruct getListaObjetos(listaCidade lista){
    Cidade* list = (Cidade*)lista;
    return list->listaO;
}

listaStruct getListaQuadras(listaCidade lista){
    Cidade* list = (Cidade*)lista;
    return list->listaQ;
}

void liberaListasCidade(listaCidade lista){
    Cidade* list = (Cidade*) lista;
    
    liberaLista(list->listaF);
    liberaLista(list->listaO);
    liberaLista(list->listaQ);

    free(list->listaF);
    free(list->listaO);
    free(list->listaQ);
    free(list);
}
