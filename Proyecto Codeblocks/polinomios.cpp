#include "polinomios.h"
#include "numericos.h"
#include "Reales.h"
#include "Enteros.h"

double Xevaluado(double* A,int a,double R){
    double v=0;
    for(int j=a;j>=0;j--){
        v+=A[j]*Potencia(R,j);
    };
    return v;
};

double* SumarPolinomios(double* A,int a,double* B,int b){
    int x=ValorAbsoluto(a-b);
    double* nuevo=new double[maximo(a,b)+1];
    for(int i=minimo(a,b)+1;i<=maximo(a,b);i++){
        if(a>b){
            nuevo[i]=A[i];
        }else if(b>a){
       	    nuevo[i]=B[i];
	    };
	};
	for(int i=0;i<=minimo(a,b);i++){
       nuevo[i]=A[i]+B[i];
	};
    return nuevo;
};

double* RestaPolinomios(double* A,int a,double* B,int b){
    int x=ValorAbsoluto(a-b);
    double* nuevo=new double[maximo(a,b)+1];
    for(int i=minimo(a,b)+1;i<=maximo(a,b);i++){
       if(a>b){
       	 nuevo[i]=A[i];
	   }else if(b>a){
	   	 nuevo[i]=B[i];
	   };
	};
	for(int i=0;i<=minimo(a,b);i++){
       nuevo[i]=A[i]-B[i];
	};
    return nuevo;
};

double* Multipolinomios(double* A,int a,double* B,int b){
    int ext=a+b;
    double* nuevo=new double[ext+1];
    for(int i=0;i<=ext;i++){
        nuevo[i]=0;
    };
    for(int j=0;j<=a;j++){
        for(int k=0;k<=b;k++){
            nuevo[j+k]+=A[j]*B[k];
        };
    };
    return nuevo;
};

double* dividir_pol(double* A,int a,double* B,int b){
        int n=a-b;
        double* X=new double[n+1];
        for(int i=0;i<=n;i++){
            double* K=creararreglo(a-i+1);
            X[n-i]=A[a-i]/B[b];
            K=multicoexdiv(B,b,a-i,X[n-i]);
            A=SumarPolinomios(A,a-i,K,a-i);
        };
        return X;
};
double* creararreglo(int a){
    double* x=new double[a];
    return x;
};
double* cerosenarreglo(double* A,int n){
    for(int i=0;i<n;i++){
        A[i]=0;
    };
    return A;
};
double* multicoexdiv(double* B, int b,int a,double n){
    double* pro=new double[a+1];
    pro=cerosenarreglo(pro,a+1);
    for(int i=b;i>=0;i--){
        pro[a]=B[i]*(-n);
        a--;
    };
    return pro;
};

double* residuo_pol(double* A,int a,double* B,int b){
    int n=a-b;
    double* X=new double[n+1];
    for(int i=0;i<=n;i++){
        double* K=creararreglo(a-i+1);
        X[n-i]=A[a-i]/B[b];
        K=multicoexdiv(B,b,a-i,X[n-i]);
        A=SumarPolinomios(A,a-i,K,a-i);
    };
    return A;
};
