#include <iostream>
#include <string>

int main() {
    std::string s = "", subs = "";
    int a = 0, b = 0, begin = 0, end = 0;

    std::cout << "Please enter a word and two integer numbers: ";
    std::getline(std::cin, s) >> a >> b;

    if(a == b) {
        while(a == b) {
            std::cout << "Please enter non equal numbers!" << std::endl;
            std::cout << "Please enter second number again: ";
            std::cin >> b;
        }
    }

    if(a > b) {
        begin = b, end = a - b;
    } else {
        begin = a, end = b - a;
    }

    subs = s.substr(begin, end);

    std::cout << subs << std::endl;

    return 0;
}