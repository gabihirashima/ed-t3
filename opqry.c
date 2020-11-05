#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "opqry.h"
#include "criaSvg.h"
#include "learq.h"
#include "lista.h"
#include "listaCidades.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"

float max(float n1, float n2){
    if(n1 > n2){
        return n1;
    }
    return n2;
}

float min(float n1, float n2){
    if(n1 > n2){
        return n2;
    }
    return n1;
}

int sobrepoeCirculoRetangulo(listaCidade listacidade, Node circulo, Node retangulo){
    double deltaX, deltaY, x, y, h, w;
    double xc, yc, rc;
    double xr, yr, wr, hr;

    Node listaF = getListaFormas(listacidade);
    tipo elemento;

    xc = getXFormas(circulo);
    yc = getYFormas(circulo);
    rc = getRFormas(circulo);
    xr = getXFormas(retangulo);
    yr = getYFormas(retangulo);
    wr = getWFormas(retangulo);
    hr = getHFormas(retangulo);

    deltaX = ((xc) - max(xr, min(xc, xr + wr)));
    deltaY = ((yc) - max(yr, min(yc, yr + hr)));

    x = min((xr), (xc - rc));
    y = min((yr), (yc - rc));
    w = max((xr + wr), (xc + rc)) - x;
    h = max((yr + hr), (yc + rc)) - y;

        if (((deltaX * deltaX) + (deltaY * deltaY)) <= (rc*rc)){
            elemento = criaRetangulo(0, w, h, x, y, 0, 0, "black", "transparent", getCWFormas(retangulo));
            insertElemento(listaF, elemento);
            return 1;
        }
        else
        {   
            elemento = criaRetanguloPontilhado(0, w, h, x, y, 0, 0, "black", "transparent", getCWFormas(retangulo));
            insertElemento(listaF, elemento);
            return 0;
        }
}

int sobrepoeCirculoCirculo(listaCidade listacidade, Node circulo1, Node circulo2){
    double distancia, x, y, w, h;
    double  xc1, yc1, rc1;
    double  xc2, yc2, rc2;

    xc1 = getXFormas(circulo1);
    yc1 = getYFormas(circulo1);
    rc1 = getRFormas(circulo1);
    xc2 = getXFormas(circulo2);
    yc2 = getYFormas(circulo2);
    rc2 = getRFormas(circulo2);

    Node listaF = getListaFormas(listacidade);
    tipo elemento;

    distancia = sqrt(pow(xc1 - xc2, 2)+ pow(yc1 - yc2, 2));

    x = min(xc1 - rc1, xc2 - rc2);
    y = min(yc1 - rc1, yc2 - rc2);
    w = max(xc1 + rc1, xc2 + rc2) - x;
    h = max(yc1 + rc1, yc2 + rc2) - y;

    if (distancia <= (rc1 + rc2)){
        elemento = criaRetangulo(0, w, h, x, y, 0, 0, "black", "transparent", getCWFormas(circulo1));
        insertElemento(listaF, elemento);
        return 1;
    }
    else{
        elemento = criaRetanguloPontilhado(0, w, h, x, y, 0, 0, "black", "transparent", getCWFormas(circulo1));
        insertElemento(listaF, elemento);
        return 0;
    }
}

int sobrepoeRetanguloRetangulo(listaCidade listacidade, Node retangulo1, Node retangulo2){
    double x, y, w, h;

    double xr1, yr1, wr1, hr1;
    double xr2, yr2, wr2, hr2;

    xr1 = getXFormas(retangulo1);
    yr1 = getYFormas(retangulo1);
    wr1 = getWFormas(retangulo1);
    hr1 = getHFormas(retangulo1);
    xr2 = getXFormas(retangulo2);
    yr2 = getYFormas(retangulo2);
    wr2 = getWFormas(retangulo2);
    hr2 = getHFormas(retangulo2);

    Node listaF = getListaFormas(listacidade);
    tipo elemento;

    x = min(xr1, xr2);
    y = min(yr1, yr2);
    w = max(xr1 + wr1, xr2 + wr2) - x;
    h = max(yr1 + hr1, yr2 + hr2) - y;
    if((wr1 + wr2) >= w && (hr1 + hr2) >= h){
        elemento = criaRetangulo(0, w, h, x, y, 0, 0, "black", "transparent", getCWFormas(retangulo1));
        insertElemento(listaF, elemento);
        return 1;
    }
    else{
        elemento = criaRetanguloPontilhado(0, w, h, x, y, 0, 0, "black", "transparent", getCWFormas(retangulo1));
        insertElemento(listaF, elemento);
        return 0;
    }
}

