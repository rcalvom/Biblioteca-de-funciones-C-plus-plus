#include "matrices.h"
#include "numericos.h"
#include "Reales.h"
#include "Arreglos.h"
#include "conjuntosarreglos.h"
#include <iostream>
using namespace std;

int** crear_matriz_int(int n, int m){
    int** X = new int*[n];
    for(int i = 0; i < n; i++){
        X[i] = new int[m];
    };
return X;
};
double** crear_matriz_double(int n, int m){
    double** X = new double*[n];
    for(int i = 0; i < n; i++){
        X[i] = new double[m];
    };
return X;
};
int** SumarMatrices(int** A,int** B,int f,int c){
    int** total=crear_matriz_int(f,c);
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            total[i][j]=A[i][j]+B[i][j];
        };
    };
    return total;
};
double** SumarMatricesR(double** A,double** B,int f,int c){
    double** total=crear_matriz_double(f,c);
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            total[i][j]=A[i][j]+B[i][j];
        };
    };
    return total;
};

int** MultiMatricesE(int** A,int** B,int f,int c){
    int** total=crear_matriz_int(f,c);
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            total[i][j]=A[i][j]*B[i][j];
        };
    };
    return total;
};
double** MultiMatricesR(double** A,double** B,int f,int c){
    double** total=crear_matriz_double(f,c);
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            total[i][j]=A[i][j]*B[i][j];
        };
    };
    return total;
};

int* SumarColumnas(int**A,int f,int c){
    int* total=new int[c];
    for(int i=0;i<c;i++){
            total[i]=0;
    };
    for(int i=0;i<c;i++){
        for(int j=0;j<f;j++){
            total[i]+=A[j][i];
        };
    };
    return total;
};

int* SumarFilas(int**A,int f,int c){
    int* total = new int[f];
    for(int i = 0; i < f; i++){
            total[i] = 0;
    };
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            total[i] += A[i][j];
        };
    };
    return total;
};

bool CuadradoMagico(int**A, int n){
    int* F = new int[n];
    int* C = new int[n];
    int d1 = 0;
    int d2 = 0;
    for(int i = 0; i < n; i++){
        F[i] = 0;
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            F[i] += A[i][j];
        };
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(F[i] != F[j]){
                return false;
            };
        };
    };
    for(int i = 0; i < n; i++){
        C[i] = 0;
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i] += A[j][i];
        };
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(C[i] != C[j]){
                return false;
            };
        };
    };
    for(int i = 0; i < n; i++){
        if(F[i] != C[i]){
            return false;
        };
    };
    for(int i = 0; i < n; i++){
        d1 += A[i][i];
    };
    for(int i = n - 1, j = 0; i >= 0 && j < n; i--, j++){
        d2 += A[i][j];
    };
    return d1 == d2 && perteneceA(F,n,d1);
};

int** ReemplazarM(int** A, int filas, int columnas, int x){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(A[i][j] > x){
                A[i][j] = 1;
            }else{
                A[i][j] = 0;
            };
        };
    };
    return A;
};

int DeterminanteMatriz(int** X,int n){
    if(n==2){
        return X[0][0]*X[1][1]-X[0][1]*X[1][0];
    }else{
        int f=0;
        for(int i =0;i<n;i++){
            f+=X[0][i]*Potencia(-1,i)*DeterminanteMatriz(Adjunta(X,i,n-1),n-1);
        };
        return f;
    };
};

int** Adjunta(int**X, int c, int n){
    int** A = new int*[n];
    for(int i =0;i<n;i++){
        A[i]=new int[n];
    };
    int y=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(c==j){
                y=1;
                A[i][j]=X[i+1][j+y];
            }else{
                A[i][j]=X[i+1][j+y];
            };
        };
        y=0;
    };
    return A;
};

int** Adjunta(int**X,int f, int c, int n){
    if(f==0){
        return Adjunta(X,c,n-1);
    }else{
        return Adjunta(MatrizCorrida(X,f,n),c,n-1);
    };
};

int** MatrizCorrida(int** X,int f,int n){
    int** A = new int*[n];
    for(int i =0;i<n;i++){
        A[i]=new int[n];
    };
    if(f==0){
        return X;
    }else{
        for(int i =0;i<n-1;i++){
            for(int j=0;j<n;j++){
                A[i][j]=X[i+1][j];
            };
        };
        for(int j=0;j<n;j++){
            A[n-1][j]=X[0][j];
        };
        return MatrizCorrida(A,f-1,n);
    };
};

int** MatrizTraspuesta(int** X, int n){
    int** Y = new int*[n];
    for(int i =0;i<n;i++){
        Y[i]= new int[n];
    };
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            Y[i][j]=X[j][i];
        };
    };
    return Y;
};

double** MatrizInversa(int** X, int n){
    double det = DeterminanteMatriz(X,n);
    double** A = new double*[n];
    for(int i =0;i<n;i++){
        A[i]=new double[n];
    };
    if(n==2){
        A[0][0]= (X[1][1])/det;
        A[0][1]= -(X[0][1])/det;
        A[1][0]= -(X[1][0])/det;
        A[1][1]= (X[0][0])/det;
        return A;
    }else{
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                A[i][j]=Potencia(-1,j)*(DeterminanteMatriz(Adjunta(MatrizTraspuesta(X,n),i,j,n),n-1))/det;
            };
        };
        return A;
    };
};

int** GirarMatrizContManecillas(int** X, int n){
    int** A = new int*[n];
    for(int i =0;i<n;i++){
        A[i]=new int[n];
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                A[i][j]= X[j][n-1-i];
        };
    };
    return A;
};

int** Espiral(int* X,int n){
    int a = Raiz2(n);
    int** A = CrearMatrizInt(a,a);
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            A[i][j]=0;
        };
    };
    int m = 0;
    int p = 0;
    int o = 0;
    int cont = 0;
    for(int i=0;i<2*a-1;i++){
        for(int j = 0;j<a-p;j++){
            A[o][j+m]=X[cont];
            cont++;
        };
        A=GirarMatrizContManecillas(A,a);
        if(i%2==0){
            p++;
        };
        if(i%4==0){
            m++;
        };
        if((i+1)%4==0){
            o++;
        };
    };
    int b=(2*a-1)%4;
    for(int i=0; i<4-b;i++){
        A=GirarMatrizContManecillas(A,a);
    };
    return A;
};

int** MatrizReemplazada(int** X, int* S, int k, int n){
    int** A = CrearMatrizInt(n,n);
    for(int i =0;i<n;i++){
        for(int j =0;j<k;j++){
            A[i][j]=X[i][j];
        };
    };
    for(int i=0;i<n;i++){
        A[i][k]=S[i];
    };
    for(int i =0;i<n;i++){
        for(int j =k+1;j<n;j++){
            A[i][j]=X[i][j];
        };
    };
    return A;
};

double* SistemaEcuaciones(int**X, int* S, int n){
    double* T = new double[n];
    int det = DeterminanteMatriz(X,n);
    for(int i =0;i<n;i++){
        T[i]=DeterminanteMatriz(MatrizReemplazada(X,S,i,n),n)/det;
    };
    return T;
};

