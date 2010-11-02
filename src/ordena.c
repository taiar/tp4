/*
 * ordena.c
 *
 *  Created on: 30/10/2010
 *      Author: taiar
 */

#include "ordena.h"

void Heapsort(char **a, int n)
{
  n -= 1;
  int i = n / 2, pai, filho;
  char t[30];
  float tmp1, tmp2;

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
      tmp1 = atof(a[filho]);
      tmp2 = atof(a[filho + 1]);
      if ((filho + 1 < n) && (tmp2 > tmp1)) filho++;
      tmp2 = atof(t);
      if (tmp1 > tmp2)
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
