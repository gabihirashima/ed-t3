#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "learq.h"
#include "criaSvg.h"
#include "lista.h"
#include "listaCidades.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"

char *retornaString(char *string){
     char *aux = strrchr(string,'/');
          if(aux == NULL){
             return strtok(string,".");
            }
	return strtok(&aux[1],".");
}

void tratamentoString(char *diretorio, char *arquivoGeo, char *arquivoQry, char *pastaSaida){
    char *nomeArquivoGeo = NULL; /*nome do arquivo geo pós tratamento*/
    char *nomeArquivoQry = NULL; /*nome do arquivo qry pós tratamento*/
    char *caminhoGeo = NULL; /*caminho final do arquivo geo*/
    char *caminhoQry = NULL; /*caminho final do arquivo Qry*/
    char *saidaSvg = NULL; /*caminho de saída para o arquivo Svg*/
    char *saidaQry = NULL; /*caminho de saída para o arquivo Qry*/

    listaCidade Cidade = iniciaListaCidade();

    nomeArquivoGeo = (char*)malloc( ( ( strlen(arquivoGeo) )+1 )*sizeof(char) );
            strcpy(nomeArquivoGeo, arquivoGeo);
            nomeArquivoGeo = strtok(nomeArquivoGeo, "."); /*vai retornar somente o nome anterior ao .geo*/ 
            /*printf("\n\nnome geo formatado: %s", nomeArquivoGeo);*/

            if (diretorio != NULL){/*Se foi passado um argumento de diretório*/
                caminhoGeo = (char*)malloc( ( ( strlen(diretorio) + strlen(arquivoGeo) )+8 )* sizeof(char) );
                sprintf(caminhoGeo, "%s/%s", diretorio, arquivoGeo);
                /*printf("\n\ncaminho geo com argumento de diretorio: %s", caminhoGeo);*/
                    if(arquivoQry !=  NULL){/*se foi passado um arquivo de qry*/
                        caminhoQry = (char*)malloc( ( ( strlen(diretorio) + strlen(arquivoQry) )+ 8 )* sizeof(char) );
                        sprintf(caminhoQry, "%s/%s", diretorio, arquivoQry);
                        /*printf("\n\ncaminho Qry com argumento de diretorio: %s", caminhoQry);*/
                    }
            }
            else{/*Não foram passados argumentos para o diretório*/
                caminhoGeo =  (char*)malloc( ( (strlen(arquivoGeo) )+8 )* sizeof(char) );
                strcpy(caminhoGeo, arquivoGeo);
                /*printf("\n\ncaminho Geo sem argumento de diretorio: %s", caminhoGeo);*/
                    if(arquivoQry != NULL){/*se foi passado um arquivo de qry*/
                        caminhoQry = (char*)malloc( ( (strlen(arquivoQry) )+8 )* sizeof(char) );
                        strcpy(caminhoQry, arquivoQry);
                       /* printf("\n\ncaminho Qry sem argumento de diretorio: %s", caminhoQry);*/
                    }

            }

                saidaSvg =  (char*)malloc( ( (strlen(pastaSaida)+strlen(nomeArquivoGeo) )+8 )* sizeof(char) );
                sprintf(saidaSvg, "%s/%s.svg", pastaSaida, nomeArquivoGeo);
                /*printf("\n\nsaida Svg: %s", saidaSvg);*/

                openGeo(Cidade, caminhoGeo, saidaSvg);

                

            if (arquivoQry != NULL){
                    nomeArquivoQry = (char*)malloc( ( ( strlen(arquivoQry) )+8 )*sizeof(char) );

                    nomeArquivoQry = strcpy(nomeArquivoQry, retornaString(arquivoQry));
         
                    /*printf("\n\nnome Qry formatado: %s", nomeArquivoQry);*/

                    saidaQry =  (char*)malloc( ( (strlen(pastaSaida)+strlen(nomeArquivoGeo)+strlen(nomeArquivoQry) )+16 )* sizeof(char) );
                    sprintf(saidaQry, "%s/%s-%s", pastaSaida, nomeArquivoGeo, nomeArquivoQry);
                    /*printf("\n\nsaida Qry: %s", saidaQry);*/
                    openQry(Cidade, caminhoQry, saidaQry);
                free(saidaQry);
                free(nomeArquivoQry);
            }


    free(saidaSvg);
    free(caminhoQry);
    free(caminhoGeo);
    free(nomeArquivoGeo);

    liberaLista(getListaFormas(Cidade));
    liberaLista(getListaObjetos(Cidade));
    liberaLista(getListaQuadras(Cidade));
    liberaLista(getListaPostos(Cidade));
    liberaLista(getListaRegioes(Cidade));
    liberaLista(getListaCasosCovid(Cidade));
    free(Cidade);

}