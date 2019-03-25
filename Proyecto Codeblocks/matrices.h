#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

int** crear_matriz_int(int n, int m);
double** crear_matriz_double(int n, int m);
int** SumarMatrices(int** A,int** B,int f,int c);
double** SumarMatricesR(double** A,double** B,int f,int c);
int** MultiMatricesE(int** A,int** B,int f,int c);
double** MultiMatricesR(double** A,double** B,int f,int c);
int* SumarColumnas(int**A,int f,int c);
int* SumarFilas(int**A,int f,int c);
bool CuadradoMagico(int**A, int n);
int** ReemplazarM(int** A, int filas, int columnas, int x);

int DeterminanteMatriz(int** X,int n);
int** Adjunta(int**X, int c, int n);
int** MatrizTraspuesta(int** X, int n);
int** Adjunta(int**X, int f, int c, int n);
int** MatrizCorrida(int** X,int f,int n);
double** MatrizInversa(int** X, int n);
int** GirarMatrizContManecillas(int** X, int n);
int** Espiral(int* X,int n);
double* SistemaEcuaciones(int**X, int* S, int n);


#endif // MATRICES_H_INCLUDED
