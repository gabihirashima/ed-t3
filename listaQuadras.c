#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaQuadras.h"

typedef struct quadra{
    char cep[20]; /*endereço da quadra*/
    double x; /*ponto x*/
    double y; /*ponto y*/
    double w; /*ponto w*/
    double h; /*ponto h*/
    char sw[20]; /*espessura*/
    char corb[20]; /*cor borda*/
    char corp[20]; /*cor preenchimento*/
    char char_id; /*identificador de tipo*/
}Quadra;

listaQuadra criaQuadra(char *cep, double x, double y, double w, double h, char *corb, char *corp, char *sw){
    Quadra *q =(Quadra*)malloc(sizeof(Quadra));
    strcpy(q->cep, cep);
    q->x = x;
    q->y = y;
    q->w = w;
    q->h = h;
    strcpy(q->corb, corb);
    strcpy(q->corp, corp);
    strcpy(q->sw, sw);
    q->char_id = 'q';
    return q;
}

char *getCepQuadra(listaQuadra lista){
    Quadra *q = (Quadra*)lista;
    return q->cep;
}

double getXQuadra(listaQuadra lista){
    Quadra *q = (Quadra*)lista;
    return q->x;
}

double getYQuadra(listaQuadra lista){
    Quadra *q = (Quadra*)lista;
    return q->y;
}

double getWQuadra(listaQuadra lista){
    Quadra *q = (Quadra*)lista;
    return q->w;
}

double getHQuadra(listaQuadra lista){
    Quadra *q = (Quadra*)lista;
    return q->h;
}

char *getCorbQuadra(listaQuadra lista){
    Quadra *q = (Quadra*)lista;
    return q->corb;
}

char *getCorpQuadra(listaQuadra lista){
    Quadra *q = (Quadra*)lista;
    return q->corp;
}

char *getSwQuadra(listaQuadra lista){
    Quadra *q = (Quadra*)lista;
    return q->sw;
}

void setCorbQuadra(listaQuadra lista, char *Cstroke){
    Quadra *q = (Quadra*)lista;
    strcpy(q->corb, Cstroke);
}

