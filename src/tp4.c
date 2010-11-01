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

  entradaInit(&entrada);
  if(!entradaLe(argc, argv, &entrada))
    return EXIT_FAILURE;

  int teste = geraTemporarios(entrada.entrada);
  mesclaTemporarios(entrada.saida, teste);

  entradaFree(&entrada);

  return EXIT_SUCCESS;
}
