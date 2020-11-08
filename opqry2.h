#ifndef OPQRY2_H_
#define OPQRY2_H_

#include <stdio.h>

/*Coloca um quadrado laranja no endereço num, da quadra identificada por cep e na face determinada. Também insere
um texto com o número de casos de covid no endereço*/
void casosCovid(listaCidade lista, int n, char *cep, char face, int num, FILE *saida);

/*ShellSort para a funcao socorro*/
void shellsort(double distanciaPostos[], double postoX[], double postoY[], int n_postos);

/*Insere um quadrado azul com bordas brancas no endereço num, da quadra identificada por cep e na face determinada.
Traça uma linha pontilhada até cada um dos n_postos de atendimento. */
void socorro(listaCidade listacidade, int n_postos, char *cep, char face, int num, FILE *saida);


#endif