#ifndef LISTACASOSCOVID_H_
#define LISTACASOSCOVID_H_

typedef void *listacasos;

listacasos criaCaso(int n_casos, double x, double y, double w, double h, char *cep, int num, char face, double xT, double yT);

int getNCasosCovid(listacasos lista);

double getXCasosCovid(listacasos lista);

double getYCasosCovid(listacasos lista);

double getWCasosCovid(listacasos lista);

double getHCasosCovid(listacasos lista);

char *getCepCasosCovid(listacasos lista);

double getNumCasosCovid(listacasos lista);

char getFaceCasosCovid(listacasos lista);

double getxTCasosCovid(listacasos lista);

double getyTCasosCovid(listacasos lista);

void setNCasosCovid(listacasos lista, int n_casos);

#endif
