#ifndef CUBO_H
#define CUBO_H
#include <string>

class Cubo {
private:
    int*** dados_;
    int n_;
public:
    explicit Cubo(int n);
    ~Cubo();
    Cubo(const Cubo&) = delete;
    Cubo& operator=(const Cubo&) = delete;

    int*** dados() const;
    int n() const;
    void preencherAleatorio(int min, int max);
    void preencherManual(int min, int max);
    void imprimir(const std::string& nome) const;
};
#endif
