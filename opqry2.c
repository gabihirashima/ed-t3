#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"
#include "listaCidades.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"
#include "listaPostos.h"
#include "listaCasosCovid.h"
#include "listaRegioes.h"
#include "criaSvg.h"
#include "learq.h"

void casosCovid(listaCidade listacidade, int n, char *cep, char face, int num, FILE *saida){
    Node listaF = getListaFormas(listacidade);
    Node listaC = getListaCasosCovid(listacidade);
    Node quadraCovid;
    tipo elemento;
    
    double x, y, w, h, nx, ny;
    
    quadraCovid = comparaCepQuadra(listacidade, cep);

    if(quadraCovid != NULL){
        x = getXQuadra(quadraCovid);
        y = getYQuadra(quadraCovid);
        w = getWQuadra(quadraCovid);
        h = getHQuadra(quadraCovid);
        char string[10];
            sprintf(string, "%d", n);
        switch(face){
            case 'S':
                nx = x + num;
                ny = y + ((4*((y+h)-y))/5);
                elemento = criaRetangulo(0, ((x+w)-x)/5, ((y+h)-y)/5, nx, ny, 0, 0, "black", "orange", "1.0px");
                insertElemento(listaF, elemento);
                elemento = criaTexto(0, nx + ((((x+w)-x)/5)/3), ny + ((((y+h)-y)/5)/1.8) , "white", "white", string);
                insertElemento(listaF, elemento);
                elemento = criaCaso(n, nx, ny, ((x+w)-x)/5, ((y+h)-y)/5);
                insertElemento(listaC, elemento);
                fprint(saida, "%d casos em %s\n", n, cep);
            break;

            case 'N':
                nx = x + num;
                ny = y;
                elemento = criaRetangulo(0, ((x+w)-x)/5, ((y+h)-y)/5, nx, ny, 0, 0, "black", "orange", "1.0px");
                insertElemento(listaF, elemento);
                elemento = criaTexto(0, nx + ((((x+w)-x)/5)/3), ny + ((((y+h)-y)/5)/1.8), "white", "white", string);
                insertElemento(listaF, elemento);
                elemento = criaCaso(n, nx, ny, ((x+w)-x)/5, ((y+h)-y)/5);
                insertElemento(listaC, elemento);
                fprint(saida, "%d casos em %s\n", n, cep);
            break;

            case 'L':
                nx = x + ((4*((x + w)-x))/5);
                ny = y + num;
                elemento = criaRetangulo(0, ((x+w)-x)/5, ((y+h)-y)/5, nx, ny, 0, 0, "black", "orange", "1.0px");
                insertElemento(listaF, elemento);
                elemento = criaTexto(0, nx + ((((x+w)-x)/5)/3), ny + ((((y+h)-y)/5)/1.8), "white", "white", string);
                insertElemento(listaF, elemento);
                elemento = criaCaso(n, nx, ny, ((x+w)-x)/5, ((y+h)-y)/5);
                insertElemento(listaC, elemento);
                fprint(saida, "%d casos em %s\n", n, cep);

            break;

            case 'O':
                nx = x;
                ny = y + num;
                elemento = criaRetangulo(0, ((x+w)-x)/5, ((y+h)-y)/5, nx, ny, 0, 0, "black", "orange", "1.0px");
                insertElemento(listaF, elemento);
                elemento = criaTexto(0, nx + ((((x+w)-x)/5)/3), ny + ((((y+h)-y)/5)/1.8), "white", "white", string);
                insertElemento(listaF, elemento);
                elemento = criaCaso(n, nx, ny, ((x+w)-x)/5, ((y+h)-y)/5);
                insertElemento(listaC, elemento);
                fprint(saida, "%d casos em %s\n", n, cep);
            break;
        }
    }
}

void incidenciaRelativa(listaCidade lista, double cx, double cy, double r, FILE *saida){
    double x, y, x2, y2;
    int nCasosTotais = 0;
    Node listaIncidencia;
        listaIncidencia = getListaCasosCovid(lista);
    Node I; 
        I = getFirst(listaIncidencia);

    if(I != NULL){
        while(I != NULL){
                x = getXCasosCovid(I);
                y = getYCasosCovid(I);
                x2 = (x + getWCasosCovid(I));
                y2 = (y + getHCasosCovid(I));
                if( ((pow((x - cx), 2) + (pow((y - cy), 2)) <= pow(r, 2)) )||  
                ((pow((x - cx), 2) + (pow((y2 - cy), 2)) <= pow(r, 2)) ) ||
                ((pow((x2 - cx), 2) + (pow((y - cy), 2)) <= pow(r, 2)) )||
                ((pow((x2 - cx), 2) + (pow((y2 - cy), 2)) <= pow(r, 2))) ){
                    nCasosTotais = nCasosTotais + getNCasosCovid(I);
                }
            I = getNext(I);
        }

        
    }
}