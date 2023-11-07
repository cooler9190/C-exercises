#include <iostream>

using u8 = unsigned char;
using u8bitpos = u8;
using u8bit = bool;

u8bit u8_get_bit(u8 num, u8bitpos pos) {
    return (num >> pos) & 1;
}

int main() {
    u8 number = 0b10011010;
    u8bitpos position = 6;

    // std::cout << "Please enter the 8 bit number: ";
    // std::cin >> number;

    // std::cout << "Now enter the number of the bit's position: ";
    // std::cin >> position;

    std::cout << u8_get_bit(number, position) << std::endl;

    return 0;
}