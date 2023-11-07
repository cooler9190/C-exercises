#include <iostream>

using u8 = unsigned char;
using u8bitpos = u8;
using u8bit = bool;

u8 u8_toggle_bits(u8& num) {
    u8 mask = 0xff;
    return num ^= mask;
    
}

int main() {    
    u8 number = 0b00011010;

    u8_toggle_bits(number);

    return 0;
}