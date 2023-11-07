#include <iostream>
#include <string>
#include <cmath>

int binToDec(std::string n) {
    int decimal = 0, exponent = 0, length = n.size();
    
    for(int i = length - 1; i >= 0; i--) {
        if(n[i] == '0') {
            decimal += int((n[i]) - 48) * pow(2, exponent); 
        } else if(n[i] == '1'){
            decimal += int((n[i]) - 48) * pow(2, exponent);
        } else {
            continue;
        }
        exponent++;
    }

    return decimal;
}

int octToDec(std::string n) {
    int decimal = 0, exponent = 0, length = n.size();
    
    for(int i = length - 1; i >= 0; i--) {
        if(n[i] >= '0' && n[i] <= '7') {
            decimal += int((n[i]) - 48) * pow(8, exponent); 
        } else {
            continue;
        }
        exponent++;
    }

    return decimal;
}

int hexToDec(std::string n) {
    int decimal = 0, exponent = 0, length = n.size();
    
    for(int i = length - 1; i >= 0; i--) {
        if(islower(n[i])) {
            n[i] = toupper(n[i]);
        }
        if(n[i] >= '0' && n[i] <= '9') {
            decimal += int((n[i]) - 48) * pow(16, exponent); 
        } else if(n[i] >= 'A' && n[i] <= 'F'){
            decimal += int((n[i]) - 55) * pow(16, exponent);
        } else {
            continue;
        }
        exponent++;
    }

    return decimal;
}

int main() {
    std::string a = "", b = "";
    int x = 0, y = 0;
    unsigned char op = '0';

    while(true) {
        std::cout << ">>> ";
        std::cin >> a;

        if(a[1] == 'b') {
            x = binToDec(a);
        } else if(a[1] == 'x') {
            x = hexToDec(a);
        } else if(a[0] == '0') {
            x = octToDec(a);
        } else {
            x = std::stoi(a);
        }

        while(true) {
            std::cout << ">>> ";
            std::cin >> op;

            std::cout << ">>> ";
            std::cin >> b;

            if(b[1] == 'b') {
                y = binToDec(b);
            } else if(b[1] == 'x') {
                y = hexToDec(b);
            } else if(b[0] == '0') {
                y = octToDec(b);
            } else {
                y = std::stoi(b);
            }

            if(op == '+') {
                x += y;
            } else if(op == '-') {
                x -= y;
            } else if(op == '*') {
                x *= y;
            } else if(op == '/') {
                while(y == 0) {
                    std::cout << "Cannot divide by 0!" << std::endl;
                    std::cout << "Please enter y again: ";
                    std::cin >> y;
                }
                x /= y;
            } else if(op == '&') {
                x &= y;
            } else if(op == '|') {
                x |= y;
            }  else if(op == '^') {
                x ^= y;
            }  else if(op == '<') {
                x <<= y;
            } else if(op == '>') {
                x >>= y;
            } else {
                return 0;
            }

            if(std::cin.eof()) {
                return 0;
            }

            std::cout << x << std::endl;
        }
    }
    return 0;
}