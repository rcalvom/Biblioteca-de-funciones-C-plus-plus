#include "Enteros.h"
#include "gemoetricos.h"
#include "granja.h"
#include "numericos.h"
#include "reales.h"
#include "probarreglos.h"
#include "otros.h"
#include "menu.h"
#include "conjuntosarreglos.h"
#include "Arreglos.h"
#include "matrices.h"
#include "polinomios.h"
#include <iostream>

using namespace std;

char** Opciones (int n){
  char** X= new char*[n];
  return X;
};

int tamanoDecimalBinarioArr(int x){
    int a = x;
    int n = 0;
    while(a>1){
        a/=2;
        n++;
    };
    if(a==1){
        n++;
    };
    return n;
};

double* leerarreglo(int n){
    double* X = new double[n];
    for(int i=0;i<n;i++){
        cout<<"Elemento ["<<(i+1)<<"] : ";
        cin>>X[i];
    };
    cout<<"\n";
    return X;
};

int* leerarregloint(int n){
    int* X = new int[n];
    for(int i=0;i<n;i++){
        cout<<"Elemento ["<<(i+1)<<"] : ";
        cin>>X[i];
    };
    cout<<"\n";
    return X;
};

int tamanocriba(int n){
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
   return contarprimos(criba,n+1);
};

int Menu (char** X,int n){
    int opc;
    do{
        for(int i = 0;i<n;i++){
            cout<<(i+1)<<". "<<X[i]<<endl;
        };
    cout<<"0. Salir.\n\n";
    cout<<"Ingrese una opcion: ";
    cin>>opc;
    if(opc<0||opc>n){
        cout<<"\nIngresa una opcion valida.\n\n"<<endl;
    };
    }while(opc<0||opc>n);
    return opc;
};

void MenuGranja(){
    char** G = Opciones(4);
    G[0] = "La leche.";
    G[1] = "Los huevos.";
    G[2] = "La poblacion de escorpiones.";
    G[3] = "La reparacion del corral.";
    int k;
    do{
        cout<<"\nLa granja.\n"<<endl;
        k = Menu(G,4);
        cout<<"\nLa opcion escogida es: "<<k<<endl<<endl<<endl;
        switch(k){
            case 1:
                cout<<"La leche."<<endl;
                int m,x,t;
                cout<<"Ingrese la leche producida por m metros de pasto: ";
                cin>>x;
                cout<<"Ingrese los metros cuadrados de pasto requeridos para producir "<<x<<" Litros de leche: ";
                cin>>m;
                cout<<"Ingrese los metros cuadrados de pasto tolates: ";
                cin>>t;
                cout<<"\nLa cantidad total de leche producida en al granja es de "<<Leche(m,x,t)<<"Litros."<<endl<<endl;

            break;
            case 2:
                cout<<"Los huevos."<<endl;
                int a;
                cout<<"Ingrese la cantidad de aves: ";
                cin>>a;
                cout<<"\nEn la granja se producen "<<Huevos(a)<<" huevos mensualmente."<<endl<<endl;

            break;
            case 3:
                cout<<"La poblacion de escorpiones."<<endl;
                int p,ma,g;
                cout<<"Ingrese la cantidad de escorpiones pequenos: ";
                cin>>p;
                cout<<"Ingrese la cantidad de escorpiones medianos: ";
                cin>>ma;
                cout<<"Ingrese la cantidad de escorpiones grandes: ";
                cin>>g;
                cout<<"\nSe puede vender un maximo de "<<Escorpiones(p,ma,g)<<" kg de escorpiones."<<endl<<endl;
            break;
            case 4:
                cout<<"La reparacion del corral."<<endl;
                int pa,q,s;
                cout<<"Ingrese el costo del alambre de puas por metro: ";
                cin>>pa;
                cout<<"Ingrese el costo de las tablas de madera por metro: ";
                cin>>q;
                cout<<"Ingrese el costo de las varillas por metro: ";
                cin>>s;
                cout<<"\nEl cercamiento es mas economico usando "<<Cerca(pa,q,s)<<"."<<endl<<endl;
            break;
        };
    }while(k!=0);
};

