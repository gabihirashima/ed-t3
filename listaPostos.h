#ifndef LISTAPOSTOS_H_
#define LISTAPOSTOS_H_

/*Define listaPosto como ponteiro void*/
typedef void *listaPosto;

/*Cria o elemento Posto e retorna o ponteiro desse elemento*/
listaPosto criaPosto(int id, double x, double y);

/*Retorna id do elemento pertencente a lista de Postos*/
int getIdPosto(listaPosto lista);

/*Retorna X do elemento pertencente a lista de Postos*/
double getXPosto(listaPosto lista);

/*Retorna Y do elemento pertencente a lista de Postos*/
double getYPosto(listaPosto lista);

#endif