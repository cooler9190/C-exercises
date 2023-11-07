#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

void shuffleText(const std::string &txt) {
    int size = txt.size();
    std::string word = "";
    std::vector<std::string> shuffledText;

    for(auto iter = txt.begin(); iter != txt.end(); ++iter) {
        if(!isspace(*iter)) {
            word += *iter;
        } else {
            shuffledText.push_back(word);
            word.clear();
        }
    }

    if(!word.empty()) {
        shuffledText.push_back(word);
    }

    while(!shuffledText.empty()) {
        int randomIndex = rand() % shuffledText.size();
        std::cout << shuffledText[randomIndex] << " ";
        shuffledText.erase(shuffledText.begin() + randomIndex);
    }

    std::cout << std::endl;
}

int main() {
    srand(time(0));
    std::string text = "";

    std::cout << "Please enter your text: " << std::endl;
    std::getline(std::cin, text);

    shuffleText(text);

    return 0;
}