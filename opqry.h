#ifndef OPQRY_H_
#define OPQRY_H_

#include <stdio.h>
#include "listaCidades.h"
#include "lista.h"

float max(float n1, float n2);

float min(float n1, float n2);

int sobrepoeCirculoRetangulo(listaCidade listacidade, Node circulo, Node retangulo);

int sobrepoeCirculoCirculo(listaCidade listacidade, Node circulo1, Node circulo2);

int sobrepoeRetanguloRetangulo(listaCidade listacidade, Node retangulo1, Node retangulo2);

void sobreposicao(int i, int k, listaCidade lista, FILE *txt);

void pontoInterno(int j, double x, double y, listaCidade lista, FILE *saida);

void pnt(int j, char *novoCorb, char *novoCorp, listaCidade lista, FILE *saida);

void delf(int j, listaCidade lista, FILE *saida);

double dist(double x1, double y1, double x2, double y2);

void delQuadras(listaCidade listacidade, FILE *txt, int htag, char *id, double r);

void delUrb(listaCidade listacidade, FILE *txt, char *cid);

void colorBorder(listaCidade listacidade, FILE *txt, double x, double y, double r, char *cstrk);

void coord(listaCidade listacidade, FILE *txt, char *cid);

void rectArea(listaCidade listacidade, FILE *txt, double x, double y, double w, double h);

#endif