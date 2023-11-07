#include <iostream>
#include <string>
#include <vector>

//switch case and check if matching

bool areBracketsCorrectlyClosed(const std::string &str) {
    std::vector<char> brackets = {};
    for(size_t i = 0; i < str.size(); ++i) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            brackets.push_back(str[i]);
        } else if(str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if(brackets.empty()) {
                return false;   //there is closing brakcet, but no opening bracket
            }

            char top = brackets.back();
            brackets.pop_back();

            if((str[i] == ')' && top != '(') ||
               (str[i] == ']' && top != '[') ||
               (str[i] == '}' && top != '{')) {
                return false; //no mathing brackets;
            }
        } 
    }

    return brackets.empty();
}

int main() {
    std::string sentance = "";

    std::cout << "Please enter a sentance: ";
    std::getline(std::cin, sentance);

    if(areBracketsCorrectlyClosed(sentance) == 1) {
        std::cout << "The brackets in the sentance are closed correctly" << std:: endl;
    } else {
        std::cout << "The brackets in the sentance are not closed correctly" << std::endl;
    }

    return 0;
}