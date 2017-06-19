#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <omp.h>

/*
#define	NEURONS // Number of neurons in hidden layer
#define INPUTS	// Amount of inputs
#define OUPUTS	// Number of outputs
#define SAMPLES // Number of samples
*/

//TODO:
//	- processar dados de arquivo CSV para preencher os pesos das camadas.
//	- modelo XOR que funcione para diferentes quantidades de neuronios

void produtomatricial(float *in1,float *in2,float *out,int row1, int row2, int col1);
void funcaoAtivacao(float *in,float *out,int row, int col);
void Usage();
//testando XOR com diferentes quantidades de NEURONS
int main(int argc, char *argv[])
{
	if (argc < 5) {
		Usage();
		return -1;
	}

	int NEURONS, INPUTS, OUTPUTS, SAMPLES;

	NEURONS = strtol(argv[1], NULL, 10);
	INPUTS 	= strtol(argv[2], NULL, 10);
	OUTPUTS = strtol(argv[3], NULL, 10);
	SAMPLES = strtol(argv[4], NULL, 10);

	float X[INPUTS+1][SAMPLES];
	float Wx[NEURONS][INPUTS+1];
	float IDF1[NEURONS][SAMPLES];
	float ATV1[NEURONS][SAMPLES];
	float Wy[OUTPUTS][NEURONS+1];
	float IDF2[OUTPUTS][SAMPLES]
	float ATV2[OUTPUTS][SAMPLES];
	float D[OUTPUTS][SAMPLES];
	produtomatricial(Wx[0],X[0],IDF1[0],NEURONS,INPUTS+1,SAMPLES);
	funcaoAtivacao(IDF1[0],ATV1[0],NEURONS,SAMPLES);
	produtomatricial(Wy[0],ATV1[0],IDF2,OUTPUTS,NEURONS+1,SAMPLES);
	funcaoAtivacao(IDF2[0],ATV2[0],OUTPUTS,SAMPLES);
	return 0;
}

void Usage(){
	cout << "Some arguments are missing. \n";
	cout << "Usage: ./feed <NEURONS> <INPUTS> <OUTPUTS> <SAMPLES> \n"<<;
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
o}