void sobreposicao(int i, int k, listaCidade lista, FILE *txt){
    Node forma1, forma2; 
    int teste; 
    
    forma1 = comparaIdFormas(lista, i);
    forma2 = comparaIdFormas(lista, k);

    char f1, f2;

        f1 = getCharIdFormas(forma1);
        f2 = getCharIdFormas(forma2);

    if(forma1 != NULL && forma2 != NULL){
        if(f1 == 'c'){
            if(f2 == 'c'){
                teste = sobrepoeCirculoCirculo(lista, forma1, forma2);
                if(teste == 1){
                        fprintf(txt, "%d:circulo %d:circulo SIM\n", getIdFormas(forma1), getIdFormas(forma2));
                }
                else{
                        fprintf(txt, "%d:circulo %d:circulo NAO\n", getIdFormas(forma1), getIdFormas(forma2));
                }
            }
            else if (f2 == 'r'){
                teste = sobrepoeCirculoRetangulo(lista, forma1, forma2);
                 if(teste == 1){
                    fprintf(txt, "%d:circulo %d:retangulo SIM\n", getIdFormas(forma1), getIdFormas(forma2));
                }
                else{
                    fprintf(txt, "%d:circulo %d:retangulo NAO\n", getIdFormas(forma1), getIdFormas(forma2));
                }      
            }
        }
        else if(f1 == 'r'){
            if(f2 == 'c'){
                teste = sobrepoeCirculoRetangulo(lista, forma2, forma1);
                if(teste == 1){
                    fprintf(txt, "%d:retangulo %d:retangulo SIM\n", getIdFormas(forma1), getIdFormas(forma2));
                }
                else{
                    fprintf(txt, "%d:retangulo %d:retangulo NAO\n", getIdFormas(forma1), getIdFormas(forma2));
                }
            }
            else if (f2 == 'r'){
                teste = sobrepoeRetanguloRetangulo(lista, forma1, forma2);
                if(teste == 1){
                    fprintf(txt, "%d:retangulo %d:circulo SIM\n", getIdFormas(forma1), getIdFormas(forma2));
                }
                else{
                    fprintf(txt, "%d:retangulo %d:circulo NAO\n", getIdFormas(forma1), getIdFormas(forma2));
                }
            }
        }
    }
}

void pontoInterno(int j, double x, double y, listaCidade lista, FILE *saida){
    
    char cor[10];
    Node listaF = getListaFormas(lista);
    Node forma1;
    tipo elemento; 

    forma1 = comparaIdFormas(lista, j);

    char f1;

    f1 = getCharIdFormas(forma1);

    if(forma1 != NULL){
        if(f1 == 'c'){
            fprintf(saida, "%d: circulo", getIdFormas(forma1));
            if(pow(x - getXFormas(forma1), 2) + pow(y - getYFormas(forma1), 2) <= (pow(getRFormas(forma1), 2))){
                strcpy(cor, "blue");
                elemento = criaCirculo(0, 1, x, y, cor, cor, getCWFormas(forma1));
                insertElemento(listaF, elemento);
                elemento = criaLinha(0, x, y, getXFormas(forma1), getYFormas(forma1), cor);
                insertElemento(listaF, elemento);
                fprintf(saida, " INTERNO\n");
            }
            else{
                strcpy(cor, "magenta");
                elemento = criaCirculo(0, 1, x, y, cor, cor, getCWFormas(forma1));
                insertElemento(listaF, elemento);
                elemento = criaLinha(0, x, y, getXFormas(forma1), getYFormas(forma1), cor);
                insertElemento(listaF, elemento);
                fprintf(saida, " NAO INTERNO\n");
            }
        }
        else{
                fprintf(saida, "%d: retangulo", getIdFormas(forma1));
                if((x >= getXFormas(forma1) && x<= (getXFormas(forma1) + getWFormas(forma1)))&&(y >= getYFormas(forma1) && y <= (getYFormas(forma1) + getHFormas(forma1)))){
                    strcpy(cor, "blue");
                    elemento = criaCirculo(0, 1, x, y, cor, cor, getCWFormas(forma1));
                    insertElemento(listaF, elemento);
                    elemento = criaLinha(0, x, y, (getWFormas(forma1))/2, (getHFormas(forma1))/2, cor);
                    insertElemento(listaF, elemento);
                    fprintf(saida, " INTERNO\n");
                }
                else{
                    strcpy(cor, "magenta");
                    elemento = criaCirculo(0, 1, x, y, cor, cor, getCWFormas(forma1));
                    insertElemento(listaF, elemento);
                    elemento = criaLinha(0, x, y, (getWFormas(forma1))/2, (getHFormas(forma1))/2, cor);
                    insertElemento(listaF, elemento);
                    fprintf(saida, " NAO INTERNO\n");
                }
            }
    }
}

