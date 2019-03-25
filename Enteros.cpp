#include "Enteros.h"

int Factorial(int x){
    if(x==0){
        return 1;
    }else{
        return x*Factorial(x-1);
    };
};

int maximo(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    };
};

int minimo(int a,int b){
    if(a<b){
        return a;
    }else{
        return b;
    };
};
