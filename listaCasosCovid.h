#ifndef LISTACASOSCOVID_H_
#define LISTACASOSCOVID_H_

typedef void *listacasos;

listacasos criaCaso(int n_casos, double x, double y, double w, double h);

int getNCasosCovid(listacasos lista);

double getXCasosCovid(listacasos lista);

double getYCasosCovid(listacasos lista);

double getWCasosCovid(listacasos lista);

double getHCasosCovid(listacasos lista);

#endif
