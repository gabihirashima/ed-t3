#ifndef LISTAREGIOES_H_
#define LISTAREGIOES_H_

typedef void *listaRegiao;

listaRegiao criaRegiao(int id, double x, double y, double w, double h, double d);

int getIdRegiao(listaRegiao lista);

double getXRegiao(listaRegiao lista);

double getYRegiao(listaRegiao lista);

double getWRegiao(listaRegiao lista);

double getHRegiao(listaRegiao lista);

double getDRegiao(listaRegiao lista);

#endif