void MenuNumericos(){
    char** N = Opciones(9);
    N[0] = "La potencia de un numero.";
    N[1] = "Numero que divide a otro.";
    N[2] = "Numero primo.";
    N[3] = "Primos relativos.";
    N[4] = "Multiplo de la Suma.";
    N[5] = "Evaluacion de un polinomio.";
    N[6] = "Coeficiente lineal de la derivada.";
    N[7] = "La derivada en un punto.";
    N[8] = "Serie de fibonacci.";
    int k;
    do{
        cout<<"\nNumericos.\n"<<endl;
        k = Menu(N,9);
        cout<<"\nLa opcion escogida es: "<<k<<endl<<endl;
        switch(k){
            case 1:
                cout<<"La potencia de un numero."<<endl;
                int a,b;
                cout<<"Ingrese la base: ";
                cin>>a;
                cout<<"Ingrese el exponente (Entero): ";
                cin>>b;
                cout<<"\nLa potencia "<<a<<"^"<<b<<" es : "<<Potencia(a,b)<<endl<<endl;
            break;
            case 2:
                cout<<"Numero que divide a otro."<<endl;
                int c,d;
                cout<<"Ingrese el dividendo: ";
                cin>>c;
                cout<<"Ingrese el divsor: ";
                cin>>d;
                if(Divisible(c,d)){
                    cout<<"\nEl numero "<<c<<" es divisible por "<<d<<"."<<endl<<endl;
                }else{
                    cout<<"\nEl numero "<<c<<" NO es divisible por "<<d<<"."<<endl<<endl;
                };

            break;
            case 3:
                cout<<"Numero primo."<<endl;
                int p;
                cout<<"Ingrese el numero a evaluar: ";
                cin>>p;
                if(Primo(p)){
                    cout<<"\nEl numero "<<p<<" es primo."<<endl<<endl;
                }else{
                    cout<<"\nEl numero "<<p<<" NO es primo."<<endl<<endl;
                };
            break;
            case 4:
                cout<<"Primos relativos."<<endl;
                int pr1,pr2;
                cout<<"Ingrese el primer numero: ";
                cin>>pr1;
                cout<<"Ingrese el segundo numero: ";
                cin>>pr2;
                if(PrimosRelativos(pr1,pr2)){
                    cout<<"\nLos numeros "<<pr1<<" y "<<pr2<<" son primos relativos."<<endl<<endl;
                }else{
                    cout<<"\nLos numeros "<<pr1<<" y "<<pr2<<" NO son primos relativos."<<endl<<endl;
                };
            break;
            case 5:
                cout<<"Multiplo de la Suma."<<endl;
                int ms1,ms2,ms3;
                cout<<"Ingrese el numero a evaluar: ";
                cin>>ms1;
                cout<<"Ingrese el primer sumando: ";
                cin>>ms2;
                cout<<"Ingrese el segundo sumando: ";
                cin>>ms3;
                if(MultiploSuma(ms1,ms2,ms3)){
                    cout<<"\nEl numero "<<ms1<<" es multiplo de la suma entre "<<ms2<<" y "<<ms3<<"."<<endl<<endl;
                }else{
                    cout<<"\nEl numero "<<ms1<<" NO es multiplo de la suma entre "<<ms2<<" y "<<ms3<<"."<<endl<<endl;
                };
            break;
            case 6:
                cout<<"Evaluacion de un polinomio."<<endl;
                double a1,b1,c1,x1;
                char bc,cc;
                cout<<"Ingrese el coeficiente del termino x^2: ";
                cin>>a1;
                cout<<"Ingrese el coeficiente del termino x: ";
                cin>>b1;
                cout<<"Ingrese el termino independiente: ";
                cin>>c1;
                cout<<"Ingrese el punto a evaluar: ";
                cin>>x1;
                if(b1>=0){
                    bc='+';
                }else{
                    bc=0;
                };
                if(c1>=0){
                    cc='+';
                }else{
                    cc=0;
                };
                cout<<"\nLa funcion "<<a1<<"x^2"<<bc<<b1<<"x"<<cc<<c1<<" evaluada en el punto x="<<x1<<" es "<<EvaluarPolinomio(a1,b1,c1,x1)<<"."<<endl<<endl;
            break;
            case 7:
                cout<<"Coeficiente lineal de la derivada."<<endl;
                double a2,b2,c2;
                char bc1,cc1;
                cout<<"Ingrese el coeficiente del termino x^2: ";
                cin>>a2;
                cout<<"Ingrese el coeficiente del termino x: ";
                cin>>b2;
                cout<<"Ingrese el termino independiente: ";
                cin>>c2;
                if(b2>=0){
                    bc1='+';
                }else{
                    bc1=0;
                };
                if(c2>=0){
                    cc1='+';
                }else{
                    cc1=0;
                };
                cout<<"\nEl coeficiente lineal de la derivada de la ecuacion "<<a2<<"x^2"<<bc1<<b2<<"x"<<cc1<<c2<<" Es "<<CoeficienteLineal(a2,b2,c2)<<"."<<endl<<endl;
            break;
            case 8:
                cout<<"La derivada en un punto."<<endl;
                double a3,b3,c3,x3;
                char bc2,cc2;
                cout<<"Ingrese el coeficiente del termino x^2: ";
                cin>>a3;
                cout<<"Ingrese el coeficiente del termino x: ";
                cin>>b3;
                cout<<"Ingrese el termino independiente: ";
                cin>>c3;
                cout<<"Ingrese el punto a evaluar: ";
                cin>>x3;
                if(b3>=0){
                    bc2='+';
                }else{
                    bc2=0;
                };
                if(c3>=0){
                    cc2='+';
                }else{
                    cc2=0;
                };
                cout<<"\nLa derivada de la funcion "<<a3<<"x^2"<<bc2<<b3<<"x"<<cc2<<c3<<" evaluada en el punto x="<<x3<<" es "<<Derivada(a3,b3,c3,x3)<<"."<<endl<<endl;
            break;
            case 9:
                cout<<"Serie de fibonacci."<<endl;
                int f;
                cout<<"Ingrese el numero a evaluar: ";
                cin>>f;
                if(Fibonacci(f)){
                    cout<<"\nEl numero "<<f<<" pertenece a la sucesion de Fibonacci."<<endl<<endl;
                }else{
                    cout<<"\nEl numero "<<f<<" NO pertenece a la sucesion de Fibonacci."<<endl<<endl;
                };
            break;
            };
    }while(k!=0);
};

