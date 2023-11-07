#include "/home/cooler9190/Code Academy/Homework/HW_12/Console Games/Headers/game_menu.hpp"

void GameMenu::setUserName() {
    std::cout << "Hello and welcome to the C++ game library!" << std::endl;
    std::cout << "What is your name: ";
    std::cin >> name;
}

void GameMenu::printMenu() {
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
            TicTacToe ticTacToe;
            ticTacToe.startGame();
        } else if(command == HANGMAN) {
            HangMan hangMan;
            hangMan.startGame();
        } else if(command == BOGGLE) {
            Boggle boggle;
            boggle.startGame();
        } else if(command == EXIT) {
            std::cout << "Goodbye " << name << "! Let's play again soon!" << std::endl;
            break;
        } else {
            std::cerr << "Invalid input!" << std::endl;
            break;
        }
    }
}

