#include"Enteros.h"
#include"Reales.h"
#include"gemoetricos.h"

double const Pi = 3.14159265359;

char* Rectas(double m1, double m2, double b1, double b2){
    if(m1==m2&&b1!=b2){
        return "Paralelas";
    }else{
        if(m1*m2==-1.0){
            return "Perpenticulares";
        }else{
            return "Ninguna";
        };
    };
};

double* Corte(double m1, double m2, double b1, double b2){
    double* r = new double [2];
    r[0]=(b2-b1)/(m1-m2);
    r[1]=m1*((b2-b1)/(m1-m2))+b1;
    return r;
};

double AreaTrianguloCircuns (double r){
    return 3*Raiz2(3)*Potencia(r,2);
};

double PerimetroTrianguloCircuns (double r){
    return 6*Raiz2(3)*r;
};

double AreaTrianguloInsc (double r){
    return 3*Raiz2(3)/4*Potencia(r,2);
};

double PerimetroTrianguloInsc (double r){
    return r*Raiz2(3)*3;
};

double AreaCuadradoCircuns (double r){
    return Potencia(2*r,2);
};

double PerimetroCuadradoCircuns (double r){
    return 8*r;
};

double AreaCuadradoInsc (double r){
    return 2*Potencia(r,2);
};

double PerimetroCuadradoInsc (double r){
    return 4*Raiz2(2)*r;
};

double AreaPentagonoCircuns(double r){
    return 5*Tangente(Pi/5)*Potencia(r,2);
};

double PerimetroPentagonoCircuns(double r){
    return 10*Tangente(Pi/5)*r;
};

double AreaPentagonoInsc (double r){
    return 5*Seno(Pi/5)*Coseno(Pi/5)*Potencia(r,2);
};

double PerimetroPentagonoInsc(double r){
    return 10*Seno(Pi/5)*r;
};

double AreaHexagonoCircuns(double r){
    return 6*Tangente(Pi/6)*Potencia(r,2);
};

double PerimetroHexagonoCircuns(double r){
    return 12*Tangente(Pi/6)*r;
};

double AreaHexagonoInsc(double r){
    return 3*Raiz2(3)/2*Potencia(r,2);
};

double PerimetroHexagonoInsc(double r){
    return 6*r;
};

double Telarana (double r){
    double x = 6*r;
    for(int i = 1;i<=(int)r;i++){
        x+=6*i;
    };
    return x;
};
