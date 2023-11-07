#ifndef GAME_MENU_HPP
#define GAME_MENU_HPP

#include <iostream>
#include <string>
#include "tic_tac_toe.hpp"
#include "hangman.hpp"
#include "boggle.hpp" 

class GameMenu {
    public:
    GameMenu() = default;
    
    enum DropDownMenu {TICTACTOE = 1, HANGMAN, BOGGLE, EXIT};

    void setUserName();

    void printMenu();
    
    private:
    std::string name;
    int command;
};

#endif