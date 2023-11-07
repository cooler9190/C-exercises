#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <string>

class HangMan {
    public:
    HangMan() = default;

    void setPlayer1();

    void setPlayer2();

    bool checkWord(const std::string &word, std::string &currentWord, const char &letter);

    void printWord(const std::string &word);

    void printGallow(const int &currentWrong);

    void startGame();
    
    private:
    std::string player1, player2, answer, word;
    char guess;
    const int maxWrong = 6;
};

#endif