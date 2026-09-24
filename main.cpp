#include "Menu.h"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    Menu menu;
    menu.executar();
    return 0;
}
