#ifndef LISTAPOSTOS_H_
#define LISTAPOSTOS_H_

typedef void *listaPosto;

listaPosto criaPosto(int id, double x, double y);

int getIdPosto(listaPosto lista);

double getXPosto(listaPosto lista);

double getYPosto(listaPosto lista);

#endif