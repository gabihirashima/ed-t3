#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tratamento.h"

int main(int argc, char *argv[]){
    char *diretorio = NULL;
    char *arquivoGeo = NULL;
    char *arquivoQry = NULL;
    char *pastaSaida = NULL;

    for (int i = 0; i<argc; i++){ /* Função para captar os caracteres do terminal */
            if ( strcmp(argv[i], "-e") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos em -e");
                    exit(1);
                }
                diretorio = (char*)malloc( ( ( strlen (argv[i]) )+1 )*sizeof(char) );
                strcpy(diretorio, argv[i]);
            }

            else if ( strcmp(argv[i], "-f") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -f");
                    exit(1);
                }
                arquivoGeo = (char*)malloc( ( ( strlen (argv[i]) )+1)*sizeof(char) );
                strcpy(arquivoGeo, argv[i]);
            }

            else if ( strcmp(argv[i], "-q") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -q");
                    exit(1);
                }
                arquivoQry = (char*)malloc( ( ( strlen(argv[i]) )+1 )*sizeof(char) );
                strcpy(arquivoQry, argv[i]);
            }

            else if ( strcmp(argv[i], "-o") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -o");
                    exit(1);
                }
                pastaSaida = (char*)malloc( ( ( strlen(argv[i]) )+1 )*sizeof(char) );
                strcpy(pastaSaida, argv[i]);
            }
        }

        printf("\n %s %s %s %s", diretorio, arquivoGeo, arquivoQry, pastaSaida);

        tratamentoString(diretorio, arquivoGeo, arquivoQry, pastaSaida);

        free(pastaSaida);
        free(arquivoQry);
        free(arquivoGeo);
        free(diretorio);
}