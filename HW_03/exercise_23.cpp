#include <iostream>
#include <string>

int main() {
    std::string text = "";
    int letterCount = 0 ,wordCount = 0, lineCount = 0;

    while(std::getline(std::cin, text)) {
        lineCount++;

        for(int i = 0; i < text.size(); i++) {
            if(text[i] == ' ') {
                wordCount++;
                continue;
            }
            letterCount++;
        }
        wordCount++;
    }

    std::cout << "The numer of lines in the text are: " << lineCount << std::endl;
    std::cout << "The numer of words in the text are: " << wordCount << std::endl;
    std::cout << "The numer of letters in the text are: " << letterCount << std::endl;

    return 0;
}