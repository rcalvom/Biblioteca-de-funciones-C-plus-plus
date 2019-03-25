#include "conjuntosarreglos.h"
#include <iostream>

using namespace std;

bool repetido(int* A, int c){
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            if(A[i] == A[j] && i != j){
                return true;
            };
        };
    };
    return false;
};

void ordenarE(int* A,int n){
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
        if(A[j] < A[i]){
            int a = A[i];
            A[i] = A[j];
            A[j] = a;
        };
    };
  };
};

int* pegarC(int* A, int* B, int n, int m){
    int* C = new int[n + m];
    for(int i = 0; i < n; i++){
        C[i] = A[i];
    };
    for(int i = n, j = 0; i < m || j < m; i++, j++){
        C[i] = B[j];
    };
    ordenarE(C,n + m);
    return C;
};
int nuevolimiteU(int* A, int n){
    int c = n;
    for(int i = 0; i < n; i++){
      if(A[i] == A[i + 1]){
        c--;
      };
    };
    return c;
};
int* unionA(int* A, int* B, int n, int m){
    int* C = pegarC(A,B,n,m);
    int d = nuevolimiteU(C,n + m);
    int* D = new int[d];
    for(int i = 0, j = 0; i < n + m || j < d; i++){
        if(C[i] != C[i + 1]){
            D[j] = C[i];
            j++;
        };
    };
    delete[] C;
    return D;
};

int nuevolimiteI(int* A, int n){
    int c = 0;
    for(int i = 0; i < n; i++){
        if(A[i] == A[i + 1]){
            c++;
        };
    };
    return c;
};

int* interseccionA(int* A, int* B, int n, int m){
    int* C = pegarC(A,B,n,m);
    int d = nuevolimiteI(C,n + m);
    int* D = new int[d];
    for(int i = 0, j = 0; i < n + m || j < d; i++){
        if(C[i] == C[i + 1]){
            D[j] = C[i];
            j++;
        };
    };
    delete[] C;
    return D;
};

int nuevolimiteD(int* A, int n, int m){
    int c = m;
    for(int i = 0; i < n; i++){
        if(A[i] == A[i+1]){
          c--;
        };
    };
    return c;
};
bool* noperteneceAB(int* A, int* B, int n, int m){
    bool* C = new bool[n];
    for(int i = 0; i < n; i++){
        C[i] = true;
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i] == B[j]){
                C[i] = false;
            };
        };
    };
    return C;
};
int* diferenciaA(int* A, int* B, int n, int m){
    int* C = pegarC(A,B,n,m);
    int d = nuevolimiteD(C,n+m,n);
    int* D = new int[d];
    for(int i = 0, j = 0; i < n || j < d; i++){
        if(noperteneceAB(A,B,n,m)[i]){
            D[j] = A[i];
            j++;
        };
    };
    delete[] C;
    return D;
};

int nuevolimiteDS(int* C, int n){
    int c = n;
    for(int i = 0; i < n; i++){
        if(C[i] == C[i + 1]){
            c -= 2;
        };
    };
    return c;
};

int* simetricaA(int* A, int* B, int n, int m){
    int* C = pegarC(A,B,n,m);
    int d = nuevolimiteDS(C,n + m);
    int* D = new int[d];
    for(int i = 0, j = 0; i < n + m || j < d; i++){
        if(C[i] == C[i + 1]){
            i++;
        }else{
            D[j] = C[i];
            j++;
        };
    };
    delete[] C;
    return D;
};

bool perteneceA(int* A, int n, int x){
    ordenarE(A,n);
    for(int i = 0; i < n; i++){
        if(A[i] == x){
            return true;
        };
    };
    return false;
};

bool perteneceB(int* B, int m, int x){
    ordenarE(B,m);
    for(int i = 0; i < m; i++){
        if(B[i] == x){
            return true;
        };
    };
    return false;
};

bool contenidoA(int* A, int* B, int n, int m){
    int* C = pegarC(A,B,n,m);
    int c = n + m;
    int d = 0;
    for(int i = 0; i < c; i++){
        if(C[i] == C[i + 1]){
            d++;
        };
    };
    return d == n;
};

int* crearC2(int n){
    int c = 1;
    int* B = new int[n];
    for(int i = 0; i < n; i++, c++){
        do{
            cout << "Ingrese un numero para el segundo conjunto: ";
            cin >> B[i];
        }while(repetido(B,c));
    };
    ordenarE(B,n);
    return B;
};

int* crearC1(int n){
    int c = 1;
    int* A = new int[n];
    for(int i = 0; i < n; i++, c++){
        do{
            cout << "Ingrese un numero para el primer conjunto: ";
            cin >> A[i];
        }while(repetido(A,c));
    };
    ordenarE(A,n);
    return A;
};
