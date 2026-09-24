#ifndef ENTRADA_H
#define ENTRADA_H
#include <string>

class Entrada {
public:
    static int lerInt(const std::string& msg, int min, int max);
    static bool perguntarAleatorio();
};
#endif
