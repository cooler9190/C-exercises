#ifndef GAME_MENU_HPP
#define GAME_MENU_HPP

#include <iostream>
#include <string>

class AbstractGame {
    public:
    virtual void Run() = 0;
    virtual void setPlayerNames() = 0;
    virtual void SaveGame() = 0;
    virtual void LoadGame() = 0;
    virtual ~AbstractGame() = default;
};

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