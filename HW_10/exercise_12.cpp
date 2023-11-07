#include <iostream>
#include <array>
#include <string>
#include <algorithm>

using Criteria = bool (*)(const std::string &str);

void eraseElements(std::array<std::string, 6> &arr, int &n, Criteria crit) {
    for(size_t i = 0; i < n; ++i) {
        if(crit(arr[i]) == 0) {
            std::remove(arr.begin(), arr.end(), arr[i]);
        }
    }
}

bool hasStringSymbols(const std::string &str) {
    for(size_t i = 0; i < str.size(); ++i) {
        if(!isalpha(str[i])) {
            return false;
        }
    }

    return true;
}

bool isStringPalindrome(const std::string &str) {
    for(size_t i = 0; i < str.size(); ++i) {
        if(str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::array<std::string, 6> strings = {"hello", "code", "noon", "academy.", "!", ":)"};
    int n = 6;

    std::cout << "The array after deleting all strings with symbols are: ";

    eraseElements(strings, n, hasStringSymbols); 
    for(size_t i = 0; i < n; ++i) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "The array after deleting all strings that are not palindromes are: ";

    eraseElements(strings, n, isStringPalindrome); 
    for(size_t i = 0; i < n; ++i) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}