#include "granja.h"

double Leche(double m, double x,double t){
    return x/m*t;
};

int Huevos (int a){
    return (int)(5.0/2*a);
};

double Escorpiones (int p, int m, int g){
    return (1/3.0)*(p*(2/100.0)+m*(3/100.0)+g*(5/100.0));
};

char* Cerca (double p, double q, double s){
    if(q*4<=p*5&&q*4<=s*8){
        return "Madera";
    }else{
        if(s*8<=q*4&&s*8<=p*5){
            return "Varilla";
        }else{
            return "Alambre";
        };
    };
};

