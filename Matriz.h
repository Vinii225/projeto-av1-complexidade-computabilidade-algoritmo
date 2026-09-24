#ifndef MATRIZ_H
#define MATRIZ_H
#include <string>

class Matriz {
private:
    int** dados_;
    int linhas_, colunas_;
public:
    Matriz(int linhas, int colunas);
    ~Matriz();
    Matriz(const Matriz&) = delete;
    Matriz& operator=(const Matriz&) = delete;

    int** dados() const;
    int linhas() const;
    int colunas() const;
    void preencherAleatorio(int min, int max);
    void preencherManual(int min, int max);
    void imprimir(const std::string& nome) const;
};
#endif
