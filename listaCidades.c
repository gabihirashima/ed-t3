#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaCidades.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"
#include "listaFormas.h"

typedef struct cidade{
    listaStruct listaF;
    listaStruct listaO;
    listaStruct listaQ;
}Cidade;

listaCidade iniciaListaCidade(){
    Cidade *lista;
    lista = (Cidade*)malloc(sizeof(Cidade));

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

Node comparaIdObjetos(listaCidade lista, char *id){
    listaStruct list = getListaObjetos(lista);
    Node no = getFirst(list);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(strcmp(getIdObjetos(elemento), id) == 0){
                    return elemento;
            }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}

Node comparaCepQuadra(listaCidade lista, char *id){
    listaStruct list = getListaQuadras(lista);
    Node no = getFirst(list);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(strcmp(getCepQuadra(elemento), id) == 0){
                    return elemento;
            }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}

Node comparaIdFormas(listaCidade lista, int id){
    listaStruct list = getListaFormas(lista);
    Node no = getFirst(list);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(getIdFormas(elemento)== id){
                    return elemento;
            }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}
