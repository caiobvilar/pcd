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

int main(int argc, char const *argv[])
{
  int first_layer = strtol(argv[1], NULL, 10);
  int a[strtol(argv[1], NULL, 10)];
  int i=0;
  double start_time, end_time;

  start_time = omp_get_wtime();
# pragma omp parallel for num_threads(2)
  for(i=0; i<first_layer; i++){
    //cout << "Eu sou a linda thread " << omp_get_thread_num() << endl;
    a[i] = i;
  }
  end_time = omp_get_wtime();
  cout << "Total time was: " << (end_time-start_time)*1000 << " ms" << endl;

  for(i=0; i<strtol(argv[1], NULL, 10); i++){
    cout << a[i] << endl;
  }
  return 0;
}
