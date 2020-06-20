/*
  FILE: heaps.c
  PURPOSE: Generate all permuations of n numbers using Heap's algorithm
  DATE: 2020-06-19
  AUTHOR: Paul Egeler, MS, GStat
  REFERENCE: https://en.wikipedia.org/wiki/Heap%27s_algorithm
*/
#include <stdio.h>
#include <stdlib.h>

void usage(char *prog)
{
  fprintf(stderr, "usage:\n%s n", prog);
  exit(1);
}

void print_array(int *a, int n)
{
  for (int i=0; i<n; i++) {
    printf("%d%c", a[i], i < n -1 ? ' ' : '\n');
  }
}

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void heaps(int *a, int n)
{
  int *c = calloc(n, sizeof(int));
  int i = 0;

  print_array(a, n);

  while (i < n) {
    if (c[i] < i) {
      i&1 ? swap(&a[c[i]], &a[i]) : swap(&a[0], &a[i]);
      print_array(a, n);
      c[i]++;
      i = 0;
    } else {
      c[i++] = 0;
    }
  }
}

int main(int argc, char *argv[])
{
  int *a;
  int n = 0;
  char c;

  if (argc != 2)
    usage(argv[0]);

  while ((c = *(argv[1]++)) >= '0' && c <= '9')
    n = n * 10 + (c - '0');

  a = malloc(n * sizeof(int));
  for (int i=0; i < n; i++)
    a[i] = i + 1;

  heaps(a, n);

  return 0;
}
