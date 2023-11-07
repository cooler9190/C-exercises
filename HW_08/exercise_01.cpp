#include <iostream>
#include <cstdlib>
#include <ctime>

int randomNumber(const int &start, const int &end) {
    int x = (rand() % (end - start + 1) + start);

    return x;
}

int main() {
    int begin = 0, end = 0;
    srand(time(0));

    std::cout << "Please enter the beginning of the range: ";
    std::cin >> begin;
    std::cout << "Now enter the end of the range: ";
    std::cin >> end;

    std::cout << "Random number from " << begin << " to " << end << " is: " << randomNumber(begin, end) << std::endl;

    return 0;
}