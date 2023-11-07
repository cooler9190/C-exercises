#include <iostream>
#include <fstream>
#include <vector>

void writeInFile(const std::vector<int> &vec) {
    std::ofstream myFile("numbers.txt");
    if(myFile.is_open()) {
        for(size_t i = 0; i < vec.size(); ++i) {
            myFile << vec[i] << " ";
        }

        myFile.close();
    } else {
        std::cout << "Unable to open file!" << std::endl;
    }
}

int main() {
    std::vector<int> numbers = {78, 37, 33, 89, 78, 40, 60, 37, 33, 49};

    writeInFile(numbers);

    return 0;
}