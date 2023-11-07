#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unistd.h>

using vectorVec = std::vector<std::vector<char>>;

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

bool validateWord(const std::string &word, const std::vector<std::string> &usedWord) {
    if(word.size() < 3) {
        return false;
    }

    for(size_t i = 0; i < usedWord.size(); ++i) {
        if(word == usedWord[i]) {
            return false;
        } 
    }

    std::ifstream dictionary("dict.txt");

    if(dictionary.is_open()) {
        std::string line = "";
        while(getline(dictionary, line)) {
            line.pop_back();
            if(word == line) {
                return true;
            }
        }
    } else {
        std::cout << "Unable to open file!" << std::endl;
    }

    dictionary.close();
    
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
    std::vector<std::string> usedWords = {};
    const vectorVec board = {{'E', 'B', 'I', 'S'},
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

        if(validateWord(word1, usedWords) == 1) {
            setPoints(pointsPlayer1, word1);
        } else {
            std::cout << player1 << "'s word is invalid" << std::endl;
        }

        if(validateWord(word2, usedWords) == 1) {
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
    Boggle();   

    return 0;
}