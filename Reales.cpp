#include"Reales.h"
#include"Enteros.h"

double Raiz2(double x){
    double Xo;
    double Xi = x;
    do{
        Xo = Xi;
        Xi = 0.5 * (Xo + x / Xo);
    }while(ValorAbsoluto(Xo - Xi) >= 1e-20);
    return 0.5 * (Xi + x / Xi);
};

double ValorAbsoluto(double x){
    if(x<0){
        return -x;
    }else{
        if(x>=0){
            return x;
        };
    };
};

double Seno(double x){
    double d = 0;
    for(int i=0;i<=12;i++){//Se toma 12 como valor finito.
        d = d + Potencia(-1,i)*Potencia(x,2*i+1)/Factorial(2*i+1);
    };
    return d;

};

double Coseno(double x){
    double a =0;
    for(int i=0;i<12;i++){//Se toma 12 como valor finito.
        a+=(Potencia(-1,i)*Potencia(x,2*i))/Factorial(2*i);
    };
    return a;
};

double Tangente(double x){
    return ((Seno(x))/(Coseno(x)));
};