void MenuGeometricos(){
    char** T = Opciones(5);
    T[0] = "Rectas en el plano.";
    T[1] = "Interseccion de dos rectas en el plano.";
    T[2] = "Area triangulo circunscrito.";
    T[3] = "Area y perimetro del cuadrado, pentagono y hexagono inscrito y circunscrito a una circunferencia.";
    T[4] = "La Telarana.";
    int k;
    do{
        cout<<"\nGeometricos.\n"<<endl;
        k = Menu(T,5);
        cout<<"\nLa opcion escogida es: "<<k<<endl<<endl;
        switch(k){
            case 1:
                cout<<"Rectas en el plano."<<endl;
                double m1,m2,b1,b2;
                cout<<"Ingrese la pendiente de la primera recta: ";
                cin>>m1;
                cout<<"Ingrese la pendiente de la segunda recta: ";
                cin>>m2;
                cout<<"Ingrese el punto de corte de la primera recta: ";
                cin>>b1;
                cout<<"Ingrese el punto de corte de la segunda recta: ";
                cin>>b2;
                cout<<"\nLas rectas son "<<Rectas(m1,m2,b1,b2)<<"."<<endl<<endl;
            break;
            case 2:
                cout<<"Interseccion de dos rectas en el plano."<<endl;
                double m11,m12,b11,b12;
                cout<<"Ingrese la pendiente de la primera recta: ";
                cin>>m11;
                cout<<"Ingrese la pendiente de la segunda recta: ";
                cin>>m12;
                cout<<"Ingrese el punto de corte de la primera recta: ";
                cin>>b11;
                cout<<"Ingrese el punto de corte de la segunda recta: ";
                cin>>b12;
                cout<<"\nLas rectas se cruzan en el punto ("<<Corte(m11,m12,b11,b12)[0]<<","<<Corte(m11,m12,b11,b12)[1]<<")"<<endl<<endl;
            break;
            case 3:
                cout<<"Area triangulo circunscrito."<<endl;
                double ra;
                cout<<"Ingrese el radio del circulo: ";
                cin>>ra;
                cout<<"\nEl area del triangulo regular circunscrito a la circunferencia de radio "<<ra<<" es "<<AreaTrianguloCircuns(ra)<<"."<<endl<<endl;
            break;
            case 4:
                cout<<"Area y perimetro del cuadrado, pentagono y hexagono inscrito y circunscrito a una circunferencia."<<endl;
                double r;
                cout<<"Ingrese el radio del circulo: ";
                cin>>r;
                cout<<"\nEl area del triangulo regular circunscrito a la circunferencia de radio "<<r<<" es "<<AreaTrianguloCircuns(r)<<".";
                cout<<"\nEl perimetro del triangulo regular circunscrito a la circunferencia de radio "<<r<<" es "<<PerimetroTrianguloCircuns(r)<<".";
                cout<<"\nEl area del triangulo regular inscrito a la circunferencia de radio "<<r<<" es "<<AreaTrianguloInsc(r)<<".";
                cout<<"\nEl perimetro del triangulo regular inscrito a la circunferencia de radio "<<r<<" es "<<PerimetroTrianguloInsc(r)<<"."<<endl;

                cout<<"\nEl area del cuadrado circunscrito a la circunferencia de radio "<<r<<" es "<<AreaCuadradoCircuns(r)<<".";
                cout<<"\nEl perimetro del cuadrado circunscrito a la circunferencia de radio "<<r<<" es "<<PerimetroCuadradoCircuns(r)<<".";
                cout<<"\nEl area del cuadrado inscrito a la circunferencia de radio "<<r<<"es "<<AreaCuadradoInsc(r)<<".";
                cout<<"\nEl perimetro del cuadrdo inscrito a la circunferencia de radio "<<r<<" es "<<PerimetroCuadradoInsc(r)<<"."<<endl;

                cout<<"\nEl area del pentagono regular circunscrito a la circunferencia de radio "<<r<<" es "<<AreaPentagonoCircuns(r)<<".";
                cout<<"\nEl perimetro del pentagono regular circunscrito a la circunferencia de radio "<<r<<" es "<<PerimetroPentagonoCircuns(r)<<".";
                cout<<"\nEl area del pentagono regular inscrito a la circunferencia de radio "<<r<<" es "<<AreaPentagonoInsc(r)<<".";
                cout<<"\nEl perimetro del pentagono regular inscrito a la circunferencia de radio "<<r<<" es "<<PerimetroPentagonoInsc(r)<<"."<<endl;

                cout<<"\nEl area del hexagono regular circunscrito a la circunferencia de radio "<<r<<" es "<<AreaHexagonoCircuns(r)<<".";
                cout<<"\nEl perimetro del hexagono regular circunscrito a la circunferencia de radio "<<r<<" es "<<PerimetroHexagonoCircuns(r)<<".";
                cout<<"\nEl area del hexagono regular inscrito a la circunferencia de radio "<<r<<" es "<<AreaHexagonoInsc(r)<<".";
                cout<<"\nEl perimetro del hexagono regular inscrito a la circunferencia de radio "<<r<<" es "<<PerimetroHexagonoInsc(r)<<"."<<endl<<endl;
            break;
            case 5:
                cout<<"La telarana."<<endl;
                double rb;
                cout<<"Ingrese el radio del circulo que debe contener a la telarana: ";
                cin>>rb;
                cout<<"\nLa cantidad de seda necesaria para construir la telarana es "<<Telarana(rb)<<"."<<endl<<endl;
            break;
            };
    }while(k!=0);
};

void MenuOtros(){
char** O = Opciones(3);
    O[0] = "Las hojas de los arboles.";
    O[1] = "El interes.";
    O[2] = "El lego.";
    int k;
    do{
        cout<<"\nOtros.\n"<<endl;
        k = Menu(O,3);
        cout<<"\nLa opcion escogida es: "<<k<<endl<<endl<<endl;
        switch(k){
            case 1:
                cout<<"Las hojas de los arboles."<<endl;
                int p,k1,t;
                cout<<"Ingrese la cantidad de hojas que tiene una rama: ";
                cin>>p;
                cout<<"Ingrese la cantidad de ramas que tiene un arbol: ";
                cin>>k1;
                cout<<"Ingrese la cantidad de hojas totales: ";
                cin>>t;
                cout<<"\nSe deben podar "<<Arbol(k1,p,t)<<" arboles para obtener "<<t<<" hojas."<<endl<<endl;
            break;
            case 2:
                cout<<"El interes."<<endl;
                int pesos,interes;
                cout<<"Ingrese la cantidad de pesos prestados: ";
                cin>>pesos;
                cout<<"Ingrese la cantidad de pesos de interes: ";
                cin>>interes;
                cout<<"\nDespues de una semana la deuda asciende a "<<InteresSimple(pesos,interes)<<" si el interes es simple."<<endl;
                cout<<"\nDespues de una semana la deuda asciende a "<<InteresCompuesto(pesos,interes)<<" si el interes es compuesto."<<endl<<endl;
            break;
            case 3:
                cout<<"El lego."<<endl;
                int ficha;
                cout<<"Ingrese la longitud de la base: ";
                cin>>ficha;
                cout<<"\nSe puede llenar la ficha de 1x"<<ficha<<" de "<<Lego1(ficha)<<" maneras distintas contando con fichas de 1x1 y 1x2."<<endl;
                cout<<"\nSe puede llenar la ficha de 1x"<<ficha<<" de "<<Lego2(ficha)<<" maneras distintas contando con ficahs de 1x1, 1x2 y 1x3."<<endl<<endl;
            break;
        };
    }while(k!=0);
};

