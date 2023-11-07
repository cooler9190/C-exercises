#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

enum Choice{
    ROCK = 1,
    PAPER,
    SCISSORS,
};

int randomChoice() {
    int x = (rand() % (3 - 1 + 1) + 1);

    return x;
}

bool checkForWinner(const int &player, const int &ai) {
    if(player == ROCK && ai == SCISSORS) {
        return true;
    } else if(player == PAPER && ai == ROCK) {
        return true;
    } else if(player == SCISSORS && ai == PAPER) {
        return true;
    } else {
        return false;
    }
}


int main() {
    srand(time(0));
    std::string name = "";
    int numberOfRounds = 0, playerChoice = 0, aiChoice = 0, playerWin = 0, aiWin = 0;

    std::cout << "Welcome to C++ Rock, Paper, Scissors!" << std::endl;
    std::cout << "Please enter your name: ";
    std::cin >> name;

    std::cout << "Now enter the number of rounds you wish to play: ";
    std::cin >> numberOfRounds;

    if(numberOfRounds >= 1) {
        while(numberOfRounds != 0) {
            aiChoice = randomChoice();
            std::cout << "The ai has made it's decision, no choose 1, 2 or 3 for Rock, Paper and Scissors: ";
            std::cin >> playerChoice;

            if(playerChoice == aiChoice) {
                std::cout << "It's a draw!" << std::endl;
            } else if(checkForWinner(playerChoice, aiChoice) == 1) {
                std::cout << name << ", you win this round!" << std::endl;
                ++playerWin;
            } else {
                std::cout << "This round goes to the AI!" << std::endl;
                ++aiWin;
            }

            std::cout << playerWin << " : " << aiWin << std::endl;

            --numberOfRounds;
        }

    } else {
        std::cout << "Goodbye!" << std::endl;
        return 0;
    }

    if(playerWin > aiWin) {
        std::cout << "Congratularions " << name << ", you win!" << std::endl;
    } else if(playerWin == aiWin) {
        std::cout << "Draw!" << std::endl;
    } else {
        std::cout << "Well shoot, the ai won!" << std::endl;
    }

    return 0;
}