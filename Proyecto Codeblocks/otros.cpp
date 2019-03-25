#include"otros.h"
#include"Reales.h"

int Arbol(int k,int p,int t){
    if(p==0||k==0||t==0){
        return 0;
    }else{
        if((t%(p*k))==0){
            return (int)(t/(p*k));
        }else{
            return ((int)(t/(p*k)))+1;
        };
    };
};

double InteresSimple(double k, double i){
    return k+7*i;
};

double InteresCompuesto(double k, double i){
    return k+Potencia(i/k,7);
};

double Lego1 (int n){
    if(n==0||n==1){
        return 1;
    }else{
        return Lego1(n-1)+Lego1(n-2);

    };
};

double Lego2 (int n){
    if(n==0||n==1){
        return 1;
    }else{
        if(n==2){
            return 2;
        }else{
            return Lego2(n-1)+Lego2(n-2)+Lego2(n-3);
        };
    };
};

