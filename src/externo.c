/*
 * externo.c
 *
 *  Created on: 28/10/2010
 *      Author: taiar
 */

#include "externo.h"

int geraTemporarios(FILE *f)
{
  int i;
  char idTempFileName[10];
  char tempFileName[20];
  FILE *temp; // apontador para criar os arquivos temporários
  int fileCounter = 0; // conta quantos arquivos temporarios foram gerados
  char **ordenacao; // vetor para ordenar os floats lidos em memoria interna

  ordenacao = (char**) malloc(sizeof(char*) * FLOATS_MAX_READ);
  for (i = 0; i < FLOATS_MAX_READ; i += 1)
  {
    ordenacao[i] = (char*) malloc(sizeof(char) * FLOATS_MAX_LENGTH);
    strcpy(ordenacao[i], "-1.\0");
  }

  while (!feof(f))
  {
    for (i = 0; i < FLOATS_MAX_READ; i += 1)
      strcpy(ordenacao[i], "-1.\0");

    for (i = 0; i < FLOATS_MAX_READ; i += 1)
    {
      if (feof(f)) break;
      fscanf(f, "%s\n", ordenacao[i]);
    }

    fileCounter += 1;

    // ordena

    //grava no arquivo temporario
    strcpy(tempFileName, "");
    sprintf(idTempFileName, "%d", fileCounter);
    strcat(tempFileName, "temp_");
    strcat(tempFileName, idTempFileName);
    temp = fopen(tempFileName, "w");
    for (i = 0; i < FLOATS_MAX_READ; i += 1)
    {
      fprintf(temp, "%s\n", ordenacao[i]);
    }

    fclose(temp);

  }

  return fileCounter;
}
