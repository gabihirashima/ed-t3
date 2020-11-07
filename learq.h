#ifndef LEARQ_H_
#define LEARQ_H_

#include "listaCidades.h"
#include "lista.h"

/*Abre o arquivo geo, insere os elementos na lista e gera o svg de .geo*/
void openGeo(listaCidade listacidade, char *nomeGeo, char *saidaSvg);

/*Abre o arquivo qry, realiza as alterações necessárias na lista e gera o svg de .qry*/
void openQry(listaCidade listacidade, char *entradaQry, char *saidaQry);

#endif