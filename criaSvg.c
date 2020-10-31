#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "criaSvg.h"

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

void desenhaLinha(FILE *saida, double x1, double x2, double y1, double y2, char *corb){
    fprintf(saida, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n",
      x1, y1, x2, y2, corb);
}

void desenhaCirculo(FILE *saida, double x, double y, double r, char *corp, char *corb, char *cw){
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\"  fill=\"%s\" stroke-width=\"%s\" />\n",
    x, y, r, corb, corp, cw);
}
