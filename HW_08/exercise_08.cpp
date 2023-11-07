#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void readFromFile(std::string &str) {
    std::ifstream myFile("numbers.txt");

    if(myFile.is_open()) {
        while(getline(myFile, str)) {
            std::cout << str << std::endl;
        }

        myFile.close();
    } else {
        std::cout << "Unable to open file!" << std::endl;
    }
}

int main() {
    std::string line = "";
    
    readFromFile(line);

    return 0;
}