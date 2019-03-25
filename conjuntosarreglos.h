#ifndef CONJUNTOSARREGLOS_H_INCLUDED
#define CONJUNTOSARREGLOS_H_INCLUDED

bool repetido(int* A, int c);
void ordenarE(int* A,int n);
int* pegarC(int* A, int* B, int n, int m);
int nuevolimiteU(int* A, int n);
int* unionA(int* A, int* B, int n, int m);
int nuevolimiteI(int* A, int n);
int* interseccionA(int* A, int* B, int n, int m);
int nuevolimiteD(int* A, int n, int m);
bool* noperteneceAB(int* A, int* B, int n, int m);
int* diferenciaA(int* A, int* B, int n, int m);
int nuevolimiteDS(int* C, int n);
int* simetricaA(int* A, int* B, int n, int m);
bool perteneceA(int* A, int n, int x);
bool perteneceB(int* B, int m, int x);
bool contenidoA(int* A, int* B, int n, int m);
int* crearC2(int n);
int* crearC1(int n);

#endif // CONJUNTOSARREGLOS_H_INCLUDED