void pnt(int j, char *novoCorb, char *novoCorp, listaCidade lista, FILE *saida){

    Node forma1;
    
    forma1 = comparaIdFormas(lista, j);

    if(forma1 != NULL){
        setCorbForma(forma1, novoCorb);
        setCorpForma(forma1, novoCorp);
        fprintf(saida, "%lf %lf\n", getXFormas(forma1), getYFormas(forma1));
    }

}

void delf(int j, listaCidade lista, FILE *saida){

    Node listaF = getListaFormas(lista);
    Node forma1;
    
    forma1 = comparaIdFormas(lista, j);

    char f1;


    if(forma1 != NULL){ 
        f1 = getCharIdFormas(forma1);
        if(f1 == 'c'){
            fprintf(saida, "%d: CIRCULO x:%lf y:%lf r:%lf corb:%s corp:%s\n", getIdFormas(forma1), getXFormas(forma1), getYFormas(forma1), getRFormas(forma1), getCorbFormas(forma1), getCorpFormas(forma1));
        }
        else if(f1 == 'r'){
            fprintf(saida, "%d: RETANGULO x:%lf y:%lf w:%lf h:%lf corb:%s corp:%s\n", getIdFormas(forma1), getXFormas(forma1), getYFormas(forma1), getWFormas(forma1), getHFormas(forma1), getCorbFormas(forma1), getCorpFormas(forma1));     
        }
        else if(f1 == 't'){
            fprintf(saida, "%d: TEXTO x:%lf y:%lf corb:%s corp:%s texto:%s\n", getIdFormas(forma1), getXFormas(forma1), getYFormas(forma1), getCorbFormas(forma1), getCorpFormas(forma1), getTextFormas(forma1));     
        }
        removeElemento(listaF, forma1);
    }
}

