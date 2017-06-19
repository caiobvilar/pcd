#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <omp.h>

/*
#define NEURONS // Number of neurons in hidden layer
#define INPUTS  // Amount of inputs
#define OUPUTS  // Number of outputs
#define SAMPLES // Number of samples
*/

//TODO:
//  - processar dados de arquivo CSV para preencher os pesos das camadas.
//  - modelo XOR que funcione para diferentes quantidades de neuronios
void random(float *m1, float *m2, int row1, int col1, int row2, int col2);
void produtomatricial(float *m1, float *m2, float *mprod, int row, int ig, int col);
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
    INPUTS  = strtol(argv[2], NULL, 10);
    OUTPUTS = strtol(argv[3], NULL, 10);
    SAMPLES = strtol(argv[4], NULL, 10);
    float X[INPUTS+1][SAMPLES];
    float Wx[NEURONS][INPUTS+1];
    float IDF1[NEURONS][SAMPLES];
    float ATV1[NEURONS][SAMPLES];
    float Wy[OUTPUTS][NEURONS+1];
    float IDF2[OUTPUTS][SAMPLES];
    float ATV2[OUTPUTS][SAMPLES];
		random(Wx[0],Wy[0],NEURONS,INPUTS+1, OUTPUTS, NEURONS+1);
    produtomatricial(Wx[0],X[0],IDF1[0],NEURONS,INPUTS+1,SAMPLES);
    funcaoAtivacao(IDF1[0],ATV1[0],NEURONS,SAMPLES);
    produtomatricial(Wy[0],ATV1[0],IDF2[0],OUTPUTS,NEURONS+1,SAMPLES);
    funcaoAtivacao(IDF2[0],ATV2[0],OUTPUTS,SAMPLES);
    int i,j;
    for(i = 0;i< OUTPUTS;i++)
    {
      for(j=0; j < SAMPLES;j++)
      {
        std::cout << std::setprecision(2) << std::fixed << ATV2[i][j] << "\t";
      }
      std::cout << "\n";
    }

    return 0;
}

void Usage()
{
    std::cout << "Some arguments are missing." << std::endl;
    std::cout << "Usage: ./feed <NEURONS> <INPUTS> <OUTPUTS> <SAMPLES>" << std::endl;
}

void produtomatricial(float *m1, float *m2, float *mprod, int row, int ig, int col)
{
  int i,j,k;
  for(i=0; i<row; i++)
  {
    for(j=0; j<col; j++)
    {
      *mprod = 0;
      for(k=0; k<ig; k++)
      {
        *mprod += (*(m1 + i*ig + k))*(*(m2 + k*col + j));
      }
      mprod++;
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
void random(float *m1, float *m2, int row1, int col1, int row2, int col2)
{
   srand(time(NULL));
   int i,j;
   for(i=0; i<row1; i++)
   {
     for(j=0; j<col1; j++)
     {
       *m1++ = (rand()%10)/10.0;
     }
   }
   for(i=0; i<row2; i++)
   {
     for(j=0; j<col2; j++)
     {
       *m2++ = (rand()%11)/10.0;
     }
   }
}