void MenuArreglos(){
    char** Arg = Opciones(13);
    Arg[0] = "La criba de eratostenes.";
    Arg[1] = "La Suma de los elementos de un arreglo.";
    Arg[2] = "EL promedio de los elementos de un arreglo.";
    Arg[3] = "El producto de dos arreglos.";
    Arg[4] = "El minimo de un arrelgo.";
    Arg[5] = "El maximo de un arreglo.";
    Arg[6] = "El producto directo de dos arreglos.";
    Arg[7] = "La mediana de un arreglo.";
    Arg[8] = "Ceros al final.";
    Arg[9] = "De binario a decimal";
    Arg[10] = "De decimal a binario.";
    Arg[11] = "Maximo comun divisor.";
    Arg[12] = "Minimo comun multiplo.";
    int k;
    do{
        cout<<"\nProblemas de arreglos.\n"<<endl;
        k = Menu(Arg,13);
        cout<<"\nLa opcion escogida es: "<<k<<endl<<endl<<endl;
        switch(k){
            case 1:
                cout<<"La criba de eratostenes."<<endl;
                int cr;
                cout<<"Ingrese el numero maximo de la criba: ";
                cin>>cr;
                cout<<"\nLos primos entre 1 y "<<cr<<" son: ";
                cout<<"{";
                for(int i=0;i<tamanocriba(cr)-1;i++){
                    cout<<CribaEratostenes(cr)[i]<<",";
                };
                cout<<CribaEratostenes(cr)[tamanocriba(cr)-1]<<"}.\n\n";
            break;
            case 2:
                cout<<"La Suma de los elementos de un arreglo."<<endl;
                int tam;
                cout<<"Indica el tamano del arreglo: ";
                cin>>tam;
                cout<<"\nLa suma de los elementos de este arreglo es: "<<SumaArrReales(leerarreglo(tam),tam)<<"."<<endl<<endl;
            break;
            case 3:
                cout<<"El promedio de los elementos de un arreglo."<<endl;
                int tam1;
                cout<<"Indica el tamano del arreglo: ";
                cin>>tam1;
                cout<<"\nEl promedio de los elementos de este arreglo es: "<<PromedioArrReales(leerarreglo(tam1),tam1)<<"."<<endl<<endl;
            break;
            case 4:
                cout<<"El producto de dos arreglos."<<endl;
                int tam2;
                cout<<"Indica el tamano de los arreglos: ";
                cin>>tam2;
                cout<<"\nEl producto de los elementos de este arreglo es: "<<ProductoArrReales(leerarreglo(tam2),leerarreglo(tam2),tam2)<<"."<<endl<<endl;
            break;
            case 5:
                cout<<"El minimo de un arrelgo."<<endl;
                int tam3;
                cout<<"Indica el tamano del arreglo: ";
                cin>>tam3;
                cout<<"\nEl minimo de los elementos de este arreglo es: "<<MinimoArrReales(leerarreglo(tam3),tam3)<<"."<<endl<<endl;
            break;
            case 6:
                cout<<"El maximo de un arrelgo."<<endl;
                int tam4;
                cout<<"Indica el tamano del arreglo: ";
                cin>>tam4;
                cout<<"\nEl maximo de los elementos de este arreglo es: "<<MaximoArrReales(leerarreglo(tam4),tam4)<<"."<<endl<<endl;
            break;
            case 7:
                {
                cout<<"El producto directo de dos arreglos."<<endl;
                int tama;
                cout<<"Indica el tamano de los arreglos: ";
                cin>>tama;
                double* X1 = new double[tama];
                X1 = leerarreglo(tama);
                double* Y1 = new double[tama];
                Y1 = leerarreglo(tama);
                cout<<"\nEl producto directo de los arreglos es: ";
                cout<<"{";
                for(int i=0;i<tama-1;i++){
                    cout<<ProductoDArrReales(X1,Y1,tama)[i]<<",";
                };
                cout<<ProductoDArrReales(X1,Y1,tama)[tama-1]<<"}.\n\n";
                delete [] X1;
                delete [] Y1;
                break;
                };
            case 8:
                cout<<"La mediana de un arreglo."<<endl;
                int tamb;
                cout<<"Indica el tamano del arreglo: ";
                cin>>tamb;
                cout<<"\nLa mediana de los elementos de este arreglo es: "<<MedianaArrReales(leerarreglo(tamb),tamb)<<"."<<endl<<endl;
            break;
            case 9:
                {
                cout<<"Ceros al final."<<endl;
                int cero;
                cout<<"Indica el tamano del arreglo: ";
                cin>>cero;
                int* X1 = new int[cero];
                X1 = leerarregloint(cero);
                cout<<"\nEl arreglo queda de la siguiente manera: ";
                cout<<"{";
                for(int i=0;i<cero-1;i++){
                    cout<<CerosArr(X1,cero)[i]<<",";
                };
                cout<<CerosArr(X1,cero)[cero-1]<<"}.\n\n";
                delete [] X1;
                };
            break;
            case 10:
                cout<<"De binario a decimal."<<endl;
                int bina;
                cout<<"Indica el tamano del numero binario: ";
                cin>>bina;
                cout<<"\nEl numero indicado en el sistema decimal es: "<<BinarioDecimalArr(leerarregloint(bina),bina)<<"."<<endl<<endl;
            break;
            case 11:
                {
                cout<<"De decimal a binario."<<endl;
                int deci;
                cout<<"Indica el numero decimal: ";
                cin>>deci;
                int tambin = tamanoDecimalBinarioArr(deci);
                cout<<"\nEl numero decimal al revez es: ";
                cout<<"{";
                for(int i=0;i<tambin-1;i++){
                    cout<<DecimalBinarioArr(deci)[i]<<",";
                };
                cout<<DecimalBinarioArr(deci)[tambin-1]<<"}.\n\n";
                };
            break;
            case 12:
                cout<<"Maximo comun divisor."<<endl;
                int mcd1;
                cout<<"Indica el tamano del arreglo: ";
                cin>>mcd1;
                cout<<"\nEl maximo comun divisor de los elementos del arreglo es: "<<mcd(leerarregloint(mcd1),mcd1)<<"."<<endl<<endl;
            break;
            case 13:
                cout<<"Minimo comun multiplo."<<endl;
                int mcm1;
                cout<<"Indica el tamano del arreglo: ";
                cin>>mcm1;
                cout<<"\nEl minimo comun multiplo de los elementos del arreglo es: "<<mcm(leerarregloint(mcm1),mcm1)<<"."<<endl<<endl;
            break;
        };
    }while(k!=0);
};

