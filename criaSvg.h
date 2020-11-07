#ifndef CRIASVG_H_
#define CRIASVG_H_

#include <stdio.h>
#include "listaCidades.h"

/*Função para desenhar semaforo no arquivo .svg*/
void desenhaSemaforo(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw);

/*Função para desenhar radio no arquivo .svg*/
void desenhaRadio(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw);

/*Função para desenhar quadra no arquivo .svg*/
void desenhaQuadra(FILE *saida, double x, double y, double w, double h, char *cfill, char *cstrk, char *sw);

/*Função para desenhar hidrante no arquivo .svg*/
void desenhaHidrante(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw);

/*Função para desenhar texto no arquivo .svg*/
void desenhaTexto(FILE *saida, double x, double y, char *corb, char *corp, char *text);

/*Função para desenhar retangulo no arquivo .svg*/
void desenhaRetangulo(FILE *saida, double x, double y, double w, double h, double rx, double ry, char *corp, char *corb, char *rw);

/*Função para desenhar retangulo pontilhado no arquivo .svg*/
void desenhaRetanguloPontilhado(FILE *saida, double x, double y, double w, double h, double rx, double ry, char *corp, char *corb, char *rw);

/*Função para desenhar linha no arquivo .svg*/
void desenhaLinha(FILE *saida, double x1, double x2, double y1, double y2, char *corb);

/*Função para desenhar linha tracejada no arquivo .svg*/
void desenhaLinhaTracejada(FILE *saida, double x1, double x2, double y1, double y2, char *corb);

/*Função para desenhar circulo no arquivo .svg*/
void desenhaCirculo(FILE *saida, double x, double y, double r, char *corp, char *corb, char *cw);

/*Função para desenhar posto de saude no arquivo .svg*/
void desenhaPostoSaude(FILE *saida, double x, double y);

/*Função para desenhar caso de covid (desenha o caso de cv e o socorro) no arquivo .svg*/
void desenhaCasoCovid(FILE *saida, double xQ, double yQ, double wQ, double hQ, int n, double xT, double yT);

/*Gera o svg a partir das informações nas listas*/
void svgen(listaCidade listacidade,char *out);

#endif