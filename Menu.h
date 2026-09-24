#ifndef MENU_H
#define MENU_H

class Matriz;

class Menu {
private:
    static constexpr int MIN_MANUAL = -1000;
    static constexpr int MAX_MANUAL = 1000;

    Matriz* criarMatrizPerguntando(bool exigirQuadrada);
    void funcao1();
    void funcao2();
    void funcao3();
    void funcao4();
    void funcao5();

public:
    void executar();
};

#endif
