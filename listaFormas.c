#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaFormas.h"

/* CHAR DE IDENTIFICAÇÃO
    c = circulo;
    r = retangulo;
    x = retangulo pontilhado;
    l = linha;
    t = texto;
*/

typedef struct formas{
    int id; /*identificacao*/
    double r; /*raio*/
    double w; /*largura*/
    double h; /*altura*/
    double x; /*ponto x*/
    double y; /*ponto y*/
    double x2; /*ponto x2*/
    double y2; /*ponto y2*/
    double rx; /*curvatura de canto retangulo, eixo x*/
    double ry; /*curvatura de canto retangulo, eixo y*/
    char corb[20]; /*cor da borda*/
    char corp[20]; /*cor do preenchimento*/
    char texto[50]; /*texto*/
    char cw[20]; /*espessura*/
    char char_id; /*char de identificacao*/
}Formas;

listaForma criaCirculo(int id, double r, double x, double y, char *corb, char *corp, char *cw){
    Formas *c =(Formas*)malloc(sizeof(Formas));
    c->id = id;
    c->r = r;
    c->x = x;
    c->y = y;
    strcpy(c->corb, corb);
    strcpy(c->corp, corp);
    strcpy(c->cw, cw);
    c->char_id = 'c';
    return c;
}

listaForma criaRetangulo(int id, double w, double h, double x, double y, double rx, double ry, char *corb, char *corp, char *rw){
    Formas *r =(Formas*)malloc(sizeof(Formas));
    r->id = id;
    r->w = w;
    r->h = h;
    r->x = x;
    r->y = y;
    r->rx = rx;
    r->ry = ry;
    strcpy(r->corb, corb);
    strcpy(r->corp, corp);
    strcpy(r->cw, rw);
    r->char_id = 'r';
    return r;
}

listaForma criaRetanguloPontilhado(int id, double w, double h, double x, double y, double rx, double ry, char *corb, char *corp, char *rw){
    Formas *r =(Formas*)malloc(sizeof(Formas));
    r->id = id;
    r->w = w;
    r->h = h;
    r->x = x;
    r->y = y;
    r->rx = rx;
    r->ry = ry;
    strcpy(r->corb, corb);
    strcpy(r->corp, corp);
    strcpy(r->cw, rw);
    r->char_id = 'x';
    return r;
}

listaForma criaLinha(int id, double x, double y, double x2, double y2, char *cor){
    Formas *l =(Formas*)malloc(sizeof(Formas));
    l->id = id;
    l->x = x;
    l->y = y;
    l->x2 = x2;
    l->y2 = y2;
    strcpy(l->corb, cor);
    strcpy(l->corp, cor);
    l->char_id = 'l';
    return l;
}

listaForma criaTexto(int id, double x, double y, char *corb, char *corp, char *texto){
    Formas *t =(Formas*)malloc(sizeof(Formas));
    t->id = id;
    t->x = x;
    t->y = y;
    strcpy(t->corb, corb);
    strcpy(t->corp, corp);
    strcpy(t->texto, texto);
    t->char_id = 't';
    return t;
}

int getIdFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->id;
}

double getWFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->w;
}

double getHFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->h;
}

double getXFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->x;
}

double getYFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->y;
}

double getRFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->r;
}

char *getCorbFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->corb;
}

char *getCorpFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->corp;
}

char *getCWFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->cw;
}

char *getTextFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->texto;
}

char getCharIdFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->char_id;
}

void setCorpForma(listaForma lista, char *Cfill){
    Formas *f = (Formas*)lista;
    strcpy(f->corp, Cfill);
}

void setCorbForma(listaForma lista, char *Cstroke){
    Formas *f = (Formas*)lista;
    strcpy(f->corb, Cstroke);
}

double getRxFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->rx;
}

double getRyFormas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->ry;
}

double getX2Formas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->x2;
}

double getY2Formas(listaForma lista){
    Formas *f = (Formas*)lista;
    return f->y2;
}