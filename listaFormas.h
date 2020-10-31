#ifndef LISTAFORMAS_H_
#define LISTAFORMAS_H_

typedef void *listaForma;

listaForma criaCirculo(int id, double r, double x, double y, char *corb, char *corp, char *cw);

listaForma criaRetangulo(int id, double w, double h, double x, double y, double rx, double ry, char *corb, char *corp, char *rw);

listaForma criaLinha(int id, double x, double y, double x2, double y2, char *cor);

listaForma criaTexto(int id, double x, double y, char *corb, char *corp, char *texto);

int getIdFormas(listaForma lista);

double getWFormas(listaForma lista);

double getHFormas(listaForma lista);

double getXFormas(listaForma lista);

double getYFormas(listaForma lista);

double getRFormas(listaForma lista);

char *getCorbFormas(listaForma lista);

char *getCorpFormas(listaForma lista);

char *getCWFormas(listaForma lista);

char *getTextFormas(listaForma lista);

#endif