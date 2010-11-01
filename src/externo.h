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

#define FLOATS_MAX_READ 1024 * 1024 // 32mb
#define FLOATS_MAX_LENGTH 20 // tamanho maximo dos pontos flutuantes
#define TEMP_FILE_PREFIX "temp_"

int geraTemporarios(FILE*);
void mesclaTemporarios(FILE*, int);

int getMinInd(double*, int);

#endif /* EXTERNO_H_ */
