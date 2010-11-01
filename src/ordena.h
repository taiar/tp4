/*
 * ordena.h
 *
 *  Created on: 30/10/2010
 *      Author: taiar
 */

#ifndef ORDENA_H_
#define ORDENA_H_

#include <stdlib.h>
#include <string.h>

/**
 * Funções do método de ordenação Quicksort (versão recursiva)
 */
void Particao(unsigned int*, unsigned int*, int, int, int*, int*);
void Ordena(unsigned int*, unsigned int*, int, int);
void Quicksort(unsigned int*, unsigned int*, int);
void Heapsort(char**, int);

#endif /* ORDENA_H_ */