void MenuConjuntosArreglos(){
    int n = 0, m = 0;
    do{
        cout << "Ingrese el tamanio del primer conjunto: ";
        cin >> n;
    }while(n < 1);
    int* A = crearC1(n);
    do{
        cout << "Ingrese el tamanio del segundo conjunto: ";
        cin >> m;
    }while(m < 1);
    int* B = crearC2(m);
    cout << "Conjunto A: " << endl;
    cout << "[ ";
    for(int i = 0; i < n; i++){
        cout << A[i] << ", ";
    };
    cout << "]" << endl;
    cout << "Conjunto B: " << endl;
    cout << "[ ";
    for(int i = 0; i < m; i++){
        cout << B[i] << ", ";
    };
    cout << "]" << endl;
    char** X = Opciones(6);
    X[0] = "Union de conjuntos.";
    X[1] = "Interseccion de conjuntos.";
    X[2] = "Diferencia de conjuntos.";
    X[3] = "Diferencia simetrica de conjuntos.";
    X[4] = "Determinar si el elemento x pertenece a alguno de los dos conjuntos.";
    X[5] = "Determinar si el primer conjunto esta contenido en el segundo conjunto.";
    int k = 0;
    do{
        k = Menu(X,6);
        switch(k){
        case 1:{
            int* D = unionA(A,B,n,m);
            int* C = pegarC(A,B,n,m);
            int d = nuevolimiteU(C,n + m);
            cout << "La union de los dos conjuntos es: " << endl;
            cout << "[ ";
            for(int i = 0; i < d; i++){
                cout << D[i] << ", ";
            };
            cout << "]" << endl;
            delete[] C;
            delete[] D;
        };
        break;
        case 2:{
            int* D = interseccionA(A,B,n,m);
            int* C = pegarC(A,B,n,m);
            int d = nuevolimiteI(C,n + m);
            cout << "La interseccion de los dos conjuntos es: " << endl;
            cout << "[ ";
            for(int i = 0; i < d; i++){
                cout << D[i] << ", ";
            };
            cout << "]" << endl;
            delete[] C;
            delete[] D;
        };
        break;
        case 3:{
            int* D = diferenciaA(A,B,n,m);
            int* C = pegarC(A,B,n,m);
            int d = nuevolimiteD(C,n+m,n);
            cout << "La diferencia de los conjuntos A menos B es: " << endl;
            cout << "[ ";
            for(int i = 0; i < d; i++){
                cout << D[i] << ", ";
            };
            cout << "]" << endl;
            delete[] C;
            delete[] D;
        };
        break;
        case 4:{
            int* D = simetricaA(A,B,n,m);
            int* C = pegarC(A,B,n,m);
            int d = nuevolimiteDS(C,n+m);
            cout << "La diferencia simetrica de los conjuntos A y B es: " << endl;
            cout << "[ ";
            for(int i = 0; i < d; i++){
                cout << D[i] << ", ";
            };
            cout << "]" << endl;
            delete[] C;
            delete[] D;
        };
        break;
        case 5:{
            int x = 0;
            cout << "Ingrese un numero entero: ";
            cin >> x;
            if(perteneceA(A,n,x) && perteneceB(B,m,x)){
                cout << "El numero entero " << x <<" pertenece a los conjuntos A y B." << endl;
            }else if(perteneceA(A,n,x)){
                cout << "El numero entero " << x <<" pertenece al conjunto A." << endl;
            }else if(perteneceB(B,m,x)){
                cout << "El numero entero " << x <<" pertenece al conjunto B." << endl;
            }else{
                cout << "El numero entero " << x <<" NO pertenece a los conjuntos A o B." << endl;
            };
        };
        break;
        case 6:{
            if(contenidoA(A,B,n,m)){
                cout << "El conjunto A esta contenido en el conjunto B." << endl;
            }else{
                cout << "El conjunto A NO esta contenido en el conjunto B." << endl;
            };
        };
        break;
        };
    }while(k!=0);

};

