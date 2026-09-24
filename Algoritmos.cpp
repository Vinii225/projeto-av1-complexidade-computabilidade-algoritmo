#include "Algoritmos.h"

long long Algoritmos::contarOcorrencias(const int* V, int n, const int* B, int k) {
    long long total = 0;
    for (int j = 0; j < k; ++j)
        for (int i = 0; i < n; ++i)
            if (V[i] == B[j]) ++total;
    return total;
}

int Algoritmos::analisarPares(int** A, int n) {
    int cont = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if ((A[i][j] + A[j][i]) % 5 == 0) ++cont;
    return cont;
}

int Algoritmos::compararCubos(int*** A, int*** B, int n) {
    long long somaA = 0, somaB = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                somaA += A[i][j][k];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                somaB += B[i][j][k];
    return somaA >= somaB ? 1 : 0;
}

unsigned long long Algoritmos::fatorial(int m) {
    unsigned long long res = 1;
    for (int c = 2; c <= m; ++c) res *= c;
    return res;
}

unsigned long long Algoritmos::processarVetor(const int* V, int n) {
    unsigned long long soma = 0;
    for (int i = 0; i < n; ++i)
        soma += (V[i] % 2 == 0) ? V[i] : fatorial(V[i]);
    return soma;
}

int Algoritmos::buscaBinaria(const int* B, int n, int x) {
    int esq = 0, dir = n - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        if (B[meio] == x) return 1;
        if (B[meio] < x) esq = meio + 1;
        else dir = meio - 1;
    }
    return 0;
}

int Algoritmos::contarPresentes(const int* A, const int* B, int n) {
    int cont = 0;
    for (int i = 0; i < n; ++i)
        if (buscaBinaria(B, n, A[i]) == 1) ++cont;
    return cont;
}
