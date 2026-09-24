#include "Menu.h"
#include "Entrada.h"
#include "Vetor.h"
#include "Matriz.h"
#include "Cubo.h"
#include "Algoritmos.h"
#include <iostream>
#include <memory>

Matriz* Menu::criarMatrizPerguntando(bool exigirQuadrada) {
    while (true) {
        int l = Entrada::lerInt("Quantas linhas? ", 1, 2000);
        int c = Entrada::lerInt("Quantas colunas? ", 1, 2000);
        if (!exigirQuadrada || l == c) return new Matriz(l, c);
        std::cout << "  Esta função exige matriz quadrada (linhas = colunas).\n";
    }
}

void Menu::funcao1() {
    int n = Entrada::lerInt("Tamanho n do vetor principal: ", 1, 200000);
    int k = Entrada::lerInt("Tamanho k do vetor de buscados: ", 1, 200000);
    Vetor V(n), B(k);
    if (Entrada::perguntarAleatorio()) {
        V.preencherAleatorio(0, 20);
        B.preencherAleatorio(0, 20);
    } else {
        std::cout << "Vetor principal:\n"; V.preencherManual(MIN_MANUAL, MAX_MANUAL);
        std::cout << "Vetor de buscados:\n"; B.preencherManual(MIN_MANUAL, MAX_MANUAL);
    }
    V.imprimir("V");
    B.imprimir("Buscados");
    std::cout << "Resultado: " << Algoritmos::contarOcorrencias(V.dados(), n, B.dados(), k) << "\n";
}

void Menu::funcao2() {
    std::unique_ptr<Matriz> A(criarMatrizPerguntando(true));
    if (Entrada::perguntarAleatorio()) A->preencherAleatorio(0, 99);
    else A->preencherManual(MIN_MANUAL, MAX_MANUAL);
    A->imprimir("A");
    std::cout << "Resultado: " << Algoritmos::analisarPares(A->dados(), A->linhas()) << "\n";
}

void Menu::funcao3() {
    int n = Entrada::lerInt("Dimensão n (cubos n x n x n): ", 1, 300);
    Cubo A(n), B(n);
    if (Entrada::perguntarAleatorio()) {
        A.preencherAleatorio(0, 99);
        B.preencherAleatorio(0, 99);
    } else {
        std::cout << "Cubo A:\n"; A.preencherManual(MIN_MANUAL, MAX_MANUAL);
        std::cout << "Cubo B:\n"; B.preencherManual(MIN_MANUAL, MAX_MANUAL);
    }
    A.imprimir("A");
    B.imprimir("B");
    std::cout << "Resultado: " << Algoritmos::compararCubos(A.dados(), B.dados(), n)
              << "  (1 = soma(A) >= soma(B), 0 = caso contrário)\n";
}

void Menu::funcao4() {
    int n = Entrada::lerInt("Tamanho n do vetor: ", 1, 200000);
    Vetor V(n);
    if (Entrada::perguntarAleatorio()) V.preencherAleatorio(0, 20);
    else V.preencherManual(0, 20);
    V.imprimir("V");
    std::cout << "Resultado: " << Algoritmos::processarVetor(V.dados(), n) << "\n";
}

void Menu::funcao5() {
    int n = Entrada::lerInt("Tamanho n dos vetores A e B: ", 1, 200000);
    Vetor A(n), B(n);
    if (Entrada::perguntarAleatorio()) {
        A.preencherAleatorio(0, 2 * n);
        B.preencherAleatorio(0, 2 * n);
    } else {
        std::cout << "Vetor A (qualquer ordem):\n"; A.preencherManual(MIN_MANUAL, MAX_MANUAL);
        std::cout << "Vetor B:\n"; B.preencherManual(MIN_MANUAL, MAX_MANUAL);
    }
    if (!B.estaOrdenado()) {
        B.ordenar();
        std::cout << "(B foi ordenado, pois a busca binária exige vetor ordenado)\n";
    }
    A.imprimir("A");
    B.imprimir("B");
    std::cout << "Resultado: " << Algoritmos::contarPresentes(A.dados(), B.dados(), n) << "\n";
}

void Menu::executar() {
    int op;
    do {
        std::cout << "\n=========== MENU ===========\n"
                  << "[1] Contagem de ocorrências distintas\n"
                  << "[2] Pares em matriz triangular\n"
                  << "[3] Comparação de matrizes 3D\n"
                  << "[4] Casos assimétricos (par/ímpar + fatorial)\n"
                  << "[5] Elementos presentes em vetor ordenado\n"
                  << "[0] Sair\n";
        op = Entrada::lerInt("Opção: ", 0, 5);
        switch (op) {
            case 1: funcao1(); break;
            case 2: funcao2(); break;
            case 3: funcao3(); break;
            case 4: funcao4(); break;
            case 5: funcao5(); break;
        }
    } while (op != 0);
}
