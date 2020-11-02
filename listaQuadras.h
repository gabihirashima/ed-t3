#ifndef LISTAQUADRAS_H_
#define LISTAQUADRAS_H_

typedef void *listaQuadra;


listaQuadra criaQuadra(char *cep, double x, double y, double w, double h, char *corb, char *corp, char *sw);

char *getCepQuadra(listaQuadra lista);

double getXQuadra(listaQuadra lista);

double getYQuadra(listaQuadra lista);

double getWQuadra(listaQuadra lista);

double getHQuadra(listaQuadra lista);

char *getCorbQuadra(listaQuadra lista);

char *getCorpQuadra(listaQuadra lista);

char *getSwQuadra(listaQuadra lista);

void setCorbQuadra(listaQuadra lista, char *Cstroke);

#endif