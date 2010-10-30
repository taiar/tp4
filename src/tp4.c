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

int main(int argc, char **argv)
{
  Entrada entrada;

  entradaInit(&entrada);
  if(!entradaLe(argc, argv, &entrada))
    return EXIT_FAILURE;

  printf("%d\n", FLOATS_MAX_READ);

  entradaFree(&entrada);

  return EXIT_SUCCESS;
}