void MenuPolinomiosArreglos(){
    int g,gr;
        do{
        cout<<"Indique el grado del primer polinomio: ";cin>>g;
        }while(g<0);
        double* polMultip1=new double[g+1];
        for(int i=g;i>=0;i--){
            cout<<"Indique el coeficiente de x^"<<i<<" ";cin>>polMultip1[i];
        };
        do{
        cout<<"Indique el grado del segundo polinomio: ";cin>>gr;
        }while(gr<0);
        double* polMultip2=new double[gr+1];
        for(int i=gr;i>=0;i--){
            cout<<"Indique el coeficiente de x^"<<i<<" ";cin>>polMultip2[i];
        };
    char** X = Opciones(6);
    X[0] = "Evaluar : Lee un real e imprime la evaluacion de los dos polinomios en dicho dato.";
    X[1] = "Sumar : Calcula el polinomio suma y lo imprime.";
    X[2] = "Resta : Calcula el polinomio resta y lo imprime.";
    X[3] = "Multiplicar : Calcula el polinomio multiplicacion y lo imprime.";
    X[4] = "Dividir: Calcula el polinomio division del primer polinomio por el segundo y lo imprime.";
    X[5] = "Residuo : Calcula el polinomio residuo de la división del primero por el segundo y lo imprime.";
    int k = 0;
    do{
        k = Menu(X,6);
        switch(k){
        case 1:
            int R;
            cout<<"Digite un real para evaluarlo en los dos polinomios";cin>>R;
            cout<<"El resultado del real evaluado en el primer polinomio es: "<<Xevaluado(polMultip1,g,R)<<endl;
            cout<<"El resultado del real evaluado en el primer polinomio es: "<<Xevaluado(polMultip2,gr,R)<<endl;
        break;
        case 2:
            cout<<"La suma de los polinomios da como resultado el siguiente polinomio: "<<endl;
            for(int i=maximo(g,gr);i>=0;i--){
                if(SumarPolinomios(polMultip1,g,polMultip2,gr)[i]!=0){
                        cout<<SumarPolinomios(polMultip1,g,polMultip2,gr)[i]<<"x^"<<i<<" + ";
                };
            };
        	cout<<endl;
        break;
        case 3:
            cout<<"La resta de los polinomios da como resultado el siguiente polinomio: "<<endl;
            for(int i=maximo(g,gr);i>=0;i--){
                if(RestaPolinomios(polMultip1,g,polMultip2,gr)[i]!=0){
                        cout<<RestaPolinomios(polMultip1,g,polMultip2,gr)[i]<<"x^"<<i<<" + ";
                };
            };
        	cout<<endl;
        break;
        case 4:
            cout<<"La multiplicacion de los polinomios da como resultado el siguiente polinomio: "<<endl;
            for(int i=gr+g;i>=0;i--){
                if(Multipolinomios(polMultip1,g,polMultip2,gr)[i]!=0){
                        cout<<Multipolinomios(polMultip1,g,polMultip2,gr)[i]<<"x^"<<i<<" + ";
                };
            };
            cout<<endl;
        break;
        case 5:
            cout<<"La division de los polinomios da como resultado el siguiente polinomio: "<<endl;
            if(gr>g){
                    cout<<"No se puede dividir el primer polinomio por el segundo."<<endl;
            }else{
                double* arr=dividir_pol(polMultip1,g,polMultip2,gr);
                for(int i=g-gr;i>=0;i--){
                            cout<<arr[i]<<"x^"<<i<<" + ";
                };
                cout<<endl;
            };
        break;
        case 6:
            cout<<"El residuo de la division de polinomios da como resultado el siguiente polinomio: "<<endl;
            if(gr>g){
                    cout<<"No se puede dividir el primer polinomio por el segundo."<<endl;
            }else{
                double* arr=residuo_pol(polMultip1,g,polMultip2,gr);
                for(int i=g-gr;i>=0;i--){
                            cout<<arr[i]<<"x^"<<i<<" + ";
                };
                cout<<endl;
            };
        break;
        };
    }while(k!=0);
};

