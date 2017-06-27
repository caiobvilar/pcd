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

void random_assngm(double a[], int length);
void Matrix_mult(int A[], int B[], int res[], int M, int L, int N, int num_threads);
void Usage();

int main(int argc, char const *argv[]) {

  if (argc < 2) Usage();

  int NEURONS, thread_count;
  NEURONS = strtol(argv[1], NULL, 10);
  thread_count = strtol(argv[2], NULL, 10);

  /*  Input vector */
  float X[(INPUTS+1)*SAMPLES] = {0,0};

  /* Hidden layer */
	float Wx[NEURONS*(INPUTS+1)];  // Hidden layer weights matrix
	float IDF1[NEURONS*SAMPLES];   // Induced Local field first layer
	float ATV1[NEURONS*SAMPLES];   // Activated induced local fields

  /* Output Layer */
  float Wy[OUTPUTS*(NEURONS+1)];  // Output layer weights matrix
  float IDF2[OUTPUTS*SAMPLES];  // Induced Local field second layer
  float ATV2[OUTPUTS*SAMPLES];  // Activated induced local fields



  return 0;
}

void Usage()
{
	cout << "Some arguments are missing. \n";
	cout << "Usage: ./feed <NEURONS> <thread_count> \n";
  exit(0);
}





void Matrix_mult(int A[], int B[], int res[], int M, int L, int N, int thread_count)
{
  /* THIS FUNCTION ASSUMES: A[M][L] x B[L][N] = RES[M][N] */
  int i, j, k;
  double result = 0;

/* Creates the team of threads */
# pragma omp parallel num_threads(thread_count) \
   private(i, j, k) shared(A,B, res,M,L,N) reduction (+: result)
{
# pragma omp for schedule(static) /* Use the defautt scheduling */
  for (i = 0; i < M; i++){
      for (j = 0; j < N; j++){
          result = 0;
          for (k = 0; k < L; k++){
              result+= A[k + i * L] * B[j + k * N];
          }
          res[j + i * N] = (int)result; /*REMINDER: result is a Double variable*/
      }
  }
}
} /* End of multiplication */

void random_assngm(double a[], int length)
{
  double random;
  srand(time(NULL));
  for (int i = 0; i < length; i++) {
    //a[i] = i;
    random = ((double)(rand()%10000))/10000;
    cout << "Random: " << random << endl;
    a[i] = random;
  }
}
