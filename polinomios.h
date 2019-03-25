#ifndef POLINOMIOS_H_INCLUDED
#define POLINOMIOS_H_INCLUDED

double Xevaluado(double* A,int a,double R);
double* SumarPolinomios(double* A,int a,double* B,int b);
double* RestaPolinomios(double* A,int a,double* B,int b);
double* Multipolinomios(double* A,int a,double* B,int b);
double* dividir_pol(double* A,int a,double* B,int b);
double* creararreglo(int a);
double* cerosenarreglo(double* A,int n);
double* multicoexdiv(double* B, int b,int a,double n);
double* residuo_pol(double* A,int a,double* B,int b);

#endif // POLINOMIOS_H_INCLUDED
