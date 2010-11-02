/*
 * tp4.c
 *
 *  Created on: 28/10/2010
 *      Author: taiar
 */

#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "externo.h"
#include "ordena.h"

int main(int argc, char **argv)
{
  Entrada entrada;
  FILE *lista;
  char buff[30];
  unsigned long int len, count = 0;
  double prob, current = -1, n;

  entradaInit(&entrada);
  if (!entradaLe(argc, argv, &entrada)) return EXIT_FAILURE;

  // Ordena e conta a quantidade de números
  len = intercalacaoBalanceada(entrada.entrada);

  // Abre lista de numeros
  lista = fopen(ENTRADA_ORDENADA, "r");

  while (!feof(lista))
  {
    fscanf(lista, "%s\n", buff);
    n = atof(buff);
    if (count == len - 1)
    {
      current = n;
      //Append X
      fprintf(entrada.saida, "%f ", current);

      //Append Y
      fprintf(entrada.saida, "%lf", 1.);
    }
    else
    {
      if (n != current)
      {
        current = n;
        prob = current / len;

        //Append X
        fprintf(entrada.saida, "%f ", current);

        //Append Y
        fprintf(entrada.saida, "%lf\n", prob);
      }
    }
    count += 1;
  }

  n =

  fclose(lista);
  entradaFree(&entrada);

  return EXIT_SUCCESS;
}
