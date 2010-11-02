/*
 * externo.h
 *
 *  Created on: 28/10/2010
 *      Author: taiar
 */

#ifndef EXTERNO_H_
#define EXTERNO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordena.h"

#define FLOATS_MAX_READ 1024 * 1024 // 32 de Floats em memória mb
#define FLOATS_MAX_LENGTH 20        // precisão máxima dos pontos flutuantes (gerados para a entrada)
#define TEMP_FILE_PREFIX "temp_"    // prefixo dos nomes dos arquivos temporários
#define ENTRADA_ORDENADA "ordenado" // nome do arquivo de entrada ordenado

/*
 * Divide o arquivo de entrada em N arquivos menores e ordenados.
 */
int geraTemporarios(FILE*);

/*
 * Mescla os arquivos temporarios gerados em um arquivo ordenado.
 */
unsigned long int mesclaTemporarios(FILE*, int);

/*
 * Executa o método de ordenação em memória externa.
 */
unsigned long int intercalacaoBalanceada(FILE*);

/*
 * Pega o indice do elemento de menor valor um vetor de floats.
 */
int getMinInd(double*, int);

#endif /* EXTERNO_H_ */
