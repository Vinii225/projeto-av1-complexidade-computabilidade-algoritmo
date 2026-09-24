#include "Vetor.h"
#include "Entrada.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

Vetor::Vetor(int tamanho) : dados_(new int[tamanho]), tamanho_(tamanho) {}
Vetor::~Vetor() { delete[] dados_; }

const int* Vetor::dados() const { return dados_; }
int Vetor::tamanho() const { return tamanho_; }

void Vetor::preencherAleatorio(int min, int max) {
    for (int i = 0; i < tamanho_; ++i)
        dados_[i] = min + rand() % (max - min + 1);
}

void Vetor::preencherManual(int min, int max) {
    for (int i = 0; i < tamanho_; ++i)
        dados_[i] = Entrada::lerInt("  [" + std::to_string(i) + "]: ", min, max);
}

void Vetor::ordenar() { std::sort(dados_, dados_ + tamanho_); }
bool Vetor::estaOrdenado() const { return std::is_sorted(dados_, dados_ + tamanho_); }

void Vetor::imprimir(const std::string& nome) const {
    std::cout << nome << " = [ ";
    for (int i = 0; i < tamanho_; ++i) std::cout << dados_[i] << " ";
    std::cout << "]\n";
}
