#include "Arreglos.h"

int** CrearMatrizInt(int n, int m){
    int** X = new int*[n];
    for(int i =0;i<m;i++){
        X[i]=new int[m];
    };
    return X;
};

double** CrearMatrizdouble(int n, int m){
    double** X = new double*[n];
    for(int i =0;i<m;i++){
        X[i]=new double[m];
    };
    return X;
};
