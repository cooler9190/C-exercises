#include <iostream>

std::size_t strlen(const char* str){
    size_t count = 0;

    while(*str != '\0') {
        ++count;
        ++str;
    }

    return count;
}

void reverseCstring(const char** matrix, const size_t &n, const size_t &m) {
    for(size_t i = 0; i < n; ++i) {
        for(signed int j = strlen(matrix[i]); j >= 0; --j) { 
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {

    const char* matrix[5][11] = {"lemon", "orange", "grapefruit", "pear", "apple"};

    reverseCstring((const char**)matrix, 5, 11);

    return 0;
}