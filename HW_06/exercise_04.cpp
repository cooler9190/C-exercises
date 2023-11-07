#include <iostream>

using u8 = unsigned char;
using u8bitpos = u8;
using u8bit = bool;

u8 u8_set_bit_off(u8& num, u8bitpos pos) {
    u8 mask = 01 << pos;
    mask = ~mask;
    return num &= mask;
}

int main() {
    u8 number = 0b10011010;
    u8bitpos position = 6;

    u8_set_bit_off(number, position);

    return 0;
}