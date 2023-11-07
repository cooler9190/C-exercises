#include <iostream>

using u8 = unsigned char;
using u8bitpos = u8;
using u8bit = bool;

void u8_set_bit(u8& num, u8bitpos pos, u8bit val) {
    if(val == 1) {
        u8 mask = 01 << pos;
        num |= mask;
    } else {
        u8 mask = 01 << pos;
        mask = ~mask;
        num &= mask;
    }
}

int main() {
    u8 number = 0b10011010;
    u8bitpos position = 6;
    u8bit value = 1;

    u8_set_bit(number, position, value);

    return 0;
}