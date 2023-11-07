#include <iostream>

using u8 = unsigned char;
using u8bitpos = u8;
using u8bit = bool;

u8 u8_reverse_bits(u8 &num) {
    u8 reverse = 0b0;

    while(num > 0) {
        reverse <<= 1;
        if(num & 1 == 1) {
            reverse ^= 1;
        }

        num >>= 1;
    }

    return reverse;
}

int main() {    
    u8 number = 0b00001101;
    std::cout << static_cast<int> (u8_reverse_bits(number));

    return 0;
}