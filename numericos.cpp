#include"numericos.h"

double Potencia(double a, int b){
    if(b==0){
        return 1;
    }else{
        if(b<0){
            return 1.0/(Potencia(a,-b));
        }else{
            if(b>0){
                return a*Potencia(a,b-1);
            };
        };
    };
};

bool Divisible(int a, int b){
    if(b==0){
        return false;
    }else{
        if(a%b==0){
            return true;
        }else{
            return false;
        };
    };
};

bool Primo (int a){
    int n = a-1;
    if(a==2){
        return true;
    }else{
        if(a==1){
            return false;
        }else{
            while(n>1){
                if(a%n==0) {
                    return false;
                }else{
                    n--;
                };
            };
            return true;
        };
    };
};

bool PrimosRelativos(int a, int b){
    int n = a;
    int m = b;
    while(n>1&&m>1){
        if((a%n==0&&b%n==0)||(a%m==0&&b%m==0)){
            return false;
        }else{
            if(n>1){
                n--;
            }else{
                if(m>1){
                    m--;
                };
            };
        };
    };
    return true;
};

bool MultiploSuma (int a, int b, int c){
    if(b+c==0) {
        return false;
    }else{
        if(a%(b+c)==0){
            return true;
        };
        return false;
    };
};

double EvaluarPolinomio (double a, double b, double c, double x){
    return a*x*x+b*x+c;
};

double CoeficienteLineal (double a, double b, double c){
    return 2*a;
};

double Derivada (double a, double b, double c, double x){
    return 2*a*x+b;
};

bool Fibonacci(int n){
    if(n==1||n==0){
        return true;
    };
    int x = 1;
    int y = 1;
    int z = 0;
    for(int i =0;i<=n;i++){
        z=x+y;
        x=y;
        y=z;
        if(n==z){
            return true;
        };
    };
    return false;
};
