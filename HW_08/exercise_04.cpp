#include <iostream>
#include <string>


using string = std::string;

bool isPalindrome(string &str) {
    string::iterator itBegin = str.begin(), itEnd = str.end() - 1;

    while(itBegin < itEnd) {
        if(*itBegin != *itEnd) {
            return false;
        }

        ++itBegin;
        --itEnd;
    }
    
    
    return true;
}

int main() {
    string word = "";

    std::cout << "Please enter a word ";
    std::cin >> word;

    if(isPalindrome(word) == 1) {
        std::cout << "The word is a palindrome." << std::endl;
    } else {
        std::cout << "The word is not a palindrome." << std::endl;
    }

    return 0;
}