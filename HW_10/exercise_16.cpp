#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using vectorVec = std::vector<std::vector<char>>;

enum Difficulty {
    EASY = 1,
    MEDIUM,
    HARD,
};

void aiMoveO(vectorVec &grid, const int &n, const int &diff) {
    if(diff == EASY) {
        for(size_t i = 0; i < n; ++i) {
            for(size_t j = 0; j < n; ++j) {
                if(grid[i][j] == 'X' && grid[i][j + 1] == ' ') {
                    grid[i][j + 1] = 'O';
                } else if(grid[n - 1][n - 1] == 'X' && grid[n -1][n -2] == ' ') {
                    grid[n - 1][n -2] = 'O';
                } 
            }
        }
    } else if(diff == MEDIUM) {
        int i = (rand() % ((n - 1) - 0 + 1) + 0);
        int j = (rand() % ((n - 1) - 0 + 1) + 0);

        if(grid[i][j] == ' ') {
            grid[i][j] = 'O';
        } else {
            aiMoveO(grid, n, diff);
        }
    }
}

bool isBoardFull(vectorVec grid) {
    bool boardFull = true;
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j] == ' ') {
                boardFull = false;
                break;
            }
        }
    }

    return boardFull;
}

bool checkHorizontalWin(vectorVec grid) {
    bool winner = false;
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
        winner = true;
    }

    return winner;
}

bool checkVerticalWin(vectorVec grid) {
    bool winner = false;
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
        winner = true;
    }

    return winner;
}

bool checkLeftDiagonal(vectorVec grid) {
    int n = 0;
    while(n < grid.size() - 1) {
        if(grid[n][n] != grid[n + 1][n + 1] || grid[n][n] == ' ') {
            return false;
        }
        ++n;
    }

    return true;
}

bool checkRightDiagonal(vectorVec grid) {
    int i = grid.size() - 1, j = 0;
    while(j < grid.size() - 1) {
        if(grid[i][j] != grid[i - 1][j + 1] || grid[i][j] == ' ') {
            return false;
        }
        --i, ++j;
    }

    return true;
}

void moveX(vectorVec &grid) {
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

void moveO(vectorVec &grid) {
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

void printBoard(vectorVec grid) {
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            std::cout << grid[i][j] << " | "; 
        }
        std::cout << std::endl;
    }
}


int main() {
    srand(time(0));
    std::string player1 = " ", player2 = " ", gameMode = " ";
    char answer = ' ';
    int n = 0, diffLevel = 0;
    
    std::cout << "Wlecome to C++ Tic Tac Toe!" << std::endl;
    std::cout << "Would you like to play against the computer or multiplayer?: ";
    std::cin >> gameMode;

    if(gameMode == "Multiplayer") {
        std::cout << "Enter name of Player 1: ";
        std::cin >> player1;
        std::cout << "Enter name of Player 2: ";
        std::cin >> player2;
    } else {
        std::cout << "Enter name of Player 1: ";
        std::cin >> player1;
        player2 = "Computer";

        std::cout << "Please enter the difficulty level (1 - Easy, 2 - Medium, 3 - Hard): ";
        std::cin >> diffLevel;

        if(diffLevel == 3) {
            while(diffLevel == 3) {
                std::cout << "Hard level is a work in progress. Please choose level again: ";
                std::cin >> diffLevel;
            } 
        } 
    }

    while(true) {
        std::cout << "Please enter the grid size of the board: ";
        std::cin >> n;

        vectorVec board(n , std::vector<char> (n, ' '));

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

            if(gameMode == "Multiplayer") {
                moveO(board);
            } else {
                aiMoveO(board, n, diffLevel);
            }
            

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

        std::cout << "You really love tic-tac-toe don't you?" << std::endl;
        std::cout << "If that's the case then how about another game?(y / n): ";
        std::cin >> answer;

        if(answer == 'y' || answer == 'Y') {
            std::cout << "That's the spirit, let's start drawing the lines!" << std::endl;
            continue;
        } else {
            std::cout << "Well suit yourself then. I'll be here if you wish to play the marvelous game of tic-tac-toe again." << std::endl;
            std::cout << "Have nice day!" << std::endl;
            break;
        }
    } 

    return 0;
}