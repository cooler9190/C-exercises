#include <iostream>
#include <string>

int main() {
    std::string s = "";
    

    std::cout << "Please enter a word: ";
    std::cin >> s;
    int length = s.size();
    bool flag = true;

    for(int i = 0; i < length; i++) {
        if(s[i] != s[length - i - 1]) {
            flag = false;
            break;
        }
    }

    if(flag == true) {
        std::cout << "The word " << s << " is a palindrome" << std::endl;
    } else {
        std::cout << "The word " << s << " is not a palindrome" << std::endl;
    }

    return 0;
}