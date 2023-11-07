#include <iostream>
#include <string>

int main() {
    std::string text = "", longestLine = "", shortestLine = "", longestWord = "", tmp = "";

    while(std::getline(std::cin, text)) {
        if(text.size() > longestLine.size()) {
            longestLine = text;
        } 

        if(shortestLine == "") {
            shortestLine = text;
        }
        
        if(text.size() < shortestLine.size()) {
            shortestLine = text;
        }
        
        for(int i = 0; i < text.size(); i++) {
            if(text[i] == ' ' || ispunct(text[i])) {
                if(tmp.size() > longestWord.size()) {
                longestWord = tmp;
                }
                tmp = "";
            } else {
                tmp += text[i];
            }
        }

        if(tmp.size() > longestWord.size()) {
            longestWord = tmp;
        }
        tmp = "";
    }

    std::cout << "The longest line in the text is: " << longestLine << " and it's length is: " << longestLine.size() << std::endl;
    std::cout << "The shortest line in the text is: " << shortestLine <<  " and it's length is: " << shortestLine.size() << std::endl;
    std::cout << "The longest word in the text is: " << longestWord <<  " and it's length is: " << longestWord.size() << std::endl;

    return 0;
}