#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "game_menu.hpp"

using vectorVec = std::vector<std::vector<char>>;

class TicTacToe : public AbstractGame {
    public:
    void setPlayerNames();

    void setBoard();

    void printBoard(const vectorVec &grid);

    void moveX(vectorVec &grid);

    void moveO(vectorVec &grid);

    bool isBoardFull(const vectorVec &grid);

    bool checkHorizontalWin(const vectorVec &grid);

    bool checkVerticalWin(const vectorVec &grid);

    bool checkLeftDiagonal(const vectorVec &grid);

    bool checkRightDiagonal(const vectorVec &grid);

    bool isSavesFileEmpty(std::ifstream &file);

    void Run();

    void SaveGame();

    void LoadGame();
    
    private:
    vectorVec board;
    size_t size;
    std::string player1, player2, answer;
    const std::string gameSaves = "data/saves.txt";
};

#endif