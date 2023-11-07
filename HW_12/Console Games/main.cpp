#include <iostream>
#include "Headers/game_menu.hpp"

int main() {
    GameMenu menu;

    menu.setUserName();
    menu.printMenu();

    return 0;
}