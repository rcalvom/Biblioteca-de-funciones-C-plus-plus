#include"probarreglos.h"
#include"numericos.h"
#include"Reales.h"

using namespace std;

int* CribaEratostenes (int n){
    int* criba = new int[n+1];
    criba[0]=0;
    criba[1]=0;
    for(int i=2;i<=n;i++){
        criba[i]=1;
    };
    int x = 2;
    while(x<=(int)(Raiz2((double)n))){
        for(int i = 2;i*x<=n;i++){
            criba[x*i]=0;
        };
        x=primosiguiente(x);
    };
    int* X = new int[contarprimos(criba,n+1)];
    int c =0;
    for(int i=2;i<=n;i++){
        if(criba[i]==1){
          X[c]=i;
          c++;
        };
    };
    return X;
};

int primosiguiente(int x){
    x++;
  while(true){
    if(Primo(x)){
        return x;
    };
    x++;
  };
};

int contarprimos(int* Z,int n){
    int x=0;
    for(int i = 0; i<n;i++){
        x+=Z[i];
    };
    return x;
};

int SumaArrEnteros (int* Z,int n){
    int x = 0;
    for(int i=0;i<n;i++){
        x+=Z[i];
    };
    return x;
};

double SumaArrReales (double* R,int n){
    double x = 0;
    for(int i=0;i<n;i++){
        x+=R[i];
    };
    return x;
};

double PromedioArrEnteros(int* Z,int n){
    return SumaArrEnteros(Z,n)/n;
};

double PromedioArrReales(double* R,int n){
    return SumaArrReales(R,n)/n;
};

int ProductoArrEnteros(int* Z,int* S,int n){
    int* Q= new int[n];
    for(int i=0;i<n;i++){
        Q[i]=S[i]*Z[i];
    };
    int x = 0;
    for(int j=0;j<n;j++){
        x +=Q[j];
    };
    return x;
};

double ProductoArrReales(double* R,double* S,int n){
    double* Q= new double[n];
    for(int i=0;i<n;i++){
        Q[i]=S[i]*R[i];
    };
    double x = 0;
    for(int j = 0;j<n;j++){
        x+=Q[j];
    };
    return x;
};

int MinimoArrEnteros(int* Z,int n){
    int x = Z[0];
    for(int i=1;i<n;i++){
        if(Z[i]<x){
            x = Z[i];
        };
    };
    return x;
};

double MinimoArrReales(double* R,int n){
    double x = R[0];
    for(int i=1;i<n;i++){
        if(R[i]<x){
            x = R[i];
        };
    };
    return x;
};

int MaximoArrEnteros(int* Z,int n){
    int x = Z[0];
    for(int i=1;i<n;i++){
        if(Z[i]>x){
            x = Z[i];
        };
    };
    return x;
};

double MaximoArrReales(double* R,int n){
    double x = R[0];
    for(int i=1;i<n;i++){
        if(R[i]>x){
            x = R[i];
        };
    };
    return x;
};

int* ProductoDArrEnteros(int* Z,int* S,int n){
    int* Q= new int[n];
    for(int i=0;i<n;i++){
        Q[i]=S[i]*Z[i];
    };
    return Q;
};

double* ProductoDArrReales(double* R,double* S,int n){
    double* Q= new double[n];
    for(int i=0;i<n;i++){
        Q[i]=S[i]*R[i];
    };
    return Q;
};

double MedianaArrEnteros(int* Z,int n){
    int c;
    for(int j = 0;j<n-1;j++){
        for(int i = 0; i<n-1;i++){
            if(Z[i]>Z[i+1]){
                c=Z[i+1];
                Z[i+1]=Z[i];
                Z[i]=c;
            };
        };
    };
    if(n%2==0){
        return (double)(Z[n/2]+Z[(n/2)-1])/2;
    }else{
        return (double) Z[(n-1)/2];
    };
};

double MedianaArrReales(double* R,int n){
    double c;
    for(int j = 0;j<n-1;j++){
        for(int i = 0; i<n-1;i++){
            if(R[i]>R[i+1]){
                c=R[i+1];
                R[i+1]=R[i];
                R[i]=c;
            };
        };
    };
    if(n%2==0){
        return (R[n/2]+R[(n/2)-1])/2;
    }else{
        return  R[(n-1)/2];
    };
};

int* CerosArr (int* Z, int n){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            if(Z[i]==0){
                for(int j = i;j<n;j++){
                    if(j==n-1){
                        Z[j]=0;
                    }else{
                        Z[j]= Z[j+1];
                    };
                };
            };
        };
    };
    return Z;
};

int BinarioDecimalArr(int* Z, int n){
    int x = 0;
    for(int i = 0; i<n; i++){
        x = x+Z[i]*Potencia(2,i);
    };
    return x;
};

int* DecimalBinarioArr(int x){
    int a = x;
    int n = 0;
    while(a>1){
        a/=2;
        n++;
    };
    if(a==1){
        n++;
    }
    int* numero = new int[n];
    a=x;
    for(int i = 0; i<n;i++){
        numero[i]=a%2;
        a/=2;
    };
    return numero;
};

int mcd(int* Z, int n){
    int c = MaximoArrEnteros(Z,n);
    int p = 0;
    while (c>0){
        for(int i =0;i<n;i++){
            if(Z[i]%c==0){
                p++;
            };
        };
        if(p==n){
            return c;
        }else{
            c--;
            p=0;
        };
    };
};

int mcm(int* Z, int n){
    int c = MinimoArrEnteros(Z,n);
    int p = 0;
    while (true){
        for(int i =0;i<n;i++){
            if(c%Z[i]==0){
                p++;
            };
        };
        if(p==n){
            return c;
        }else{
            c++;
            p=0;
        };
    };
};
