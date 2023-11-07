#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <unistd.h>

using vectorVec = std::vector<std::vector<char>>;

enum DropDownMenu {
    TICTACTOE = 1,
    HANGMAN,
    BOGGLE,
    EXIT,
};

bool isBoardFull(const vectorVec &grid) {
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

bool checkHorizontalWin(const vectorVec &grid) {
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

bool checkVerticalWin(const vectorVec &grid) {
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

bool checkLeftDiagonal(const vectorVec &grid) {
    int n = 0;
    while(n < grid.size() - 1) {
        if(grid[n][n] != grid[n + 1][n + 1] || grid[n][n] == ' ') {
            return false;
        }
        ++n;
    }

    return true;
}

bool checkRightDiagonal(const vectorVec &grid) {
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

void TicTacToe() {
    std::string player1 = " ", player2 = " ";
    std::string answer = " ";
    int n = 0;
    
    std::cout << "Wlecome to C++ Tic Tac Toe!" << std::endl;
    std::cout << "Enter name of Player 1: ";
    std::cin >> player1;
    std::cout << "Enter name of Player 2: ";
    std::cin >> player2;

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

bool checkWord(const std::string &word, std::string &currentWord, const char &letter) {
    bool flag = false;
    for(size_t i = 0; i < word.size(); ++i) {
        if(word[i] == letter) {
            currentWord[i] = word[i];
            flag = true;
        }
    }

    return flag;
}

void printWord(const std::string &word) {
    for(size_t i = 0; i <= word.size(); ++i) {
        std::cout << word[i];
    }
    std::cout << std::endl;
}

void printGallow(const int &currentWrong) {
    if(currentWrong == 0) {
        std::cout << " _________ " << std::endl;
        std::cout << "|  /      | " << std::endl;
        std::cout << "| /        " << std::endl;
        std::cout << "|/         " << std::endl;
        std::cout << "|          " << std::endl;
        std::cout << "|" << std::endl;
    } else if(currentWrong == 1) {
        std::cout << " _________ " << std::endl;
        std::cout << "|  /      | " << std::endl;
        std::cout << "| /       O " << std::endl;
        std::cout << "|/         " << std::endl;
        std::cout << "|          " << std::endl;
        std::cout << "|" << std::endl;
    } else if(currentWrong == 2) {
        std::cout << " _________ " << std::endl;
        std::cout << "|  /      | " << std::endl;
        std::cout << "| /       O " << std::endl;
        std::cout << "|/        | " << std::endl;
        std::cout << "|          " << std::endl;
        std::cout << "|" << std::endl;
    } else if(currentWrong == 3) {
        std::cout << " _________ " << std::endl;
        std::cout << "|  /      | " << std::endl;
        std::cout << "| /       O " << std::endl;
        std::cout << "|/       /|  " << std::endl;
        std::cout << "|          " << std::endl;
        std::cout << "|" << std::endl;
    } else if(currentWrong == 4) {
        std::cout << " _________ " << std::endl;
        std::cout << "|  /      | " << std::endl;
        std::cout << "| /       O " << std::endl;
        std::cout << "|/       /|/  " << std::endl;
        std::cout << "|          " << std::endl;
        std::cout << "|" << std::endl;
    } else if(currentWrong == 5) {
        std::cout << " _________ " << std::endl;
        std::cout << "|  /      | " << std::endl;
        std::cout << "| /       O " << std::endl;
        std::cout << "|/       /|/  " << std::endl;
        std::cout << "|        / " << std::endl;
        std::cout << "|" << std::endl;
    } else {
        std::cout << " _________ " << std::endl;
        std::cout << "|  /      | " << std::endl;
        std::cout << "| /       O " << std::endl;
        std::cout << "|/       /|\\ " << std::endl;
        std::cout << "|        / / " << std::endl;
        std::cout << "|" << std::endl;
    }
    
}

void HangMan() {
    std::string player1 = " ", player2 = " ", word = " ", answer = " ";
    char guess = ' ';
    const int maxWrong = 6;

    std::cout << "Wlecome to C++ Hangman!" << std::endl;
    std::cout << "Enter name of Player 1: ";
    std::cin >> player1;
    std::cout << "Enter name of Player 2: ";
    std::cin >> player2;

    std::cout << std:: endl;

    while(true) {
        std::cout << player1 << ", please enter the word for " << player2 << " to guess: ";
        std::cin >> word;

        for(size_t i = 0; i < word.size(); ++i) {
            if(islower(word[i])) {
                word[i] = toupper(word[i]);
            }
        }

        std::string currentWord(word.size(), '_');
        int currentWrong = 0;

        while((currentWrong < maxWrong) && (currentWord != word))  {
            printGallow(currentWrong);
            std::cout << player2 << ", choose a letter: ";
            std::cin >> guess;

            if(islower(guess)) {
                guess = toupper(guess);
            }

            printWord(currentWord);

            if(checkWord(word, currentWord, guess) == 0) {
                std::cout << "Shoot, worng letter. You're gonna hang soon!" << std::endl;
                ++currentWrong;
            } else if(checkWord(word, currentWord, guess) == 1){
                std::cout << "Correct! You found a letter." << std::endl;
            }
        }

        if(currentWrong == maxWrong) {
            std::cout << "Sorry " << player2 << " you got hangged!" << std::endl;
        } else if(currentWord == word) {
            std:: cout << "Congratulations " << player2 << "! You guessed the word and didn't hang!" << std::endl;
        }

        std::cout << "Want to try your luck again? (y / n): ";
        std::cin >> answer;

        if(answer == "y" || answer == "Y") {
            std::cout << "Great, let's go again!" << std::endl;
            continue;
        } else {
            std::cout << "Oh well. If you change your mind I'll be here." << std::endl;
            std::cout << "Goodbye!" << std::endl;
            break;
        }
    }
}

void timer() {
    int seconds = 180;
    while(seconds != 0) {
        sleep(1);
        if(seconds == 120) {
            std::cout << "You have 2 minutes left" << std:: endl;
        } else if(seconds == 60) {
            std::cout << "You have 1 minute left" << std:: endl;
        } else if(seconds == 30) {
            std::cout << "You have 30 seconds left" << std:: endl;
        } else if(seconds == 10) {
            std::cout << "You have 10 seconds left" << std:: endl;
        } else if(seconds == 5) {
            std::cout << "You have 5 seconds left" << std:: endl;
        }
        --seconds;
    }
}

bool validateWord(const std::string &word, const std::vector<std::string> &dict, const std::vector<std::string> &usedWord) {
    if(word.size() < 3) {
        return false;
    }

    for(size_t i = 0; i < usedWord.size(); ++i) {
        if(word == usedWord[i]) {
            return false;
        } 
    }

    for(size_t i = 0; i < dict.size(); ++i) {
        if(word == dict[i]) {
            return true;
        }
    }

    return false;
}

void setPoints(int &points, const std::string &word) {
    if(word.size() == 3 || word.size() == 4) {
        points += 1;
    } else if(word.size() == 5) {
        points += 2;
    } else if(word.size() == 6) {
        points += 3;
    } else if(word.size() == 7) {
        points += 5;
    } else if(word.size() >= 8) {
        points += 11;
    }
}

void Boggle() {
    std::string word1 = "", word2 = "", answer = "";
    int pointsPlayer1 = 0, pointsPlayer2 = 0;
    std::vector<std::string> deictionary = {"ELK", "WHITE", "BLACK", "WAR", "BIRD", "RED", "DRAW", "LAW", "TRACK"};
    std::vector<std::string> usedWords = {};
    vectorVec board = {{'E', 'B', 'I', 'S'},
                       {'L', 'D', 'R', 'E'},
                       {'K', 'A', 'D', 'T'},
                       {'C', 'W', 'H', 'I'}};

    std::string player1 = " ", player2 = " ", word = " ";

    std::cout << "Wlecome to C++ Boggle!" << std::endl;
    std::cout << "Enter name of Player 1: ";
    std::cin >> player1;
    std::cout << "Enter name of Player 2: ";
    std::cin >> player2;

    while(true) {
        std::cout << "You have 3 minutes to find words" << std:: endl;

    for(size_t i = 0; i < board.size(); ++i) {
        for(size_t j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << std::endl;
    }
    
    timer();

    std::cout << "Time's up!" << std::endl;
    
    while(true) {
        std::cout << player1 << " write your word: ";
        std::cin >> word1;

        for(size_t i = 0; i < word1.size(); ++i) {
            if(islower(word1[i])) {
                word1[i] = toupper(word1[i]);
            }
        }

        std::cout << player2 << " write your word: ";
        std::cin >> word2;

        for(size_t i = 0; i < word2.size(); ++i) {
            if(islower(word2[i])) {
                word2[i] = toupper(word2[i]);
            }
        }

        if(word1 == word2) {
            std::cout << "The words are the same, so nobody gets points" << std::endl;
            usedWords.push_back(word1);
            continue;
        }

        if(validateWord(word1, deictionary, usedWords) == 1) {
            setPoints(pointsPlayer1, word1);
        } else {
            std::cout << player1 << "'s word is invalid" << std::endl;
        }

        if(validateWord(word2, deictionary, usedWords) == 1) {
            setPoints(pointsPlayer2, word2);
        } else {
            std::cout << player2 << "'s word is invalid" << std::endl;
        }

        std::cout << "Are these all the words? (y / n): ";
        std::cin >> answer;

        if(answer == "n" || answer == "N") {
            continue;
        } else {
            break;
        }
    }

        if(pointsPlayer1 > pointsPlayer2) {
            std::cout << player1 << " wins! Congratulations!" << std::endl;
        } else if(pointsPlayer1 < pointsPlayer2) {
            std::cout << player2 << " wins! Congratulations!" << std::endl;
        } else {
            std::cout << "It's a draw!" << std::endl;
        }

        std::cout << "What a game! Do you want to play again? (y / n): ";
        std::cin >> answer;

        if(answer == "y" || answer == "Y") {
            std::cout << "Great, let's go again!" << std::endl;
            continue;
        } else {
            std::cout << "Oh well. If you change your mind I'll be here." << std::endl;
            std::cout << "Goodbye!" << std::endl;
            break;
        }
    }  
}

int main() {
    std::string name = "";
    int command = 0;
    std::cout << "Hello and welcome to the C++ game library!" <<std::endl;
    std::cout << "What is your name: ";
    std::cin >> name;

    std::cout << "Welcome " << name << ". It is very nice to meet you." << std::endl;

    std::cout << "-----------------------------------------------------" << std::endl;

    std::cout << "Wlcome to the Main Menu of the library " << name << std::endl;
    std::cout << "From here you can choose one of three games: Tic-Tac-Toe, Hangman and Boggle!" << std::endl;
    std::cout << "If you're thinking: 'This isn't much of a game library!' than maybe you should consider making one yoursef wise guy!" <<std::endl;
    
    std::cout << std::endl;

    while(command != EXIT) {
        std::cout << "------------ Main Menu ------------" << std::endl;
        std::cout << "          _______________          " << std::endl;
        std::cout << "         |  Tic-Tac-Toe  |         " << std::endl;
        std::cout << "          _______________          " << std::endl;
        std::cout << "         |    Hangman    |         " << std::endl;
        std::cout << "          _______________          " << std::endl;
        std::cout << "         |    Boggle     |         " << std::endl;
        std::cout << "          _______________          " << std::endl;
        std::cout << "         |     Exit      |         " << std::endl;
        std::cout << std::endl;
        std::cout << "-----------------------------------" << std::endl;

        std::cout << "Please choose a drop down menu number: ";
        std::cin >> command;

        if(command == TICTACTOE) {
            TicTacToe();
        } else if(command == HANGMAN) {
            HangMan();
        } else if(command == BOGGLE) {
            Boggle();
        } else if(command == EXIT) {
            std::cout << "Goodbye " << name << "! Let's play again soon!" << std::endl;
            return 0;
        } else {
            std::cerr << "Invalid input!" << std::endl;
            return 0;
        }
    }

    return 0;
}