#ifndef LISTAOBJURBANOS_H_
#define LISTAOBJURBANOS_H_

/*Define listaObjetos como ponteiro void*/
typedef void *listaObjetos;

/*Cria o elemento Hidrante e retorna o ponteiro desse elemento*/
listaObjetos criaHidrante(char id[], double x, double y, char corb[], char corp[], char sw[]);

/*Cria o elemento Semaforo e retorna o ponteiro desse elemento*/
listaObjetos criaSemaforo(char id[], double x, double y, char corb[], char corp[], char sw[]);

/*Cria o elemento Radio e retorna o ponteiro desse elemento*/
listaObjetos criaRadio(char id[], double x, double y, char corb[], char corp[], char sw[]);

/*Retorna id do elemento pertencente a lista de objetos*/
char *getIdObjetos(listaObjetos Lista);

/*Retorna X do elemento pertencente a lista de objetos*/
double getXObjetos(listaObjetos Lista);

/*Retorna Y do elemento pertencente a lista de objetos*/
double getYObjetos(listaObjetos Lista);

/*Retorna Sw do elemento pertencente a lista de objetos*/
char *getSwObjetos(listaObjetos Lista);

/*Retorna Corb do elemento pertencente a lista de objetos*/
char *getCorbObjetos(listaObjetos Lista);

/*Retorna Corp do elemento pertencente a lista de objetos*/
char *getCorpObjetos(listaObjetos Lista);

/*Retorna CharId do elemento pertencente a lista de objetos*/
char getCharIdObjetos(listaObjetos Lista);

#endif