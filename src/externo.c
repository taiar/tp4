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
    Heapsort(ordenacao, FLOATS_MAX_READ);

    //grava no arquivo temporario
    strcpy(tempFileName, "");
    sprintf(idTempFileName, "%d", fileCounter);
    strcat(tempFileName, "temp_");
    strcat(tempFileName, idTempFileName);
    temp = fopen(tempFileName, "w");
    for (i = 0; i < FLOATS_MAX_READ; i += 1)
      if (strcmp(ordenacao[i], "-1.") != 0) fprintf(temp, "%s\n", ordenacao[i]);
    fclose(temp);

  }

  return fileCounter;
}

void mesclaTemporarios(FILE *f, int t)
{
  int i;
  int id;
  FILE **temps;
  double *floats;
  char idTempFileName[10];
  char tempFileName[20];
  char buff[30];

  temps = (FILE**) malloc(sizeof(FILE*) * t);
  for (i = 0; i < t; i += 1)
  {
    id = i + 1;
    sprintf(idTempFileName, "%d", id);
    strcpy(tempFileName, "temp_");
    strcat(tempFileName, idTempFileName);
    temps[i] = fopen(tempFileName, "r");
  }

  floats = (double*) malloc(sizeof(double) * t);

  for (i = 0; i < t; i += 1)
  {
    fscanf(temps[i], "%s\n", buff);
    floats[i] = atof(buff);
  }



  for (i = 0; i < t; i += 1)
    fclose(temps[i]);

  free(floats);
}