void MenuMatrices(){
    char** X = Opciones(10);
    X[0] = "Suma de dos matrices de numeros.";
    X[1] = "Producto de dos matrices de numeros.";
    X[2] = "Suma de los elementos de una columna dada de una matriz.";
    X[3] = "Suma de los elementos de una fila dada de una matriz.";
    X[4] = "Matriz cuadrada mágica.";
    X[5] = "Mayores de un numero en una matriz";
    X[6] = "Determinante de una matriz.";
    X[7] = "Solucion a un sistema de ecuaciones.";
    X[8] = "Inversa de una Matriz";
    X[9] = "Espiral";
    int k = 0;
    do{
        k = Menu(X,10);
        switch(k){
                case 1:
                {
                    char** X = Opciones(2);
                    X[0] = "Matriz de enteros";
                    X[1] = "Matriz de reales";

                    int k = 0;
                        do{
                        k = Menu(X,2);
                        switch(k){
                        case 1:
                        {
                        int f,c;
                        do{
                        cout<<"Indique la cantidad de filas en las matrices ";cin>>f;
                        }while(f<0);
                        do{
                        cout<<"Indique la cantidad de columnas en las matrices: ";cin>>c;
                        }while(c<0);

                        int** m1=CrearMatrizInt(f,c);
                        int** m2=CrearMatrizInt(f,c);
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"Indique dato en la posicion "<<"["<<i<<"]"<<"["<<j<<"]"<<"de la primer matriz: ";cin>>m1[i][j];
                            };
                        };
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"Indique dato en la posicion "<<"["<<i<<"]"<<"["<<j<<"]"<<"de la segunda matriz: ";cin>>m2[i][j];
                            };
                        };
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"|"<<SumarMatrices(m1,m2,f,c)[i][j];
                                if(SumarMatrices(m1,m2,f,c)[i][j]<10){
                                    cout<<" ";
                                };
                            };
                            cout<<"|"<<endl;
                        };
                        };
                        break;
                        case 2:
                        {
                        int f,c;
                        do{
                        cout<<"Indique la cantidad de filas en las matrices ";cin>>f;
                        }while(f<0);
                        do{
                        cout<<"Indique la cantidad de columnas en las matrices: ";cin>>c;
                        }while(c<0);

                        double** m1=crear_matriz_double(f,c);
                        double** m2=crear_matriz_double(f,c);
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"Indique dato en la posicion "<<"["<<i<<"]"<<"["<<j<<"]"<<"de la primer matriz: ";cin>>m1[i][j];
                            };
                        };
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"Indique dato en la posicion "<<"["<<i<<"]"<<"["<<j<<"]"<<"de la segunda matriz: ";cin>>m2[i][j];
                            };
                        };
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"|"<<SumarMatricesR(m1,m2,f,c)[i][j];
                                if(SumarMatricesR(m1,m2,f,c)[i][j]<10){
                                    cout<<" ";
                                };
                            };
                            cout<<"|"<<endl;
                        };
                        };
                        break;
                        };
                        }while(k!=0);
                };
                break;
                case 2:
                    {
                    char** X = Opciones(2);
                    X[0] = "Matriz de enteros";
                    X[1] = "Matriz de reales";

                    int k = 0;
                        do{
                        k = Menu(X,2);
                        switch(k){
                        case 1:
                        {
                        int f,c;
                        do{
                        cout<<"Indique la cantidad de filas en las matrices ";cin>>f;
                        }while(f<0);
                        do{
                        cout<<"Indique la cantidad de columnas en las matrices: ";cin>>c;
                        }while(c<0);

                        int** m1=crear_matriz_int(f,c);
                        int** m2=crear_matriz_int(f,c);
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"Indique dato en la posicion "<<"["<<i<<"]"<<"["<<j<<"]"<<"de la primer matriz: ";cin>>m1[i][j];
                            };
                        };
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"Indique dato en la posicion "<<"["<<i<<"]"<<"["<<j<<"]"<<"de la segunda matriz: ";cin>>m2[i][j];
                            };
                        };
                        cout<<"La multiplicacion tre las matrices da como resultado la siguiente matriz: "<<endl;
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"|"<<MultiMatricesE(m1,m2,f,c)[i][j];
                                if(MultiMatricesE(m1,m2,f,c)[i][j]<10){
                                    cout<<" ";
                                };
                            };
                            cout<<"|"<<endl;
                        };
                        };
                        break;
                        case 2:
                        {
                        int f,c;
                        do{
                        cout<<"Indique la cantidad de filas en las matrices ";cin>>f;
                        }while(f<0);
                        do{
                        cout<<"Indique la cantidad de columnas en las matrices: ";cin>>c;
                        }while(c<0);

                        double** m1=crear_matriz_double(f,c);
                        double** m2=crear_matriz_double(f,c);
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"Indique dato en la posicion "<<"["<<i<<"]"<<"["<<j<<"]"<<"de la primer matriz: ";cin>>m1[i][j];
                            };
                        };
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"Indique dato en la posicion "<<"["<<i<<"]"<<"["<<j<<"]"<<"de la segunda matriz: ";cin>>m2[i][j];
                            };
                        };
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"|"<<MultiMatricesR(m1,m2,f,c)[i][j];
                                if(MultiMatricesR(m1,m2,f,c)[i][j]<10){
                                    cout<<"  ";
                                };
                            };
                            cout<<"|"<<endl;
                        };
                        };
                        break;
                        };
                        }while(k!=0);
                };

                break;
                case 3:
                    {
                        int f,c;
                        do{
                        cout<<"Indique la cantidad de filas en la matriz. ";cin>>f;
                        }while(f<0);
                        do{
                        cout<<"Indique la cantidad de columnas en la matriz: ";cin>>c;
                        }while(c<0);

                        int** m1=crear_matriz_int(f,c);
                        for(int i=0;i<f;i++){
                            for(int j=0;j<c;j++){
                                cout<<"Indique dato en la posicion "<<"["<<i<<"]"<<"["<<j<<"]"<<"de la matriz: ";cin>>m1[i][j];
                            };
                        };
                        cout<<"La suma de las columnas : "<<endl;
                        cout<<"[";
                        for(int i=0;i<c;i++){
                                cout<<SumarColumnas(m1,f,c)[i]<<",";
                        };
                        cout<<"]"<<endl;
                    };
                break;
                case 4:{
                        int filas = 0, columnas = 0;
                        do{
                        cout << "Ingrese la cantidad de filas en la matriz: ";
                        cin >> filas;
                        }while(filas < 1);
                        do{
                        cout << "Ingrese la cantidad de columnas en la matriz: ";
                        cin >> columnas;
                        }while(columnas < 1);
                        int** m1 = crear_matriz_int(filas,columnas);
                        for(int i = 0; i < filas; i++){
                            for(int j = 0; j < columnas; j++){
                                cout << "Ingrese dato en la posicion " << "[" << i << "]" << "[" << j << "]" << "de la matriz: ";
                                cin >> m1[i][j];
                            };
                        };
                        cout << "La matriz quedo de la siguiente manera: " << endl;
                        for(int i = 0; i < filas; i++){
                            for(int j = 0; j < columnas; j++){
                                cout <<"| "<< m1[i][j];
                            };
                            cout << " |" << endl;
                        };
                        cout << "La suma de las filas es: " << endl;
                        cout << "[ ";
                        for(int i = 0; i < filas; i++){
                            cout << SumarFilas(m1,filas,columnas)[i] << ", ";
                        };
                        cout << "]" << endl;
                };
                break;
                case 5:
                    {
                        int n = 0;
                        do{
                        cout << "Ingrese el tamanio del lado del cuadrado magico: ";
                        cin >> n;
                        }while(n < 1);
                        int** m1 = crear_matriz_int(n,n);
                        for(int i = 0; i < n; i++){
                            for(int j = 0; j < n; j++){
                                cout << "Ingrese dato en la posicion " << "[" << i << "]" << "[" << j << "]" << "de la matriz: ";
                                cin >> m1[i][j];
                            };
                        };
                        cout << "La matriz quedo de la siguiente manera: " << endl;
                        for(int i = 0; i < n; i++){
                            for(int j = 0; j < n; j++){
                                cout <<"| "<< m1[i][j];
                            };
                            cout << " |" << endl;
                        };
                        if(CuadradoMagico(m1,n)){
                            cout << "El cuadrado es magico" << endl;
                        }else{
                            cout << "El cuadrado NO es magico" << endl;
                        };
                    break;
        }
                    case 6:
                        {
                    int filas = 0, columnas = 0, x = 0;
                        do{
                        cout << "Ingrese la cantidad de filas en la matriz: ";
                        cin >> filas;
                        }while(filas < 1);
                        do{
                        cout << "Ingrese la cantidad de columnas en la matriz: ";
                        cin >> columnas;
                        }while(columnas < 1);
                        int** m1 = crear_matriz_int(filas,columnas);
                        for(int i = 0; i < filas; i++){
                            for(int j = 0; j < columnas; j++){
                                cout << "Ingrese dato en la posicion " << "[" << i << "]" << "[" << j << "]" << "de la matriz: ";
                                cin >> m1[i][j];
                            };
                        };
                        cout << "La matriz quedo de la siguiente manera: " << endl;
                        for(int i = 0; i < filas; i++){
                            for(int j = 0; j < columnas; j++){
                                cout <<"| "<< m1[i][j];
                            };
                            cout << " |" << endl;
                        };
                        cout << "ingrese un numero entero para reemplazar la matriz: ";
                        cin >> x;
                        int** A = ReemplazarM(m1,filas,columnas,x);
                        cout << "La matriz en unos y ceros reemplazada es: " << endl;
                        for(int i = 0; i < filas; i++){
                            for(int j = 0; j < columnas; j++){
                                cout <<"| "<< A[i][j];
                            };
                            cout << " |" << endl;
                        };

                break;
        }
                    case 7:
                        {
                    int n = 0;
                        do{
                        cout << "Ingrese el tamanio del lado de la matriz: ";
                        cin >> n;
                        }while(n < 1);
                        int** m1 = crear_matriz_int(n,n);
                        for(int i = 0; i < n; i++){
                            for(int j = 0; j < n; j++){
                                cout << "Ingrese dato en la posicion " << "[" << i << "]" << "[" << j << "]" << "de la matriz: ";
                                cin >> m1[i][j];
                            };
                        };
                        cout << "La matriz quedo de la siguiente manera: " << endl;
                        for(int i = 0; i < n; i++){
                            for(int j = 0; j < n; j++){
                                cout <<"| "<< m1[i][j];
                            };
                            cout << " |" << endl;
                        };
                        cout << "La determinante de esa matriz es: " <<DeterminanteMatriz(m1,n)<< endl;

                    break;
        }
                    case 8:
                        {
                    int n= 0;
                        do{
                        cout << "Ingrese el tamanio del lado de la matriz: ";
                        cin >> n;
                        }while(n < 1);
                        int** m1 = crear_matriz_int(n,n);
                        for(int i = 0; i < n; i++){
                            for(int j = 0; j < n; j++){
                                cout << "Ingrese dato en la posicion " << "[" << i << "]" << "[" << j << "]" << "de la matriz: ";
                                cin >> m1[i][j];
                            };
                        };
                        cout << "La matriz quedo de la siguiente manera: " << endl;
                        for(int i = 0; i < n; i++){
                            for(int j = 0; j < n; j++){
                                cout <<"| "<< m1[i][j];
                            };
                            cout << " |" << endl;
                        };

                        int* m2= new int[n];
                        for(int i = 0; i < n; i++){
                                cout << "Ingrese dato en la posicion " << "[" << i << "]" << "del arreglo: ";
                                cin >> m2[i];
                            };
                            cout << "El arreglo quedo de la siguiente manera: " << endl;
                            for(int i = 0; i < n; i++){
                                cout <<"| "<< m2[i];
                        };
                        cout<<endl;
                        cout << "las soluciones al sistema de ecuaciones son: ";
                        for(int i =0;i<n;i++){
                            cout<<SistemaEcuaciones(m1,m2,n)[i]<<"|";
                        };
                        cout<<endl;
                break;
        }
                        case 9:
                        {
                    int n = 0;
                        do{
                        cout << "Ingrese el tamanio del lado de la matriz: ";
                        cin >> n;
                        }while(n < 1);
                        int** m1 = crear_matriz_int(n,n);
                        for(int i = 0; i < n; i++){
                            for(int j = 0; j < n; j++){
                                cout << "Ingrese dato en la posicion " << "[" << i << "]" << "[" << j << "]" << "de la matriz: ";
                                cin >> m1[i][j];
                            };
                        };
                        cout << "La matriz quedo de la siguiente manera: " << endl;
                        for(int i = 0; i < n; i++){
                            for(int j = 0; j < n; j++){
                                cout <<"| "<< m1[i][j];
                            };
                            cout << " |" << endl;
                        };

                        cout << "La inversa de esa matriz es: "<<endl;
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                cout<<"| "<<MatrizInversa(m1,n)[i][j];
                            };
                            cout << " |" << endl;
                        };

                break;
        }
                    case 10:
                        {
                    int n = 0;
                        do{
                        cout << "Ingrese el tamanio del arreglo: ";
                        cin >> n;
                        }while(n < 1);
                        int* m1 = new int[n];
                        for(int i = 0; i < n; i++){
                                cout << "Ingrese dato en la posicion " << "[" << i << "]" << "del arreglo: ";
                                cin >> m1[i];
                            };
                        cout << "El arreglo quedo siguiente manera: " << endl;
                        for(int i = 0; i < n; i++){
                                cout <<"| "<< m1[i];
                        }
                        cout << "\nMatriz en espiral es: "<<endl;
                        for(int i=0;i<Raiz2(n);i++){
                            for(int j=0;j<Raiz2(n);j++){
                                cout<<"| "<<Espiral(m1,n)[i][j];
                            };
                            cout << " |" << endl;
                        };

                break;
        }
                };
            }while(k!=0);
};

void MenuPrincipal(){
    char** A = Opciones(9);
    A[0] = "La granja.";
    A[1] = "Numericos.";
    A[2] = "Geometricos.";
    A[3] = "Otros.";
    A[4] = "Problemas de arrreglos.";
    A[5] = "Problemas de conjuntos como arreglos.";
    A[6] = "Problemas de polinomios como arrelgos.";
    A[7] = "Problemas de matrices.";
    A[8] = "Relaciones binarias como matrices";
    int k;
    do{
        k = Menu(A,9);
        cout<<"\nLa opcion escogida es: "<<k<<endl<<endl;
        switch(k){
            case 1:
                MenuGranja();
            break;
            case 2:
                MenuNumericos();
            break;
            case 3:
                MenuGeometricos();
            break;
            case 4:
                MenuOtros();
            break;
            case 5:
                MenuArreglos();
            break;
            case 6:
                MenuConjuntosArreglos();
            break;
            case 7:
                MenuPolinomiosArreglos();
            break;
            case 8:
                MenuMatrices();
            break;
            };
    }while(k!=0);
};
