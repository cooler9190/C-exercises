#include <iostream>
#include <string>
#include <cctype>

void isPalindrome(std::string s, bool onlyLetters) {
    bool flag = true;

    for(int i = 0; i < s.size(); i++) {
        if(islower(s[i])) {
            s[i] = toupper(s[i]);
        }
    }

    for(int i = 0; i < s.size(); i++) {
        if(onlyLetters == true) {
            if(!isalpha(s[i])) {
                continue;
            }
        }
        
        if(s[i] != s[s.size() - i - 1]) {
            flag = false;
            break;
        }
    }

    if(flag == true) {
        std::cout << "This is a palindrome" << std::endl;
    } else {
        std::cout << "This is not a palindrome" << std::endl;
    }
}

int main() {
    std::string s = "", answer = "";
    bool onlyLetters;
    
    std::cout << "Please enter a word: ";
    std::cin >> s;
    std::cout << "Do you want to ignore symbols other than letters?(y/n): ";
    std::cin >> answer;

    if(answer == "y") {
        onlyLetters = true;
    } else {
        onlyLetters = false;
    }

    isPalindrome(s, onlyLetters);

    return 0;
}