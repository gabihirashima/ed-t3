#ifndef LISTACASOSCOVID_H_
#define LISTACASOSCOVID_H_

/*define o listacasos como ponteiro void*/
typedef void *listacasos;

/*cria caso de covid*/
listacasos criaCaso(int n_casos, double x, double y, double w, double h, char *cep, int num, char face, double xT, double yT);

/*retorna o numero de casos de covid*/
int getNCasosCovid(listacasos lista);

/*retorna a coordenada x de onde se encontra o(s) caso(s) de covid*/
double getXCasosCovid(listacasos lista);

/*retorna a coordenada y de onde se encontra o(s) caso(s) de covid*/
double getYCasosCovid(listacasos lista);

/*retorna a largura de onde se encontra o(s) caso(s) de covid*/
double getWCasosCovid(listacasos lista);

/*retorna a altura de onde se encontra o(s) caso(s) de covid*/
double getHCasosCovid(listacasos lista);

/*retorna o cep de onde se encontra o(s) caso(s) de covid*/
char *getCepCasosCovid(listacasos lista);

/*retorna o número do endereço de onde se encontra o(s) caso(s) de covid*/
double getNumCasosCovid(listacasos lista);

/*retorna a face da quadra de onde se encontra o(s) caso(s) de covid*/
char getFaceCasosCovid(listacasos lista);

/*retorna o ponto central x de onde se encontra o(s) caso(s) de covid*/
double getxTCasosCovid(listacasos lista);

/*retorna o ponto central y de onde se encontra o(s) caso(s) de covid*/
double getyTCasosCovid(listacasos lista);

/*altera o numero de casos de covid*/
void setNCasosCovid(listacasos lista, int n_casos);

#endif
