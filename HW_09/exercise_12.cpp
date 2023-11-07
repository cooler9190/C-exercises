#include <iostream>
#include <cstring>
#include <string>

std::size_t strlen(const char* str){
    size_t count = 0;

    while(*str != '\0') {
        ++count;
        ++str;
    }

    return count;
}

const char* strstr(const char* haystack, const char* needle) {
    char tmp[strlen(needle) + 1];
    const char* res = nullptr;

    for(size_t i = 0; haystack[i] != '\0'; ++i) {
        tmp[0] = haystack[i];
        if(tmp == needle) {
            return needle;
        }
        for(size_t j = i + 1, index = 1; haystack[j] != '\0'; ++j, ++index) {
            tmp[index] = haystack[j];

            if(strlen(tmp) < strlen(needle)) {
                continue;
            } else if(strlen(tmp) > strlen(needle)) {
                break;
            } else if(strlen(tmp) == strlen(needle)) {
                if(std::strcmp(tmp, needle) == 0) {
                    return needle;
                }
            } else {
                break;
            }
        }

        std::memset(tmp, '\0', sizeof(tmp));
    }

    return res;
}

int main() {
    const char* haystack = "Hello,CodeAcademy";
    const char* needle = "!!!";

    const char* result = strstr(haystack, needle);

    if(result != nullptr) {
        std::cout << result << " is present in the c-string " << std::endl;
    } else {
        std::cout << result << " is not present in the c-string" << std::endl;
    }

    return 0;
}