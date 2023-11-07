#include <iostream>

std::size_t strlen(const char* str){
    size_t count = 0;

    while(*str != '\0') {
        ++count;
        ++str;
    }

    return count;
}

void printLettersEqualToColumn(const char** matrix, const size_t &n) {
    bool flag = false;
    for(size_t i = 0; i < n; ++i) {
        if(strlen(matrix[i]) == i + 1) {
            flag = true;
            std::cout << "The word: " << matrix[i] << " has the same amount of letters as it's column number" << std::endl;
        }
    }

    if(flag == false) {
        std::cout << "There are no words with matching amount of letters and column numbers." << std::endl;
    }
}

int main() {

    const char* matrix[5][11] = {"lemon", "orange", "grapefruit", "pear", "apple"};

    printLettersEqualToColumn((const char**)matrix, 5);

    return 0;
}