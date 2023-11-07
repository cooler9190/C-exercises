#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> stringVec;
typedef void (*funcPtr)(const std::string &s);

auto vecPrintType(const stringVec &vec, funcPtr userChoice) -> void{
    for(const std::string str : vec) {
        userChoice(str);
    }
}

inline void printString(const std::string &str) { std::cout << str << " ";}

void printReverseString(const std::string &str) { 
    for(int i = str.length(); i >= 0; --i) {
        std::cout << str[i];
    }

    std::cout << " ";
}


int main() {
    stringVec strings = {"Hello", "Code", "Academy", "!"};

    vecPrintType(strings, printString);

    std::cout << std::endl;

    vecPrintType(strings, printReverseString);

    std::cout << std::endl;

    return 0;
}