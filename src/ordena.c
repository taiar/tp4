/*
 * ordena.c
 *
 *  Created on: 30/10/2010
 *      Author: taiar
 */

#include "ordena.h"

void Particao(unsigned int *v, unsigned int *u, int e, int d, int *i, int *j)
{
  int x, w, ww;
  *i = e;
  *j = d;
  x = v[(e + d) / 2];
  do
  {
    while (v[*i] < x)
      (*i)++;
    while (v[*j] > x)
      (*j)--;
    if (*i <= *j)
    {
      w = v[*i];
      ww = u[*i];
      v[*i] = v[*j];
      u[*i] = u[*j];
      v[*j] = w;
      u[*j] = ww;
      (*i)++;
      (*j)--;
    }
  }
  while (*i <= *j);
}

void Ordena(unsigned int *v, unsigned int *u, int e, int d)
{
  int i, j;
  Particao(v, u, e, d, &i, &j);
  if (e < j) Ordena(v, u, e, j);
  if (i < d) Ordena(v, u, i, d);
}

void Quicksort(unsigned int *v, unsigned int *u, int tam)
{
  Ordena(v, u, 0, tam - 1);
}

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
