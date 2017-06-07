#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

float Wx[][];
float Wy[][];
float X[][];
float y[][];
float D[][];
produtomatricial(Wx[0],X[0],A[0],neuronios,entradas+1,exemplos);
funcaoAtivacao(A[0],Z[0],neuronios,exemplos);
////////////////////////////END -FEEDFOWARD/////////////////////////////
/////////////////////////////INIT - FEEDFORWARD 2.2//////////////////////////
produtomatricial(Wy[0],Z[0],C[0],saidas,neuronios+1,exemplos);
funcaoAtivacao(C[0],Y[0],saidas,exemplos);
