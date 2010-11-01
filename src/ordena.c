/*
 * ordena.c
 *
 *  Created on: 30/10/2010
 *      Author: taiar
 */

#include "ordena.h"

void Heapsort(char **a, int n)
{
  int i = n / 2, pai, filho;
  char t[30];

  for (;;)
  {
    if (i > 0)
    {
      i--;
      strcpy(t, a[i]);
    }
    else
    {
      n--;
      if (n == 0) return;
      strcpy(t, a[n]);
      strcpy(a[n], a[0]);
    }

    pai = i;
    filho = i * 2 + 1;

    while (filho < n)
    {
      if ((filho + 1 < n) && (strcmp(a[filho + 1], a[filho]) > 0)) filho++;
      if (strcmp(a[filho], t) > 0)
      {
        strcpy(a[pai], a[filho]);
        pai = filho;
        filho = pai * 2 + 1;
      }
      else break;
    }
    strcpy(a[pai], t);
  }
}
