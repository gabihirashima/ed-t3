#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "criaSvg.h"
#include "lista.h"
#include "listaCidades.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"

void desenhaSemaforo(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double w, h;
    w =  8;
    h =  20;
    fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n"
    , x, y, w, h, cfill, cstrk, sw );
}

void desenhaRadio(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double r;
    r = 6;
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", 
    x, y, r, cfill, cstrk, sw);
}

void desenhaQuadra(FILE *saida, double x, double y, double w, double h, char *cfill, char *cstrk, char *sw){
    fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n"
    , x, y, w, h, cfill, cstrk, sw );
}

void desenhaHidrante(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double r;
    r = 6;
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", 
    x, y, r, cfill, cstrk, sw);
}

void desenhaTexto(FILE *saida, double x, double y, char *corb, char *corp, char *text){
    fprintf(saida, "<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" fill=\"%s\">%s</text>\n",
     x, y, corb, corp, text);
}

void desenhaRetangulo(FILE *saida, double x, double y, double w, double h, double rx, double ry, char *corp, char *corb, char *rw){
     fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height =\"%lf\" rx=\"%lf\" ry=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\"/>\n",
     x, y, w, h, rx, ry, corb, corp, rw);
}

void desenhaRetanguloPontilhado(FILE *saida, double x, double y, double w, double h, double rx, double ry, char *corp, char *corb, char *rw){
     fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height =\"%lf\" rx=\"%lf\" ry=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\" stroke-dasharray=\"4\"/>\n",
     x, y, w, h, rx, ry, corb, corp, rw);
}

void desenhaLinha(FILE *saida, double x1, double x2, double y1, double y2, char *corb){
    fprintf(saida, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n",
      x1, y1, x2, y2, corb);
}

void desenhaCirculo(FILE *saida, double x, double y, double r, char *corp, char *corb, char *cw){
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\"  fill=\"%s\" stroke-width=\"%s\" />\n",
    x, y, r, corb, corp, cw);
}

void svgen(listaCidade listacidade,char *out){
    FILE *svg;
    Node listQ = getListaQuadras(listacidade);
    Node listO = getListaObjetos(listacidade);
    Node listF = getListaFormas(listacidade);

    Node Q = getFirst(listQ);
    Node O = getFirst(listO);
    Node F = getFirst(listF);

    tipo q, o, f;

    svg = fopen(out,"w");

    if(svg==NULL){
        perror("nao foi possivel operar arquivo svg");
        exit(1);
    }

    fprintf(svg,"<svg>\n");

    while(Q!=NULL){
        q = getElemento(Q);
        desenhaQuadra(svg,getXQuadra(q),getYQuadra(q),getWQuadra(q),getHQuadra(q),getCorpQuadra(q),getCorbQuadra(q),getSwQuadra(q));
        Q = getNext(Q);
    }
    while(O!=NULL){
        o = getElemento(O);
        char c = getCharIdObjetos(o);
            if (c == 'h'){
                desenhaHidrante(svg, getXObjetos(o), getYObjetos(o), getCorpObjetos(o), getCorbObjetos(o), getSwObjetos(o));
            }
            else if (c == 's'){
                desenhaSemaforo(svg, getXObjetos(o), getYObjetos(o), getCorpObjetos(o), getCorbObjetos(o), getSwObjetos(o));
            }
            else if (c == 'b'){
                desenhaRadio(svg, getXObjetos(o), getYObjetos(o), getCorpObjetos(o), getCorbObjetos(o), getSwObjetos(o));
            }
        O = getNext(O);
    }
    while(F!=NULL){
        f = getElemento(F);
        char c = getCharIdFormas(f);
            if(c == 'c'){
                desenhaCirculo(svg, getXFormas(f), getYFormas(f), getRFormas(f), getCorpFormas(f), getCorbFormas(f), getCWFormas(f));
            }
            else if(c == 'r'){
                desenhaRetangulo(svg, getXFormas(f), getYFormas(f), getWFormas(f), getHFormas(f), getRxFormas(f), getRyFormas(f), getCorpFormas(f), getCorbFormas(f), getCWFormas(f));
            }
            else if(c == 'x'){
                desenhaRetanguloPontilhado(svg, getXFormas(f), getYFormas(f), getWFormas(f), getHFormas(f), getRxFormas(f), getRyFormas(f), getCorpFormas(f), getCorbFormas(f), getCWFormas(f));
            }
            else if(c == 'l'){
                desenhaLinha(svg, getXFormas(f), getX2Formas(f), getYFormas(f), getY2Formas(f), getCorpFormas(f));
            }
            else if(c == 't'){
                desenhaTexto(svg, getXFormas(f), getYFormas(f), getCorbFormas(f), getCorpFormas(f), getTextFormas(f));
            }
        F = getNext(F);

    }
    fprintf(svg,"\n</svg>");
    fclose(svg);
}