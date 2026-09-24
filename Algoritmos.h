#ifndef ALGORITMOS_H
#define ALGORITMOS_H

class Algoritmos {
public:
    static long long contarOcorrencias(const int* V, int n, const int* B, int k);
    static int analisarPares(int** A, int n);
    static int compararCubos(int*** A, int*** B, int n);
    static unsigned long long fatorial(int m);
    static unsigned long long processarVetor(const int* V, int n);
    static int buscaBinaria(const int* B, int n, int x);
    static int contarPresentes(const int* A, const int* B, int n);
};

#endif
