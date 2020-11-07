#ifndef LISTAQUADRAS_H_
#define LISTAQUADRAS_H_

/*Define listaQuadra como ponteiro void*/
typedef void *listaQuadra;

/*Cria o elemento Quadra e retorna o ponteiro desse elemento*/
listaQuadra criaQuadra(char *cep, double x, double y, double w, double h, char *corb, char *corp, char *sw);

/*Retorna Cep do elemento pertencente a lista de Quadras*/
char *getCepQuadra(listaQuadra lista);

/*Retorna X do elemento pertencente a lista de Quadras*/
double getXQuadra(listaQuadra lista);

/*Retorna Y do elemento pertencente a lista de Quadras*/
double getYQuadra(listaQuadra lista);

/*Retorna W do elemento pertencente a lista de Quadras*/
double getWQuadra(listaQuadra lista);

/*Retorna H do elemento pertencente a lista de Quadras*/
double getHQuadra(listaQuadra lista);

/*Retorna Corb do elemento pertencente a lista de Quadras*/
char *getCorbQuadra(listaQuadra lista);

/*Retorna Corp do elemento pertencente a lista de Quadras*/
char *getCorpQuadra(listaQuadra lista);

/*Retorna Sw do elemento pertencente a lista de Quadras*/
char *getSwQuadra(listaQuadra lista);

/*Retorna Corb do elemento pertencente a lista de Quadras*/
void setCorbQuadra(listaQuadra lista, char *Cstroke);

#endif