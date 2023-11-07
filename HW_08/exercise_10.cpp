#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


int randomNumber() {
    int x = (rand() % (100 - 1 + 1) + 1);

    return x;
}

void hotOrCold(const int &x, const int &guess) {
    int diferrence = abs(x - guess);
    if(x > guess) {
        if(diferrence <= 5) {
            std::cout << "You're hot ;)" << std::endl;
            std::cout << "Go higher" << std::endl;
        } else if(diferrence > 5 && diferrence <= 10) {
            std::cout << "You're warm" << std::endl;
            std::cout << "Go higher" << std::endl;
        } else if(diferrence > 10 && diferrence <= 15) {
            std::cout << "You're cool" << std::endl;
            std::cout << "Go higher" << std::endl;
        } else if(diferrence > 15 && diferrence <= 20) {
            std::cout << "You're cold" << std::endl;
            std::cout << "Go higher" << std::endl;
        } else {
            std::cout << "You're freezing" << std::endl;
            std::cout << "Go higher" << std::endl;
        }
    } else if(x < guess) {
        if(diferrence <= 5) {
            std::cout << "You're hot ;)" << std::endl;
            std::cout << "Go lower" << std::endl;
        } else if(diferrence > 5 && diferrence <= 10) {
            std::cout << "You're warm" << std::endl;
            std::cout << "Go lower" << std::endl;
        } else if(diferrence > 10 && diferrence <= 15) {
            std::cout << "You're cool" << std::endl;
            std::cout << "Go lower" << std::endl;
        } else if(diferrence > 15 && diferrence <= 20) {
            std::cout << "You're cold" << std::endl;
            std::cout << "Go lower" << std::endl;
        } else {
            std::cout << "You're freezing" << std::endl;
            std::cout << "Go lower" << std::endl;
        }
    } else {
        std::cout << "You guessed it! Good job!" << std::endl;
    }
}


int main() {
    int guess = 0, x = randomNumber();
    srand(time(0));

    while(guess != x) {
        std::cout << "Please enter a number between 1 and 100 to guess x: ";
        std::cin >> guess;

        hotOrCold(x, guess);
    }

    return 0;
}