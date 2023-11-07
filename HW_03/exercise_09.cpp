#include <iostream>

int main() {
    unsigned long long int milliseconds = 0, seconds = 0, minutes = 0, hours = 0, days = 0;

    std::cout << "Please enter an integer number in milliseconds: ";
    std::cin >> milliseconds;

    seconds = milliseconds / 1000;
    minutes = seconds / 60;
    hours = minutes / 60;
    days = hours / 24;

    milliseconds %= 1000;
    seconds %= 60;
    minutes %= 60;
    hours %= 24;

    std::cout << days << " " << hours << " " << minutes << " " << seconds << " " << milliseconds << std::endl;

    return 0;
}