#include <iostream>

using u8 = unsigned char;
using u8bitpos = u8;
using u8bit = bool;

int u8_toggle_bit(u8& num, u8bitpos pos) {
    u8 mask = 01 << pos;
    return static_cast<int> (num ^= mask);
    
}

int main() {     
    u8 number = 0b10101100;
    u8bitpos position = 3;

    std::cout << u8_toggle_bit(number, position);

    return 0;
}