#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef std::vector<std::string> stringVec;
typedef void (*funcPtr)(const std::string &);
typedef void (*funcPtr2)(stringVec &, std::string &);

auto vecManipulation(const stringVec &vec, funcPtr userChoice) -> void{
    for(const std::string str : vec) {
        userChoice(str);
    }
}

auto vecManipulation(stringVec &vec, funcPtr2 userChoice, std::string &userInput) -> void{
    userChoice(vec, userInput);
}

inline void printString(const std::string &str) { std::cout << str << " ";}

void printReverseString(const std::string &str) { 
    for(int i = str.length(); i >= 0; --i) {
        std::cout << str[i];
    }

    std::cout << " ";
}

void writeInElement(stringVec &vector, std::string &input) {
    for(std::string &str : vector) {
        str += " " + input;
    }
}

void toLower(stringVec &vector, std::string &input) {
    std::reverse(vector.begin(), vector.end());
    for(std::string &str : vector) {
        for(char &c : str) {
            if(std::isupper(c)) {
                c = std::tolower(c);
            }
        }
    }
}


int main() {
    stringVec strings = {"Hello", "Code", "Academy", "!"};
    std::string userInput = "";

    vecManipulation(strings, printString);

    std::cout << std::endl;

    std::cout << "Please enter a string to be appended to every element: ";
    std::cin >> userInput;

    vecManipulation(strings, writeInElement, userInput);

    vecManipulation(strings, printString);

    vecManipulation(strings, printReverseString);

    std::cout << std::endl;

    vecManipulation(strings, toLower, userInput);
    
    vecManipulation(strings, printString);

    std::cout << std::endl;

    return 0;
}