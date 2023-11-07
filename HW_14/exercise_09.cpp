#include <iostream>
#include <fstream>
#include <string>

//pos = word.find()
int main(int argc, char *argv[]) {
    std::ifstream dictionary("words_alpha.txt");
    std::string word = "";

    if(dictionary.is_open()) {
        bool flag = false;
        while(getline(dictionary, word)) {
            word.pop_back();
            if(argv[1] == word) {
                flag = true;
                std::cout << argv[1] << " is spelled correctly." << std::endl;
                break;
            } 
        }

        if(flag == false) {
            std::cout << argv[1] << " is not spelled correctly." << std::endl;
        }

        dictionary.close();
    } else {
        std::cout << "Unable to open file!" << std::endl;
    }

    return 0;
}
