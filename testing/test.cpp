/*
  To compile.
  g++ -g -Wall -fopenmp -o test test.cpp
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <omp.h>

using namespace std;

void random_Matrix(int *a, int cols, int rows)
{
  a = a + 1;
  *a=2;
}

int main(int argc, char const *argv[])
{
  int DIMENSION = strtol(argv[1], NULL, 10);
  int a[DIMENSION][DIMENSION];
	
  random_Matrix(a[0], DIMENSION, DIMENSION);

  cout << "My A[0][1]: " << a[0][1] << endl;

  cout << sizeof(int) << endl;

  return 0;
}
