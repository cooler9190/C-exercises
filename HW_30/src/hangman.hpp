#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <string>
#include "game_menu.hpp"

class HangMan : public AbstractGame {
    public:
    void setPlayerNames();

    bool checkWord(const std::string &word, std::string &currentWord, const char &letter);

    void printWord(const std::string &word);

    void printGallow(const int &currentWrong);

    void Run();

    void SaveGame();

    void LoadGame();
    
    private:
    std::string player1, player2, answer, word;
    char guess;
    const int maxWrong = 6;
};

#endif