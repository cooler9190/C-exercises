#include <iostream>
#include <string>


using string = std::string;

void printStringInReverse(string &str) {
    for(string::iterator iter = str.end(); iter >= str.begin(); --iter) {
        std::cout << *iter;
    }
    std::cout << std::endl;
}

int main() {
    string sentance = "";

    std::cout << "Please enter a sentance: ";
    std::getline(std::cin, sentance);

    printStringInReverse(sentance);

    return 0;
}