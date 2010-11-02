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

void Particao(char **v, int e, int d, int *i, int *j)
{
  char x[30], w[30];
  double a, b;
  *i = e;
  *j = d;
  strcpy(x, v[(e + d) / 2]);
  do
  {
    a = atof(v[*i]);
    b = atof(x);
    while (a < b)
    {
      (*i)++;
      a = atof(v[*i]);
    }
    a = atof(v[*j]);
    while (a > b)
    {
      (*j)--;
      a = atof(v[*j]);
    }
    if (*i <= *j)
    {
      strcpy(w, v[*i]);
      strcpy(v[*i], v[*j]);
      strcpy(v[*j], w);
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

void Ordena(char **v, int e, int d)
{
  int i, j;
  Particao(v, e, d, &i, &j);
  if (e < j) Ordena(v, e, j);
  if (i < d) Ordena(v, i, d);
}

void Quicksort(char **v, int tam)
{
  Ordena(v, 0, tam - 1);
}
