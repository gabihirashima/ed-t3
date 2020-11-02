#ifndef LISTAOBJURBANOS_H_
#define LISTAOBJURBANOS_H_

typedef void *listaObjetos;

listaObjetos criaHidrante(char id[], double x, double y, char corb[], char corp[], char sw[]);

listaObjetos criaSemaforo(char id[], double x, double y, char corb[], char corp[], char sw[]);

listaObjetos criaRadio(char id[], double x, double y, char corb[], char corp[], char sw[]);

char *getIdObjetos(listaObjetos Lista);

double getXObjetos(listaObjetos Lista);

double getYObjetos(listaObjetos Lista);

char *getSwObjetos(listaObjetos Lista);

char *getCorbObjetos(listaObjetos Lista);

char *getCorpObjetos(listaObjetos Lista);

char getCharIdObjetos(listaObjetos Lista);

#endif