#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"
#include "lista.h"
#include "listaCidades.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"
#include "listaPostos.h"
#include "listaRegioes.h"

void casosCovid(listaCidade lista, int n, char *cep, char face, int num){
    Node listaQ = getListaQuadras(lista);
    Node listaF = getListaFormas(lista);
    Node quadraCovid;
    tipo elemento;
    double x, y, w, h, nw, nh, wx, hy, nx, ny;
    quadraCovid = comparaCepQuadra(listaQ, cep);
    x = getXQuadra(quadraCovid);
    y = getYQuadra(quadraCovid);
    w = getWQuadra(quadraCovid);
    h = getHQuadra(quadraCovid);

    switch(face){
        case 'S':
            nx = x + (double)num;
            ny = y + ((5*(y+h))/6);
            elemento = criaRetangulo(0, (x+w)/6, (y+h)/6, nx, ny, 0, 0, "black", "orange", "1.0px");
            insertElemento(listaF, elemento);
            elemento = criaTexto(0, (x+w)/2, (y+h)/2, "black", "white", n);
            insertElemento(listaF, elemento);
        break;

        case 'N':
            nx = x + (double)num;
            ny = y;
            elemento = criaRetangulo(0, (x+w)/6, (x+h)/6, nx, ny, 0, 0, "black", "orange", "1.0px");
            insertElemento(listaF, elemento);
            elemento = criaTexto(0, (x+w)/2, (y+h)/2, "black", "white", n);
            insertElemento(listaF, elemento);
        break;

        case 'L':
            nx = x + ((5*(x + w))/6);
            ny = y + (double)num;
            elemento = criaRetangulo(0, (x+w)/6, (x+h)/6, nx, ny, 0, 0, "black", "orange", "1.0px");
            insertElemento(listaF, elemento);
            elemento = criaTexto(0, (x+w)/2, (y+h)/2, "black", "white", n);
            insertElemento(listaF, elemento);

        break;

        case 'O':
            nx = x;
            ny = y + (double)num;
            elemento = criaRetangulo(0, (x+w)/6, (x+h)/6, nx, ny, 0, 0, "black", "orange", "1.0px");
            insertElemento(listaF, elemento);
            elemento = criaTexto(0, (x+w)/2, (y+h)/2, "black", "white", n);
            insertElemento(listaF, elemento);
        break;
    }

}