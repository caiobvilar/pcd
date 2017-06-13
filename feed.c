#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


void produtomatricial(float *in1,float *in2,float *out,int row1, int row2, int col1);
void funcaoAtivacao(float *in,float *out,int row, int col);

int main(int argc, char *argv[])
{
	float Wx[][];
	float Wy[][];
	float X[][];
	float y[][];
	float D[][];
	//TODO:
	//	- inserir dados das matrizes por arquivos CSV
	//	- funcoes que processem o csv e preencha as matrizes.
	produtomatricial(Wx[0],X[0],A[0],neuronios,entradas+1,exemplos);
	funcaoAtivacao(A[0],Z[0],neuronios,exemplos);
	produtomatricial(Wy[0],Z[0],C[0],saidas,neuronios+1,exemplos);
	funcaoAtivacao(C[0],Y[0],saidas,exemplos);
	return 0;
}





void produtomatricial(float *in1,float *in2,float *out,int row1, int col1, int col2)
{
  int i,j,k;
  for(i=0; i<row; i++)
  {
    for(j=0; j<col; j++)
    {
      *out = 0;
      for(k=0; k<row2; k++)
      {
        *out += (*(in1 + i*col1 + k))*(*(in2 + k*col2 + j));
      }
      out++;
    }
  }
}

void funcaoAtivacao(float *in,float *out,int row, int col)
{
	int i,j;
	for(i=0;i < row;i++)
	{
		for(j = 0;j< col;j++)
		{
			out[i*col+j] = 1.0/(1.0 + exp(-(in[i*col+j])));
		}
	}
}

