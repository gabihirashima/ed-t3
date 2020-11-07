#ifndef LISTAFORMAS_H_
#define LISTAFORMAS_H_

/*Define listaForma como ponteiro void*/
typedef void *listaForma;

/*Cria o elemento circulo e retorna o ponteiro desse elemento*/
listaForma criaCirculo(int id, double r, double x, double y, char *corb, char *corp, char *cw);

/*Cria o elemento retangulo e retorna o ponteiro desse elemento*/
listaForma criaRetangulo(int id, double w, double h, double x, double y, double rx, double ry, char *corb, char *corp, char *rw);

/*Cria o elemento retangulo pontilhado e retorna o ponteiro desse elemento*/
listaForma criaRetanguloPontilhado(int id, double w, double h, double x, double y, double rx, double ry, char *corb, char *corp, char *rw);

/*Cria o elemento linha e retorna o ponteiro desse elemento*/
listaForma criaLinha(int id, double x, double y, double x2, double y2, char *cor);

/*Cria o elemento linha tracejada e retorna o ponteiro desse elemento*/
listaForma criaLinhaTracejada(int id, double x, double y, double x2, double y2, char *cor);

/*Cria o elemento texto e retorna o ponteiro desse elemento*/
listaForma criaTexto(int id, double x, double y, char *corb, char *corp, char *texto);

/*Retorna id do elemento pertencente a lista de formas*/
int getIdFormas(listaForma lista);

/*Retorna W do elemento pertencente a lista de formas*/
double getWFormas(listaForma lista);

/*Retorna H do elemento pertencente a lista de formas*/
double getHFormas(listaForma lista);

/*Retorna X do elemento pertencente a lista de formas*/
double getXFormas(listaForma lista);

/*Retorna Y do elemento pertencente a lista de formas*/
double getYFormas(listaForma lista);

/*Retorna R do elemento pertencente a lista de formas*/
double getRFormas(listaForma lista);

/*Retorna Corb do elemento pertencente a lista de formas*/
char *getCorbFormas(listaForma lista);

/*Retorna Corp do elemento pertencente a lista de formas*/
char *getCorpFormas(listaForma lista);

/*Retorna CW do elemento pertencente a lista de formas*/
char *getCWFormas(listaForma lista);

/*Retorna Texto do elemento pertencente a lista de formas*/
char *getTextFormas(listaForma lista);

/*Retorna o Char_id do elemento pertencente a lista de formas*/
char getCharIdFormas(listaForma lista);

/*Altera o corp do elemento pertencente a lista de formas*/
void setCorpForma(listaForma lista, char *Cfill);

/*Altera a corb do elemento pertencente a lista de formas*/
void setCorbForma(listaForma lista, char *Cstroke);

/*Retorna Rx do elemento pertencente a lista de formas*/
double getRxFormas(listaForma lista);

/*Retorna Ry do elemento pertencente a lista de formas*/
double getRyFormas(listaForma lista);

/*Retorna X2 do elemento pertencente a lista de formas*/
double getX2Formas(listaForma lista);

/*Retorna Y2 do elemento pertencente a lista de formas*/
double getY2Formas(listaForma lista);

#endif