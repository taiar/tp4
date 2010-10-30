/*
 * ordena.h
 *
 *  Created on: 30/10/2010
 *      Author: taiar
 */

#ifndef ORDENA_H_
#define ORDENA_H_

/**
 * Funções do método de ordenação Quicksort (versão recursiva)
 */
void Particao(unsigned int*, unsigned int*, int, int, int*, int*);
void Ordena(unsigned int*, unsigned int*, int, int);
void Quicksort(unsigned int*, unsigned int*, int);

#endif /* ORDENA_H_ */
