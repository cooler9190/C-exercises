#ifndef BOGGLE_HPP
#define BOGGLE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "game_menu.hpp"

using vectorVec = std::vector<std::vector<char>>;

class Boggle : public AbstractGame {
    public:
    void setPlayerNames();

    void timer();

    bool validateWord(const std::string &word, const std::vector<std::string> &dict, const std::vector<std::string> &usedWord);

    void setPoints(int &points, const std::string &word);

    void Run();

    void SaveGame();

    void LoadGame();

    private:
    std::string player1, player2, word, wordPlayer1, wordPlayer2, answer;
    int pointsPlayer1, pointsPlayer2;
    const std::vector<std::string> deictionary = {"ELK", "WHITE", "BLACK", "WAR", "BIRD", "RED", "DRAW", "LAW", "TRACK"};
    std::vector<std::string> usedWords = {};
    const vectorVec board = {{'E', 'B', 'I', 'S'},
                       {'L', 'D', 'R', 'E'},
                       {'K', 'A', 'D', 'T'},
                       {'C', 'W', 'H', 'I'}};
};

#endif