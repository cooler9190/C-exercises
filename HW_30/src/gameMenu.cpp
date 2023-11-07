#include "game_menu.hpp"
#include "boggle.hpp"
#include "hangman.hpp"
#include "tic_tac_toe.hpp"

void GameMenu::setUserName() {
    std::cout << "Hello and welcome to the C++ game library!" << std::endl;
    std::cout << "What is your name: ";
    std::cin >> name;
}

void GameMenu::printMenu() {
    std::cout << "Welcome " << name << ". It is very nice to meet you. \n"
        "----------------------------------------------------- \n"
        "Wlcome to the Main Menu of the library \n"
        "From here you can choose one of three games: Tic-Tac-Toe, Hangman and Boggle! \n"
        "If you're thinking: 'This isn't much of a game library!' than maybe you should consider making one yoursef wise guy! \n";
    
    std::cout << std::endl;

    while(command != EXIT) {
        std::cout << "------------ Main Menu ------------ \n"
                    "          _______________          \n" 
                    "         |  Tic-Tac-Toe  |         \n" 
                    "          _______________          \n" 
                    "         |    Hangman    |         \n"
                    "          _______________          \n"
                    "         |    Boggle     |         \n"
                    "          _______________          \n"
                    "         |     Exit      |         \n"
                    "\n"
                    "-----------------------------------\n"

                    "Please choose a drop down menu number: ";
        std::cin >> command;

        if(command == TICTACTOE) {
            TicTacToe ticTacToe;
            ticTacToe.Run();
        } else if(command == HANGMAN) {
            HangMan hangMan;
            hangMan.Run();
        } else if(command == BOGGLE) {
            Boggle boggle;
            boggle.Run();
        } else if(command == EXIT) {
            std::cout << "Goodbye " << name << "! Let's play again soon!" << std::endl;
            break;
        } else if(std::cin.eof()) {
            break;
        } else {
            std::cerr << "Invalid input!" << std::endl;
            break;
        }
    }
}

