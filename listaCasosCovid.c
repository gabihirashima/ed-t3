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
    char cep[20]; /*endereço*/
    int num; /*numero*/
    char face; /*face*/
    double xT;
    double yT;
}casosCovid;

listacasos criaCaso(int n_casos, double x, double y, double w, double h, char *cep, int num, char face, double xT, double yT){
    casosCovid *c =(casosCovid*)malloc(sizeof(casosCovid));
    c->n_casos = n_casos;
    c->x = x;
    c->y = y;
    c->w = w;
    c->h = h;
    strcpy(c->cep, cep);
    c->num = num;
    c->face = face;
    c->xT = xT;
    c->yT = yT;
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

char *getCepCasosCovid(listacasos lista){
    casosCovid *c = (casosCovid*)lista;
    return c->cep;
}

double getNumCasosCovid(listacasos lista){
    casosCovid *c = (casosCovid*)lista;
    return c->num;
}

char getFaceCasosCovid(listacasos lista){
    casosCovid *c = (casosCovid*)lista;
    return c->face;
}

double getxTCasosCovid(listacasos lista){
    casosCovid *c = (casosCovid*)lista;
    return c->xT;
}

double getyTCasosCovid(listacasos lista){
    casosCovid *c = (casosCovid*)lista;
    return c->yT;
}

void setNCasosCovid(listacasos lista, int n_casos){
    casosCovid *c = (casosCovid*)lista;
    c->n_casos = n_casos;
}