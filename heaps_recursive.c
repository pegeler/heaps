/*****************************************************************************
  FILE: heaps_recursive.c
  PURPOSE: Generate all permuations of n numbers using Heap's algorithm. This
      implementation uses the recursive algorithm found on the wiki page.
  DATE: 2020-10-20
  AUTHOR: Paul Egeler, MS, GStat
  REFERENCE: https://en.wikipedia.org/wiki/Heap%27s_algorithm
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**
 * print the array
 */
void print(int n, int *A) {
  for (int i=0; i < n; i++)
    printf("%d%c", A[i], i < n-1 ? ' ' : '\n');
}

/**
 * swap two integers
 */
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/**
 * recursive implementation of Heap's algorithm
 */
void heaps(int n, int k, int *A) {
  if (k == 1) {
    print(n, A);
  } else {
    heaps(n, k - 1, A);
    for (int i=0; i < k - 1; i++) {
      if (k % 2 == 0)
        swap(A + i, A + k - 1);
      else
        swap(A, A + k - 1);
      heaps(n, k - 1, A);
    }
  }
}

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  int *A = malloc(n * sizeof(int));
  for (int i=0; i < n; i++)
    A[i] = i + 1;
  heaps(n, n, A);
  return 0;
}
