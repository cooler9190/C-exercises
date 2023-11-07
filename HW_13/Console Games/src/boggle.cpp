#include "/home/cooler9190/Code Academy/Homework/HW_13/Console Games/header/boggle.hpp"

void Boggle::setPlayer1() {
    std::cout << "Wlecome to C++ Boggle!" << std::endl;
    std::cout << "Enter name of Player 1: ";
    std::cin >> player1;
}

void Boggle::setPlayer2() {
    std::cout << "Enter name of Player 2: ";
    std::cin >> player2;
}

void Boggle::timer() {
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

bool Boggle::validateWord(const std::string &word, const std::vector<std::string> &dict, const std::vector<std::string> &usedWord) {
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

void Boggle::setPoints(int &points, const std::string &word) {
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

void Boggle::startGame() {
    setPlayer1();
    setPlayer2();
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
            std::cin >> wordPlayer1;

            for(size_t i = 0; i < wordPlayer1.size(); ++i) {
                if(islower(wordPlayer1[i])) {
                    wordPlayer1[i] = toupper(wordPlayer1[i]);
                }
            }

            std::cout << player2 << " write your word: ";
            std::cin >> wordPlayer2;

            for(size_t i = 0; i < wordPlayer2.size(); ++i) {
                if(islower(wordPlayer2[i])) {
                    wordPlayer2[i] = toupper(wordPlayer2[i]);
                }
            }

            if(wordPlayer1 == wordPlayer2) {
                std::cout << "The words are the same, so nobody gets points" << std::endl;
                usedWords.push_back(wordPlayer1);
                continue;
            }

            if(validateWord(wordPlayer1, deictionary, usedWords) == 1) {
                setPoints(pointsPlayer1, wordPlayer1);
            } else {
                std::cout << player1 << "'s word is invalid" << std::endl;
            }

            if(validateWord(wordPlayer2, deictionary, usedWords) == 1) {
                setPoints(pointsPlayer2, wordPlayer2);
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