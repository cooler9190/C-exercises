#include <iostream> 
#include <string>
#include <cctype>

int main() {
    std::string s = "", word = "";
    double wordCount = 0, totalLengthOfWords = 0, averageLengthOfWords = 0;

    std::cout << "Please enter a sentance: ";
    std::getline(std::cin, s);

    if(s[s.size() - 1] != '.' && s[s.size() - 1] != '!' && s[s.size() - 1] != '?') {
        std::cout << "The sentance must end with an ending punctuation(. , !, ?)!" << std::endl;
        return 0;
    }

    for(int i = 0; i < s.size(); ++i) {
        if(isalpha(s[i])) {
            word += s[i];
        } else {
            if(word.empty()) {
                continue;
            }
            wordCount++;
            totalLengthOfWords += word.size();
            word.clear();
        }
    }

    averageLengthOfWords = totalLengthOfWords / wordCount;

    std::cout << "The average length of the words is: " << averageLengthOfWords << std::endl;

    return 0;
}