#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <vector>
#include <string>

using vectorVec = std::vector<std::vector<char>>;

class TicTacToe {
    public:
    TicTacToe() = default;

    void setPlayer1();
    //biba te obicha nali znaesh <3
    void setPlayer2();

    void setBoard();

    void printBoard(const vectorVec &grid);

    void moveX(vectorVec &grid);

    void moveO(vectorVec &grid);

    bool isBoardFull(const vectorVec &grid);

    bool checkHorizontalWin(const vectorVec &grid);

    bool checkVerticalWin(const vectorVec &grid);

    bool checkLeftDiagonal(const vectorVec &grid);

    bool checkRightDiagonal(const vectorVec &grid);

    void startGame();
    
    private:
    vectorVec board;
    int size;
    std::string player1, player2, answer;
};

#endif