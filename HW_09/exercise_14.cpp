#include <iostream>

char * strncpy(char *dest, const char *src, const std::size_t &num) {
    size_t i = 0;
    if(num > 0) {
        for(; i < num && src[i] != '\0'; ++i) {
            dest[i] = src[i];
        }

        dest[i] = '\0';
    } else {
        dest[i] = '\0';
    }

    return dest;
}

int main() {
    char source[] = "Hello,CodeAcademy!";
    std::size_t number = 0;

    std::cout << "Plese enter the number of characters you wish to copy: ";
    std::cin >> number;

    char destination[number + 1];

    std::cout << strncpy(destination, source, number) << std::endl;


    return 0;
}