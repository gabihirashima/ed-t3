#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaCasosCovid.h"
#include "listaCidades.h"

typedef struct casoscovid{
    int n_casos; /*numero de casos relatados*/
    double x; /*coordenada x*/
    double y; /*coordenada y*/
    double w; /*largura da estrutura*/
    double h; /*altura da estrutura*/
}casosCovid;

listacasos criaCaso(int n_casos, double x, double y, double w, double h){
    casosCovid *c =(casosCovid*)malloc(sizeof(casosCovid));
    c->n_casos = n_casos;
    c->x = x;
    c->y = y;
    c->w = w;
    c->h = h;
    return c;
}

int getNCasosCovid(listacasos lista){
    casosCovid *c = (casosCovid*)lista;
    return c->n_casos;
}

double getXCasosCovid(listacasos lista){
    casosCovid *c = (casosCovid*)lista;
    return c->x;
}

double getYCasosCovid(listacasos lista){
    casosCovid *c = (casosCovid*)lista;
    return c->y;
}

double getWCasosCovid(listacasos lista){
    casosCovid *c = (casosCovid*)lista;
    return c->w;
}

double getHCasosCovid(listacasos lista){
    casosCovid *c = (casosCovid*)lista;
    return c->h;
}