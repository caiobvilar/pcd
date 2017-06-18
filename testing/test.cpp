/*
  To compile.

  g++ -g -Wall -fopenmp -o omp_trap1 omp_trap1.cpp
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <omp.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int a[strtol(argv[1], NULL, 10)];
  int i=0;

# pragma omp parallel for num_threads(2)
  for(i=0; i<strtol(argv[1], NULL, 10); i++){
    cout << "Eu sou a linda thread " << omp_get_thread_num() << endl;
    a[i] = i;
  }


  for(i=0; i<strtol(argv[1], NULL, 10); i++){
    cout << a[i] << endl;
  }

  return 0;
}
