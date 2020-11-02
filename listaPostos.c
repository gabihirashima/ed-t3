#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaPostos.h"

typedef struct posto{
    int id;
    double x;
    double y;
}Posto;

listaPosto criaPosto(int id, double x, double y){
    Posto *p =(Posto*)malloc(sizeof(Posto));

    p->id = id;
    p->x = x;
    p->y = y;

    return p;
}

int getIdPosto(listaPosto lista){
    Posto *p = (Posto*)lista;
    return p->id;
}

double getXPosto(listaPosto lista){
    Posto *p = (Posto*)lista;
    return p->x;
}

double getYPosto(listaPosto lista){
    Posto *p = (Posto*)lista;
    return p->y;
}