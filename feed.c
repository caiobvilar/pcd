#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


void produtomatricial(float *in1,float *in2,float *out,neuronios,entradas+1,exemplos);

int main(int argc, char *argv[])
{
	float Wx[][];
	float Wy[][];
	float X[][];
	float y[][];
	float D[][];
	produtomatricial(Wx[0],X[0],A[0],neuronios,entradas+1,exemplos);
	funcaoAtivacao(A[0],Z[0],neuronios,exemplos);
	produtomatricial(Wy[0],Z[0],C[0],saidas,neuronios+1,exemplos);

	funcaoAtivacao(C[0],Y[0],saidas,exemplos);
}



