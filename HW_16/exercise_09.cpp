#include <iostream>
#include <algorithm>

int main() {
    char cstring[] = "HHHeello, CcodeeAAcaddemmy!";
    int size = sizeof(cstring) / sizeof(char);
    char *lastPtr = cstring + size - 1;

    char *newLastPtr = std::unique(cstring, lastPtr);

    *newLastPtr = '\0'; 

    std::cout << cstring << std::endl;

    return 0;
}