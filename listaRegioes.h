#ifndef LISTAREGIOES_H_
#define LISTAREGIOES_H_

/*Define listaRegiao como ponteiro void*/
typedef void *listaRegiao;

/*Cria o elemento Regiao e retorna o ponteiro desse elemento*/
listaRegiao criaRegiao(int id, double x, double y, double w, double h, double d);

/*Retorna int do elemento pertencente a lista de Regiao*/
int getIdRegiao(listaRegiao lista);

/*Retorna X do elemento pertencente a lista de Regiao*/
double getXRegiao(listaRegiao lista);

/*Retorna Y do elemento pertencente a lista de Regiao*/
double getYRegiao(listaRegiao lista);

/*Retorna W do elemento pertencente a lista de Regiao*/
double getWRegiao(listaRegiao lista);

/*Retorna H do elemento pertencente a lista de Regiao*/
double getHRegiao(listaRegiao lista);

/*Retorna D do elemento pertencente a lista de Regiao*/
double getDRegiao(listaRegiao lista);

/*Retorna Categoria do elemento pertencente a lista de Regiao*/
char getCategoriaRegiao(listaRegiao lista);

/*Altera categoria do elemento pertencente a lista de Regiao*/
void setCategoriaRegiao(listaRegiao lista, char categoria);

#endif