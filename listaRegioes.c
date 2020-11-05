#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaRegioes.h"

typedef struct regiao{
    int id; /*id da regiao*/
    double x; /*ponto x da regiao*/
    double y; /*ponto y da regiao*/
    double w;  /*w da regiao*/
    double h; /*h da regiao*/
    double d; /*densidade de regiao por km*/
    char categoria;
}Regiao;

listaRegiao criaRegiao(int id, double x, double y, double w, double h, double d){
    Regiao *r =(Regiao*)malloc(sizeof(Regiao));
    r->id = id; 
    r->x = x; 
    r->y = y;
    r->w = w; 
    r->h = h;
    r->d = d;
    return r;
}

int getIdRegiao(listaRegiao lista){
    Regiao *r = (Regiao*)lista;
    return r->id;
}

double getXRegiao(listaRegiao lista){
    Regiao *r = (Regiao*)lista;
    return r->x;
}

double getYRegiao(listaRegiao lista){
    Regiao *r = (Regiao*)lista;
    return r->y;
}

double getWRegiao(listaRegiao lista){
    Regiao *r = (Regiao*)lista;
    return r->w;
}

double getHRegiao(listaRegiao lista){
    Regiao *r = (Regiao*)lista;
    return r->h;
}

double getDRegiao(listaRegiao lista){
    Regiao *r = (Regiao*)lista;
    return r->d;
}

char getCategoriaRegiao(listaRegiao lista){
    Regiao *r = (Regiao*)lista;
    return r->categoria;
}

void setCategoriaRegiao(listaRegiao lista, char categoria){
    Regiao *r = (Regiao*)lista;
    r->categoria = categoria;
}


