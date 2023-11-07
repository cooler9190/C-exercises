#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
 
using matrix = std::vector<std::string>;
 
void printNodes(const matrix (&matr)) {
    for(size_t row = 0; row < matr.size(); ++row) {
        for(size_t col = 0; col < matr[row].size(); ++col) {
            if(matr[row][col] == '0') {
                int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
 
                for(size_t i = col + 1; i < matr[row].size(); ++i) {
                    if(matr[row][i] == '0') {
                        x2 = i, y2 = row;
                        break;
                    }
                }
                for(size_t j = row + 1; j < matr.size(); ++j) {
                    if(matr[j][col] == '0') {
                        x1 = col, y1 = j;
                        break;
                    }
                }
                std::cout << col << " " << row << " " << x2 << " " << y2 << " " << x1 << " " << y1 << std::endl;
            } else {
                continue;
            }
        }
    }
}

int main()
{
    int width; 
    std::cin >> width; std::cin.ignore();
    int height; 
    std::cin >> height; std::cin.ignore();
    matrix matrix;
    for (int i = 0; i < height; i++) {
        std::string line;
        std::getline(std::cin, line); 
        matrix.push_back(line);
    }
 
    printNodes(matrix);
}
