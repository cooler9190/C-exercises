#include <iostream>
#include <string>

int convert(const std::string &str) {
    return std::stoi(str);
}

std::string convert(const int &a) {
    return std::to_string(a);
}

int main() {
    int a = 13;
    std::string num = "13cd";

    std::cout <<  convert(a) << std::endl;
    std::cout << convert(num) << std::endl;

    return 0;
}