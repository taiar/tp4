/*
 * ordena.h
 *
 *  Created on: 30/10/2010
 *      Author: taiar
 */

#ifndef ORDENA_H_
#define ORDENA_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Heapsort(char**, int);

/**
 * Funções do método de ordenação Quicksort (versão recursiva)
 */
void Particao(char **, int, int, int*, int*);
void Ordena(char **, int, int);
void Quicksort(char **, int);

#endif /* ORDENA_H_ */
