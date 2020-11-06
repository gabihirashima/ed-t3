#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaCidades.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"
#include "listaFormas.h"
#include "listaPostos.h"
#include "listaRegioes.h"
#include "listaCasosCovid.h"

typedef struct cidade{
    listaStruct listaF;
    listaStruct listaO;
    listaStruct listaQ;
    listaStruct listaR;
    listaStruct listaP;
    listaStruct listaC;
}Cidade;

listaCidade iniciaListaCidade(){
    Cidade *lista;
    lista = (Cidade*)malloc(sizeof(Cidade));

    lista->listaF = criaLista();
    lista->listaQ = criaLista();
    lista->listaO = criaLista();
    lista->listaR = criaLista();
    lista->listaP = criaLista();
    lista->listaC = criaLista();

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

listaStruct getListaRegioes(listaCidade lista){
    Cidade* list = (Cidade*)lista;
    return list->listaR;
}

listaStruct getListaPostos(listaCidade lista){
    Cidade* list = (Cidade*)lista;
    return list->listaP;
}

listaStruct getListaCasosCovid(listaCidade lista){
    Cidade* list = (Cidade*)lista;
    return list->listaC;
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

Node comparaEnderecoCasosCovid(listaCidade lista, char *cep, char face, int num){
     listaStruct list = getListaCasosCovid(lista);

    Node no = getFirst(list);
    tipo elemento;
         do{
            elemento = getElemento(no);
                if(strcmp(getCepCasosCovid(elemento), cep) == 0){
                    if(getFaceCasosCovid(elemento) == face ){
                        if(getNumCasosCovid(elemento) == num){
                            return elemento;
                        }
                    }
                }
            no = getNext(no);
        }while(no != NULL);
    return NULL;
}