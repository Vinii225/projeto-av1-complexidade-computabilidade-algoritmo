#include "Entrada.h"
#include <iostream>
#include <limits>
#include <cstdlib>

int Entrada::lerInt(const std::string& msg, int min, int max) {
    int x;
    while (true) {
        std::cout << msg;
        if (std::cin >> x && x >= min && x <= max) return x;
        if (std::cin.eof()) std::exit(0);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Valor inválido (aceito de " << min << " a " << max << ").\n";
    }
}

bool Entrada::perguntarAleatorio() {
    return lerInt("Preencher como? [1] Manualmente  [2] Aleatoriamente: ", 1, 2) == 2;
}
