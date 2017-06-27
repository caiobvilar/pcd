#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <omp.h>
#include <time.h>

using namespace std;

//#define DEBUG

void mult(int A[], int B[], int res[], int M, int L, int N, int thread_count)
{
  /* THIS FUNCTION ASSUMES: A[M][L] x B[L][N] = RES[M][N] */
  int i, j, k;
  double result = 0;

/* Creates the team of threads */
# pragma omp parallel num_threads(thread_count) \
   private(i, j, k) shared(A,B, res,M,L,N) reduction (+: result)
   //private(i, j, k, result) shared(A,B, res,M,L,N)
{
//# pragma omp for schedule(static) /* Use the defautt scheduling */
  for (i = 0; i < M; i++){
#     pragma omp for schedule(static)
      for (j = 0; j < N; j++) {
          result = 0;
          for (k = 0; k < L; k++) {
              result+= A[k + i * L] * B[j + k * N];
              //res[j + i * N] += A[k + i * L] * B[j + k * N];
          }
          res[j + i * N] = (int)result;
      }
  }
}

} /* End of mult */


void random_assngm(int a[], int length)
{
  for (int i = 0; i < length; i++) {
    a[i] = i;
  }
}

void print_matrix(int a[], int rows, int cols)
{
  int j,i;
  for (i = 0; i < rows; i++){
    for (j = 0; j < cols; j++){
      cout << a[i*cols + j] << " ";
    }
    cout << endl;
  }

  cout << "-----------" << endl;
}

int main(int argc, char const *argv[]) {

  int M,  L,  N, thread_count;
  # ifdef DEBUG
    M = 2;
    L = 4;
    N = 3;
    thread_count = strtol(argv[1], NULL, 10);
  # else
    M            = strtol(argv[1], NULL, 10);
    L            = strtol(argv[2], NULL, 10);
    N            = strtol(argv[3], NULL, 10);
    thread_count = strtol(argv[4], NULL, 10);
  # endif

  int A[M*L], B[L*N], res[M*N];
  int expectedResult[] = { 42, 48, 54, 114, 136, 158};
  double start, finish;

  random_assngm(A, M*L);
  random_assngm(B, L*N);

  # ifdef DEBUG
    print_matrix(A, M, L);
    print_matrix(B, L, N);
  # endif

  start = omp_get_wtime();
  mult(A, B, res, M, L, N, thread_count);
  finish = omp_get_wtime();

  cout << "Total time taken: " << finish-start << endl;

  # ifdef DEBUG
    print_matrix(res, M, N);
    cout << " Expected matrix result is: \n \n";
    print_matrix(expectedResult, 2, 3);
  # endif

  return 0;
}
