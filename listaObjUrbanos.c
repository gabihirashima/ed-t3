#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaObjUrbanos.h"

/* CHAR DE IDENTIFICAÇÃO
    h = hidrante;
    s = semaforo;
    b = radiobase;
*/

typedef struct objetoUrbano{
    char id[20]; /*identificador*/
    double x; /*ponto x*/
    double y; /*ponto y*/
    char corb[20]; /*cor da borda*/
    char corp[20]; /*cor da preenchimento*/
    char sw[20]; /*espessura*/
    char char_id; /*identificador de tipo*/
}objetosUrbanos;

listaObjetos criaHidrante(char id[], double x, double y, char corb[], char corp[], char sw[]){
    objetosUrbanos *o = (objetosUrbanos*)malloc(sizeof(objetosUrbanos));
    strcpy(o->id, id);
    o->x = x;
    o->y = y;
    strcpy(o->corb, corb);
    strcpy(o->corp, corp);
    strcpy(o->sw, sw);
    o->char_id = 'h';
    return o;
}

listaObjetos criaSemaforo(char id[], double x, double y, char corb[], char corp[], char sw[]){
    objetosUrbanos *o = (objetosUrbanos*)malloc(sizeof(objetosUrbanos));
    strcpy(o->id, id);
    o->x = x;
    o->y = y;
    strcpy(o->corb, corb);
    strcpy(o->corp, corp);
    strcpy(o->sw, sw);
    o->char_id = 's';
    return o;
}

listaObjetos criaRadio(char id[], double x, double y, char corb[], char corp[], char sw[]){
    objetosUrbanos *o = (objetosUrbanos*)malloc(sizeof(objetosUrbanos));
    strcpy(o->id, id);
    o->x = x;
    o->y = y;
    strcpy(o->corb, corb);
    strcpy(o->corp, corp);
    strcpy(o->sw, sw);
    o->char_id = 'b';
    return o;
}

char *getIdObjetos(listaObjetos Lista){
  objetosUrbanos *o = (objetosUrbanos*)Lista;
  return o->id;
}

double getXObjetos(listaObjetos Lista){
  objetosUrbanos *o = (objetosUrbanos*)Lista;
  return o->x;
}

double getYObjetos(listaObjetos Lista){
  objetosUrbanos *o = (objetosUrbanos*)Lista;
  return o->y;
}

char *getSwObjetos(listaObjetos Lista){
  objetosUrbanos *o = (objetosUrbanos*)Lista;
  return o->sw;
}

char *getCorbObjetos(listaObjetos Lista){
   objetosUrbanos *o = (objetosUrbanos*)Lista;
  return o->corb;
}

char *getCorpObjetos(listaObjetos Lista){
   objetosUrbanos *o = (objetosUrbanos*)Lista;
  return o->corp;
}

char getCharIdObjetos(listaObjetos Lista){
  objetosUrbanos *o = (objetosUrbanos*)Lista;
  return o->char_id;
}