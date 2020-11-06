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
#include "opqry.h"

void casosCovid(listaCidade listacidade, int n, char *cep, char face, int num, FILE *saida){
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
                ny = y;
                elemento = criaCaso(n, nx, ny, ((y+h)-y)/4, ((y+h)-y)/4, cep, num, face, (nx + ((((y+h)-y)/4)/2)) - 3 , (ny + ((((y+h)-y)/4)/2)) + 3 );
                insertElemento(listaC, elemento);
                fprintf(saida, "%d casos em %s\n", n, cep);
            break;

            case 'N':
                nx = x + num;
                ny = y + ((3*((y+h)-y))/4);
                elemento = criaCaso(n, nx, ny, ((y+h)-y)/4, ((y+h)-y)/4, cep, num, face, (nx + ((((y+h)-y)/4)/2)) - 3 , (ny + ((((y+h)-y)/4)/2)) + 3 );
                insertElemento(listaC, elemento);
                fprintf(saida, "%d casos em %s\n", n, cep);
            break;

            case 'L':
                nx = x;
                ny = y + num;
                elemento = criaCaso(n, nx, ny, ((y+h)-y)/4, ((y+h)-y)/4, cep, num, face, (nx + ((((y+h)-y)/4)/2)) - 3 , (ny + ((((y+h)-y)/4)/2)) + 3 );
                insertElemento(listaC, elemento);
                fprintf(saida, "%d casos em %s\n", n, cep);

            break;

            case 'O':
                nx = x + ((3*((x + w)-x))/4);
                ny = y + num;
                elemento = criaCaso(n, nx, ny, ((y+h)-y)/4, ((y+h)-y)/4, cep, num, face, (nx + ((((y+h)-y)/4)/2)) - 3 , (ny + ((((y+h)-y)/4)/2)) + 3 );
                insertElemento(listaC, elemento);
                fprintf(saida, "%d casos em %s\n", n, cep);
            break;
        }
    }
}

void socorro(listaCidade listacidade, int n_postos, char *cep, char face, int num, FILE *saida){
     Node listaC = getListaCasosCovid(listacidade);
     Node listaF = getListaFormas(listacidade);
     Node listaP = getListaPostos(listacidade);
     Node quadraCovid = comparaCepQuadra(listacidade, cep);
     tipo elemento, ps;
    
     double x, y, w, h, nx, ny, cx, cy;
     double postoX[100], postoY[100];
     double distanciaPosto[100];   
     Node P;
     int totalP = 0;

        if(listaP != NULL){
            if(quadraCovid != NULL){
                x = getXQuadra(quadraCovid);
                y = getYQuadra(quadraCovid);
                w = getWQuadra(quadraCovid);
                h = getHQuadra(quadraCovid);
                P = getFirst(listaP);

                while(P != NULL){
                    ps = getElemento(P);
                    postoX[totalP] = getXPosto(ps);
                    postoY[totalP] = getYPosto(ps);
                    P = getNext(P);
                    totalP = totalP + 1; 
                }

                switch(face){
                    case 'S':
                        nx = x + num;
                        ny = y;
                        cx = (nx + ((((y+h)-y)/4)/2));
                        cy = (ny + ((((y+h)-y)/4)/2));
                        elemento = criaCaso(0, nx, ny, ((y+h)-y)/4, ((y+h)-y)/4, cep, num, face, cx-3 , cy+3 );
                        insertElemento(listaC, elemento);
                    break;

                    case 'N':
                        nx = x + num;
                        ny = y + ((3*((y+h)-y))/4);
                        cx = (nx + ((((y+h)-y)/4)/2));
                        cy = (ny + ((((y+h)-y)/4)/2));
                        elemento = criaCaso(0, nx, ny, ((y+h)-y)/4, ((y+h)-y)/4, cep, num, face, cx - 3 , cy + 3 );
                        insertElemento(listaC, elemento);
                    break;

                    case 'L':
                        nx = x;
                        ny = y + num;
                        cx = (nx + ((((y+h)-y)/4)/2));
                        cy = (ny + ((((y+h)-y)/4)/2));
                        elemento = criaCaso(0, nx, ny, ((y+h)-y)/4, ((y+h)-y)/4, cep, num, face, cx - 3 , cy + 3 );
                        insertElemento(listaC, elemento);
                    break;

                    case 'O':
                        nx = x + ((3*((x + w)-x))/4);
                        ny = y + num;
                        cx = (nx + ((((y+h)-y)/4)/2));
                        cy = (ny + ((((y+h)-y)/4)/2));
                        elemento = criaCaso(0, nx, ny, ((y+h)-y)/4, ((y+h)-y)/4, cep, num, face, cx - 3 , cy + 3 );
                        insertElemento(listaC, elemento);
                    break;
                }

                for(int i = 0; i < totalP; i++){
                    distanciaPosto[i] = dist(cx, cy, postoX[i], postoY[i]);
                    printf("dist posto: %lf\n", distanciaPosto[i]);
                }

                if(totalP == 1){
                    elemento = criaLinhaTracejada(0, cx, cy, postoX[0], postoY[0], "black");
                    insertElemento(listaF, elemento);
                    fprintf(saida, "posto em x: %lf y: %lf\n", postoX[0], postoY[0]);
                }
                else{
                    double aux;
                    for(int i = 0; i < totalP-1; i++){
                        for(int j = i; j < totalP - 1; j++){
                            if(distanciaPosto[j+1] < distanciaPosto[i]){
                                aux = distanciaPosto[i];
                                distanciaPosto[i] = distanciaPosto[j+1];
                                distanciaPosto[j+1] = aux;

                                aux = postoX[i];
                                postoX[i] = postoX[j+1];
                                postoX[j+1] = aux;

                                
                                aux = postoY[i];
                                postoY[i] = postoY[j+1];
                                postoY[j+1] = aux;
                            }
                        }
                    }

                    for (int i = 0; i < totalP; i++){
                        if(i < n_postos){
                        elemento = criaLinhaTracejada(0, cx, cy, postoX[i], postoY[i], "black");
                        insertElemento(listaF, elemento);
                        fprintf(saida, "posto em x: %lf y: %lf\n", postoX[i], postoY[i]);
                        }
                    }
                }

            }
        }

}       

void incidenciaRelativa(listaCidade lista, double cx, double cy, double r, FILE *saida){
    double x, y, x2, y2;
    int nCasosTotais = 0;
    Node listaIncidencia;
        listaIncidencia = getListaCasosCovid(lista);
    Node I; 
    tipo i;
        I = getFirst(listaIncidencia);

    if(I != NULL){
        while(I != NULL){
                i = getElemento(I);
                x = getXCasosCovid(i);
                y = getYCasosCovid(i);
                x2 = (x + getWCasosCovid(i));
                y2 = (y + getHCasosCovid(i));
                if( ((pow((x - cx), 2) + (pow((y - cy), 2)) <= pow(r, 2)) )||  
                ((pow((x - cx), 2) + (pow((y2 - cy), 2)) <= pow(r, 2)) ) ||
                ((pow((x2 - cx), 2) + (pow((y - cy), 2)) <= pow(r, 2)) )||
                ((pow((x2 - cx), 2) + (pow((y2 - cy), 2)) <= pow(r, 2))) ){
                    nCasosTotais = nCasosTotais + getNCasosCovid(i);
                }
            I = getNext(I);
        }

        
    }
}