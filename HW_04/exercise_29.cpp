#include <iostream>
#include <string>

std::string atbashCipher(std::string message) {
    std::string encryptedMessage = "";

    std::string reverseAplha = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    
    for(int i = 0; i < message.size(); i++) {
        if(isspace(message[i]) || ispunct(message[i])) {
            continue;
        } else if(isupper(message[i])) {
            encryptedMessage += reverseAplha[(int) message[i] - 65];
        } else {
            message[i] = toupper(message[i]);
            encryptedMessage += char(reverseAplha[(int) message[i] - 65] + 32);
        }
    }

    return encryptedMessage;
    
}

int main() {
    std::string message = "";
    int shift = 0;

    std::cout << "Enter the message you wish to decrypt: ";
    getline(std::cin, message);

    std::cout << atbashCipher(message) << std::endl;

    return 0;
}