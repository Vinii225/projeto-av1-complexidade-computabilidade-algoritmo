#ifndef VETOR_H
#define VETOR_H
#include <string>

class Vetor {
private:
    int* dados_;
    int tamanho_;
public:
    explicit Vetor(int tamanho);
    ~Vetor();
    Vetor(const Vetor&) = delete;
    Vetor& operator=(const Vetor&) = delete;

    const int* dados() const;
    int tamanho() const;
    void preencherAleatorio(int min, int max);
    void preencherManual(int min, int max);
    void ordenar();
    bool estaOrdenado() const;
    void imprimir(const std::string& nome) const;
};
#endif
