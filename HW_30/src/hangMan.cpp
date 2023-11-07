#include "hangman.hpp"

void HangMan::setPlayerNames() {
    std::cout << "Wlecome to C++ Hang Man \n"
                 "Enter name of Player 1: ";
    std::cin >> player1;
    std::cout << "Enter name of Player 2: ";
    std::cin >> player2;
}

bool HangMan::checkWord(const std::string &word, std::string &currentWord, const char &letter) {
    bool flag = false;
    for(size_t i = 0; i < word.size(); ++i) {
        if(word[i] == letter) {
            currentWord[i] = word[i];
            flag = true;
        }
    }

    return flag;
}

void HangMan::printWord(const std::string &word) {
    for(size_t i = 0; i <= word.size(); ++i) {
        std::cout << word[i];
    }
    std::cout << std::endl;
}

void HangMan::printGallow(const int &currentWrong) {
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
        std::cout << "|/       /|\\  " << std::endl;
        std::cout << "|          " << std::endl;
        std::cout << "|" << std::endl;
    } else if(currentWrong == 5) {
        std::cout << " _________ " << std::endl;
        std::cout << "|  /      | " << std::endl;
        std::cout << "| /       O " << std::endl;
        std::cout << "|/       /|\\  " << std::endl;
        std::cout << "|        / " << std::endl;
        std::cout << "|" << std::endl;
    } else {
        std::cout << " _________ " << std::endl;
        std::cout << "|  /      | " << std::endl;
        std::cout << "| /       O " << std::endl;
        std::cout << "|/       /|\\ " << std::endl;
        std::cout << "|        / \\ " << std::endl;
        std::cout << "|" << std::endl;
    }   
}

void HangMan::Run() {
    setPlayerNames();
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

            if(checkWord(word, currentWord, guess) == 0) {
                printWord(currentWord);
                std::cout << "Shoot, worng letter. You're gonna hang soon!" << std::endl;
                ++currentWrong;
            } else if(checkWord(word, currentWord, guess) == 1){
                printWord(currentWord);
                std::cout << "Correct! You found a letter." << std::endl;
            }
        }

        if(currentWrong == maxWrong) {
            printGallow(currentWrong);
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

void HangMan::SaveGame() {
    return;
};

void HangMan::LoadGame() {
    return;
};