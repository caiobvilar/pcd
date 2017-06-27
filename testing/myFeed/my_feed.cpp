#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <omp.h>
#include <time.h>


using namespace std;

#define OUTPUTS	1
#define INPUTS  2
#define SAMPLES 1

void Random_assngm(int a[], int length);
void Ratrix_mult(int A[], int B[], int res[], int M, int L, int N, int num_threads);
void Usage();

int main(int argc, char const *argv[]) {

  if (argc < 2) Usage();

  int NEURONS, thread_count;
  NEURONS = strtol(argv[1], NULL, 10);
  thread_count = strtol(argv[2], NULL, 10);

  return 0;
}

void Usage()
{
	cout << "Some arguments are missing. \n";
	cout << "Usage: ./feed <NEURONS> <thread_count> \n";
  exit(0);
}


void Matrix_mult(int A[], int B[], int res[], int M, int L, int N, int num_threads)
{
  /* THIS FUNCTION ASSUMES: A[M][L] x B[L][N] = RES[M][N] */
  int i, j, k;
  double result = 0;
  for (i = 0; i < M; i++){
      for (j = 0; j < N; j++) {
          res[j + i * N] = 0;
          for (k = 0; k < L; k++) {
              res[j + i * N] += A[k + i * L] * B[j + k * N];
          }
      }
  }
}
