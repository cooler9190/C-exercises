#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using highResClock = std::chrono::high_resolution_clock;
using seconds = std::chrono::seconds;

void randomNumbers(int &a, int &b) {
    a = (rand() % (10 - 1 + 1) + 1);
    b = (rand() % (10 - 1 + 1) + 1);
}

int main() {
    srand(time(0));
    int x = 0, y = 0, n = 0, answer = 0, wrongAnswer = 0;

    std::cout << "Hello! Please enter the number of desired questions: ";
    std::cin >> n;

    auto t1 = highResClock::now();
    while(n != 0) {
        randomNumbers(x, y);
        std::cout << "What is " << x << " X " << y << " ?" << std:: endl;
        std::cin >> answer;
        while(answer != x * y) {
            ++wrongAnswer;
            std::cout << "Wrong answer. Try again: ";
            std::cin >> answer;
        }

        --n;
    }
    auto t2 = highResClock::now();

    auto duration = std::chrono::duration_cast<seconds> (t2 - t1);

    std::cout << "You finished in: " << duration.count() << " seconds and you got " << wrongAnswer << " mistakes " << std::endl; 

    return 0;
}