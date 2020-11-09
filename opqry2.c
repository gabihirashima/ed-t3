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
#include "learq.h"

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

void quicksortPointsStack(listaStruct lista){

}

void shellsort(double distanciaPostos[], double postoX[], double postoY[], int n_postos){
    int i, j, k;
    double temp;
        for(i = n_postos/2; i > 0; i = i/2){
            for(j = i; j < n_postos; j++){
                for(k = j - i; k >= 0; k = k - i){
                    if(distanciaPostos[k+i] >= distanciaPostos[k])
                        break;
                    else{
                        temp = distanciaPostos[k];
                        distanciaPostos[k] = distanciaPostos[k+i];
                        distanciaPostos[k+i] = temp;

                        temp = postoX[k];
                        postoX[k] = postoX[k+i];
                        postoX[k+i] = temp;

                        temp = postoY[k];
                        postoY[k] = postoY[k+i];
                        postoY[k+i] = temp;
                    }
                }
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
                    /*printf("dist posto: %lf\n", distanciaPosto[i]);*/
                }

                if(totalP == 1){
                    elemento = criaLinhaTracejada(0, cx, cy, postoX[0], postoY[0], "black");
                    insertElemento(listaF, elemento);
                    fprintf(saida, "posto em x: %lf y: %lf\n", postoX[0], postoY[0]);
                }
                else{
                    shellsort(distanciaPosto, postoX, postoY, totalP);
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

double ConvexArea(listaStruct hull){ //Método de Gauss para calcular a área de polígonos irregulares, recebe uma lista com os pontos da envoltória convexa
    Node P = getFirst(hull);
    double a1 = 0, a2 = 0, area;
    tipo p;

    while(getNext(P)!=NULL){
        p = getElemento(P);
        a1 = a1 + getXCasosCovid(p)*getYCasosCovid(getElemento(getNext(P)));
        a2 = a2 + getYCasosCovid(p)*getXCasosCovid(getElemento(getNext(P)));
        P = getNext(P);
    }

    area = (a1-a2)/2;

    return area;
}

double *ConvexCentroid(listaStruct hull){ //Retorna um vetor de dois atributos double que são as coordenadas do centróide do polígono, sendo C[0] = Cx e C[1] = Cy
    Node P = getFirst(hull);
    double *C;
    C[0] = 0;
    C[1] = 0;
    tipo p;

    while(getNext(P)!=NULL){
        p = getElemento(P);
        C[0] = C[0] + (getXCasosCovid(p)+getXCasosCovid(getElemento(getNext(P)))) * (getXCasosCovid(p)*getYCasosCovid(getElemento(getNext(P))) + getYCasosCovid(p)*getXCasosCovid(getElemento(getNext(P))));
        C[1] = C[1] + (getYCasosCovid(p)+getYCasosCovid(getElemento(getNext(P)))) * (getYCasosCovid(p)*getXCasosCovid(getElemento(getNext(P))) + getXCasosCovid(p)*getYCasosCovid(getElemento(getNext(P))));
        P = getNext(P);
    }

    C[0] = C[0]/6*ConvexArea(hull);
    C[1] = C[1]/6*ConvexArea(hull);

    return C;
}

int orientacao(tipo a, tipo b, tipo c){
    if(a == NULL || b == NULL || c == NULL)
        return 2;
    
    double dir = (getYCasosCovid(b) - getYCasosCovid(a)) * (getXCasosCovid(c) - getXCasosCovid(b)) - (getXCasosCovid(b) - getXCasosCovid(a)) * (getYCasosCovid(c) - getYCasosCovid(b));

    if(dir == 0)
        return 0;

    if(dir > 1)
        return 1;

    return 2;
}

int compara(tipo a, tipo b, tipo p){
    int o = orientacao(p, a, b);
    if(o == 0){
        
        if(dist(getXCasosCovid(p),getYCasosCovid(p),getXCasosCovid(b),getYCasosCovid(b)) >= dist(getXCasosCovid(p),getYCasosCovid(p),getXCasosCovid(a),getYCasosCovid(a)))
            return -1;
        
        return 1;
    }
    if(o == 2)
        return -1;
    
    return 1;
}

void incidenciaRelativa(listaCidade lista, double cx, double cy, double r, FILE *saida){
    double x, y, x2, y2, hx, hy;
    int nCasosTotais = 0, n = 0;
    Node listaIncidencia;
        listaIncidencia = getListaCasosCovid(lista);
    Node I; 
        I = getFirst(listaIncidencia);
    tipo i;

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

        I = getFirst(listaIncidencia);
        i = getElemento(I);
        hx = getXCasosCovid(i);
        hy = getYCasosCovid(i);
        I = getNext(I);
        while(I != NULL){
            i = getElemento(I);
            if(hy > getYCasosCovid(i)){
                hx = getXCasosCovid(i);
                hy = getYCasosCovid(i);
            }
            I = getNext(I);
        }

        I = getFirst(listaIncidencia);
        while(I != NULL){
            i = getElemento(I);
            n++;
            if(hy == getYCasosCovid(i))
                hx = min(hx, getXCasosCovid(i));
            I = getNext(I);
        }

        listaStruct HullStack = criaLista();
        I = getFirst(listaIncidencia);
        while(I != NULL){
            i = getElemento(I);
            if(hy == getYCasosCovid(i) && hx == getXCasosCovid(i))
                insertElemento(HullStack, i);
            I = getNext(I);
        }

        I = getFirst(listaIncidencia);
         while(I != NULL){
            i = getElemento(I);
            insertElemento(HullStack, i);
            I = getNext(I);
        }

        //qsort(HullStack, n-1, sizeof(listaIncidencia), compara);

    }

}