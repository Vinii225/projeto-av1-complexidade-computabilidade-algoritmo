#include "Matriz.h"
#include "Entrada.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Matriz::Matriz(int linhas, int colunas) : linhas_(linhas), colunas_(colunas) {
    dados_ = new int*[linhas_];
    for (int i = 0; i < linhas_; ++i) dados_[i] = new int[colunas_];
}

Matriz::~Matriz() {
    for (int i = 0; i < linhas_; ++i) delete[] dados_[i];
    delete[] dados_;
}

int** Matriz::dados() const { return dados_; }
int Matriz::linhas() const { return linhas_; }
int Matriz::colunas() const { return colunas_; }

void Matriz::preencherAleatorio(int min, int max) {
    for (int i = 0; i < linhas_; ++i)
        for (int j = 0; j < colunas_; ++j)
            dados_[i][j] = min + rand() % (max - min + 1);
}

void Matriz::preencherManual(int min, int max) {
    for (int i = 0; i < linhas_; ++i)
        for (int j = 0; j < colunas_; ++j)
            dados_[i][j] = Entrada::lerInt(
                "  [" + std::to_string(i) + "][" + std::to_string(j) + "]: ", min, max);
}

void Matriz::imprimir(const std::string& nome) const {
    std::cout << nome << " (" << linhas_ << "x" << colunas_ << "):\n";
    for (int i = 0; i < linhas_; ++i) {
        for (int j = 0; j < colunas_; ++j) std::cout << std::setw(6) << dados_[i][j];
        std::cout << "\n";
    }
}
