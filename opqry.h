#ifndef OPQRY_H_
#define OPQRY_H_

#include <stdio.h>
#include "listaCidades.h"
#include "lista.h"

/*Retorna o maior valor entre n1 e n2*/
float max(float n1, float n2);

/*Retorna o menor valor entre n1 e n2*/ 
float min(float n1, float n2);

/*Verifica se o circulo e o retangulo se sobrepoe e passa o  resultado da verificação para a lista de qry e para o txt*/
int sobrepoeCirculoRetangulo(listaCidade listacidade, Node circulo, Node retangulo);

/*Verifica se o circulo e o circulo se sobrepoe e passa o  resultado da verificação para a lista de qry e para o txt*/
int sobrepoeCirculoCirculo(listaCidade listacidade, Node circulo1, Node circulo2);

/*Verifica se o retangulo e o retangulo se sobrepoe e passa o  resultado da verificação para a lista de qry e para o txt*/
int sobrepoeRetanguloRetangulo(listaCidade listacidade, Node retangulo1, Node retangulo2);

/*Verifica qual o tipo de verificação entre objetos irá ocorrer*/
void sobreposicao(int i, int k, listaCidade lista, FILE *txt);

/*Verifica se um ponto é interno a uma figura e passa o  resultado da verificação para a lista de qry e para o txt*/
void pontoInterno(int j, double x, double y, listaCidade lista, FILE *saida);

/*Altera a cor de uma figura j, altera a lista de qry e passa a figura alterada para txt*/
void pnt(int j, char *novoCorb, char *novoCorp, listaCidade lista, FILE *saida);

/*Apaga uma figura j da lista, altera a lista de qry e passa as verificações para txt*/
void delf(int j, listaCidade lista, FILE *saida);

/*Calcula a distância entre dois pontos*/
double dist(double x1, double y1, double x2, double y2);

/*Função para deletar quadras dentro de uma distancia r de um equipamento urbano. Se o parametro htag for '#' 
as quadras removidas devem aparecer com as bordas arredondadas, caso contrário, apenas apagar*/
void delQuadras(listaCidade listacidade, FILE *txt, int htag, char *id, double r);

/*Função para deletar objetos urbanos*/
void delUrb(listaCidade listacidade, FILE *txt, char *cid);

/*Função para alterar cor de borda de todas as quadras contidas dentro do circulo com centro em (x,y) e com raio r*/
void colorBorder(listaCidade listacidade, FILE *txt, double x, double y, double r, char *cstrk);

/*Imprime no txt as coordenadas do equipamento urbano de um determinado cep ou com uma determina identificação*/
void coord(listaCidade listacidade, FILE *txt, char *cid);

/*Calcula a área total das quadras e dos equipamentos urbanos que estiverem dentro do retângulo*/
void rectArea(listaCidade listacidade, FILE *txt, double x, double y, double w, double h);


#endif