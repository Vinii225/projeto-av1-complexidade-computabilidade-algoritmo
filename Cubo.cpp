#include "Cubo.h"
#include "Entrada.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Cubo::Cubo(int n) : n_(n) {
    dados_ = new int**[n_];
    for (int i = 0; i < n_; ++i) {
        dados_[i] = new int*[n_];
        for (int j = 0; j < n_; ++j) dados_[i][j] = new int[n_];
    }
}

Cubo::~Cubo() {
    for (int i = 0; i < n_; ++i) {
        for (int j = 0; j < n_; ++j) delete[] dados_[i][j];
        delete[] dados_[i];
    }
    delete[] dados_;
}

int*** Cubo::dados() const { return dados_; }
int Cubo::n() const { return n_; }

void Cubo::preencherAleatorio(int min, int max) {
    for (int i = 0; i < n_; ++i)
        for (int j = 0; j < n_; ++j)
            for (int k = 0; k < n_; ++k)
                dados_[i][j][k] = min + rand() % (max - min + 1);
}

void Cubo::preencherManual(int min, int max) {
    for (int i = 0; i < n_; ++i)
        for (int j = 0; j < n_; ++j)
            for (int k = 0; k < n_; ++k)
                dados_[i][j][k] = Entrada::lerInt(
                    "  [" + std::to_string(i) + "][" + std::to_string(j) + "][" +
                    std::to_string(k) + "]: ", min, max);
}

void Cubo::imprimir(const std::string& nome) const {
    std::cout << nome << " (" << n_ << "x" << n_ << "x" << n_ << "):\n";
    for (int i = 0; i < n_; ++i) {
        std::cout << " camada " << i << ":\n";
        for (int j = 0; j < n_; ++j) {
            for (int k = 0; k < n_; ++k) std::cout << std::setw(6) << dados_[i][j][k];
            std::cout << "\n";
        }
    }
}
