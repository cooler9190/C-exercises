#include <iostream>

int main() {
    int sec = 60, hours = 24, min = 60, days = 365, leapYear = 366; 

    hours *= days;
    min *= hours;
    sec *= min;  

    std::cout << "There are " << sec << " seconds in a year." << std::endl;

    sec += 1440 * 60;

    std::cout << "There are " << sec << " seconds in a leap year." << std::endl;


    return 0;
}