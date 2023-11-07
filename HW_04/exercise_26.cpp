#include <iostream>
#include <string>

std::string caesarsCipher(std::string message, int shift) {
    std::string encryptedMessage = "";

    for(signed int i = 0; i < message.size(); i++) {
        if(isspace(message[i]) || ispunct(message[i])) {
            continue;
        } else if(isupper(message[i])) {
            encryptedMessage += char(int(message[i] - shift + 65) % 26 + 65);
        } else {
            message[i] = toupper(message[i]);
            encryptedMessage += char(int(message[i] - shift + 65) % 26 + 65 + 32);
        }
    }

    return encryptedMessage;
    
}

int main() {
    std::string message = "";
    int shift = 0;

    std::cout << "Enter the message you wish to encrypt: ";
    getline(std::cin, message);

    std::cout << "Now enter the shift number: ";
    std::cin >> shift;

    if(shift < 0 || shift > 25 ) {
        while(shift < 0 || shift > 25) {
            std::cout << "The key must be in the range from 0-25." << std::endl;
            std::cout << "Please enter the key again: ";
            std::cin >> shift;
        }
    }

    std::cout << caesarsCipher(message, shift) << std::endl;

    return 0;
}