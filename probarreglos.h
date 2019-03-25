#ifndef PROBARREGLOS_H_INCLUDED
#define PROBARREGLOS_H_INCLUDED

int* CribaEratostenes (int n);
int primosiguiente(int x);
int contarprimos(int* criba,int n);
int SumaArrEnteros (int* Z,int a);
double SumaArrReales(double* R,int a);
double PromedioArrEnteros(int* Z,int a);
double PromedioArrReales(double* R,int a);
int ProductoArrEnteros(int* Z,int* S,int n);
double ProductoArrReales(double* R,double* S,int n);
int MinimoArrEnteros(int* Z,int n);
double MinimoArrReales(double* R,int n);
int MaximoArrEnteros(int* Z,int n);
double MaximoArrReales(double* R,int n);
int* ProductoDArrEnteros(int* Z,int* S,int n);
double* ProductoDArrReales(double* R,double* S,int n);
double MedianaArrEnteros(int* Z,int n);
double MedianaArrReales(double* R,int n);
int* CerosArr (int* Z, int n);
int BinarioDecimalArr(int* Z, int n);
int* DecimalBinarioArr(int x);
int mcd(int* Z, int n);
int mcm(int* Z, int n);

#endif // PROBARREGLOS_H_INCLUDED
