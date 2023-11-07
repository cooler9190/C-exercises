#include "/home/cooler9190/Code Academy/Homework/HW_12/Console Games/Headers/tic_tac_toe.hpp"

void TicTacToe::setPlayer1() {
    std::cout << "Wlecome to C++ Tic Tac Toe!" << std::endl;
    std::cout << "Enter name of Player 1: ";
    std::cin >> player1;
}

void TicTacToe::setPlayer2() {
    std::cout << "Enter name of Player 2: ";
    std::cin >> player2;
}

void TicTacToe::setBoard() {
    std::cout << "Please enter the grid size of the board: ";
    std::cin >> size;
    for(size_t i = 0; i < size; ++i) {
        std::vector<char> row;
        board.push_back(row);
        for(size_t j = 0; j < size; ++j) {
            board[i].push_back(' ');
        }
    }
}

void TicTacToe::printBoard(const vectorVec &grid) {
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            std::cout << grid[i][j] << " | "; 
        }
        std::cout << std::endl;
    }
}

void TicTacToe::moveX(vectorVec &grid) {
    int i = 0, j = 0;
    std::cout << "Choose the number of row and column to mark it: ";
    std::cin >> i >> j;
    if(grid[i][j] == ' ') {
        grid[i][j] = 'X';
    } else {
        std::cout << "Position already market!" << std::endl;
        moveX(grid);
    }
    
} 

void TicTacToe::moveO(vectorVec &grid) {
    int i = 0, j = 0;
    std::cout << "Choose the number of row and column to mark it: ";
    std::cin >> i >> j;
    if(grid[i][j] == ' ') {
        grid[i][j] = 'O';
    } else {
        std::cout << "Position already market!" << std::endl;
        moveO(grid);
    }
}

bool TicTacToe::isBoardFull(const vectorVec &grid) {
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j] == ' ') {
                return false;
                break;
            }
        }
    }

    return true;
}

bool TicTacToe::checkHorizontalWin(const vectorVec &grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size() - 1; ++j) {
            if(grid[i][j] != grid[i][j + 1] || grid[i][j] == ' ') {
                ++count;
                break;
            } 
        }
    }

    if(count != grid.size()) {
        return true;
    }

    return false;
}

bool TicTacToe::checkVerticalWin(const vectorVec &grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size() - 1; ++j) {
            if(grid[j][i] != grid[j + 1][i] || grid[j][i] == ' ') {
                ++count;
                break;
            } 
        }
    }

    if(count != grid.size()) {
        return true;
    }

    return false;
}

bool TicTacToe::checkLeftDiagonal(const vectorVec &grid) {
    int n = 0;
    while(n < grid.size() - 1) {
        if(grid[n][n] != grid[n + 1][n + 1] || grid[n][n] == ' ') {
            return false;
        }
        ++n;
    }

    return true;
}

bool TicTacToe::checkRightDiagonal(const vectorVec &grid) {
    int i = grid.size() - 1, j = 0;
    while(j < grid.size() - 1) {
        if(grid[i][j] != grid[i - 1][j + 1] || grid[i][j] == ' ') {
            return false;
        }
        --i, ++j;
    }

    return true;
}

void TicTacToe::startGame() {
    setPlayer1();
    setPlayer2();
    while(true) {
        setBoard();
        while(true) {
            std::cout << "It's " << player1 << "'s turn: " << std::endl;
            printBoard(board);
            
            moveX(board);

            if(isBoardFull(board) == 1) {
                std::cout << "It's a draw! What a dull game that was." << std:: endl;
                break;
            } else if(checkHorizontalWin(board) == 1) {
                std::cout << "The winner is: " << player1 << ". You are a tic-tac-toe master tactician!" << std::endl;
                printBoard(board);
                break;
            } else if(checkVerticalWin(board) == 1) {
                std::cout << "The winner is: " << player1 << ". You are a tic-tac-toe master tactician!" << std::endl;
                printBoard(board);
                break;
            } else if(checkLeftDiagonal(board) == 1) {
                std::cout << "The winner is: " << player1 << ". You are a tic-tac-toe master tactician!" << std::endl;
                printBoard(board);
                break;
            } else if(checkRightDiagonal(board) == 1) {
                std::cout << "The winner is: " << player1 << ". You are a tic-tac-toe master tactician!" << std::endl;
                printBoard(board);
                break;
            }

            std::cout << "It's " << player2 << "'s turn: " << std::endl;
            printBoard(board);

            moveO(board);

            if(isBoardFull(board) == 1) {
                std::cout << "It's a draw! Well that was an uneventful game." << std:: endl;
                break;
            } else if(checkHorizontalWin(board) == 1) {
                std::cout << "The winner is: " << player2 << ". You are a tic-tac-toe master tactician!" << std::endl;
                printBoard(board);
                break;
            } else if(checkVerticalWin(board) == 1) {
                std::cout << "The winner is: " << player2 << ". You are a tic-tac-toe master tactician!" << std::endl;
                printBoard(board);
                break;
            } else if(checkLeftDiagonal(board) == 1) {
                std::cout << "The winner is: " << player2 << ". You are a tic-tac-toe master tactician!" << std::endl;
                printBoard(board);
                break;
            } else if(checkRightDiagonal(board) == 1) {
                std::cout << "The winner is: " << player2 << ". You are a tic-tac-toe master tactician!" << std::endl;
                printBoard(board);
                break;
            }
        }

        std::cout << std::endl;

        std::cout << "You really love tic-tac-toe don't you?" << std::endl;
        std::cout << "If that's the case then how about another game?(y / n): ";
        std::cin >> answer;

        if(answer == "y" || answer == "Y") {
            std::cout << "That's the spirit, let's start drawing the lines!" << std::endl;
            continue;
        } else {
            std::cout << "Well suit yourself then. I'll be here if you wish to play the marvelous game of tic-tac-toe again." << std::endl;
            std::cout << "Have nice day!" << std::endl;
            std::cout << std::endl;
            break;
        }
    }
}