#include <iostream>

std::size_t strlen(const char* str){
    size_t count = 0;

    while(*str != '\0') {
        ++count;
        ++str;
    }

    return count;
}

char *strcat(char *dest, const char *src) {
    for(size_t i = 0, index = strlen(dest); i <= strlen(src) + 1; ++i, ++index) {
        dest[index] = src[i];
    }

    return dest;
}

int main() {
    char destination[256] = "Hello,";
    char source[] = "CodeAcademy!";

    std::cout << strcat(destination, source) << std::endl;

    return 0;
}