double dist(double x1, double y1, double x2, double y2){
    return  sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void delQuadras(listaCidade listacidade, FILE *txt, int htag, char *id, double r){
    char cfill[20], cstrk[20], sw[10];
    Node ListQ = getListaQuadras(listacidade);
    Node eq,Q;
    tipo q, elemento, cq, a1, a2;
    double x, y, qx, qy, w, h;
    
    eq = comparaIdObjetos(listacidade,id);
            x = getXObjetos(eq);
            y = getYObjetos(eq);
            strcpy(cfill, getCorpObjetos(eq));
            strcpy(cstrk, getCorbObjetos(eq));
            strcpy(sw,getSwObjetos(eq));

    Q = getFirst(ListQ);

    while(Q!=NULL){
        q = getElemento(Q);
        qx = getXQuadra(q);
        qy = getYQuadra(q);
        w = getWQuadra(q);
        h = getHQuadra(q);
        
        Q = getNext(Q);
        
        if(dist(qx,qy,x,y) <=r && dist(qx+w,qy,x,y) <=r && dist(qx,qy+h,x,y) <=r && dist(qx+w,qy+h,x,y) <= r){
            fprintf(txt, "\n%s", getCepQuadra(q));
            if(htag){
                elemento = criaRetangulo(-1,w,h,qx,qy,10,10,"olive","beige",getSwQuadra(q));
                insertElemento(getListaFormas(listacidade), elemento);
            }
            removeElemento(ListQ,q); 
        }
        
    }
    a2 = criaCirculo(-1,8,x,y,"yellow","none","6.0px");
    insertElemento(getListaFormas(listacidade),a2);
    a1 = criaCirculo(-1,8,x,y,"blue","none","4.0px");
    insertElemento(getListaFormas(listacidade),a1);
    cq = criaCirculo(-1,r,x,y,"black","none","2.0px");
    insertElemento(getListaFormas(listacidade),cq);
    
    fprintf(txt, "\n%s %lf %lf %s %s %s", id, x, y, cfill, cstrk, sw);

}

void delUrb(listaCidade listacidade, FILE *txt, char *cid){
    char type = cid[0], cfill[20], cstrk[20], sw[10];
    double x, y, w, h;
    Node listQ = getListaQuadras(listacidade);
    Node listO = getListaObjetos(listacidade);
    Node urb;
    tipo dell,itxt;

        if (type == 'r' || type == 's' || type == 'h'){
            urb = comparaIdObjetos(listacidade,cid);
            x = getXObjetos(urb);
            y = getYObjetos(urb);
            strcpy(cstrk,getCorbObjetos(urb));
            strcpy(cfill,getCorpObjetos(urb));
            strcpy(sw,getSwObjetos(urb));
            fprintf(txt, "\nId: %s  X: %lf  Y: %lf  Cfill: %s  CStrk: %s  Sw: %s",cid,x,y,cfill,cstrk, sw);
            dell = criaLinha(-1,x,y,x,0,"black");
            insertElemento(getListaFormas(listacidade),dell);
            itxt = criaTexto(-1,x+2,0,"black","black",cid);
            insertElemento(getListaFormas(listacidade),itxt);
            removeElemento(listO,urb);
        }
        else{
            urb = comparaCepQuadra(listacidade,cid);
            x = getXQuadra(urb);
            y = getYQuadra(urb);
            w = getWQuadra(urb);
            h = getHQuadra(urb);
            strcpy(cfill,getCorpQuadra(urb));
            strcpy(cstrk,getCorbQuadra(urb));
            strcpy(sw,getSwQuadra(urb));
            fprintf(txt, "\nCep: %s  X: %lf  Y: %lf  W: %lf  H: %lf  Cfill: %s  CStrk:%s  Sw:%s",cid,x,y,w,h,cfill,cstrk, sw);
            dell = criaLinha(-1,x+w/2,y+h/2,x+w/2,0,"black");
            insertElemento(getListaFormas(listacidade),dell);
            itxt = criaTexto(-1,x+w/2+2,0,"black","black",cid);
            insertElemento(getListaFormas(listacidade),itxt);
            removeElemento(listQ,urb);
        }
      
}

void colorBorder(listaCidade listacidade, FILE *txt, double x, double y, double r, char *cstrk){
    Node listQ = getListaQuadras(listacidade);
    Node Q;
    tipo q;
    double qx, qy, w, h;

    Q = getFirst(listQ);
    while(Q!=NULL){
        q = getElemento(Q);
        qx = getXQuadra(q);
        qy = getYQuadra(q);
        w = getWQuadra(q);
        h = getHQuadra(q);
        
        if(dist(qx,qy,x,y) <=r && dist(qx+w,qy,x,y) <=r && dist(qx,qy+h,x,y) <=r && dist(qx+w,qy+h,x,y) <= r){
            setCorbQuadra(q,cstrk);
            fprintf(txt, "\n%s", getCepQuadra(q));
        }
        Q = getNext(Q);
    }
}


void coord(listaCidade listacidade, FILE *txt, char *cid){
    char type = cid[0];
    Node urb;

    switch(type){
        case 'r':
            urb = comparaIdObjetos(listacidade,cid);
            if(urb==NULL){
                break;
            }
            fprintf(txt,"\nId: %s  X: %lf  Y: %lf  Rádio-base",getIdObjetos(urb),getXObjetos(urb),getYObjetos(urb));
            break;
        case 's':
            urb = comparaIdObjetos(listacidade,cid);
            if(urb==NULL){
                break;
            }
            fprintf(txt,"\nId: %s  X: %lf Y: %lf  Semáforo",getIdObjetos(urb),getXObjetos(urb),getYObjetos(urb));
            break;
        case 'h':
            urb = comparaIdObjetos(listacidade,cid);
            if(urb==NULL){
                break;
            }
            fprintf(txt,"\nId: %s  X: %lf Y: %lf Hidrante",getIdObjetos(urb),getXObjetos(urb),getYObjetos(urb));
            break;
        default:
            urb = comparaCepQuadra(listacidade,cid);
            if(urb==NULL){
                break;
            }
            fprintf(txt,"\nId: %s  X: %lf  Y: %lf Quadra",getCepQuadra(urb),getXQuadra(urb),getYQuadra(urb));
            break;
    }
}

void rectArea(listaCidade listacidade, FILE *txt, double x, double y, double w, double h){
    Node listQ = getListaQuadras(listacidade);
    Node Q;
    tipo q, a, at, rq, rql;
    double qx, qy, qw, qh, A = 0, AT = 0;
    char areatxt[30],atotaltxt[30];

    Q = getFirst(listQ);
    while(Q!=NULL){
        q = getElemento(Q);
        qx = getXQuadra(q);
        qy = getYQuadra(q);
        qw = getWQuadra(q);
        qh = getHQuadra(q);

        if(qx >= x && qx + qw <= x + w && qy >= y && qy + qh <= y + h){
            A = qw*qh;
            fprintf(txt, "\nCep: %s  Area: %lf",getCepQuadra(q), A);
            sprintf(areatxt,"Area: %lf m²",A);
            a = criaTexto(-1,qx+qw/2,qy+qh/2,"black","black",areatxt);
            insertElemento(getListaFormas(listacidade),a);
            AT += A;
        }
        Q = getNext(Q);
    }
    fprintf(txt,"\nArea total: %lf m²",AT);
    rq = criaRetangulo(-1,w,h,x,y,0,0,"black","none","2.0px");
    insertElemento(getListaFormas(listacidade),rq);
    rql = criaLinha(-1,x,y,x,0,"black");
    insertElemento(getListaFormas(listacidade),rql);
    sprintf(atotaltxt,"Area Total: %lf m²",AT);
    at = criaTexto(-1,x+5,0,"black","black",atotaltxt);
    insertElemento(getListaFormas(listacidade),at);
}

