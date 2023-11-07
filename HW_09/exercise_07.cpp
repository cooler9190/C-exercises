#include <iostream>

std::size_t strlen(const char* str){
    size_t count = 0;
    // for(size_t i = 0; str[i] != '\0'; ++i) {
    //     ++count;
    // }

    while(*str != '\0') {
        ++count;
        ++str;
    }

    return count;
}

int main() {
    const char* cstring = "Codessssss";

    std::cout << "The length of the c-string is: " << strlen(cstring) << std::endl;

    return 0;
}